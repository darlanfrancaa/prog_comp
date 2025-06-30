#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*link do problema: https://atcoder.jp/contests/abc295/tasks/abc295_d*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string pal; cin >> pal;
    int tamanho = pal.size();
    unordered_map<int,long long> mapa;
    mapa[0]++;
    int atual = 0;
    for(int i=0;i<tamanho;i++){
        int num_atual = pal[i] - '0';
        atual ^= (1 << num_atual);
        mapa[atual]++;
    }
    long long sum = 0;
    for(auto [k,v]: mapa){
        sum += (long long)(v * (v - 1))/ 2;
    }
    cout << sum << endl;

    return 0;
}