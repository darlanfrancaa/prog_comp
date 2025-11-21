#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int r,c;

int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};

bool dentro(int x, int y){ 
    bool a = (0 <= x && x < r);
    bool b = (0 <= y && y < c);
    return a && b;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c; 
    int x, y; cin >> x >> y; 
    x--;
    y--;
    int sx, sy; cin >> sx >> sy; 
    sx--;
    sy--;
    string tab[51];
    for(int i=0;i<r;i++){
            cin >> tab[i];
    }
    int contador = 0; 
    int dir = 0;
    while((x != sx || y != sy)&& contador < 1e5){
        contador++;
        int esq = (dir+3)%4;

        if(dentro(x+di[esq], y+dj[esq]) && tab[x+di[esq]][y+dj[esq]] == '0'){
            dir = esq;
            x += di[dir];
            y += dj[dir];
        }
        else if(dentro(x+di[dir], y+dj[dir]) && tab[x+di[dir]][y+dj[dir]] == '0'){
            x += di[dir];
            y += dj[dir];
        }
        else{
            dir = (dir + 1) % 3;
        }
    }
    if(contador < 1e5) cout << 1 << endl;
    else cout << "0\n";


    return 0;
}