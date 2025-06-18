#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, k;
vector<int> vetor;

bool maximum_sum(ll s){
    int contador = 1;
    ll soma = 0; 
    for(int i=0;i<n;i++){
        if(vetor[i]>s) return false;
        if(soma + vetor[i] > s){
            contador++;
            soma = vetor[i];
        } else soma += vetor[i];
    }
    return contador <= k;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vetor.resize(n);
    for(auto &elemento: vetor) cin >> elemento;
    ll left = 0; ll right = 2e14;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(maximum_sum(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}