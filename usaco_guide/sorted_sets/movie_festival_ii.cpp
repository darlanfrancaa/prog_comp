#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Movie{ 
    int start, end;
};

struct CompareMovie{
    bool operator()(Movie &a, Movie &b){
        return a.end < b.end;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n , k; cin >> n >> k; 
    vector<Movie> movies;
    multiset<int> membros;
    for(int i=0;i<n;i++){
        int begin, end; cin >> begin >> end; 
        movies.push_back({begin,end});
    }
    sort(movies.begin(), movies.end() , CompareMovie()); 
    for(int i=0;i<k;i++){
        membros.insert(0);
    }
    int contador = 0;
    for(auto &movie: movies){
        auto it = membros.upper_bound(movie.start);
        if(it != membros.begin()){
            --it; 
            membros.erase(it);
            membros.insert(movie.end);
            contador++;
        }
    }
    cout << contador << "\n";
    return 0;
}