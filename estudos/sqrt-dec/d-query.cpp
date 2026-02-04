#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://www.spoj.com/problems/DQUERY/
const int N = 30010;
const int b = 180;
int v[N], sum[N/b+10];

void update(int i, int x){
    sum[i/b] += x; 
    sum[i/b] -= v[i]; 
    v[i] = x;
    return;
}

int query(int l, int r){
    int ret = 0; 
    while(l <= r && l % b != 0) ret += v[l++];
    while(l + b - 1 <= r){
        ret += sum[l/b];
        l+= b;
    }
    while(l <= r) ret += v[l++];
    return ret;
}

struct Queries{
    int begin, end, idx; 
    bool operator<(const Queries &a)const{
        return end < a.end;
    }
};

const int MAXA = 1e6+10;
int last[MAXA];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(last,last+MAXA,-1);
    int n; cin >> n; 
    vector<int> nums(n); 
    for(auto &c : nums) cin >> c; 
    int q; cin >> q; 
    vector<Queries> quer(q);
    for(int i=0;i<q;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        quer[i] = {a,b,i};
    }
    
    sort(quer.begin(), quer.end());
    // for(int i=0;i<query.size();i++){
    //     cout << query[i].begin << " " <<  query[i].end << "\n";
    // }
    int curr_query = 0;
    vector<int> ans(q);
    
    for(int i=0;i<n;i++){
        if(last[nums[i]] == -1){
            update(i,1);
            last[nums[i]] = i;
        } else {
            int pos = last[nums[i]];
            update(pos, 0);
            update(i, 1);
            last[nums[i]] = i;
        }
        while(curr_query < q && quer[curr_query].end == i){
            auto [comeco,fim,idx] = quer[curr_query++];
            ans[idx] = query(comeco, fim);
        }
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}