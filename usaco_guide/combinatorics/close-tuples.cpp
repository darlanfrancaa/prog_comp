#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+1;
ll fatorial[MAXN+1];
ll inv[MAXN+1];

ll exp(ll a, ll b){
    a %= MOD;
    ll ret = 1; 
    while(b > 0){
        if ( b % 2 == 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b = b / 2;
    }
    return ret;
}

void preencher_fatorial(int n){
    fatorial[0] = 1;
    for(int i=1;i<=n;i++){
        fatorial[i] = i * fatorial[i-1] % MOD;
    }
}

void preencher_inversos(int n){
    inv[n] = exp(fatorial[n],MOD-2);
    for(int i=n-1;i>=0;i--){
        inv[i] = (i+1) * inv[i+1] % MOD; 
    }
}

int binomial(int n, int k){
    return fatorial[n] * inv[k] % MOD * inv[n-k] % MOD;
}





int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    preencher_fatorial(MAXN);
    preencher_inversos(MAXN);
    while(t--){
        int n, m , k; cin >> n >> m >> k;
        vector<int> nums(n);

        for(auto &num: nums) cin >> num;
        sort(nums.begin(),nums.end());

        int left = 0, right = 0;
        int ans = 0; 
        while(left < n  && right < n){
            while(right + 1 < n && nums[right+1]-nums[left] <= k) right++;
            int tamanho = right - left + 1;
            if(tamanho >= m){
                ans = (ans + binomial(tamanho-1, m - 1)) % MOD;
            }         
            left++;
        }
        cout << ans << endl;
    }
    return 0;
}