import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime, timezone

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    
    # Create a list of query to the user's portfolio
    portfolio = db.execute(
        "SELECT symbol, name,price, SUM(shares) as Usershares FROM userportfolio WHERE user_id = :unq_id GROUP BY symbol HAVING Usershares > 0 ORDER BY symbol ASC", unq_id=session['user_id'])
    
    # Get user's cash from userportfolio dict starting from 0
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session['user_id'])[0]["cash"]
    
    # Initialize cash as a function
    user_total = cash
    
    # iterate through the portfolio and add price and total to the dictionaries
    for queried_stock in portfolio:
        if queried_stock.get("Usershares") == 0:
            continue
        queried_stock["total"] = queried_stock["Usershares"] * queried_stock["price"]
        user_total += queried_stock["price"] * queried_stock["Usershares"]

    return render_template("index.html", portfolio=portfolio, cash=cash, usd=usd, user_total=user_total)
    
    
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        
        # Get input from Symbols field
        symbol = request.form.get("symbol").upper()
        
        # Get input from the Shares field
        amount = (request.form.get("shares"))
        
        # looks up the Stock Symbol
        query = lookup(symbol)
        
        # Validity checker for symbol and shares
        if request.form.get("symbol").upper() == "":
            return apology("Input Your Symbol", 400)
        # check for invalid input
        if not amount.isdigit():
            return apology("Please provide a positive numeric number", 400)
        elif int(request.form.get("shares")) < 1:
            return apology("Shares must not be of negative value!", 400)
        else:
            if query is None:
                return apology("Your Symbol is Invalid!", 400)

        # Assign quantity of shares to the user
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        
        # Put queried fields into variables
        user_name = query["name"]
 
        total_user_shares = int(amount) * query["price"]
        
        remain = cash - total_user_shares

        # Check also if the cash is still sufficient
        if cash < total_user_shares:
            return apology("You don't have enough cash!", 400)
        else:
            # Deduct the cost from the user's balance
            db.execute("UPDATE users SET cash = ? WHERE id = ?", remain, session["user_id"])
            # Insert data into the userportfolio table
            db.execute("INSERT INTO userportfolio (user_id, name, symbol, shares, price, type, timestamp) VALUES (?, ?, ?, ?, ?, ?, ?)",
                       session["user_id"], user_name, symbol, amount, query["price"], "buy", time_zone())
                
            return redirect("/")
    else:
        # Just return back to buy.html
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    
    # Store the username of the user logged
    portfolio = db.execute(
        "SELECT type AS Type, symbol AS Symbol, price AS Price, shares AS Shares, timestamp AS Time FROM userportfolio WHERE user_id = :unique_id", unique_id=session['user_id'])
    # Goes to the history
    return render_template("history.html", portfolio=portfolio,)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # For request sent via POST
    if (request.method == "POST"):

        symbol = request.form.get("symbol")

        if not request.form.get("symbol"):
            return apology("Pls Enter A Stock!", 400)

        query = lookup(symbol)

        if not query:
            return apology("Pls put a valid stock!", 400)
            return render_template("quote.html", invalid=True, the_quote=symbol)
        return render_template("quoted.html", find=query)

    else:
        # If only GET, then render quote.html
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # For information sent via POST
    if (request.method == "POST"):

        # Get input fields
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username field is not empty
        if not request.form.get("username"):
            return apology("Pls Enter Username!", 400)

        # Ensure password field is not empty
        elif password == "":
            return apology("Pls Enter Password!", 400)

        # Ensure confirmation field is not empty
        elif confirmation == "":
            return apology("Pls Enter Confirmation!", 400)

        # Ensures that passwords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords don't match!", 400)

        elif len(db.execute("SELECT username FROM users WHERE username = ?", username)) > 0:
            return apology("Username Already Exists!", 400)

        # Insert user fields into database
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, generate_password_hash(password))

        # start session
        cookies = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Remember to give session for every user
        session["user_id"] = cookies[0]["id"]

        # Redirect user to home page
        return redirect("/")
    else:
        # If only GET, then render register.html
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    
    # For information sent via POST
    if request.method == "POST":
        
        # Get symbol and shares in the required field 
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares")) 
        unique_id = session["user_id"]
       
        # Store the symbol inputed
        query_item = lookup(symbol)
       
        # Validity checker for symbol and shares
       
        if not request.form.get("symbol") or query_item == None:
            return apology("You must pick your stock!", 400)
        elif int(request.form.get("shares")) < 1:
            return apology("Amount must be positive integer!", 400)
        elif not shares:
            return apology("Plus put a valid amount of shares!", 400)
        else:
            if query_item is None:
                return apology("Your Stock Not Found!", 400)

        # Assign quantity of shares owned to variable
        owned_shares = db.execute("SELECT shares FROM userportfolio WHERE user_id= ? AND symbol = ? GROUP BY symbol", 
                                  session["user_id"], symbol.upper())[0]["shares"]
        
        # Store the value of shared stocks
        item_value = query_item["price"]
        
        # Store the value of computed sale
        value = item_value * shares
        
        # Store the value of names of stocks   
        stock_name = query_item["name"]
        
        # Compares the users shares
        if owned_shares < shares:
            return apology("You don't have enough shares!", 400)
       
        if owned_shares == None:
            return apology("You don't have shares in the Stock!", 400)
           
        # Queries into the cash field
        cash = db.execute("SELECT cash FROM users WHERE id = ?", unique_id)[0]["cash"]
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", value, session["user_id"])
        db.execute("INSERT INTO userportfolio (user_id, name, shares, price, type, symbol, timestamp) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   session["user_id"],
                   stock_name,
                   -shares,
                   item_value,
                   "sell",
                   symbol.upper(),
                   time_zone())
        # Update the portfolio
        return redirect("/")     
           
    else:
        # Get the symbols from portfolio for the select list
        select_stocks = db.execute(
            "SELECT symbol FROM userportfolio WHERE user_id=:unique_id GROUP BY symbol", unique_id=session["user_id"])
        return render_template("sell.html", amt_owned=select_stocks)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
    
    
def time_zone():
    """HELPER: get current UTC date and time"""
    now_utc = datetime.now(timezone.utc)
    return str(now_utc.date()) + ' - ' + now_utc.time().strftime("%H:%M:%S")