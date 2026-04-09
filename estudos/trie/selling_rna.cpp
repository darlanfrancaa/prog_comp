#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://oj.uz/problem/view/JOI16_selling_rna

int char_int(char c){
    if(c == 'A') return 0; 
    if(c == 'C') return 1; 
    if(c == 'G') return 2; 
    if(c == 'U') return 3;
    return 0; 
}

struct Trie{
    vector<array<int,4>> next; 
    vector<int> tin, tout;
    int timer; 
    Trie(){
        next.push_back({-1,-1,-1,-1});
        tin.push_back(0);
        tout.push_back(0);
        timer = 0;
    }

    int add(const string &s){
        int u = 0; 
        for(char c: s){
            int v = char_int(c);
            if(next[u][v] == -1){
                next[u][v] = next.size(); 
                next.push_back({-1,-1,-1,-1});
                tin.push_back(0);
                tout.push_back(0);
            }
            u = next[u][v];
        }
        return u;
    }

    int get_node(const string& s){
        int u = 0; 
        for(char c: s){
            int v = char_int(c);
            if(next[u][v] == -1) return -1; 
            u = next[u][v];
        }
        return u;
    }

    void dfs(int u = 0){
        tin[u] = ++timer;
        for(int i=0;i<4;i++){
            if(next[u][i] != -1){
                dfs(next[u][i]);
            }
        }
        tout[u] = timer;
    }
};

struct BIT{
    int n; 
    vector<int> tree;
    BIT(int n) : n(n), tree(n+1,0) {}

    void add(int i, int delta){
        for(; i<=n; i += i & -i) tree[i] += delta;
    }

    int query(int i){
        int sum = 0;
        for(; i>0; i -= i & -i) sum += tree[i];
        return sum;
    }

    int query(int a, int b){
        if(a > b) return 0;
        return query(b) - query(a-1);
    }
};

struct Query{ 
    int x, y1,y2, id, pos; 
    bool operator<(const Query& other) const { 
        return x < other.x;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    Trie pref, suff; 
    vector<int> end_pref(n), end_suf(n);

    for(int i=0;i<n;i++){
        string s; cin >> s;
        end_pref[i] = pref.add(s);
        string reverse_s = s;  
        reverse(reverse_s.begin(), reverse_s.end());
        end_suf[i] = suff.add(reverse_s);
    }
    pref.dfs(); suff.dfs();
    vector<vector<int>> ord_x(pref.timer + 1);
    for(int i=0;i<n;i++){
        int x = pref.tin[end_pref[i]];
        int y = suff.tin[end_suf[i]];
        ord_x[x].push_back(y);
    }
    vector<Query> queries;
    vector<int> ans(m, 0);

    for(int j=0;j<m;j++){
        string p,q; cin >> p >> q; 
        reverse(q.begin(), q.end());
        int u = pref.get_node(p);
        int v = suff.get_node(q);
        if(u == -1 || v == -1){
            ans[j] = 0; 
            continue;
        }

        int x1 = pref.tin[u], x2 = pref.tout[u];
        int y1 = suff.tin[v], y2 = suff.tout[v];
        queries.push_back({x1 -1, y1,y2, j, -1});
        queries.push_back({x2, y1,y2, j, 1});
    }

    sort(queries.begin(), queries.end());
    BIT bit(suff.timer+1);
    int idx_query = 0; 

    for(int x = 0; x <= pref.timer; x++){
        for(int y : ord_x[x]){
            bit.add(y,1);
        }
        while(idx_query <queries.size() && queries[idx_query].x == x){
            auto q = queries[idx_query];
            int qntd = bit.query(q.y1, q.y2);
            ans[q.id] += qntd * q.pos;
            idx_query++;
        }
    }

    for(int j=0;j<m;j++){
        cout << ans[j] << "\n";
    }


    return 0;
}