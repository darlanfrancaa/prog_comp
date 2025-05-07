#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, tempo; 
vector<int> cows;

int max_time(int k){
    priority_queue<int,vector<int>,greater<int>> pq; 
    for(int i=0;i<k;i++) pq.push(cows[i]);
    for(int i=k;i<n;i++){
        pq.push(pq.top()+cows[i]); //a cow[i] só vai sair depois de pq.top()+cow[i] segundos
        pq.pop();
    }
    while(pq.size()>1) pq.pop(); //vai deixar apenas a vaca que mais demoraria a sair
    if(pq.top() > tempo) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> tempo;
    cows.resize(n);
    for(auto &cow: cows) cin >> cow;
    int left = 1, right = n; 
    while(left< right){
        int mid = left + (right-left)/2;
        if(max_time(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}