#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// a ideia é usar a ideia de prefix_sum para intervalos pq queremos colocar quanto cada i está em algum
// intervalo, e fazer isso diretamente ficaria o(n(b-a)) = o(10^14) que nao funciona, entao precisamos 
// utilizar a ideia de mudar em cada intervalor somando t no comeco e -t no final e depois calculando a soma
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> times;
    for(int i=0; i<n;i++){
        int x, y; cin >> x >> y; 
        times.push_back({x,1});
        times.push_back({y,-1});
    }

    sort(times.begin(), times.end());
    int atual = 0, maximo = 0; 
    for(auto &t : times){
        atual += t.second;
        maximo = max(maximo, atual);
    }
    cout << maximo << endl;

    return 0;
}