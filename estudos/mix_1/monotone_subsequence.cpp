#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2152/E

void solve(){
    int n; cin >> n;
    int tam = n * n + 1;
    vector<vector<int>> check(tam+1);
    vector<bool> used(tam+1, false);
    int contador = tam;
    for(int i=0;i<n;i++){
        cout << "? " << contador << " "; 
        cout.flush();
        for(int j=1;j<=tam;j++){
            if(!used[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
        int val; cin >> val; 
        for(int j = 0; j < val; j++){
            int idx; cin >> idx;
            used[idx] = true;
            check[i].push_back(idx);
        }
        contador-= val;
        if(val >= n+1){
            cout << "! ";
            for(int j=0;j<n+1;j++){
                cout << check[i][j] << " ";
            }
            cout << endl;
            return;
        }
    }
    // em check[i] tem a i-1 - esima operação
    int primeiro = 0;
    for(int i=1;i<=tam;i++){
        if(!used[i]) {
            primeiro = i;
            break;
        }
    }
    vector<int> ans;
    ans.push_back(primeiro);
    for(int i=n-1;i>=0;i--){
        auto it = lower_bound(check[i].begin(), check[i].end(), primeiro);
        it--;
        primeiro = *it;
        ans.push_back(primeiro);
    }
    cout << "! ";
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}