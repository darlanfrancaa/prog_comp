#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// link : https://codeforces.com/contest/888/problem/E

int n,m;

void sum(vector<int> &arr, set<int>& s){
    int k = arr.size(); 
    for(int mask = 0; mask < (1 << k); mask++){
        int sum = 0; 
        for(int i = 0; i< k;i++){
            if(mask & (1 << i)) sum = (sum + arr[i]) % m; 
        }
        s.insert(sum);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> v_inicial(n); 
    for(auto &v: v_inicial) cin >> v; 
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        if(i<n/2) v1.push_back(v_inicial[i]);
        else v2.push_back(v_inicial[i]);
    }
    set<int> s1, s2; 
    sum(v1,s1); 
    sum(v2,s2);
    
    int ans = 0;
    for(auto it = s1.begin(); it!= s1.end(); it++){
        
        int val = *it; 
        auto it1 = s2.lower_bound(m - val);
        if(it1 != s2.begin()) { 
            auto prev_it = prev(it1);
            ans = max(ans, (val + *prev_it) % m);
        }
        int maior = *s2.rbegin(); 
        ans = max(ans, (val + maior) % m);
    }

    cout << ans << "\n";
    return 0;
}