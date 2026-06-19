#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 6e6 + 10;
// problem link: https://codeforces.com/problemset/problem/2104/D

vector<int> eh_primo;
vector<int> primos;
vector<int> pref_primes;

void compute_primes(){
    int n = MAXN;
    eh_primo.assign(n+1, true);
    eh_primo[0] = eh_primo[1] = false;
    for(int i=2; i*i <=n;i++){
        if(eh_primo[i]){
            for(int j=i*i; j<n;j+=i){
                eh_primo[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(eh_primo[i]) primos.push_back(i);
    }

    pref_primes.push_back(0);
    int acc = 0;
    for(int i=0;i<primos.size();i++){
        acc += primos[i];
        pref_primes.push_back(acc);
    }
}

bool bbin(vector<int> &suf, vector<int> &pref, int k,int n){
    // quero saber se os últimos k caras ganham dos ultimos k primeiros primos
    int last = n - k + 1;
    if(suf[last] >= pref[k]) return true; 
    return false;
}

void solve(){
    int n; cin >> n; 
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin()+1, v.end());
    vector<int> suf(n+1,0);
    suf[n] = v[n];
    for(int i=n-1;i>=1;i--){
        suf[i] = suf[i+1] + v[i];
    }
    int l=0, r=n+1;
    while(r-l > 1){
        // cout << "fazendo para l = " << l << " e r = " << r << endl;
        int mid = (l+r)/2;
        if(bbin(suf, pref_primes, mid, n)) l = mid; 
        else r = mid;
    }

    int ans = n - l; 
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    compute_primes();
    int t;cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}