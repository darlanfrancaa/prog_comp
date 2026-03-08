#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int dr[] = {0,1,1,-1};
const int dc[] = {1,0,1,-1};

vector<int> build_freq(const string &s){
    vector<int> freq(26,0);
    for(char c: s){
        freq[c]++;
    } 
    return freq;
}

void find_anag(const string& word, const vector<string>& grid, vector<vector<int>> &ans, int R, int C){
    int len = word.size();
    vector<int> word_freq = build_freq(word);
    vector<vector<bool>> used(R, vector<bool>(C,false));
    for(int r=0; r<R; r++){
        for(int c=0;c<C;c++){
            for(int d=0; d<4;d++){
                int end_r = r + (len-1) * dr[d];
                int end_c = c + (len-1) * dc[d];
                if (end_r >= 0 && end_r < R && end_c >= 0 && end_c < C) {
                    vector<int> freq_jan(26,0);
                    for(int k=0; k<len;k++){
                        freq_jan[grid[r + k * dr[d]][c + k * dc[d]]]++;
                    }
                    if(word_freq == freq_jan){
                        for(int k=0;k<len;k++){
                            used[r + k*dr[d]][c + k * dc[d]] = true;
                        }
                    }
                }
            }
        }
    }
    for (int r=0; r<R; r++) {
        for (int c=0; c < C; c++) {
            if (used[r][c]) {
                ans[r][c]++;
            }
        }
    }
}

void solve(){
    int R,C;
    cin >> R >> C; 
    vector<string> grid(R);
    for(int i=0;i<R;i++){
        cin >> grid[i];
    }
    int N; cin >> N;
    vector<string> words(N);
    for(int i=0;i<N;i++){
        cin >> words[i];
    }
    vector<vector<int>> ans(R,vector<int>(C,0));
    for(const string& w: words){
        find_anag(w,grid,ans,R,C);
    }
    int resp = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (ans[r][c] >= 2) {
                resp++;
            }
        }
    }

    cout << resp << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}