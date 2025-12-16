#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
#define popcount __builtin_popcountll
const int MAXN = 25; 
struct No{
    int d1; 
    int d2; 
    int a; 
    int mask;

    bool operator<(const No& other) const {
        if (d1 != other.d1) return d1 < other.d1; 
        if (d2 != other.d2) return d2 < other.d2; 
        if (a != other.a) return a < other.a;   
        return mask < other.mask; 
    }
};

int n;
int nums[MAXN][3];

vector<No> calc_lista(int l, int r){ // vai de [l,r);
    int total_l = 0, total_m =0, total_w = 0;
    for(int i=l;i<r;i++){
        total_l += nums[i][0];
        total_m += nums[i][1];
        total_w += nums[i][2];
    }

    int tam = r - l; 
    int max_mask = 1;
    for(int i=0;i<tam;i++) max_mask *= 3;
    vector<No> ret(max_mask);
    for(int mask = 0; mask < max_mask; mask++){
        int curr_mask = mask;
        array<int,3> removed = {0,0,0};
        for(int j=0;j<tam;j++){
            removed[curr_mask % 3] += nums[l+j][curr_mask % 3];
            curr_mask /= 3;
        }

        array<int,3> final = {total_l - removed[0], total_m - removed[1], total_w - removed[2]};
        ret[mask] = {final[1]-final[0], final[2]-final[1],final[0], mask};
    }

    return ret;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> nums[i][j];
        }
    }

    int n1 = (int)(n/2);

    vector<No> left = calc_lista((int)0,(int)n1);
    vector<No> right = calc_lista((int)n1,(int)n);

    sort(begin(right), end(right));

    int mask1_ans = -1; 
    int mask2_ans = -1;
    int ans_max = LLONG_MIN;

    for(auto &[d1, d2, a, mask1]: left){
        No teste = {-d1,-d2, LLONG_MAX, 0};
        auto it = lower_bound(begin(right), end(right), teste);
        if(it == begin(right)) continue; 
        it = prev(it);

        auto [dist1, dist2, b, mask2] = *it;
        if(dist1 + d1 != 0 || dist2 + d2 != 0) continue;
        int curr_ans = a + b; 
        if(curr_ans > ans_max){
            ans_max = curr_ans;
            mask1_ans = mask1;
            mask2_ans = mask2;
        } 
    }

    if(ans_max == LLONG_MIN){
        cout << "Impossible" << '\n';
        return 0;
    }

    array<string, 3> comn = {"MW", "LW", "LM"};
    for(int i=0;i<n1;i++){
        cout << comn[mask1_ans%3] << "\n";
        mask1_ans /=3 ;
    }
    for(int i=0;i<n-n1;i++){
        cout << comn[mask2_ans%3] << "\n";
        mask2_ans /=3;
    }

    return 0;
}