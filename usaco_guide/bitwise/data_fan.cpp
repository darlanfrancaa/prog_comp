#include <bits/stdc++.h>
using namespace std;

//problem: https://codeforces.com/contest/1872/problem/E

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t>0){
        t--;
        int n; cin >> n; 
        vector<int> nums(n,0);
        for(auto &num: nums) cin >> num;
        string s; cin >> s;
        vector<int> prefix_xor(n+1,0);
        prefix_xor[0] = 0;
        for(int i=1;i<=n;i++) prefix_xor[i]  = prefix_xor[i-1] ^ nums[i-1];
        int xor1 = 0, xor0 = 0;

        for(int i=0;i<n;i++){
            if(s[i]== '1') xor1 ^= nums[i];
            else xor0 ^= nums[i];
        }
        //armazeno aqui os xor dos numeros 0 e dos numeros 1

        int q; cin >> q;
        for(int i=0;i<q; i++){
            int op; cin >> op;
            if(op == 1){
                int l, r; cin >> l >> r;
                int sum = prefix_xor[r] ^ prefix_xor[l-1];  
                //ao inves de mudar a string s por completa, vamos mudar apenas o xor1 e xor0
                //quando fazemos uma alteracao entre l,r cada 1 vai virar 0 e cada 0 vira 1, então o valor de cada 1 tem que ir pra xor0 e de cada 0
                //tem que ir pra xor1
                xor1 ^= sum; xor0^=sum;
            } else {
                int g; cin >> g;
                if(g == 1) cout << xor1 << " ";
                else cout << xor0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}