#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int upper_bound(const vector<int> &vetor, int num){
    int left = 0, right = vetor.size();
    while(left < right){
        int mid = (left+right) / 2;
        if(vetor[mid] <= num) left = mid + 1;
        else right = mid;   
    }
    return left;
}
int lower_bound(const vector<int> &vetor, int num){
    int left = 0, right = vetor.size();
    while(left < right){
        int mid = (left+right) / 2;
        if(vetor[mid] < num) left = mid + 1;
        else right = mid;   
    }
    return left;
}

int main() {
	int n, q; cin >> n >> q;
    vector<int> haybales(n);
    for(auto &haybale: haybales) cin >> haybale; 
    sort(haybales.begin(),haybales.end());
    for(int i=0;i<q;i++){
        int a, b; cin >> a >> b;
        //queremos >= a e <= b
        int left = lower_bound(haybales,a); //retorna o i tal que v[i] >= a
        int right = upper_bound(haybales,b) - 1; //retorna o i tal que v[i] > a, entao v[i-1] <= a
        cout << right - left + 1 << endl;
    } 
}