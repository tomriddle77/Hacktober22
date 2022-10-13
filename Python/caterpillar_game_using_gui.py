import turtle as t
import time as ti
import random  as rd


t.bgcolor('yellow')

caterpillar = t.Turtle()
caterpillar.shape('square')
caterpillar.speed(0)
caterpillar.penup()
caterpillar.hideturtle()


leaf = t.Turtle()
leaf_shape=((0,0),(15,2),(18,6),(20,20),(6,18),(2,15))
t.register_shape('leaf',leaf_shape)
leaf.shape('leaf')
leaf.color('green')
leaf.penup()
leaf.hideturtle()
leaf.speed()


game_started=False
text_turtle = t.Turtle()
text_turtle.write("Press space to start the game",align='center',font=('Arial',18,'bold'))
text_turtle.hideturtle()

score_turtle = t.Turtle()
score_turtle.hideturtle()
score_turtle.speed(0)

def outside_window():
    left_limit=  -t.window_width()/2
    right_limit= t.window_width()/2
    top_limit = t.window_height()/2
    bottom_limit = -t.window_height()/2

    (x,y)=caterpillar.pos()

    outside= x<left_limit or x>right_limit or y<bottom_limit or y>top_limit

    return outside

def place_leaf():
    leaf.hideturtle()
    leaf.setx(rd.randint(-200,200))
    leaf.sety(rd.randint(-200,200))
    leaf.showturtle()

def game_over():
    caterpillar.color('yellow')
    leaf.color('yellow')
    t.penup()
    t.hideturtle()
    t.write("GAME OVER !",align='center',font=('Arial',30, 'bold italic'))


def display_score(curr_score):
    score_turtle.clear()
    score_turtle.penup()
    x=(t.window_width()/2)-50
    y=(t.window_height()/2)-50
    score_turtle.setpos(x,y)
    score_turtle.write(str(curr_score),align='right',font=('Arial',30,'bold'))


def start_game():
    global game_started
    if game_started:
        return
    game_started=True
    caterpillar.showturtle()
    score=0
    text_turtle.clear()
    caterpillar_speed=2
    caterpillar_length=3
    caterpillar.shapesize(1,caterpillar_length,1)
    display_score(score)
    place_leaf()

    while True :
        caterpillar.forward(caterpillar_speed)
        if caterpillar.distance(leaf)<30:
            place_leaf()
            caterpillar_length=caterpillar_length+1
            caterpillar.shapesize(1,caterpillar_length,1)
            caterpillar_speed=caterpillar_speed+1
            score=score+10
            display_score(score)
        if outside_window():
            game_over()
            break

def move_up():
    if caterpillar.heading()==0 or caterpillar.heading()==180:
        caterpillar.setheading(90)

def move_down():
    if caterpillar.heading()==0 or caterpillar.heading()==180:
        caterpillar.setheading(270)

def move_left():
    if caterpillar.heading()==90 or caterpillar.heading()==270:
        caterpillar.setheading(180)

def move_right():
    if caterpillar.heading()==90 or caterpillar.heading()==270:
        caterpillar.setheading(0)


t.onkey(start_game,'space')
t.onkey(move_up,'Up')
t.onkey(move_down,'Down')
t.onkey(move_left,'Left')
t.onkey(move_right,'Right')
t.listen()
t.mainloop()
ti.sleep(5)
