#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Node{
    string palavra; int idx;
};

//link : https://neps.academy/br/exercise/606

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    map<string,vector<string>> adj;
    set<string> pals;
    for(int i=0;i<n;i++){
        string a,b; cin >> a >> b; 
        pals.insert(a); 
        pals.insert(b); 
        adj[a].push_back(b);
    }
    vector<string> palavras;
    for(auto value: pals){
        palavras.push_back(value);
    }
    sort(palavras.begin(), palavras.end());
    for(int i=0;i<palavras.size()-1;i++){
        string atual = palavras[i];
        string proximo = palavras[i+1];
        adj[atual].push_back(proximo);
        adj[proximo].push_back(atual);
    }
    string comeco, fim; 
    cin >> comeco >> fim;
    map<string, int> dist;
    dist[comeco] = 0;
    queue<string> q; 
    q.push(comeco);
    while(!q.empty()){
        string curr = q.front(); q.pop(); 
        for(auto s: adj[curr]){
            if(!dist.count(s)){
                dist[s] = dist[curr] + 1;
                q.push(s);
            }
        }
    } 
    cout << dist[fim] << "\n";
    return 0;
}