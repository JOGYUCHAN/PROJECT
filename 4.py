import turtle

import random

 

## 전역변수 선언 부분 ##

myTurtle, tX, tY, tColor, tSize, tShape, tSum = [None] * 7 # tSum = X좌표와 Y좌표의 합

playerTurtles = []

swidth, sheight = 500, 500

 

## 메인 함수 부분 ##

if __name__ == "__main__" :

    turtle.title('거북이 리스트 활용(정렬)')

    turtle.setup(width = swidth + 50, height = sheight + 50)

    turtle.screensize(swidth, sheight)

 

    ## 랜덤으로 거북이 객체 10개를 생성 후 playerTurtles에 넣기 ##

    for i in range(0, 5) :

        myTurtle = turtle.Turtle('turtle')

        tX = random.randrange(-swidth / 2, swidth / 2)

        tY = random.randrange(-sheight / 2, sheight / 2)

        r = random.random(); g = random.random(); b = random.random()

        tSize = random.randrange(1, 3)

        tSum = tX + tY

        playerTurtles.append([myTurtle, tX, tY, tSize, r, g, b, tSum])

 

    ## tSum을 key로 오름차순 정렬

    soredTurtles = sorted(playerTurtles, key=lambda turtles : turtles[7] ,reverse = True)

 

    for index, tList in enumerate(soredTurtles[0:]) : # enumerate는 index 값을 같이 반환해 줌 (튜플 형태)

        myTurtle = tList[0]

        myTurtle.color((tList[4], tList[5], tList[6]))

        myTurtle.pencolor((tList[4], tList[5], tList[6]))

        myTurtle.turtlesize(tList[3])

        myTurtle.penup()

        if index == 0 : # 첫 번째 거북이는 해당 위치로 이동

            myTurtle.goto(tList[1], tList[2])

            continue

        myTurtle.goto(soredTurtles[index-1][1], soredTurtles[index-1][2]) # 이전 거북이 위치로 이동

        myTurtle.pendown()

        myTurtle.goto(tList[1], tList[2]) # 거북이의 좌표로 선 긋기

 

turtle.done()