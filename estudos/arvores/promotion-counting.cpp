#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://usaco.org/index.php?page=viewproblem2&cpid=696
const int N = 1e5+10;

class SegTree{
private: 
    int n; 
    vector<int> tree; 
public:
    SegTree(int k){
        int n = k;
        tree.resize(4*n);
    }

    void update(int node, int l, int r, int val, int pos){
        if(l == r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*node, l, mid, val, pos);
        else update(2*node+1,mid+1, r, val, pos);
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    int query(int node, int begin, int end, int l, int r){
        if(l <= begin && end <= r) return tree[node];
        if(begin > r || end < l) return 0; 
        int mid = (begin + end)/2;
        int q1 = query(2*node, begin, mid, l, r);
        int q2 = query(2*node+1, mid+1, end, l, r);
        return q1+q2;
    }
};

int n;
vector<int> adj[N];
int tin[N], tout[N], vals_not_comp[N], vals[N];
int timer = 1;

void dfs(int v, int p){
    tin[v] = timer++;
    for(auto node: adj[v]){
        if(node != p) dfs(node,v);
    }
    tout[v] = timer;
}

struct Node{
    int vertice; 
    int valor;
    bool operator<(const Node& other) const{
        return valor > other.valor; // ordenando ao contrário, mesmo que isso seja má prática
    }
};


signed main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    vector<Node> vetor(n+10); 
    for(int i=1;i<=n;i++){
        cin >> vals_not_comp[i];
        vetor[i] = {i, vals_not_comp[i]};
    }

    for(int i=2;i<=n;i++){
        int a;cin >> a; 
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    vector<int> ans(n+1);
    sort(vetor.begin()+1, vetor.end());
    dfs(1,0);
    SegTree seg(n);
    for(int i=1;i<=n;i++){
        auto [vertice, valor] = vetor[i];
        int begin = tin[vertice], end = tout[vertice]-1;
        seg.update(1,1,n,1,begin);
        if(begin == end) ans[vertice] = 0; 
        else { 
            ans[vertice] = seg.query(1,1,n,begin+1,end); // begin + 1  é o primeiro cara que tá na subárvore e end é o último e não é o vértice já que não tem  repetição nesse euler tour
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << "\n";




    

    return 0;
}