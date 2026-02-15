#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2032/D

void solve(){
    int n; cin >> n; 
    // os valores são preenchidos por nível, então eu poderia salvar para cada nível quem a gnt colocou no nivel atual; 
    vector<int> folhas;
    vector<int> ans(n+1);
    folhas.push_back(1);
    ans[1] = 0;
    int curr_val = 2; 
    while(curr_val < n){
        cout << "? " << curr_val << ' ' << 1 << endl; 
        cout.flush();
        int op; cin >> op; 
        if(op == 1){
            ans[curr_val] = 0;
            folhas.push_back(curr_val);
            curr_val++; // eu to checando quais caras estão ligados no 0 e colocando eles no primeiro nivel
        }
        else break;
    }
    if(curr_val < n){
        ans[curr_val] = 1;
        folhas.push_back(curr_val); 
        
        curr_val++;
    }
    int idx_nivel = 1; 
    while(curr_val < n){
        if(idx_nivel >= folhas.size()) idx_nivel = 0;
        cout << "? " << folhas[idx_nivel] << " " << curr_val << " ";
        cout.flush(); 
        int op; cin >> op; 
        if(op == 1){
            // então trocou de pai
            idx_nivel++;
        } else { 
            // então o pai realmente é o idx_nivel
            // printf("Então isso quer dizer que estamos num caso de parentesco e, portanto, estamos colocando %lld no nivel atual, filho do %lld\n", curr_val, nivel_antigo[idx_nivel]);
            ans[curr_val] = folhas[idx_nivel];
            folhas.push_back(curr_val);
            curr_val++; 
            idx_nivel++;
        }

    }

    cout << "! ";
    cout.flush();
    for(int i=1;i<=n-1;i++){
        cout << ans[i] << " ";
        cout.flush();
    }
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}