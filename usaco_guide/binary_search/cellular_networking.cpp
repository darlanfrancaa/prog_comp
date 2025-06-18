#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int lower_bound(const vector<int>& vetor, int num){
    int left = 0, right = vetor.size();
    while(left<right){
        int mid = (left+right)/2;
        if(vetor[mid]<num) left = mid + 1;
        else right = mid;
    }
    return left;
}

int upper_bound(const vector<int>& vetor, int num){
    int left = 0, right = vetor.size();
    while(left<right){
        int mid = (left+right)/2;
        if(vetor[mid]<=num) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<int> cities(n,0);
    vector<int> towers(m,0);
    for(auto &city : cities) cin >> city;
    for(auto &tower : towers) cin >> tower;
    int ans = INT_MIN;
    for(auto city:cities){
        int right = lower_bound(towers,city); //aqui calcula quando o indice v[i] >= city
        int left = right - 1; //aqui calcula quando o menor indice v[i-1] < city 
        int atual_ans = INT_MAX;
        if (right < towers.size())
            atual_ans = min(atual_ans, abs(towers[right] - city));
        if (left >= 0)
            atual_ans = min(atual_ans, abs(towers[left] - city));
        ans = max(ans,atual_ans);
    }
    cout << ans;
    return 0;
}