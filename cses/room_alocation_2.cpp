#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
using pii = pair<int,int>;

struct Sala{
    int comeco, fim, idx;
};

bool compara_salas(Sala &a, Sala &b){
    return a.comeco < b.comeco;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> ans(n);
    vector<Sala> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].comeco >> v[i].fim;
        v[i].idx = i;
    }

    sort(v.begin(),v.end(),compara_salas);

    int ultima_sala = 0; 
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    for(int i=0;i<n;i++){
        if(pq.empty() || pq.top().first >= v[i].comeco){
            ultima_sala++;
            pq.push({v[i].fim, ultima_sala});
            ans[v[i].idx] = ultima_sala;
        } else {
            pii ultimo = pq.top();
            pq.pop();
            pq.push({v[i].fim, ultimo.second});
            ans[v[i].idx] = ultimo.second;
        }
    }
    cout << ultima_sala << endl;
    for(auto i : ans) cout << i << " ";


    return 0;
}