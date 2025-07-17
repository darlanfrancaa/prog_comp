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
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        k--;
        vector<int> nums(n);
        for(int &num:nums){
            cin >> num;
        }
        int valor_torre_atual = nums[k];
        sort(nums.begin(),nums.end());
        if(valor_torre_atual >= nums[n-1]){
            cout << "yes" << endl;
            continue;
        }
        int altura_agua = 0;
        int torre_atual = lower_bound(nums,valor_torre_atual);
        bool chegou = false;
        bool morreu = false;
        while(!chegou && !morreu){
            int proximo_valor = 2 * nums[torre_atual] - altura_agua ;
            auto maior_torre = upper_bound(nums,proximo_valor) - 1;
            if (nums[maior_torre] <= nums[torre_atual]){
                morreu = true;
            } else {
                altura_agua += nums[maior_torre] - nums[torre_atual];
                torre_atual = maior_torre; 
            }
            if(torre_atual == n-1) chegou = true;
        }
        if(chegou) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}