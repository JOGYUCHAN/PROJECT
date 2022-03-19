import random as r

d1, d2, d3, d4, d5, d6 = [0]*6
throwCount, serialCount = 0,0

if __name__=="__main__" : 
    while True :
        throwCount += 1

        d1 = r.randrange(1, 7)
        d2 = r.randrange(1, 7)
        d3 = r.randrange(1, 7)
        d4 = r.randrange(1, 7)
        d5 = r.randrange(1, 7)
        d6 = r.randrange(1, 7)

        if d1 == d2 == d3 == d4 == d5 ==d6 :
            print('6개의 주사위가 모두 동일한 숫자가 나옴 -->', d1, d2, d3, d4,d5, d6)
            break
        elif (d1 == 1 or d2 == 1 or d3 == 1 or d4 == 1 or d5 == 1 or d6 == 1) and \
             (d1 == 1 or d2 == 1 or d3 == 1 or d4 == 1 or d5 == 1 or d6 == 1) and \
             (d1 == 1 or d2 == 1 or d3 == 1 or d4 == 1 or d5 == 1 or d6 == 1) and \
             (d1 == 1 or d2 == 1 or d3 == 1 or d4 == 1 or d5 == 1 or d6 == 1) and \
             (d1 == 1 or d2 == 1 or d3 == 1 or d4 == 1 or d5 == 1 or d6 == 1) and \
             (d1 == 1 or d2 == 1 or d3 == 1 or d4 == 1 or d5 == 1 or d6 == 1) :
             serialCount += 1

print('6개가 동일한 숫자가 나올 때 까지 주사위를 던진 횟수 -->', throwCount)
print('6개가 동일한 숫자가 나올 때 까지, 1~6dml 연속번호가 나온 횟수 -->', serialCount)

            

