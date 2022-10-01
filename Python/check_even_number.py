# Check if number that user type is even or odd number
user_input = input("Enter Your Number: ")
num = int(user_input)
if (num % 2) == 0:
    print(str(num) + " is EVEN NUMBER.")
else:
    print(str(num) + " is ODD NUMBER.")
