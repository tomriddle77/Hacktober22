yr = int(input("Please Enter the year to check leap or not: "))

if (( yr%400 == 0)or (( yr%4 == 0 ) and ( yr%100 != 0))):
    print("%d is a Leap year" %yr)
else:
    print("%d is Not Leap year" %yr)
