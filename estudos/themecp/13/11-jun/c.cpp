#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1793/C

struct SparseTableMin {
    int n; 
    vector<int> lg; 
    vector<vector<int>> st;
    SparseTableMin(const vector<int> &v){
        n = v.size(); 
        lg.resize(n+1);
        lg[1] = 0; 
        for(int i=2;i<=n;i++){
            lg[i] = lg[i/2] + 1;
        }
        int K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        for(int i=0;i<n;i++){
            st[0][i] = v[i];
        }

        for(int k=1;k < K; k++){
            for(int i=0;i + (1 << k) <= n;i++){
                st[k][i] = min(
                    st[k-1][i], 
                    st[k-1][i + (1 << (k-1))]                
                );
            }
        }
    }

    int query(int l, int r){
        int k = lg[r-l+1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

struct SparseTableMax {
    int n; 
    vector<int> lg; 
    vector<vector<int>> st;
    SparseTableMax(const vector<int> &v){
        n = v.size(); 
        lg.resize(n+1);
        lg[1] = 0; 
        for(int i=2;i<=n;i++){
            lg[i] = lg[i/2] + 1;
        }
        int K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        for(int i=0;i<n;i++){
            st[0][i] = v[i];
        }

        for(int k=1;k < K; k++){
            for(int i=0; i+(1 << k) <= n;i++){
                st[k][i] = max(
                    st[k-1][i], 
                    st[k-1][i + (1 << (k-1))]                
                );
            }
        }
    }

    int query(int l, int r){
        int k = lg[r-l+1];
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve(){
    int n; cin >> n; 
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    SparseTableMin stmin(v);
    SparseTableMax stmax(v);
    int l = 0, r = n-1;
    while(l < r){
        if(stmin.query(l, r) == v[l] || stmax.query(l,r) == v[l]) l++;
        else if(stmin.query(l,r) == v[r] || stmax.query(l,r) == v[r]) r--;
        else { 
            cout << l+1 << " " << r+1 << "\n"; 
            return;
        }
    }
    cout << "-1\n";
    return;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();   
    }
    return 0;
}