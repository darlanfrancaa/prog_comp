#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n+1),b(n+1),c(n+1);
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]] = i; // esse vetor vai armazenar a posição de cada valor a[i]
    }
    for(int i=1;i<=n;i++) cin >> b[i]; 
    for(int i=1;i<=n;i++) c[i] = pos[b[i]]; // ja esse vetor vai armazenar a posicao no vetor b, que o valor a[i] está
    vector<int> lis;
    for(int i=1;i<=n;i++){
        int valor = lower_bound(lis.begin(), lis.end(), c[i]) - lis.begin();
        if (valor == lis.size()) lis.push_back(c[i]);
        else lis[valor] = c[i];
    }
    cout << lis.size() << endl; 
    return 0;
}