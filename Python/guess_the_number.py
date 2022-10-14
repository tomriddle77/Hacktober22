import random

while True:
    try:
        n = int(input("Level: "))
        if n > 0:
            break
    except ValueError:
        pass

number = random.randint(1, n + 1)

while True:
    try:
        guess = int(input("Guess: "))

        if guess > number and guess in range(1, n+1):
            print("Too large!")
        elif guess < number and guess in range(1, n+1):
            print("Too small!")
        elif guess == number and guess in range(1, n+1):
            print("Just right!")
            break
        
    except ValueError:
        pass

