#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/3405

class OrQueue{
private: 
    stack<pair<int,int>> s1,s2;

    void or_push(int x){
        int curr_or = x; 
        if(!s1.empty()){ 
            curr_or |= s1.top().second;
        }
        s1.push({x,curr_or});
    }


    pii or_pop(){
        if(!s2.empty()){
            auto ret = s2.top(); s2.pop();
            return ret;
        }

        while(!s1.empty()){
            auto par = s1.top(); s1.pop();
            int curr_or = par.first; 
            if(!s2.empty()){
                curr_or |= s2.top().second;
            }
            s2.push({par.first, curr_or});
        }
        if(!s2.empty()) {
            auto ret = s2.top(); s2.pop();
            return ret;
        }
        return {0,0};
    }

    int or_query(){
        if(s1.empty() && s2.empty()) return 0; 
        if(s1.empty()) return s2.top().second; 
        if(s2.empty()) return s1.top().second; 
        return s1.top().second | s2.top().second;
    }
public: 
    void push(int x){
        or_push(x);
    }
    
    pii pop(){
        return or_pop();
    }

    int query(){
        return or_query();
    }

    bool empty(){
        if(s2.empty() && s1.empty()) return true; 
        return false;
    }
};

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    int x,a,b,c; cin >> x >> a >> b >> c; 
    int curr = x; 
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] = curr; 
        curr = (a * curr + b) % c;
    }
    int i=0; 
    OrQueue q; 
    while(i < k) {
        // cout << v[i]  << " ";
        q.push(v[i++]); 
    }
    // cout << "\n";
    int ans = 0; 
    ans = q.query();

    // cout << ans << '\n';
    // while(!q.empty()){
    //     auto [val,curr_xor] = q.pop(); 
    //     printf("o valor daqui é val = %lld, e o xor acumulado é %lld\n", val, curr_xor);
    // }
    while(i < n){
        q.push(v[i++]); 
        q.pop();
        ans ^= q.query(); 
        // cout << q.query() << "\n";
    }
    cout << ans << "\n";
    return 0;
}