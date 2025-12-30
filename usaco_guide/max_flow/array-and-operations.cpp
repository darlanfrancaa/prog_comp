#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 3010;

// problem link: https://codeforces.com/contest/498/problem/c

struct No{
    int prime; 
    int original_idx;
};

vector<int> adj[MAXN];
vector<int> match;
vector<bool> used;

bool try_kuhn(int v){
    if(used[v]) return false;
    used[v] = true;
    for(int to: adj[v]){
        if(match[to] == -1 || try_kuhn(match[to])){
            match[to] = v;
            return true;
        }
    }
    return false;
}

void fact(int val, int idx, vector<No>& side){
    for(int i=2;i*i <= val;i++){
        while(val % i == 0){
            side.push_back({i, idx});
            val /= i;
        }
    }
    if(val > 1) side.push_back({val,idx});
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    cin >> n >> m; 
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<No> left, right;

    for(int i=0;i<n;i++){
        if(i % 2 != 0) fact(a[i], i , left); // eu coloco todos os ímpares no lado esquerdo pois não vão ter dois conectados jamais
        else fact(a[i], i, right);
    }

    // for(int i=0;i<left.size();i++){
    //     printf("o primo é %lld, e o idx é %lld\n", left[i].prime, left[i].original_idx);
    // }

    for(int k=0;k<m;k++){
        int u,v; cin >> u >> v; 
        u--; v--;
        if(u % 2 == 0) swap(u,v); // pra garantir que o primeiro é ímpar
        
        for(int i =0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if(left[i].original_idx == u && right[j].original_idx == v && left[i].prime == right[j].prime) adj[i].push_back(j);
            }
        }
    }

    int ans = 0; 
    match.assign(right.size(), -1);
    for(int i=0;i<left.size();i++){
        used.assign(left.size(),false); // quais caras do lado direito já apareceram no caminho aumentante
        if(try_kuhn(i)) ans++;
    }

    cout << ans << "\n";
    return 0;
}