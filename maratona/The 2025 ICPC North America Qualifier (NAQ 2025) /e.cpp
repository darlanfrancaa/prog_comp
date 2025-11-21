#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

double dist(double a, double b, double x, double y){
    double dx = pow(x-a,2);
    double dy = pow(y-b, 2); 
    double ans = dx + dy;
    return ans; 
}

signed main() {
    int red = 0;
    int yellow = 0;

    double x = 144, y = 84;

    for(int j = 0; j < 10; j++){
        int n; cin >> n;
        priority_queue<double,vector<double> , greater<double>> r; 
        priority_queue<double,vector<double> , greater<double>> ye; 
        for(int i=0;i<n;i++){
            double a, b; cin >> a >> b; 
            double distancia = dist(a,b,x,y);
            r.push(distancia);
        }
        int m; cin >> m; 
        for(int i=0;i<m;i++){
            double a , b; cin >> a >> b; 
            double distancia = dist(a,b,x,y);
            ye.push(distancia);
        }
        if(n == 0){
            yellow += m;
            continue;
        } 
        if(m == 0){
            red += n; 
            continue;
        }
        
        if(!r.empty() && r.top() < ye.top()){
            int contador = 0; 
            while(!r.empty() &&  r.top() < ye.top()) {
                r.pop();
                contador++;
            }
            red += contador;
        }
        else if(!ye.empty() && ye.top() < r.top()){
            int contador = 0; 
            while(!ye.empty() && ye.top() < r.top()){
                ye.pop(); 
                contador++;
            }
            yellow += contador;
        }
        
    }
    cout << red << " " << yellow << "\n";
}