#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1159

const int inf = 1e9;

class MaxQueue{
private: 
    // vou colocar {valor, maximo, lazy}
    stack<array<int,3>> s1,s2;
    int tam = 0;
public: 

    void unlazys1(){
        if(s1.empty()) return;
        auto [x,mx,lz] = s1.top();
        s1.pop();
        x += lz; mx += lz; 
        if(!s1.empty()){
            s1.top()[2] += lz;
        }
        s1.push({x,mx,0});
    }
    void unlazys2(){
        if(s2.empty()) return; 
        auto [x,mx,lz] = s2.top();
        s2.pop(); 
        x += lz; mx += lz;
        if(!s2.empty()){
            s2.top()[2] += lz;
        }
        s2.push({x,mx,0});
    }
    void add(int x){
        unlazys1();
        int max_val = x;
        if(!s1.empty()){
            max_val = max(max_val, s1.top()[1]);
        }
        s1.push({x,max_val,0});
        tam++;
    }
    void sum(int x){
        if(s1.empty() && s2.empty()) return;
        if(!s1.empty()) s1.top()[2] += x;
        if(!s2.empty()) s2.top()[2] += x;
    }

    void remove(){
        if(tam == 0) return; 
        unlazys2(); 
        if(s2.empty()){
            while(!s1.empty()){
                unlazys1();
                auto [x,mx,lz] = s1.top(); s1.pop();
                int maximo_s2 = x; 
                if(!s2.empty()){
                    maximo_s2 = max(maximo_s2, s2.top()[1]);
                }
                s2.push({x,maximo_s2, 0});
            }
        }
        unlazys2(); 
        s2.pop();
        tam--;
    }

    int query(){
        if(tam == 0) return -inf;
        unlazys1(); 
        unlazys2();
        if(s1.empty()) return s2.top()[1];
        if(s2.empty()) return s1.top()[1];
        return max(s1.top()[1], s2.top()[1]);
    }

    void clear(){
        stack <array <int, 3>> aux;
        s1 = aux;
        s2 = aux;
        tam=0;
    }

    int size(){
        return tam;
    }
};
MaxQueue q[1010];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> h(n), s(n), k(n); 
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) cin >> k[i];


    vector<int> dp(x+1, -inf);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        int preco = h[i], paginas = s[i], maximo = k[i];
        for(int r = 0; r < preco; r++) q[r].clear();

        for(int j = 0; j <= x; j++){
            int r = j % preco;
            q[r].sum(paginas);
            if(dp[j] != -inf){
                q[r].add(dp[j]);
            } else {
                q[r].add(LLONG_MIN);
            }

            if(q[r].size() > maximo + 1){
                q[r].remove();
            }
            int ans = q[r].query();
            if(ans != -inf) dp[j] = ans;
        }

    }
    int resp = 0;
    for(int i =0;i<=x;i++ ) resp = max(resp, dp[i]);
    cout << resp << '\n';
    return 0;
}