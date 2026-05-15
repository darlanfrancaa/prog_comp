#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;

// Tentiva de impleementação que tomou tle 

class SegTree{
private: 
    int n; 
    vector<int> tree;
public: 
    SegTree() : n(0) {}
    SegTree(int n): n(n), tree(4*n, 0) {} 

    pair<int, vector<int>> get_parms(){
        return {n, tree};
    }

    SegTree(int n, vector<int> tree){ 
        this->n = n; 
        this->tree = tree;
    }

    void build(int node, int l, int r, vector<int> &v){
        if(l == r) {
            tree[node] = v[l];
            return; 
        } 
        int mid = (l+r)/2; 
        build(2*node, l, mid, v);
        build(2*node+1, mid+1 , r,v);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }   

    void update(int node, int l, int r, int pos, int val){
        if(l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node + 1, mid+1, r, pos, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int begin, int end, int l, int r){
        if(l <= begin && end <= r) return tree[node];
        if(begin > r || end < l) return 0; 
        int mid = (begin + end)/2;
        return query(2*node, begin , mid, l,r ) + query(2*node+1, mid+1, end, l,r);
    }
};

SegTree merge(SegTree a, SegTree b){
    auto [n1, tree_a] = a.get_parms();
    auto [n2, tree_b] = b.get_parms();
    int n = n1;
    vector<int> tree(4*n, 0);
    for(int i=0;i<4*n;i++){
        tree[i] = tree_a[i] + tree_b[i];
    }
    return SegTree(n, tree);
}

class SegTree2D{
private: 
    int n; 
    vector<SegTree> tree;
public: 
    SegTree2D(int n): n(n), tree(4*n) {
        for(int i=0; i<4*n; i++) tree[i] = SegTree(n);
    }

    void build(int node, int l, int r, vector<SegTree> &v){
        if(l == r) {
            tree[node] = v[l];
            return; 
        } 
        int mid = (l+r)/2; 
        build(2*node, l, mid, v);
        build(2*node+1, mid+1 , r,v);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }   

    void update(int node, int l, int r, int lin, int col, int val){
        if(l == r) {
            tree[node].update(1,0, n-1, col, val);
            return;
        }
        int mid = (l+r)/2;
        if(lin <= mid) update(2*node, l, mid, lin, col, val);
        else update(2*node + 1, mid+1, r, lin, col, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int begin, int end, int lin1, int col1, int lin2, int col2){
        if(lin1 <= begin && end <= lin2) return tree[node].query(1,0, n-1, col1, col2);
        if(begin > lin2 || end < lin1) return 0;
        int mid = (begin + end)/2;
        int val1 = query(2*node, begin ,mid, lin1,col1,lin2,col2);
        int val2 = query(2*node+1, mid+1 ,end, lin1,col1,lin2,col2);
        return val1 + val2;
    }
};

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n, q; 
    if(!(cin >> n >> q)) return 0;
    
    vector<vector<int>> tab(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        string s; cin >> s; 
        for(int j=0;j<n;j++){
            tab[i][j] = (s[j] == '*' ? 1 : 0);
        }
    }
    
    vector<SegTree> segs;
    for(int i=0;i<n;i++){
        SegTree seg(n);
        seg.build(1,0,n-1,tab[i]);
        segs.push_back(seg);
    }
    
    SegTree2D seg2d(n);
    seg2d.build(1,0,n-1, segs);
    
    for(int i=0;i<q;i++){
        int op; cin >> op; 
        if(op == 1){
            int x, y; cin >> x >> y; 
            x--; y--; 
            
            int current_val = seg2d.query(1, 0, n-1, x, y, x, y);
            int new_val = (current_val == 1) ? 0 : 1;
            
            seg2d.update(1,0,n-1,x,y,new_val);
        } else {
            int l1,c1,l2,c2; cin >> l1 >> c1 >> l2 >> c2; 
            l1--; c1--; l2--; c2--; 
            cout << seg2d.query(1,0,n-1, l1,c1,l2,c2) << "\n";
        }
    }

    return 0;
}