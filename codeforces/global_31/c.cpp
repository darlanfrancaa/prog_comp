#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k; 
    vector<int> ans(k);
    int log = __lg(n);
    vector<bool> apertado(k, true);
    int count_a = k, count_s = 0;
    for(int i=log;i>=0;i--){
        if(!(n & (1<<i))){
            if(count_s % 2 == 0){
                for(int j=0;j<k;j++){
                    if(apertado[j]) continue; // se ele tá apertado, é 0 mesmo
                    ans[j] |= (1<<i); // eu coloco o bit em todo mundo que é solto
                }
            } else {
                bool primeiro = true;
                for(int j=0;j<k;j++){
                    if(apertado[j]) continue;
                    if(primeiro){
                        primeiro = false; // eu coloco o bit em todo mundo que é solto tirando no primeiro
                        continue;
                    } 
                    ans[j] |= (1 << i);
                }
            }
        }
        else {
            if(count_s % 2 != count_a % 2){
                for(int j=0;j<k;j++){
                    ans[j] |= (1<<i);// só coloco o bit 1 em todo mundo
                }
            } else {
                // aqui eu gostaria de soltar o primeiro apertado e colocar 1 no resto
                if(count_a >= 1){
                    bool primeiro_apert = true;
                    for(int j=0;j<k;j++){
                        if(apertado[j] && primeiro_apert) {
                            primeiro_apert = false; 
                            apertado[j] = false;
                            count_a--;
                            count_s++;
                        } else {
                            ans[j] |= (1<<i);
                        }
                    }
                } else{
                    bool primeiro = true;
                    for(int j=0;j<k;j++){
                        if(primeiro){
                            primeiro = false; // eu coloco o bit em todo mundo que é solto tirando no primeiro
                            continue;
                        } 
                        ans[j] |= (1 << i);
                    }
                }
                
            }
        }
    }
    for(int i=0;i<k;i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}