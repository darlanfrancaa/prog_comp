#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

int kadane(vector<int> v){
    // a ideia é fazer uma função que dado o vetor retorna o valor máximo da soma de um subarry contíguo
    int n = v.size();
    int soma_max = 0; 
    int curr_soma = 0;
    for(int i=0;i<n;i++){
        curr_soma = curr_soma + v[i];
        if(curr_soma < 0) curr_soma = 0; 
        soma_max = max(curr_soma, soma_max);
    }
    return soma_max;
}

vector<pair<int,int>> v_clock = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // D B E C
vector<pair<int,int>> v_anti_clock = {{0,-1}, {-1,0}, {0,1}, {1,0}}; // C E B D 

vector<int> spiral(vector<vector<int>> &matrix, int i, int j, int idx_dir, vector<pair<int,int>> &orientation) {
    vector<int> ans;
    int n = matrix.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[i][j] = true;
    ans.push_back(matrix[i][j]);
    
    int contador = 1;
    int curr_i = i, curr_j = j;
    
    while(contador < n * n){
        int next_i = curr_i + orientation[idx_dir].first;
        int next_j = curr_j + orientation[idx_dir].second;
        
        if(0 <= next_i && next_i < n && 0 <= next_j && next_j < n && !visited[next_i][next_j]) {
            contador++;
            ans.push_back(matrix[next_i][next_j]);
            curr_i = next_i;
            curr_j = next_j;
            visited[next_i][next_j] = true;
        } 
        else idx_dir = (idx_dir + 1) % 4;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> v; 
    int ans = LLONG_MIN;
    v = spiral(matrix, 0, 0, 0, v_clock);
    ans = max(ans, kadane(v));
    v = spiral(matrix, n-1, 0, 1, v_clock);
    ans = max(ans, kadane(v));
    v = spiral(matrix, n-1, n-1, 2, v_clock);
    ans = max(ans, kadane(v));
    v = spiral(matrix, 0,n-1, 3, v_clock);
    ans = max(ans, kadane(v));

    v = spiral(matrix, 0, 0, 2, v_anti_clock);
    ans = max(ans, kadane(v));
    v = spiral(matrix, 0, n-1, 3, v_anti_clock);
    ans = max(ans, kadane(v));
    v = spiral(matrix, n-1, n-1, 0, v_anti_clock);
    ans = max(ans, kadane(v));
    v = spiral(matrix, n-1, 0, 1, v_anti_clock);
    ans = max(ans, kadane(v));

    cout << ans << "\n";

    return 0;
}