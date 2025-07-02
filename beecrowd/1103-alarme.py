atual = True

while atual: 
    h1,m1,h2,m2 = map(int,input().split())
    if h1 == 0 and h2 == 0 and m1 == 0 and m2 == 0:
        atual = False
    else: 
        min1 = 60*h1 + m1
        min2 = 60*h2 + m2
        if min1 < min2:
            print(min2-min1)
        elif min1 > min2:
            dif = 60 * 24 - min1
            print(min2 + dif)