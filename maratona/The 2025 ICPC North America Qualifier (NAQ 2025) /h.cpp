#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int GLOBAL_ID = 0;

struct Person{
    mutable int id;
    int qntd;
    double peso; 
    double distancia;
};

struct ComparePersonPeso{
    bool operator()(const Person &a, const Person &b) const {
        return a.peso < b.peso;
    }
};

struct ComparePersonDistancia
{
    bool operator()(const Person &a, const Person &b) const {
        if(abs(a.distancia != b.distancia) > 1e-9)
            return a.distancia < b.distancia;
        return a.id < b.id;
    }
};

Person merge(const Person &a, const Person &b){
    int qntd = a.qntd + b.qntd;
    double peso = ((a.peso * a.qntd) + (b.peso * b.qntd)) / qntd;
    double distancia = max(a.distancia, b.distancia);
    Person ret = {++GLOBAL_ID, qntd,peso, distancia};
    return ret;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // eu quero criar uma fila de prioridade em relação ao maior peso
    // e eu quero criar um set para eu saber quem é a proxima distância
    priority_queue<Person, vector<Person>,ComparePersonPeso> pq;
    set<Person, ComparePersonDistancia> s; 
    int n; cin >> n; 
    double delta = 0; 
    vector<pair<double,double>> entrada(n);
    for(int i=0;i<n;i++){
        cin >> entrada[i].first >> entrada[i].second;
        delta += entrada[i].first * entrada[i].second;
    }

    // apenas negativa tudo caso o delta seja maior que 0;
    if(delta > 0){
        delta = 0; 
        for(int i =0;i<n;i++){
            entrada[i].first = -entrada[i].first;
            delta += entrada[i].first * entrada[i].second;
        }
    }

    for(int i=0; i<n; i++){
        Person p = {++GLOBAL_ID, 1, entrada[i].second, entrada[i].first};
        pq.push(p);
        s.insert(p);
    }

    double total_dist = 0;


    while(delta < -1e-7){
        Person maior_peso = pq.top(); pq.pop();
        auto test = s.find(maior_peso);
        if(test == s.end()){
            continue; // Se um elemento não está no set, mas está na fila, podemos pular na fila pois isso quer dizer que já o retiramos.
        }
        if(s.upper_bound(maior_peso) == s.end()){
            // isso quer dizer que o maior peso está no final, então poderíamos movê-lo livremente:
            total_dist += abs(delta/maior_peso.peso);
            break;
        }
        Person next_dist = *s.upper_bound(maior_peso);
        double max_dist = next_dist.distancia - maior_peso.distancia;
        double peso_total_grupo = maior_peso.peso * maior_peso.qntd;
        double torque = max_dist * peso_total_grupo;

        if(torque + delta >= 0){
            // se é possível mover o maior peso e ganhar de delta, então eu movo apenas o necessário
            total_dist += abs(delta/maior_peso.peso);
            delta = 0;
        } else { 
            // caso contrário, eu ando o máximo possível, junto os dois e insiro na fila e no set
            delta += torque;
            total_dist += abs(max_dist * maior_peso.qntd);
            s.erase(maior_peso); s.erase(next_dist); // tiro os dois para depois inserir o merge deles dois;
            Person Merge = merge(next_dist, maior_peso);
            pq.push(Merge);
            s.insert(Merge);
        }
    }
    cout << fixed << setprecision(6) << total_dist << "\n";
    return 0;
}