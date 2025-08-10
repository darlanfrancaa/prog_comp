#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n), b(n); 
        for(auto &num: a) cin >> num;
        for(auto &num: b) cin >> num;
        vector<pii> ans; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(a[j] > a[j+1])  {
                    int tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                    ans.push_back({1,j+1});
                }
                if(b[j] > b[j+1])  {
                    int tmp = b[j];
                    b[j] = b[j+1];
                    b[j+1] = tmp;
                    ans.push_back({2,j+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i] > b[i]){
                int tmp = a[i];
                a[i] = b[i];
                b[i] = tmp;
                ans.push_back({3,i+1});
            }
        }
        cout << ans.size() << endl;
        for(auto par: ans) cout << par.first << " " << par.second << endl;
    }
    return 0;
}