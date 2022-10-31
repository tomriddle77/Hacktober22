# Python3 program for the above approach

# Function to check if the triangle
# is equilateral or isosceles or scalene
def checkTriangle(x, y, z):

	# _Check for equilateral triangle
	if x == y == z:
		print("Equilateral Triangle")

	# Check for isosceles triangle
	elif x == y or y == z or z == x:
		print("Isosceles Triangle")

	# Otherwise scalene triangle
	else:
		print("Scalene Triangle")


# Driver Code

# Given sides of triangle
x = 8
y = 7
z = 9

# Function Call
checkTriangle(x, y, z)
