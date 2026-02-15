#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXPROD = 1e15;

// problem link: https://codeforces.com/problemset/problem/1872/G

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        // cout << "entrei numa query nova ----------------\n" ;
        int n; cin >> n; 
        vector<int> v(n+1); 
        int contador = 0;
        vector<int> pos;
        bool passou = false;
        int produto_total = 1;
        int soma_total = 0;
        for(int i=1;i<=n;i++){
            int val; cin >> val;
            v[i] = val; 
            soma_total += v[i];

            if(val > 1) {
                pos.push_back(i);
                if(!passou){
                    if(val > MAXPROD/produto_total) {
                        passou = true;
                    }
                    else produto_total *= val;
                }
            }
        }
        // for(int i=0;i<pos.size();i++){
        //     cout << pos[i] << "  ";
        // }
        if(passou){
            cout << pos.front() << " " << pos.back() << "\n";
        } else {
            vector<int> prod(n+1), sum(n+1);
            prod[0] = 1; 
            sum[0] = 0;
            for(int i=1;i<=n;i++){
                prod[i] = prod[i-1] * v[i];
                sum[i] = sum[i-1] + v[i];
            }
            int maximo = soma_total;
            pii ans = {1,1};
            for(int i=0;i<pos.size();i++){
                for(int j = i; j<pos.size();j++){
                    int l = pos[i], r = pos[j];
                    // printf("testando para l = %lld e r= %lld\n", l, r);
                    int val_prod = prod[r] / prod[l-1];
                    int val_sum = sum[r] - sum[l-1];
                    if(soma_total + val_prod - val_sum > maximo){
                        maximo = soma_total + val_prod - val_sum; 
                        ans = {l, r};
                    }
                }
            }
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return 0;
}