#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int read_op() {
    int op;
    cin >> op;
    if (op == -1) {
        exit(0); 
    }
    return op; 
}

void solve(){
    int n; 
    cin >> n;
    
    vector<int> candidatos;
    for(int i = 1; i <= n; i++) candidatos.push_back(i);

    while(candidatos.size() > 1){
        int u = candidatos.back(); candidatos.pop_back();
        int v = candidatos.back(); candidatos.pop_back();

        cout << "? " << u << " " << v << endl; 
        
        int op = read_op(); 
        
        if(op == 1) {
            candidatos.push_back(v);
        } else {
            candidatos.push_back(u);
        }
    }

    if (candidatos.empty()) {
        cout << "! -1" << endl;
        return;
    }

    int final = candidatos[0];
    for(int i = 1; i <= n; i++){
        if(i == final) continue;
        
        cout << "? " << final << " " << i << endl; 
        int op = read_op(); 
        if(op == 1){ 
            cout << "! -1" << endl;
            return; 
        }
        
        cout << "? " << i << " " << final << endl; 
        int op2 = read_op(); 
        if(op2 == 0){ 
            cout << "! -1" << endl;
            return; 
        }
    }
    
    cout << "! " << final << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    if(cin >> t) {
        while(t--){
            solve();
        }
    }
    return 0;
}