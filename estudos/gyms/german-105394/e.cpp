#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 301;
// problem link: https://codeforces.com/gym/105394/problem/E

bool dp[2][2][N][N][N];
// representa dp[player][valor_atual][a][b][c]
// vamos assumir que o 1 quer acabar em ímpar e o 0 acabar em par
// suponha que a ordem eh s0, s1, p0;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 

    set<pair<char, int>> conj_s0, conj_s1, conj_p0;
    int s0 = 0, s1 = 0, p0 = 0;
    
    for(int i = 0; i < n; i++){
        char op; int val; 
        cin >> op >> val; 
        if(op == '+' && val % 2 == 1) { s1++; conj_s1.insert({op, val}); }
        else if(op == '+' && val % 2 == 0) { s0++; conj_s0.insert({op, val}); }
        else if(op == '*' && val % 2 == 1) { s0++; conj_s0.insert({op, val}); }
        else if(op == '*' && val % 2 == 0) { p0++; conj_p0.insert({op, val}); }
    }
    
    int start_val;
    cin >> start_val;
    
    dp[0][0][0][0][0] = 1; 
    dp[0][1][0][0][0] = 0; 
    dp[1][0][0][0][0] = 0; 
    dp[1][1][0][0][0] = 1; 

    for(int k = 0; k <= s0; k++){
        for(int l = 0; l <= s1; l++){
            for(int m = 0; m <= p0; m++){
                if(k == 0 && l == 0 && m == 0) continue; 
                
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        int other = i ^ 1; 
                        bool win = false;
                        if(k >= 1 && dp[other][j][k-1][l][m] == 0) win = true;
                        if(l >= 1 && dp[other][j ^ 1][k][l-1][m] == 0) win = true;
                        if(m >= 1 && dp[other][0][k][l][m-1] == 0) win = true;
                        dp[i][j][k][l][m] = win;
                    }
                }
            }
        }
    }
    int curr_val = start_val % 2; 
    int my_role = dp[1][curr_val][s0][s1][p0] ? 1 : 0;
    if(my_role == 1) cout << "me" << endl;
    else cout << "you" << endl;

    int curr_player = 1; 
    for(int i = 0;i<n;i++){
        if(curr_player == my_role){
            int other = my_role ^1; 
            char op_jogada; int val_jogado;
            if(s0 > 0 && dp[other][curr_val][s0-1][s1][p0] == 0){
                auto it = conj_s0.begin();
                op_jogada = it->first; val_jogado = it->second;
                conj_s0.erase(it);
                s0--;
            } else if (s1 > 0 && dp[other][curr_val ^ 1][s0][s1-1][p0] == 0) {
                auto it = conj_s1.begin();
                op_jogada = it->first; val_jogado = it->second;
                conj_s1.erase(it);
                curr_val ^= 1;
                s1--;
            } else if(p0 > 0 && dp[other][0][s0][s1][p0-1] == 0) {
                auto it = conj_p0.begin();
                op_jogada = it->first; val_jogado = it->second;
                conj_p0.erase(it);
                curr_val = 0;
                p0--;
            }

            cout << op_jogada << " " << val_jogado << endl; // joga e da flush
        } else {
            char op;  int val; 
            cin >> op >> val; 
            if(op == '+' && val % 2 == 1) {
                conj_s1.erase({op, val}); s1--;
                curr_val ^= 1;
            } else if(op == '+' && val % 2 == 0) {
                conj_s0.erase({op, val}); s0--;
            } else if(op == '*' && val % 2 == 1) {
                conj_s0.erase({op, val}); s0--;
            } else if(op == '*' && val % 2 == 0) {
                conj_p0.erase({op, val}); p0--;
                curr_val = 0;
            }
        }
        curr_player ^= 1;
    }
    
    
            
        
    

    return 0;
}