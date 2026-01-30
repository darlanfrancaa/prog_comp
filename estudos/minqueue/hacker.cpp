#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://oj.uz/problem/view/BOI15_hac

class MinQueue {
private: 
    stack<pair<int,int>> s1,s2;
public:
    void push(int x){
        int curr_min = x; 
        if(!s1.empty()){
            curr_min = min(curr_min, s1.top().second);
        }
        s1.push({x, curr_min});
    }

    void pop(){
        if(!s2.empty()){
            s2.pop();
            return;
        }
        while(!s1.empty()){
            auto par = s1.top(); s1.pop(); 
            int curr_min = par.first;
            if(!s2.empty()){
                curr_min = min(curr_min, s2.top().second);
            }
            s2.push({par.first, curr_min});
        }
        if(!s2.empty()) s2.pop(); 
    }

    int query(){
        if(s1.empty() && s2.empty()) return LLONG_MAX;
        if(s1.empty()) return s2.top().second;
        if(s2.empty()) return s1.top().second;
        return min(s1.top().second, s2.top().second);
    }
};


signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    int k = (n % 2 == 0) ? n/2 : n/2 + 1;
    vector<int> v(n); 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> v2(2*n);
    for(int i=0;i<2*n;i++){
        v2[i] = v[i % n];
    } // copiei o circular para o vetor v2 de tamanho 2n para se livrar do circular
    // for(auto c : v2){
    //     cout << c << " ";
    // }

    vector<int> sums;
    int i=0, sum = 0;
    while(i < k){
        sum += v2[i++];
    }
    // printf("a soma dos k= %lld primeiros foi sum %lld \n", k, sum);
    sums.push_back(sum);
    while(sums.size() < n){
        sum += v2[i];
        sum -= v2[i-k];
        sums.push_back(sum);
        // printf("aqui eu estou em i = %lld, eu coloquei o v[i] = %lld, tirei o v[i-k] = %lld, e a soma atual é %lld\n", i, v2[i], v2[i-k], sum);
        i++;
    }
    // então em sums está armazenada as n somas possíveis
    vector<int> sums2(2*n); 
    for(int i=0;i<2*n;i++){
        sums2[i] = sums[i % n];
    }
    // cout << "\n";
    // for(int i=0;i<2*n;i++){
    //     cout << sums2[i] << ' ';
    // }

    MinQueue q; 
    for(int i=n-k+1;i<=n;i++){
        q.push(sums2[i]);
    }
    int ans = q.query();
    // cout << "\n" <<  ans << "\n";
    for(int i=n+1;i<2*n;i++){
        q.push(sums2[i]);
        q.pop();
        ans = max(ans, q.query());
        // printf("o resultado para a query atual foi %lld e o agora ans = %lld\n", q.query(), ans);
    }
    cout << ans << "\n";
    return 0;
}