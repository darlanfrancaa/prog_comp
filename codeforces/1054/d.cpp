#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n; 
    vector<char> s(n+1);
    for(int i=1;i<=n;i++) cin >> s[i];
    vector<int> minimos_1(n+1,LLONG_MAX);
    int pb=1, ub=n;
    while(pb <= n && s[pb] != 'b') pb++;
    while(ub >= 1 && s[ub] != 'b') ub--;
    // cout << "as bordas foram " << pb << " " << ub << "\n";
    int contadorb = 0;
    for(int i=pb; i<= ub; i++){
        if(s[i] == 'b') contadorb++;
        else { 
            minimos_1[i] = min(minimos_1[i], contadorb);
            // cout << "o contador foi " << contadorb << " mas a quantidade no minimo " << i << " foi " << minimos_1[i] << "\n";
        }
    }
    contadorb = 0;
    for(int i=ub; i>=pb; i--){
        if(s[i] == 'b') contadorb++;
        else { 
            minimos_1[i] = min(minimos_1[i], contadorb);
            // cout << "o contador foi " << contadorb << " mas a quantidade no minimo " << i << " foi " << minimos_1[i] << "\n";
        }
    }
    int minimo_1 = 0;
    // cout << "printando para b \n";
    for(int i=pb;i<=ub;i++){
        // cout << minimos_1[i] << " ";
        if(minimos_1[i] != LLONG_MAX){
            // cout << minimos_1[i] << " ";
            minimo_1 += minimos_1[i];
        }
    }


    vector<int> minimos_2(n+1,LLONG_MAX);
    int pa=1, ua=n;
    while(pa <= n && s[pa] != 'a') pa++;
    while(ua >= 1 && s[ua] != 'a') ua--;
    int contadora = 0;
    for(int i=pa; i<= ua; i++){
        if(s[i] == 'a') contadora++;    
        else { 
            minimos_2[i] = min(minimos_2[i], contadora);
        }
    }
    contadora = 0;
    for(int i=ua; i>=pa; i--){
        if(s[i] == 'a') contadora++;
        else { 
            minimos_2[i] = min(minimos_2[i], contadora);
        }
    }
    int minimo_2 = 0;
    for(int i=pa;i<=ua;i++){
        if(minimos_2[i] != LLONG_MAX){
            minimo_2 += minimos_2[i];       
        }
    }
    cout << min(minimo_1, minimo_2) << "\n";

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}