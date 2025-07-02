def solve():
    altura,comprimento = map(int,input().split())
    if altura == 0 and comprimento == 0:
        return False
    blocos = list(map(int,input().split()))
    quantidade = 0
    quantidade += altura - blocos[comprimento-1]
    for i in range(1,comprimento):
        if blocos[i] > blocos[i-1]:
            quantidade += blocos[i] - blocos[i-1]
    print(quantidade)
    return True

if __name__ == "__main__":
    var = True
    while var:
        var = solve()