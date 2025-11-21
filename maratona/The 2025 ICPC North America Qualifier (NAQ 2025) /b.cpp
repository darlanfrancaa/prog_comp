#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int r; int c; 
bool dentro(int x, int y){ 
    bool a = (0 <= x && x < r);
    bool b = (0 <= y && y < c);
    return a && b;
}

struct Obj
{
    int i; 
    int j;
    int distancia; 
    int torre;
};

int di[4] = {1,0,-1,0};
int dj[4] = {0,-1,0,1};



signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> r >> c >> n; 
    queue<Obj> q; 
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        q.push({a,b,0,i+1});
    }
    vector<int> count[500][500];
    while(!q.empty()){
        auto [i,j,dist, torre] = q.front(); q.pop(); 
        // printf("estou na posicao   i %lld, j %lld , torre %lld\n", i, j , torre);
       
        if(count[i][j].size() == 0){
            count[i][j].push_back(torre);
        } 
        else if(count[i][j].size() == 1){
            if(count[i][j][0] == torre){
                continue;
            } else { 
                count[i][j].push_back(torre);
            }
        } else { 
            continue;
        }
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(count[i][j].empty()) cout << -1 << " ";
        //         else cout << count[i][j][0] << " ";
        // }
        // cout << "\n";
        // }
        for(int k = 0; k<4;k++){
            int xi = i + di[k]; 
            int xj = j + dj[k];
            if(dentro(xi,xj)){
                q.push({xi,xj,dist+1,torre});
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << count[i][j][0] << " ";
        }
        cout << "\n";
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << count[i][j][1] << " ";
        }
        cout << "\n";
    }
    return 0;
}