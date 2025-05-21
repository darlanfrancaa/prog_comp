#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
using pii = pair<int,int>;

/*
a ideia é primeiro ordenar e depois ir passando por todos os i = 1 a 10^9 do seguinte modo:
primeiro, colocaremos todo mundo da sequencia tal que Li == i dentro da nossa pq
depois tiraremos o cara com o menor R até agora
e depois incrementamos o nosso i
veja que isso funciona pois a cada momento, tiramos da pq o cara mais urgente a ser tirado e nao faz sentido tirar outro alem dele 
alem disso, se colocamos ele na lista, quer dizer que i>= l_j ou seja, ele ja pode ser retirado
o unico momento em que essa ideia poderia dar errado eh quando o menor elemento de pq, ou seja o menor r_j, for menor que i,entao nao seria 
mais possivel colocar essa bola em lugar algum
*/ 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t>0){
        t--;
        int n; cin >> n;
        vector<pii> balls(n);
        for(int i=0;i<n;i++){
            cin >> balls[i].first >> balls[i].second;
        }
        sort(balls.begin(), balls.end());
        priority_queue<int,vector<int>, greater<int>> pq;
        int i = 1; 
        int idx = 0;
        bool certo = true;

        while(idx < n || !pq.empty()){
            if(pq.empty() &&  idx < n && balls[idx].first>i){
                i = balls[idx].first;
            }       
            while(idx < n &&  balls[idx].first == i){
                pq.push(balls[idx++].second);
            } 
            if (pq.empty()) {
                ++i;
                continue;
            }
            int r = pq.top(); pq.pop();
            if(r<i){
                cout << "no" << endl;
                certo = false;
            }
            ++i;
        }
        if(certo) cout << "yes" << endl;
        

    }
    return 0;
}