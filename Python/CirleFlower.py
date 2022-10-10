
import turtle
Cppsecrets = turtle.Screen()
Cppsecrets.bgcolor('black')
s = turtle.Turtle()
s.speed('fastest')
s.color('white')
rotate=int(180)
def Circles(t,size):
    for i in range(10):
        t.circle(size)
        size=size-4
def Cppsecrets1(t,size,repeat):
  for i in range (repeat):
    Circles(t,size)
    t.right(360/repeat)
Cppsecrets1(s,200,10)
t1 = turtle.Turtle()
t1.speed(0)
t1.color('yellow')
rotate=int(90)
def Circles(t,size):
    for i in range(4):
        t.circle(size)
        size=size-10
def Cppsecrets1(t,size,repeat):
    for i in range (repeat):
        Circles(t,size)
        t.right(360/repeat)
Cppsecrets1(t1,160,10)
t2= turtle.Turtle()
t2.speed(0)
t2.color('blue')
rotate=int(80)
def Circles(t,size):
    for i in range(4):
        t.circle(size)
        size=size-5
def Cppsecrets1(t,size,repeat):
    for i in range (repeat):
        Circles(t,size)
        t.right(360/repeat)
Cppsecrets1(t2,120,10)
t3 = turtle.Turtle()
t3.speed(0)
t3.color('red')
rotate=int(90)
def Circles(t,size):
    for i in range(4):
        t.circle(size)
        size=size-19
def Cppsecrets1(t,size,repeat):
    for i in range (repeat):
        Circles(t,size)
        t.right(360/repeat)
Cppsecrets1(t3,80,10)
t4= turtle.Turtle()
t4.speed(0)
t4.color('green')

rotate=int(90)
def Circles(t,size):
    for i in range(4):
        t.circle(size)
        size=size-20
def Cppsecrets1(t,size,repeat):
    for i in range (repeat):
        Circles(t,size)
        t.right(360/repeat)
Cppsecrets1(t4,40,10)
