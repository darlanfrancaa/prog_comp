#include <bits/stdc++.h>
using namespace std;
    
#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
    
// problem link: 
    
struct Order
{
    int di,pi,ci,lxi,rxi,lyi,ryi;
};
    
    
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<Order> v(n);
    for(int i=0;i<n;i++){
        int di,pi,ci,lxi,rxi,lyi,ryi;
        cin >> di >> pi >> ci >> lxi >> rxi >> lyi >> ryi; 
        v[i] = {di,pi,ci,lxi,rxi,lyi,ryi};
    }
    vector<double> dp((1<<n), -1.0);
    vector<int> total_time((1<<n), 0);
    dp[0] = 0.0; 
    total_time[0] = 0;
    
    for(int mask = 1; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                total_time[mask] = total_time[mask ^ (1 << i)] + v[i].ci;
                break; 
            }
        }
    }
    
    
    for(int mask = 1; mask < (1 << n); mask++){
        long long t = total_time[mask]; 
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))) continue; 
            int prev_mask = mask ^ (1 << i);
            if(dp[prev_mask] < 0.0) continue;
            if(t > v[i].di) continue; 
    
            double lucro_inicial = v[i].pi;
            double bonus_esperado = (v[i].lxi + v[i].rxi) / 2.0;
            
            double prob_bonus = 0.0;
            if(t <= v[i].lyi){
                prob_bonus = 1.0;
            } else if(t >= v[i].ryi){
                prob_bonus = 0.0;
            } else {
                prob_bonus = (double)(v[i].ryi - t) / (v[i].ryi - v[i].lyi);
            }
            
            double ganho_esperado = lucro_inicial + (bonus_esperado * prob_bonus);
            
            dp[mask] = max(dp[mask], dp[prev_mask] + ganho_esperado);
        }
    }
    
    double ans = 0.0;
    for(int mask = 0; mask < (1 << n); mask++){
        ans = max(ans, dp[mask]);
    }
    
    cout << fixed << setprecision(8) << ans; 
    
    return 0;
}

