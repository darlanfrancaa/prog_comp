#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://neps.academy/br/exercise/371

struct Node{
    int minimo; 
    int maximo; 
    int diff;
};

class SegTree{
private: 
    int n; 
    vector<Node> tree;
public:

    Node join(Node a, Node b){
        Node res; 
        res.minimo = min(a.minimo, b.minimo);
        res.maximo = max(a.maximo, b.maximo); 
        res.diff = max({
            a.diff,
            b.diff,
            a.maximo - b.minimo, 
            b.maximo - a.minimo 
        });
        return res;
    }

    void build(int node, int l, int r, vector<Node> &v){
        if(l==r){
            tree[node] = v[l];
            tree[node].diff = -1;
            return;
        }
        int mid = (l+r)/2; 
        build(2*node, l, mid, v); 
        build(2*node+1, mid+1, r, v); 
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }

    SegTree(int n, vector<Node> &v){
        tree.resize(4*n,{LLONG_MAX,LLONG_MIN});
        build(1,0,n-1, v);
    }

    void update(int node, int begin, int end, int pos, Node val){
        if(begin == end){
            tree[node] = val;
            tree[node].diff = -1;
            return;
        }
        int mid = (begin+end)/2; 
        if(pos <= mid) update(2*node,begin,mid, pos,val);
        else update(2*node+1, mid+1, end, pos, val);
        tree[node] = join(tree[2*node], tree[2*node+1]);
    }

    Node query(int node, int begin, int end, int l, int r){
        if(begin > r || end < l) return {LLONG_MAX,LLONG_MIN, -1};
        if(l <= begin && end <= r) return tree[node];
        int mid = (begin+end)/2; 
        Node p1 = query(2*node, begin, mid, l,r);
        Node p2 = query(2*node+1, mid+1, end, l, r); 
        if (p1.minimo == LLONG_MAX) return p2; 
        if (p2.minimo == LLONG_MAX) return p1;
        return join(p1,p2); 
    } 

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    vector<int> v(n);
    vector<Node> aux(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        aux[i] = {v[i], v[i],-1};
    }
    SegTree seg(n, aux);
    while(m--){
        int op; cin >> op;
        if(op == 1){
            int peso, balde; cin >> peso >> balde;
            balde--; 
            Node atual = seg.query(1,0,n-1,balde,balde);
            Node novo ;
            novo.minimo = min(atual.minimo, peso);
            novo.maximo = max(atual.maximo, peso);
            novo.diff = -1;
            seg.update(1,0,n-1,balde, novo);
        } else { 
            int l, r; cin >> l >> r; 
            l--; r--;
            Node q = seg.query(1,0,n-1,l,r); 
            cout << q.diff << "\n";
        }
    }
    return 0;
}