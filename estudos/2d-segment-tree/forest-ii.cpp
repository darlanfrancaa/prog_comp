#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int bit[MAXN][MAXN];
int n;

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            bit[i][j] += val;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            sum += bit[i][j];
        }
    }
    return sum;
}

int query(int r1, int c1, int r2, int c2) {
    return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; 
    cin >> n >> q; 
    
    vector<vector<int>> tab(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        string s; cin >> s; 
        for(int j = 1; j <= n; j++){
            if(s[j-1] == '*') {
                tab[i][j] = 1;
                update(i, j, 1);
            }
        }
    }
    
    while(q--){
        int op; cin >> op; 
        if(op == 1){
            int x, y; cin >> x >> y; 
            if(tab[x][y] == 1) {
                update(x, y, -1); 
                tab[x][y] = 0;
            } else {
                update(x, y, 1);  
                tab[x][y] = 1;
            }
        } else {
            int y1, x1, y2, x2; 
            cin >> y1 >> x1 >> y2 >> x2; 
            cout << query(y1, x1, y2, x2) << "\n";
        }
    }
    return 0;
}