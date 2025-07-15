#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;

ll v_2[MAXN+1];

void preencher_v2(int n){
    v_2[1] = 0;
    for(int i=2;i<=n;i++){
        int num_atual = i;
        int cont_pot_2 = 0;
        while(num_atual % 2 == 0){
            num_atual /= 2;
            cont_pot_2++;
        }
        v_2[i] = v_2[i-1] + cont_pot_2;
    }
}

bool verificar_paridade_binomial(int m, int n){
    return v_2[m] > v_2[n] + v_2[m-n]; 
} 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> nums(n);
    preencher_v2(n);
    for(auto &num: nums) cin >> num;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!verificar_paridade_binomial(n-1,i)) ans ^= nums[i];
    }
    cout << ans << endl;
    
    
    return 0;
}