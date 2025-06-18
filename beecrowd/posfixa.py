from collections import deque

def precedence(op):
    if op in ('+', '-'):
        return 1
    elif op in ('*', '/'):
        return 2
    elif op == '^':
        return 3
    return 0

t = int(input())
while t > 0:
    t -= 1
    
    pilha = deque()
    leitura = input()
    resposta = ''

    for letra in leitura:
        if (letra.isalpha() or letra.isdigit()):
            resposta += letra
        elif letra == '(':
            pilha.append(letra)
        elif letra == ')':
            while pilha and pilha[-1] != '(':
                resposta += pilha.pop()
            if pilha and pilha[-1] == '(':
                pilha.pop()
        else:
            while (pilha and 
                   pilha[-1] != '(' and 
                   (precedence(pilha[-1]) > precedence(letra) or 
                    (precedence(pilha[-1]) == precedence(letra) and letra != '^'))):
                resposta += pilha.pop()
            pilha.append(letra)
            
    while pilha:
        resposta += pilha.pop()
        
    print(resposta)