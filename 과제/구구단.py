import turtle as t

i, k, tX, tY = [0] * 4
swidth, sheight = 800, 450

if __name__ == "__main__" :
    t.title("거북이 구구단")
    t.shape('turtle')
    t.setup(width = swidth + 510, height = sheight + 50)
    t.screensize(swidth, sheight)
    t.penup()
    tX, tY = -500, 250
    t.goto(tX, tY)

    for i in range(1, 10) :
        for k in range(2, 10) : 
            t.goto(tX + 80 * k, tY - 40 * i)
            gugu = str(k) + 'x' + str(i) + ' = ' +str(k * i)
            t.write(gugu, font = ('Arial', 12, 'bold'))

    t.done()