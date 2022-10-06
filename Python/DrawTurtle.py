import turtle

def draw_shapes():
    window = turtle.Screen()
    window.bgcolor("blue")
    brad = turtle.Turtle()
    brad.shape("turtle")
    brad.color("yellow")
    brad.speed(5)
    n = 0
    while n < 36:
       for i in range(1,5):
           move = brad.forward(100)
           turn = brad.right(90)
       brad.right(10)
       n += 1
    window.exitonclick()

draw_shapes()
