#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t>0){
        t--;
        int n,d,h;
        cin >> n >> d >> h;
        double area = static_cast<double>(d) *h / 2.0;
        vector<int> alturas (n);
        for(int &c :alturas)  cin >> c; 
        double soma = area; int atual = alturas[0];
        for(int i=1; i<n; i++) {
            if(alturas[i] >= atual + h) {
                soma += area;
            } else {
                double razao = static_cast<double> (h-(alturas[i]-atual)) / h;
                double area_2 = area * (1 - razao*razao);
                soma += area_2;
            }
            atual = alturas[i];
        }
        cout << fixed << setprecision(7) << soma << endl;
    }
}