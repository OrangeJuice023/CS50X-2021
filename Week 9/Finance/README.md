# C$50 Finance 📈

C$50 Finance is a web-based tool that allows users to manage portfolios of stocks. This project is a stock trading simulator that lets users "buy" and "sell" stocks using real-world market data, managed via a virtual cash balance.

## features

- **User Authentication**: Secure registration and login system with persistent sessions.
- **Real-time Stock Quotes**: Fetches latest stock prices using the **Massive (Polygon.io)** API.
- **Stock Trading**: Buy and sell stocks at current market prices.
- **Portfolio Management**: View a summary of your holdings, current prices, and total portfolio value.
- **Transaction History**: Track every buy and sell transaction with timestamps and pricing details.
- **Virtual Balance**: Every user starts with a virtual $10,000.00 to trade.

## tech stack

- **Backend**: Python with the [Flask](https://flask.palletsprojects.com/) web framework.
- **Database**: [SQLite](https://www.sqlite.org/) for persistent storage of users and transactions.
- **Frontend**: HTML5, CSS3, and [Bootstrap 5](https://getbootstrap.com/) for a responsive, clean UI.
- **API**: [Massive (Polygon.io)](https://polygon.io/) for real-time market data.
- **Templating**: Jinja2 for dynamic content rendering.

## installation

1. **Clone the repository** (if applicable) or navigate to the project directory.
2. **Install dependencies**:
   ```bash
   python -m pip install -r requirements.txt
   ```
   *Note: Ensure you have `flask`, `flask-session`, `requests`, and `cs50` installed.*

3. **Set your API Key**:
   Get a free API key from [Polygon.io](https://polygon.io/) and set it as an environment variable:
   ```bash
   # Windows (PowerShell)
   $env:API_KEY = "your_api_key_here"
   
   # Linux/macOS
   export API_KEY="your_api_key_here"
   ```

## running the app

Run the Flask development server:

```bash
# Set the FLASK_APP environment variable
$env:FLASK_APP = "application.py"

# Run Flask
python -m flask run
```

The application will be available at `http://127.0.0.1:5000` (or the port specified in your run command).

## layout credits
Original design and requirements provided by **CS50x**. Data integration updated to support the Massive API for modern reliability.
