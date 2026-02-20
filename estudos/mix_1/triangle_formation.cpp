#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1991/F

bool eh_triangulo(int a, int b, int c) {
    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;
    return true;
}

bool dois_triangulos(int p0, int p1, int p2, int p3, int p4, int p5) {
    int p[6] = {p0, p1, p2, p3, p4, p5};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 6; k++) {
                int p2[3];
                int idx = 0;
                for (int m = 0; m < 6; m++) {
                    if (m != i && m != j && m != k) {
                        p2[idx++] = p[m];
                    }
                }
                if (eh_triangulo(p[i], p[j], p[k]) && eh_triangulo(p2[0], p2[1], p2[2])) {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(vector<int> &vetor){
    int l,r; cin >> l >> r; 
    if(r - l + 1 >= 48){
        cout << "Yes\n"; 
        return;
    } else { 
        vector<int> v;
        for(int i=l;i<=r;i++) v.push_back(vetor[i]);
        sort(v.begin(), v.end());
        // eu quero checar primeiro se tem 6 caras consecutivos que funcionam
        int tam = v.size();
        for(int i = 0; i + 5 < tam; i++){
            vector<int> perm; 
            for(int k = 0; k < 6; k++) perm.push_back(v[i+k]);
            
            if(dois_triangulos(v[i], v[i+1], v[i+2], v[i+3], v[i+4], v[i+5])) {
                cout << "Yes\n";
                return;
            }
        }
        // se passou até aqui então naõ tem dois caras consecutivos, então basta procurar pelos disjuntos
        int qntd = 0;
        for(int i = 0; i + 2 < tam; i++){
            if(eh_triangulo(v[i], v[i+1], v[i+2])){
                qntd++;
                i+=2;
            }
        }
        if(qntd >= 2) {
            cout << "Yes\n";
            return; 
        } else { 
            cout << "No\n";
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<int> vetor(n+1);
    for(int i=1;i<=n;i++){
        cin >> vetor[i];
    }
    while(q--){
        solve(vetor);
    }
    return 0;
}