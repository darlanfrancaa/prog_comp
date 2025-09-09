#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D

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


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> v(2*n+1);
    for(int i=1;i<=2*n;i++) cin >> v[i];
    vector<pii> pos(n+1,{0,0});
    for(int i=1;i<=2*n;i++){
        int val = v[i];
        if(pos[val].first == 0) pos[val].first = i;
        else pos[val].second = i;
    } 
    vector<int> v1(2*n+1,0);
    vector<int> ans(n+1,0);
    Seg seg1(2*n);
    seg1.build(1,1,2*n,v1);
    for(int i=2*n;i>=1;i--){
        if(v1[i] == 0){
            int val = v[i];
            int l = pos[val].first; 
            v1[l] = 1;
            ans[val] += seg1.query(1,1,2*n,l,i); 
            seg1.update(1,1,2*n,l,1);
        }
    }
    v1.assign(2*n+1,0);
    Seg seg2(2*n);
    seg2.build(1,1,n,v1);
    for(int i=1;i<=2*n;i++){
        if(v1[i]==0){
            int val = v[i];
            int r = pos[val].second;
            v1[r] = 1;
            ans[val] += seg2.query(1,1,2*n,i,r);
            seg2.update(1,1,2*n,r,1);
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}