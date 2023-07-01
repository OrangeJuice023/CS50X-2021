import cs50
from sys import argv

# global variables
zelch = 0
hydra = 8
uno = 1
length = len(argv)

able = cs50.get_int


def main():
    # receives command-line arguments
    if length == uno:
        print(f"hello user, ")
       
    while True:
        h = able("Height: ")
        if h > zelch and h <= hydra:
            break

    for blocks in range(uno, (h + uno)):
        # declare
        spacing = h - blocks
        # Print spaces in a row and hashes at the same time
        print(" " * (spacing) + "#" * blocks, end='')
        print()


if __name__ == "__main__":
    main()

