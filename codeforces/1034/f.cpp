#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5+1;
vector<bool> primos(MAXN,true);

void crivo(){
    primos[0] = primos[1] = false;
    for(int p=2;p*p<MAXN;p++){
        if(primos[p]){
            for(int i=p*p;i<MAXN;i+=p){
                primos[i] = false;
            }
        }
    }
}

vector<int> numeros(int primo, const vector<int> &ans, int n){
    vector<int> ret; 
    int atual = primo;
    while(atual <= n){ 
        if(ans[atual] == 0) ret.push_back(atual);
        atual += primo;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    crivo();
    while(t--){
        int n; cin >> n; 
        vector<int> ans(n + 1, 0);
        ans[1] = 1;
        for(int i=n;i>=2;i--){
            if(primos[i]){
                if(2*i > n) ans[i] = i;
                else {
                    vector<int> nums = numeros(i,ans,n);
                    for(int j=0;j<nums.size()-1;j++){
                        ans[nums[j]] = nums[j+1];
                    }
                    ans[nums.back()] = nums[0];
                }
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}