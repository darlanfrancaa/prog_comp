#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
	int t; cin >> t; 
    while(t>0){
        t--;
        int n; cin >> n; 
        vector<ll> fome(n+1);
        for(int i=1;i<=n;i++){
            cin >> fome[i];
        }

        ll ans = 0; 
        for(int i=1;i<n;i++){
            if(fome[i+1]> fome[i]){
                if(i+2>n){
                    ans = -1; 
                    break;
                }

                ll diff = fome[i+1]-fome[i];
                fome[i+1] -= diff;
                fome[i+2] -= diff;
                if(fome[i+2]<0){
                    ans = -1;
                    break;
                }
                ans += diff * 2;
            }
            else if(fome[i] > fome[i+1]){
                if(i%2 == 1){
                    ans = -1;
                    break;
                }
                ll diff = fome[i]-fome[i+1];
                ans += diff * i;
            }
        }
        cout << ans << endl;
    }
}
