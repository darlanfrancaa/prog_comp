#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/106073/problem/L

struct Dict {
    string s;
    int x; 
    int y; 
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<Dict> dicionario(n); 
    map<string, pii> mapa;
    for(int i=0; i<n; i++){
        cin >> dicionario[i].s >> dicionario[i].x >> dicionario[i].y; 
        mapa[dicionario[i].s] = {dicionario[i].x, dicionario[i].y};
    }
    int m; cin >> m; 
    vector<string> texto(m); 
    for(int i=0; i<m; i++){
        cin >> texto[i];
    }
    int q, k_max; cin >> q >> k_max;

    for(int i=0; i<q; i++){
        int f; cin >> f; 
        vector<string> ans(f);
        for(int j=0; j<f; j++){
            cin >> ans[j];
            cout << ans[j] << " "; 
        }

        vector<string> candidates;
        int curr_k = k_max;

        while(curr_k >= 1) {
            vector<string> janela(ans.end() - curr_k, ans.end());
            for(int j = 0; j <= m - curr_k - 1; j++){
                bool match = true;
                for(int w = 0; w < curr_k; w++){
                    if(texto[j + w] != janela[w]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    candidates.push_back(texto[j + curr_k]);
                }
            }
            if(!candidates.empty()){
                break; 
            }
            curr_k--;
        }

        if(candidates.empty()){
            cout << "*\n"; 
        } else {
            int sum_x = 0, sum_y = 0;
            for(string c : candidates){
                sum_x += mapa[c].first;
                sum_y += mapa[c].second;
            }
            int max_val = LLONG_MIN; 
            string melhor_pal = "";
            for(int j = 0; j < n; j++){
                int score = (dicionario[j].x * sum_x) + (dicionario[j].y * sum_y);
                if(score > max_val){
                    max_val = score;
                    melhor_pal = dicionario[j].s;
                }
            }
            
            cout << melhor_pal << "\n";
        }
    }
    return 0;
}