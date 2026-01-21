#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://www.spoj.com/problems/ORDERSET/

const int N = 2e5+10;

class SegTree{
private: 
    int n; 
    vector<int> tree;
public: 

    void build(int node, int l, int r, vector<int> &v){
        if(l==r){
            tree[node] = v[l];
            return;
        } 
        int mid = (l+r)/2; 
        build(2*node, l,mid,v);
        build(2*node+1, mid+1,r, v);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    SegTree(int n, vector<int> &v){
        tree.resize(4*n);
        build(1,0,n-1, v);
    }

    void update(int node, int begin, int end, int pos, int val){
        if(begin == end){
            tree[node] = val;
            return;
        }
        int mid = (begin+end)/2;
        if(pos <= mid) update(2*node, begin, mid, pos, val);
        else update(2*node+1, mid+1, end, pos, val);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int begin, int end, int l, int r){
        if(begin > r || end < l) return 0;
        if(l <= begin && end <= r) return tree[node];
        int mid = (begin+end)/2; 
        int j1 = query(2*node, begin,mid, l,r); 
        int j2 = query(2*node+1, mid+1, end, l, r); 
        return j1+j2;
    }

    int find_k(int node, int begin, int end, int k){
        if(k > tree[node]) return -1;
        if(begin == end){
            return begin;
        }
        int mid = (begin+end)/2;
        if(k <= tree[2*node]) return find_k(2*node, begin, mid, k); 
        else {
            int remain = k - tree[2*node];
            return find_k(2*node+1, mid+1,end, remain);
        }
    }

};


struct Queries{
    char tipo; 
    int numero;
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q; 
    vector<Queries> queries;
    map<int,int> cord;
    int contador = 0;
    while(q--){
        char t; int num; 
        cin >> t >> num;
        queries.push_back({t,num});
        cord[num];
    }
    vector<int> orig(N);

    for(auto &par: cord) {
        par.second = contador;
        orig[contador++] = par.first;  
    }
    vector<int> v(N,0);
    SegTree seg(N,v);
    for(auto [tipo, numero]: queries){
        if(tipo == 'I'){
            seg.update(1,0,N-1,cord[numero],1);
        } else if ( tipo == 'D'){
            seg.update(1,0,N-1,cord[numero], 0);
        } else if (tipo == 'K'){
            int ans = seg.find_k(1,0,N-1,numero);
            if(ans == -1) cout << "invalid\n";
            else cout << orig[ans] << "\n";
        } else if(tipo == 'C'){
            cout << seg.query(1,0,N-1,0,cord[numero]-1) << '\n';
        }
    }
    return 0;
}