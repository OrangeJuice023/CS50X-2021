# header files

import cs50
import string
from sys import argv

# global variables

uno = 1
zelch = 0
hund = 100
lowstfloat = 0.0588
lowerfloat = 0.296
lowfloat = 15.8
sixteen = 16
whitespace = string.whitespace
punctutation = string.punctuation
string = cs50.get_string
req_length = len(argv)


def main():
    
    # receives command-line arguments
    if req_length == 1:
        print(f"hello user ")
     
    # Get user input
    prompt = cs50.get_string("What is the text? : ").strip()

    n_let = n_sen = zelch
    n_words = uno

    # Loop through string, identifying each letter
    for letter in prompt:
        if letter in whitespace:
            n_words += uno
        elif letter == "!" or letter == "?" or letter == ".":
            n_sen += uno
        elif letter in punctutation:
            continue 
        elif prompt:
            n_let += uno
        else:
            break
    
    # store the scores as final
    
    finalscore = getscore(n_let, n_sen, n_words)
    
    # print the very final score
    
    printlvl(finalscore)
    

def getscore(n_let, n_sen, n_words):
    
    # Calculations for liau index
    equation = round(lowstfloat * (n_let / n_words * hund) - lowerfloat * (n_sen / n_words * hund) - lowfloat)
    liauIndex = equation
    
    return liauIndex


def printlvl(liauIndex):
    
    # Print correct grade based on liau indx
    if liauIndex >= sixteen:
        print("Grade 16+")
    elif liauIndex < uno:
        print("Before Grade 1")
    else:
        print(f"Grade {liauIndex}")
        
       
main()