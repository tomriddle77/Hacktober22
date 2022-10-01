#Password Generator Project
import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters= int(input("How many letters would you like in your password?\n")) 
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))

letters_pass=[]
symbols_pass=[]
numbers_pass=[]

for x in range(nr_letters):
  l_pass=random.choice(letters)
  letters_pass+=l_pass
  
for y in range(nr_symbols):
  s_pass=random.choice(symbols)
  symbols_pass+=s_pass
  
for z in range(nr_numbers):
  n_pass=random.choice(numbers)
  numbers_pass+=n_pass

password=letters_pass+symbols_pass+numbers_pass

random.shuffle(password)
pass_1=''
for i in password:
  pass_1 += i
print(f'Your new password is : {pass_1}')
