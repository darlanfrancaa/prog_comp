#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin >> k; 
    vector<int> ingr(k);
    for(auto &i: ingr) cin >> i; 
    int n; cin >> n; 
    vector<vector<int>> orders(n, vector<int> (k,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++) {
            cin >> orders[i][j];
        }
    }
    vector<int> dia_completo(k);
    for(int i=0;i<k;i++){
        int sum = 0; 
        for(int j=0;j<n;j++){
            sum += orders[j][i];
        }
        dia_completo[i] = sum;
    }
    // cout << "o valor do vetor dia completo foi:\n";
    // for(auto r: dia_completo){
    //     cout << r << " ";
    // }
    // cout << "\n";
    int min_day = LLONG_MAX;
    for(int i=0;i<k;i++){
        if (dia_completo[i] > 0) {
            min_day = min(min_day, ingr[i] / dia_completo[i]); 
        } 
    }
    vector<int> rem(k);
    for(int i=0;i<k;i++){
        rem[i] = ingr[i] - dia_completo[i] * min_day;
    }
    // cout << "o valor do vetor restante foi:\n";
    // for(auto r: rem){
    //     cout << r << " ";
    // }
    // cout << "\n";
    int ord=0;
    int ans_ord = 0;
    while(true){
        bool neg = true;
        for(int i=0;i<k;i++){
            rem[i] = rem[i] - orders[ord][i];
            if(rem[i] < 0){
                neg = false;
                break;
            }
        }
        if(!neg){
            ans_ord = ord + 1;
            break;
        }
        ord++;
    }

    cout << min_day + 1 << " " << ans_ord << endl;


    return 0;
}