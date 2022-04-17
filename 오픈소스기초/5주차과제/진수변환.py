def base2(a):
    result =[]
    while a>0:
        b,c=divmod(a,2)
        a=b
        result.append(str(c))
    result.reverse()
    print(' '.join(result))

def base8(a):
    result =[]
    while a>0:
        b,c=divmod(a,8)
        a=b
        result.append(str(c))
    result.reverse()
    print(' '.join(result))


def base16(a):
    result =[]
    while a>0:
        b,c=divmod(a,16)
        a=b
        result.append(format(c,'x'))
    result.reverse()
    print(' '.join(result)) 

a = int(input("10진수 입력 :"))
print('2진수:')
base2(a)
print('8진수:')
base8(a)
print('16진수')
base16(a)