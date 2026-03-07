#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 2e5+10;
// problem link: https://codeforces.com/problemset/problem/2126/G2

struct Node{ 
    int mn,mx;
};

class SegTree {
private:
    int n; 
    vector<Node> tree; 
    vector<int> lazy;

    void unlazy(int node, int l, int r){
        if(lazy[node] != 0){
            if(l != r) { 
                tree[2*node].mn += lazy[node];
                tree[2*node].mx += lazy[node];
                lazy[2*node] += lazy[node];

                tree[2*node+1].mn += lazy[node];
                tree[2*node+1].mx += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

public: 
    void build(int node, int l, int r, vector<int> &v){
        if(l == r){
            tree[node] = {v[l], v[l]};
            return;
        }
        int mid = (l+r)/2;
        build(2*node, l, mid, v);
        build(2*node+1, mid+1, r, v);
        
        tree[node].mn = min(tree[2*node].mn, tree[2*node+1].mn);
        tree[node].mx = max(tree[2*node].mx, tree[2*node+1].mx);
    }

    SegTree(int tam){
        n = tam; 
        tree.resize(4*n, {0,0});
        lazy.resize(4*n,0);
    }


    void update(int node, int begin, int end, int l, int r, int val){
        if(begin > r || end < l) return;
        unlazy(node, begin, end);
        
        if(l <= begin && end <= r){
            tree[node].mn += val;
            tree[node].mx += val;
            lazy[node] += val;
            return;
        }
        
        int mid = (begin + end)/2;
        update(2*node, begin, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        
        tree[node].mn = min(tree[2*node].mn, tree[2*node+1].mn);
        tree[node].mx = max(tree[2*node].mx, tree[2*node+1].mx);
    }

    int query_min(int node, int begin, int end, int l, int r){
        if(begin > r || end < l) return LLONG_MAX; 
        unlazy(node, begin, end);
        if(l <= begin && end <= r) return tree[node].mn;
        
        int mid = (begin + end)/2;
        return min(query_min(2*node, begin, mid, l, r),
                   query_min(2*node+1, mid+1, end, l, r));
    }

    int query_max(int node, int begin, int end, int l, int r){
        if(begin > r || end < l) return LLONG_MIN; 
        unlazy(node, begin, end);
        if(l <= begin && end <= r) return tree[node].mx;
        
        int mid = (begin + end)/2;
        return max(query_max(2*node, begin, mid, l, r),
                   query_max(2*node+1, mid+1, end, l, r));
    }
};

vector<int> posicoes[N]; // vou salvar todas as posições que um valor aparece dentro de um vetor
int l_borda[N], r_borda[N]; // vou salvar para cada i o último valor antes de i e o próximo valor depois de i de modo que ambos são menores que v[i];


bool check(int D, int n, const vector<int>& v) {
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int val = (v[i] >= D + 1) ? 1 : -1;
        pref[i] = pref[i - 1] + val;
    }

    SegTree seg(n + 1);
    seg.build(1, 0, n, pref); 

    for (int m = 1; m <= n; m++) {
        for (int idx : posicoes[m]) {
            int esq = l_borda[idx];     
            int dir = r_borda[idx] - 1; 
            int max_R = seg.query_max(1, 0, n, idx, dir);
            int min_L = seg.query_min(1, 0, n, esq, idx - 1);
            if (max_R - min_L >= 0) return true;
        }

        int troca = m + D;
        if (troca <= n) {
            for (int idx : posicoes[troca]) {
                seg.update(1, 0, n, idx, n, -2);
            }
        }
    }
    return false;
}

void solve() {
    int n; cin >> n; 
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++) {
        posicoes[i].clear();
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        posicoes[v[i]].push_back(i);
    }
    stack<int> st;
    for(int i = 1; i <= n; i++){
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();
        if(st.empty()) l_borda[i] = 0;
        else l_borda[i] = st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop(); 
    for(int i = n; i >= 1; i--){
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();
        if(st.empty()) r_borda[i] = n + 1;
        else r_borda[i] = st.top();
        st.push(i);
    }
    int l = 0, r = n+1; // o valor na esq sempre vai funcionar
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(check(mid,n,v)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}