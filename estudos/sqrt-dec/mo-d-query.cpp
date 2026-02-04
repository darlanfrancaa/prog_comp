#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://www.spoj.com/problems/DQUERY/

const int N = 30010; 
const int M = 1000010;
const int B = 250;
int v[N], qntd[M]; 
int ans = 0;

bool cmp(array <int,3> a, array<int,3> b){
    if(a[0]/B < b[0]/B) return true;
    if(a[0]/B > b[0]/B) return false;
    return a[1] < b[1];
}

void add(int val){
    if(qntd[val] == 0) ans++;
    qntd[val]++;
    return;
}

void remove(int val){
    qntd[val]--;
    if(qntd[val] == 0) ans--;
    return;
}

int resp[2000010];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    int q; cin >> q; 
    vector<array<int,3>> qr; 
    for(int i=0;i<q;i++){
        int l,r; cin >> l >> r; 
        qr.push_back({l,r,i});
    }
    sort(qr.begin(), qr.end(), cmp);
    int tl = 1, tr = 1;
    ans = 1;
    qntd[v[1]]++;
    for(auto [l,r,i]: qr){
        while(tr < r){
            tr++;
            add(v[tr]);
        }
        while(tl > l){
            tl--; 
            add(v[tl]);
        }
        while(tr > r){
            remove(v[tr]);
            tr--;
        }
        while(tl < l){
            remove(v[tl]);
            tl++;
        }
        resp[i] = ans;
    }
    for(int i=0;i<q;i++){
        cout << resp[i] << "\n";
    }
    return 0;
}