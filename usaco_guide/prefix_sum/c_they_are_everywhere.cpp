    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    const int MOD = 1e9 + 7;

    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        int n; cin >> n; 
        string palavra; cin >> palavra;
        unordered_map <char, int> mapa;
        for(int i=0;i<n;i++) mapa[palavra[i]]++;
        int left = 0, right = 0; 
        unordered_map <char,int> mapa_atual;
        int distancia_atual = 0, ans = INT_MAX;
        while(right < n){
            mapa_atual[palavra[right]]++;
            while (left<right+1 && mapa_atual[palavra[left]] > 1) mapa_atual[palavra[left++]]--;
            distancia_atual = right - left + 1;
            if(mapa_atual.size() == mapa.size()) ans = min(ans, distancia_atual);
            right++;
        }
        cout << ans;
        return 0;
    }