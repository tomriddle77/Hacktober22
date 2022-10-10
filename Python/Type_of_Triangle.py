# Given length of all sides of a triangle determine the type of triangle - 
# equilateral, isosceles or scalene, using if-else condition.

# Input the length of 3 sides a, b, c of the triangle

a = int(input("Enter the first side of triangle a: "))
b = int(input("Enter the second side of triangle b: "))
c = int(input("Enter the third side of triangle c: "))

# Equilateral Triangle: all sides a, b, c are equal i.e. a=b=c
if a==b==c:
    print("It is an Equilateral Triangle")

# Isosceles Triangle: any two sides are equal a=b or b=c or c=a
elif a==b or b==c or c==a:
    print("It is an Isosceles Triangle")
    
# Scalene Triangle: if none of the sides are equal a!=b!=c
else:
    print("It is a Scalene Triangle")
