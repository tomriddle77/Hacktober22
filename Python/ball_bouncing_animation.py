from vpython import *
from time import *

mRadius = .8
rHeight = 7
rWidth = 15
rDepth = 8
rThick = .3

floor = box(pos=vector(0,-rHeight/2,0), color=color.white, size = vector(rWidth, rThick, rDepth))
top = box(pos=vector(0,rHeight/2,0), color=color.white, size = vector(rWidth, rThick, rDepth))
backWall = box(pos=vector(0,0,-rDepth/2), color=color.white, size = vector(rWidth, rHeight, rThick))
# frontWall = box(pos=vector(0,0,5), color=color.white, height=10, width=.2, length=10)
rightWall = box(pos=vector(rWidth/2,0,0), color=color.white, size = vector(rThick, rHeight, rDepth))
leftWall = box(pos=vector(-rWidth/2,0,0), color=color.white, size = vector(rThick, rHeight, rDepth))
marble = sphere(radius = mRadius, color=color.red)

deltaX = .1
deltaY = .1
deltaZ = .1

xPos = 0
yPos = 0
zPos = 0

while True:
    rate(25)
    xPos = xPos + deltaX
    x = rWidth/2 - rThick/2 - mRadius
    y = -rWidth/2 + rThick/2 + mRadius
    if((xPos>x) or xPos < (y)):
        deltaX = deltaX*(-1)
    
    yPos = yPos + deltaY
    x = rHeight/2 - rThick/2 - mRadius
    y = -rHeight/2 + rThick/2 + mRadius
    if((yPos>x) or (yPos < y)):
        deltaY = deltaY*(-1)

    zPos = zPos + deltaZ
    x = rDepth/2 - rThick/2 - mRadius
    y = -rDepth/2 + rThick/2 + mRadius
    if((zPos>x) or (zPos<y)):
        deltaZ = deltaZ * (-1)

    # marble.pos = vector(0, 0, zPos) 
    marble.pos = vector(xPos, yPos, zPos) 
