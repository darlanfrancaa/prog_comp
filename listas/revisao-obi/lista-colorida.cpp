#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link: https://neps.academy/br/exercise/49

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> v(n), zeros;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] == 0) zeros.push_back(i);
    }
    vector<int> ans1(n,LLONG_MAX), ans2(n,LLONG_MAX);
    int contador = 0;
    for (int i = zeros[0];i<n;i++){
        if(v[i] == 0){
            ans1[i] = 0;
            contador = 0;
            continue;
        }
        contador++;
        ans1[i] = contador;
    }
    
    for (int i = zeros.back();i>=0;i--){
        if(v[i] == 0){
            ans2[i] = 0;
            contador = 0;
            continue;
        }
        contador++;
        ans2[i] = contador;
    }
    for(int i=0;i<n;i++){
        int num =  min(ans1[i], ans2[i]);
        cout << min(num, 9LL) << " ";
    }
    return 0;
}