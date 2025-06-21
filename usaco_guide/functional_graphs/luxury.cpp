#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int operacao(vector<int> &left, vector<int> &right, string &pal, int idx){
    int proximo = idx;
    for(int i=0;i<pal.size();i++){
        if(pal[i] == 'L') proximo = left[proximo];
        else proximo = right[proximo];
    }
    return proximo;
}


int main() {
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    vector<int> left(n,0);
    vector<int> right(n,0);
    vector<int> graph(n,0);
    for(int i=0;i<n;i++){
        int l, r; cin >> l >> r;
        l--; r--;
        left[i] = l;
        right[i] = r;
    }
    string pal = "";
    for(int i=0;i<m;i++){
        char op; cin >> op;
        pal += op;
    }
    for(int i=0;i<n;i++){
        int next = operacao(left, right, pal , i);
        graph[i] = next;
    }
    vector<vector<int>> vetor (n,vector<int> (30));
    for(int i=0;i<n;i++){
        vetor[i][0] = graph[i];
    }
    for(int j = 1; j < 30; j++){
        for(int i = 0; i < n; i++){
            vetor[i][j] = vetor[vetor[i][j-1]][j-1];
        }
    }
    int ans = 0;
    for(int b = 0; b < 30 ; b++){
        if( ( k >> b) & 1 ) {
            ans = vetor[ans][b];
        }
    }
    cout << ans + 1;
    return 0;
}