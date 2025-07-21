#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<int> dp;

void fill_dp(const vector<int> &moedas, int x){
    dp.assign(x+1,0);
    dp[0] = 1;
    for(auto &moeda: moedas){
        for(int i=1;i<=x;i++){
            if(i >= moeda){
                dp[i] = (dp[i] + dp[i-moeda]) % MOD; //em cada ponto de cada moeda vai armazenar de quantos modos podem ser feitos 
                //utilizando apenas moedas que aparecem antes da moeda atual que estamos considerando
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x; cin >> n >> x; 
    vector<int> moedas(n);
    for(auto &moeda: moedas) cin >> moeda; 
    fill_dp(moedas,x);
    cout << dp[x] << endl;
    return 0;
}