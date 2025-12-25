# CS50x Birthdays

A simple web application to keep track of your friends' birthdays. This project is part of Harvard's CS50x course (Week 9: Flask).

## Features
- **Add Birthdays:** Submit a friend's name, birthday month, and day via a form.
- **View Birthdays:** See a list of all saved birthdays stored in a SQLite database.
- **Persistence:** data is saved to `birthdays.db`.

## Prerequisites
- Python 3.x
- pip (Python package installer)

## Installation

1.  Navigate to the project directory:
    ```bash
    cd birthdays
    ```

2.  Install the required dependencies:
    ```bash
    pip install cs50 flask
    ```

## Usage

1.  Start the Flask server:
    ```bash
    flask run
    ```
    *Alternatively, you can run:* `python -m flask run`

2.  Open your web browser and visit the URL shown in your terminal (usually):
    ```
    http://127.0.0.1:5000
    ```

## Project Structure
- `app.py`: Main Flask application file.
- `birthdays.db`: SQLite database file.
- `templates/`: HTML templates (index.html).
- `static/`: CSS and other static assets.
