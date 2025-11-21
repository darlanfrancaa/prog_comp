#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {

    int x; int y;
    while(1){ // achar o 3x3 que ganha

    cout << "? 2 2" << endl;

    cout.flush();

    int respa; cin >> respa;
    if(respa == 1){
        x=2; y=2;
        break;
    }

    cout << "? 4 2" << endl;
    cout.flush();

    int respb; cin >> respb;
    if(respb == 1){
        x=4; y =2;
        break;
    }

    cout << "? 4 4" << endl;
    cout.flush();

    int respc; cin >> respc;
    if(respc == 1){
        x=4; y=4;
        break;
    }

    x = 2; y = 4;
    break;
    
   } 


   cout << "? " << x-1 << " " << y << endl;
   cout.flush();

   int a; cin >> a;
   if(a == 1){

    cout << "? " << x-1 << " " << y-1 << endl;
    cout.flush();

    int b; cin >> b;
    if(b == 1){
        cout << "! " << x-1 << " " << y-1 << endl;
        exit(0);
    }else{
        cout << "! " << x-1 << " " << y << endl;
        exit(0);
    }




   }else{

    cout << "? " << x << " " << y-1 << endl;
    cout.flush();

    int c; cin >> c;
    if(c == 1){
        cout << "! " << x << " " << y-1 << endl;
        exit(0);

    }else{
        cout << "! " << x << " " << y << endl;
        exit(0);

    }

   }











    return 0;
}