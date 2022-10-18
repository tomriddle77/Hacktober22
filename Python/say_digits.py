# Say Digits
def sayDigits(n,arr):
    if n==0:
        return 
    
    sayDigits(n//10,arr)
    print(arr[n%10],end=' ')




if __name__ == "__main__":
    map=['Zero','One','Two','Three','Four','Five','Six','Seven','Eight','Nine']
    
    num = int(input("Enter the number to be said!\n"))
    sayDigits(num,map)