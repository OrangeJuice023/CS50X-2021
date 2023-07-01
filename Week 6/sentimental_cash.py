# header files
import cs50
from sys import argv

# initiate some global variables

uno = 1
zelch = 0
hundred = 100
highest = 25
high = 10 
lima = 5
length = len(argv)

able = cs50.get_float

# main function


def main():
    
    if length == uno:
        print(f"hello user")
       
    sukli = ask_change()
    pera = calc_coins(sukli)
    print(f"{pera}")

# prompts the user of change


def ask_change():
    while True:
        sukli = able("How many cash owed? : ")
        if sukli >= zelch:
            break

    return sukli

# initiates the greedy algorithm


def calc_coins(sukli):
    cents = round(sukli * hundred)
    greedy_algo = cents//highest + (cents % highest)//high + ((cents % highest) % high)//lima + ((cents % highest) % high) % lima
    num_coins = greedy_algo
    pera = int(num_coins)
    
# returns the answer to the algorithm
    return pera


main()

