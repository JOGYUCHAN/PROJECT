i, k, heartnum = 0, 0, 0
numStr, ch, heartStr = "", "", ""

if __name__  == "__main__" : 
    numStr = input("숫자를 입력하세요 : ")
    print("")
    i = 0
    ch = numStr[i]
    while True : 
        heartnum = int(ch)

        heartStr = ""
        for k in range(0, heartnum) : 
            heartStr += "\u2665"
            k += 1

        print(heartStr)

        i += 1
        if(i > len(numStr) - 1) : 
            break

        ch = numStr[i]