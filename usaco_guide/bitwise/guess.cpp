#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int pergunta(string s, int a, int b){
    cout << s << " " << a << " " << "\n";
    int ans; 
    cin >> ans;
    return ans;
}

int soma(int a, int b){
    a++; b++;
    int e = pergunta("and", a, b);
    int ou = pergunta("or", a, b);
    int xor_ = ~e & ou;
    
    return 2 * e + xor_;
}

int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    int a_mais_b = soma(0,1);
    int a_mais_c = soma(0,2);
    int b_mais_c = soma(1,2);
    
    vector<int> ans{(a_mais_b + a_mais_c - b_mais_c)/2};
    ans.push_back(a_mais_b - ans[0]);
    ans.push_back(a_mais_c - ans[0]);

    for(int i=3;i<n;i++){
        ans.push_back(soma(i-1,i)-ans.back());
    }
    sort(ans.begin(), ans.end());
    cout << "finish" << ans[k-1] << endl;
    return 0;
    
}