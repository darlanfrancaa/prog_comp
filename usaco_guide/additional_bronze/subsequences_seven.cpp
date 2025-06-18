#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_map <int,vector<int>> mapa;
    int n; cin >> n; 
    vector<int> vetor(n+1);
    ll acc = 0;
    mapa[0].push_back(0);

    for(int i=1;i<=n;i++) {
        cin >> vetor[i];
        acc += vetor[i];
        mapa[(acc%7)].push_back(i);
    }
    int maximo = 0;
    for(int i=0;i<7;i++){
        if(mapa[i].size()<=1) continue;
        maximo = max(maximo,(mapa[i].back() - mapa[i].front()));
    }
    cout << maximo;
    return 0;
}