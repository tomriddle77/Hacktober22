def palindrome():
    # input string
    str = input("\nEnter the string: ")
    str = str.lower()
    str1 = ''
    # iterate upto string length
    for i in range(len(str)):
        str1 = str[i] + str1
    
    if str1 == str:
        print("\n{} is palindrome!".format(str))
    else:
        print("\n{} is not palindrome!".format(str))

palindrome()        