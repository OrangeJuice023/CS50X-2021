from cs50 import get_string
from sys import argv

# receives command-line arguments
if len(argv) == 1:
    print(f"hello user, ")

# prints the name of the user
answer = get_string("What's your name? ")
print("hello, " + answer)