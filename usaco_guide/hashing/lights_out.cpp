#include <bits/stdc++.h>
using namespace std;

#define int long long


struct HashPair{ 
    int hash, dist;
    bool operator==(const HashPair& other) const { return hash == other.hash && dist == other.dist; }
    bool operator!=(const HashPair& other) const { return !(*this == other); }
};

class HashedString{
private: 
    static const int M = (1LL << 61) - 1; 
    static const int B = 9973; 
    static vector<int> pow;
    vector<HashPair> p_hash; 

    int multimod(int a, int b){ return ((__int128)a * b) % M; }

public: 

    HashedString(const vector<int>& content, const vector<int> &distances) : p_hash(content.size()+1){
        if (pow.empty()) pow.push_back(1);
        while(pow.size() <= content.size()) pow.push_back(multimod(pow.back(), B));

        p_hash[0] = {0, 0};
        for(int i=0; i<content.size(); i++){
            int new_hash = (multimod(p_hash[i].hash, B) + content[i]) % M;
            int new_dist = p_hash[i].dist + distances[i]; 
            p_hash[i+1] = {new_hash, new_dist};
        }
    }

    HashPair get_hash(int start, int end){ 
        if (start > end) return {0, 0}; 
        int val_hash = p_hash[end+1].hash - multimod(p_hash[start].hash, pow[end-start+1]);
        val_hash = (val_hash + M) % M;
        int distancia = p_hash[end+1].dist - p_hash[start].dist;
        return {val_hash, distancia};
    }
};
vector<int> HashedString::pow;


struct Point { int x, y; };
int N;
vector<Point> P;
vector<int> edge_len; 
vector<int> dist_cw_to_exit; 

int get_min_dist(int idx, int perimeter) {
    int d_cw = dist_cw_to_exit[idx];
    int d_ccw = perimeter - d_cw;
    return min(d_cw, d_ccw);
}

signed main() {
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    P.resize(N);
    for(int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

    int perimeter = 0;
    edge_len.resize(N);
    vector<int> raw_node_types(N);

    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N;
        int prev = (i - 1 + N) % N;
        edge_len[i] = abs(P[next].x - P[i].x) + abs(P[next].y - P[i].y);
        perimeter += edge_len[i];

        if (i == 0) raw_node_types[i] = 0; 
        else {
            int dx1 = P[i].x - P[prev].x; int dy1 = P[i].y - P[prev].y;
            int dx2 = P[next].x - P[i].x; int dy2 = P[next].y - P[i].y;
            raw_node_types[i] = (dx1 * dy2 - dy1 * dx2 < 0) ? 1 : 2;
        }
    }

    vector<int> temp_dist(N+1, 0);
    for(int i=0; i<N; i++) temp_dist[i+1] = temp_dist[i] + edge_len[i];
    dist_cw_to_exit.resize(N);
    for(int i=0; i<N; i++) 
        dist_cw_to_exit[i] = (i==0 ? 0 : perimeter - temp_dist[i]);
    
    vector<int> v_types;     
    vector<int> v_dists;     
    
    vector<int> e_lengths;   
    vector<int> e_dists;     

    vector<int> map_original_idx; 

    for(int i=1; i<N; i++) { 
        map_original_idx.push_back(i);
        
        v_types.push_back(raw_node_types[i]);
        v_dists.push_back(0);

        e_lengths.push_back(edge_len[i]);
        e_dists.push_back(edge_len[i]);
    }

    v_types.push_back(raw_node_types[0]);
    v_dists.push_back(0);
    map_original_idx.push_back(0);

    HashedString hs_verts(v_types, v_dists);
    HashedString hs_edges(e_lengths, e_dists);

    int max_extra_cost = 0;
    int path_len = v_types.size();


    for(int i = 0; i < path_len - 1; i++) {
        int start_node_orig = map_original_idx[i];
        
        for(int k = 0; i + k < path_len; k++) {
            
            HashPair h_v = hs_verts.get_hash(i, i + k);
            HashPair h_e = hs_edges.get_hash(i, i + k - 1);
            
            int matches = 0;
            
            for(int j = 0; j < path_len - 1; j++) {
                if(i == j) { matches++; continue; }
                
                if(j + k < path_len) {
                    HashPair other_v = hs_verts.get_hash(j, j + k);
                    HashPair other_e = hs_edges.get_hash(j, j + k - 1);
                    
                    if(h_v == other_v && h_e == other_e) {
                        matches++;
                    }
                }
            }

            int current_idx_in_vec = i + k;
            int current_node_val = v_types[current_idx_in_vec];

            if (current_node_val == 0) {
                int dist_walked = h_e.dist; 
                int optimal_orig = get_min_dist(start_node_orig, perimeter);
                max_extra_cost = max(max_extra_cost, dist_walked - optimal_orig);
                break;
            }

            if (matches == 1) {
                int dist_walked = h_e.dist;
                int current_node_orig = map_original_idx[current_idx_in_vec];
                
                int optimal_rem = get_min_dist(current_node_orig, perimeter);
                int optimal_orig = get_min_dist(start_node_orig, perimeter);
                
                max_extra_cost = max(max_extra_cost, (dist_walked + optimal_rem) - optimal_orig);
                break;
            }
        }
    }

    cout << max_extra_cost << endl;

    return 0;
}