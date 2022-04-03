instr, outstr = "", ""
ch = ""
count, i =0, 0

instr = input("문자열을 입력하세요 : ")
count = len(instr)

for i in range(0, count) :
    ch = instr[i]
    if(ord(ch)) >= ord("A") and ord(ch) <= ord("Z") :
        newCh = ch.lower()
    elif(ord(ch)) >= ord("a") and ord(ch) <= ord("z") :
        newCh = ch.upper()
    else :
        newCh = ch

    outstr += newCh
    
print("대소문자 변환결과 -> %s"%outstr)
    
