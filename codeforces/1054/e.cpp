#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Seg{
    vector<int> tree; 

    Seg(int n){
        tree.resize(4*(n+1));
    }

    void build(int node, int ini, int fim, const vector<int> &v){
        if(ini == fim){
            tree[node] = v[ini];
            return;
        }
        int mid = (ini+fim)/2;
        build(2*node, ini, mid, v);
        build(2*node+1, mid+1, fim, v);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int node, int ini, int fim, int pos , int val){
        if(ini == fim){
            tree[node] = val;
            return;
        }
        int mid = (ini+fim)/2;
        if(pos<=mid) update(2*node, ini, mid, pos, val);
        else update(2*node+1, mid+1, fim, pos, val);
        tree[node]  = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int ini, int fim , int l, int r){
        if(l<= ini && fim <= r) return tree[node];
        if(ini > r || fim < l) return 0; 
        int mid = (ini+fim)/2;
        return query(2*node, ini, mid, l, r) + query(2*node+1, mid + 1, fim , l ,r );
    }



};

void solve(){
    int n,k,l,r; cin >> n >> k >> l >> r; 
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    } 
    Seg seg(n);
    vector<int> a(n+1,0);
    seg.build(1,1,n,a);
    map<int,int> mapa;
    int contador = 0;
    for(int i=1;i<=n;i++){
        if(!mapa[v[i]]) mapa[v[i]] = i;
        else {
            seg.update(1,1,n,mapa[v[i]], 0);
            mapa[v[i]] = i;
        } 
        seg.update(1,1,n,i,1);

        int low = 1, high = i;
        int limite_direita = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(seg.query(1, 1, n, mid, i) >= k){
                limite_direita = mid; 
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        low = 1, high = i;
        int limite2 = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(seg.query(1, 1, n, mid, i) > k){
                limite2 = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int limite_esquerda = limite2 + 1;

        if (limite_direita == 0) continue;

        int b_min_len = i - r + 1;
        int b_max_len = i - l + 1;

        int final_l = max(limite_esquerda, b_min_len);
        int final_r = min(limite_direita, b_max_len);

        if (final_l <= final_r) {
            contador += (final_r - final_l + 1);
        }
    }
    cout << contador << "\n";
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}