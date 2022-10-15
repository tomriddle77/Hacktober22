import random

newInt = random.randrange(1, 100, 1)

while True:
    n = int(input("Please enter your choice: "))

    if n < newInt:
        print(f"{n} is too small!!")
    elif n > newInt:
        print(f"{n} is too big!!")
    else:
        print(f"{n} was the correct number and you guessed correctly")
        break

