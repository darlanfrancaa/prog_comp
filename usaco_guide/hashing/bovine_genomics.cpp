#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

class HashedString{
private: 
    static const int M = (1LL << 61) - 1;
    static const int B = 9973; 

    static vector<int> pow; 
    vector<int> p_hash;

    __int128 multi(int a, int b){
        return (__int128)a*b;
    }

    int mod_multi(int a,int b){
        return multi(a,b) % M;
    }
public: 
    HashedString(string &s): p_hash(s.size()+1){
        while(pow.size() <= s.size()){
            pow.push_back(mod_multi(pow.back(), B));
        }
        p_hash[0] = 0;
        for(int i=0;i<s.size();i++){
            p_hash[i+1] =(mod_multi(p_hash[i], B) + s[i]) % M;
        }
    }

    int get_hash(int start, int end){
        int val = p_hash[end+1] - mod_multi(p_hash[start], pow[end-start+1]);
        return (val % M + M) % M;
    }
};
vector<int> HashedString:: pow = {1};
int n, m; 
vector<string> spots, cows;
vector<HashedString> hashed_spots;
vector<HashedString> hashed_cows;

bool solvek(int k){
    // eu quero checar todos os intervalos de i até i+k-1
    int i=0; 
    while(i+k-1<m){
        // printf("testando para k = %lld e [%lld, %lld]\n", k, i, i+k-1);
        set<int> hash; 
        for(int j=0;j<n;j++){
            int val = hashed_spots[j].get_hash(i, i+k-1);
            // printf("para k = %lld, j = %lld, intervalo [%lld, %lld], temos o resultado %lld \n",k,j,i,i+k-1,val);
            hash.insert(val);
        }
        bool flag = true; 
        for(int j=0;j<n;j++){
            int val = hashed_cows[j].get_hash(i,i+k-1);
            // printf("para k = %lld, j = %lld, intervalo [%lld, %lld], temos o resultado %lld \n",k,j,i,i+k-1,val);
            if(hash.find(val) != hash.end()) flag = false;
        }
        // cout << flag << "\n";
        if(!flag && i+k == m) {
            return false;
        } else if(!flag) i++;
        else return true; 
    }
    return false;
}


signed main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    spots.resize(n);cows.resize(n); 

    for(auto &s: spots) cin >> s; 
    for(auto &c: cows) cin >> c;

    for(int i=0;i<n;i++){
        hashed_spots.emplace_back(spots[i]);
    } 
    for(int i=0;i<n;i++){
        hashed_cows.emplace_back(cows[i]);
    } 
    int left = 0, right = m;
    // se um valor k funciona, todo mundo maior que k funciona também, então eu vou armazenar em right todos os valores que funcionam e em left todos os valores que não funcionam
    while(right - left > 1){
        int mid = (left+right)/2;
        // printf("estou testando para o valor mid = %lld\n", mid);
        if(solvek(mid)) right = mid;
        else left = mid;
    }
    cout << right << "\n";

    return 0;
}