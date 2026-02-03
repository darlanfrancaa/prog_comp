#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1664

const int MAXN = 2e5 + 10; 
const int LOG = 20; 

int dp[MAXN][LOG];

class SegTree {
private: 
    int n; 
    vector<pii> tree; 
public: 
    
    pii join(pii a, pii b){
        int m1 = max(a.first , b.first);
        int m2 = max(a.second, b.second);
        return {m1,m2};
    }

    void build(int node, int l, int r, vector<pii> &v){
        if(l == r){
            tree[node] = v[l];
            return;
        }
        int mid = (l+r)/2; 
        build(2*node, l, mid, v);
        build(2*node+1, mid+1, r, v);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }

    SegTree(int n, vector<pii> &v){
        tree.resize(4*n); 
        build(1,0,n-1,v);
    }

    // eu quero achar o primeiro valor tal que l >= val e r é mínimo, como está ordenado por r, basta achar o menor índice tal que l>=val

    pii search(int node, int l, int r, int val){
        if(tree[node].second < val) return {-1,-1};
        if(l == r) {
            return tree[node];
        }
        int mid = (l+r)/2; 
        if(tree[2*node].second >= val) return search(2*node, l, mid, val);
        else return search(2*node+1, mid+1,r,val);
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<pii> movies(n);
    for(int i=0;i<n;i++){
        cin >> movies[i].second >> movies[i].first; 
    }
    sort(movies.begin(), movies.end());
    // eu quero encontrar o primeiro filme [li,ri] tal que li >= r 
    map<pii,int> mapa; 
    for(int i=0;i<n;i++){
        mapa[movies[i]] = i; // aqui eu estou usando um map apenas para identificar qual par está associado a cada índice
    }

    SegTree seg(n,movies);
    // agora eu quero preencher o vetor de dp
    for(int i=0;i<n;i++){
        pii next = seg.search(1,0,n-1,movies[i].first); // encontro o filme que começa depois do fim de i
        if(next.first != -1) dp[i][0] = mapa[next]; // e faço a dp receber o índice desse filme
        else dp[i][0] = n;
    }

    dp[n][0] = n;

    for(int j=1;j<LOG;j++){
        for(int i=0;i<=n;i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    while(q--){
        int a, b; cin >> a >> b; 
        pii next = seg.search(1,0,n-1, a); // então eu encontrei o primeiro filme agora basta eu seguir a lista desse filme usando o binary lifting
        if(next.first == -1 || next.first > b){
            cout << 0 << "\n"; 
            continue;
        }
        int ans = 1;
        int idx = mapa[next];
        for(int j = LOG-1; j>=0;j--){
            int filme = dp[idx][j]; 
            auto [fim, comeco] = movies[filme];
            if(filme != n && fim <= b){
                ans += (1 << j);
                idx = filme;
            }
        }
        cout << ans << "\n";

    }

    return 0;
}