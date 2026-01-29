#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

class MinQueue { 
private: 
    stack<pii> s1,s2; // de modo que s1 é a pilha de entrada e s2 é a pilha de saida
public: 
    void push_min(int a){
        if(s1.empty()) {
            s1.push({a,a});
            return;
        }
        else {
            auto [val,minimo] = s1.top(); 
            int curr_min = min(minimo, a);
            s1.push({a,curr_min});
        }
    }

    void pop_min(){
        if(!s2.empty()){
            s2.pop();
            return;
        } // então eu tenho que passar todo mundo de s1 pra s2 em ordem
        while(!s1.empty()){
            auto par = s1.top(); s1.pop(); 
            int minimo_s2 = par.first;
            if(!s2.empty()){
                minimo_s2 = min(minimo_s2, s2.top().second);
            }
            s2.push({par.first, minimo_s2});

        }

        if(!s2.empty()) s2.pop();
    }

    int get_min(){
        if(s1.empty() && s2.empty()) return LLONG_MAX;
        if(s1.empty()) return s2.top().second;
        if(s2.empty()) return s1.top().second;
        return min(s1.top().second, s2.top().second);
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
    // for(auto c: v){
    //     cout << c << " ";
    // } 
    int i = 0; 
    MinQueue q; 
    int ans = 0;
    while(i < k){
        q.push_min(v[i]);
        i++;
        // cout << v[i] << ' ';
    }
    ans ^= (q.get_min());
    // cout << "o valor de ans é " << ans << '\n';
    while(i < n){
        q.push_min(v[i++]);
        q.pop_min();
        ans ^= (q.get_min()); 
    }
    cout << ans << '\n';
    return 0;
}