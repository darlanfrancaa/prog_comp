#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Par{
    int valor; char cor;
};

struct Comparator{

    bool operator()(const Par &a, Par &b) {
        return a.valor < b.valor;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, v; cin >> a >> v; 
    priority_queue<Par,vector<Par>, Comparator> pq;
    for(int i=0;i<a;i++){
        int cor; cin >> cor; 
        pq.push({cor, 'a'});
    }
    for(int i=0;i<v;i++){
        int cor; cin >> cor; 
        pq.push({cor, 'v'});
    }
    int cor_comeco = pq.top().cor; pq.pop();
    int contador = 0;

    while(!pq.empty()){
        auto [valor, cor] = pq.top(); pq.pop(); 
        if(cor != cor_comeco) break;
        contador++;
    }
    cout << contador << "\n";
    return 0;
}