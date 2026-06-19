#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(6);
    int soma = 0;
    for(auto &n: v) {
        cin >> n; 
        soma += n;
    }
    if(soma % 3 != 0){
        cout << "N"; 
        return 0;
    }
    soma = soma/3;
    bool flag = false;
    for(int i=0;i<6;i++){
        if(v[i] == soma){
            flag = true;
            v[i] = LLONG_MAX;
        } 
    }
    if(!flag){
        cout << "N";
        return 0;
    } 
    vector<int> dois = {0,0,0,0,1,1};
    flag = false;
    do{
        int s = 0;
        for(int i=0;i<6;i++){
            s += dois[i]*v[i];
        }   
        if(s == soma){
            flag = true;
            break;
        }
    }while(next_permutation(dois.begin(), dois.end()));
    
    if(flag) cout << "S\n";
    else {
        cout << "N\n"; 
        return 0;
    }
    return 0;
}