#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> val(513,INT_MAX); // aqui o v[i] vai armazenar o menor valor tal que existe uma lis tal que o xor dê exatamente i;
    val[0] = 0;
    for(int j=0;j<n;j++){
        int num; cin >> num; 
        val[num] = min(val[num], num);
        for(int i=0; i<512;i++){
            if(val[i] < num) val[i ^ num] = min(val[i ^ num] , num);
        }
    }
    int contador = 0;
    for(int i=0;i<512;i++){
        if(val[i] != INT_MAX) contador++;
    }
    cout << contador << endl;
    for(int i=0;i<512;i++){
        if(val[i] != INT_MAX) cout << i << " "; 
    }
    return 0;
}