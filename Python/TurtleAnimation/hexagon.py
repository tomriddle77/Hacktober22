import turtle
import colorsys
t = turtle.Turtle() 
s = turtle.Screen().bgcolor('black')
t.color('white')
t.speed(0)
t.width(5) 
n = 200 
h = 0 
for  i in range(300):
    t.right(59)
    for c in range(1):
        t.forward(i*2)
        c= colorsys.hsv_to_rgb(h,1,0.8)
        h += i/n
        t.color(c) 
turtle.exitonclick()
