#include <iostream>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t>0){
        int x,y,a; cin >> x >> y >> a;
        if(a % (x+y) < x) cout << "no" << endl;
        else cout << "yes" << endl;
        t--;
    }
}