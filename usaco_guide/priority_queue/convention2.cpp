#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Cow
{
    int chegada, tempo, idx;
};

struct ComparebyIdx 
{
   bool operator()(const Cow& a, const Cow& b){
    return a.idx > b.idx;
   } 
};

struct ComparebyChegada 
{
   bool operator()(const Cow& a, const Cow& b){
    return a.chegada < b.chegada;
   } 
};



int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<Cow> vacas(n);
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b; 
        vacas[i].chegada = a;
        vacas[i].tempo = b;
        vacas[i].idx = i;
    }
    sort(vacas.begin(),vacas.end(),ComparebyChegada());
    int k = 0, tempo = 0, maximo = INT_MIN;
    priority_queue<Cow, vector<Cow> , ComparebyIdx> pq; 
    pq.push(vacas[k++]);
    while(k<n || !pq.empty()){
        Cow atual = pq.top(); pq.pop();
        tempo = max(tempo, atual.chegada); //tempo esta armazenando quando que a vaca comecou de verdade, que pode ser tanto no tempo da sua chegada, ou quando a ultima saiu.
        maximo = max(maximo, tempo - atual.chegada); //aqui seria o tempo total de espera dela e o maximo calcula o maximo
        tempo += atual.tempo; // aqui armazena o tempo exato em que ela saiu
        while(vacas[k].chegada <= tempo && k < n) pq.push(vacas[k++]); //se ela chegou antes de acabar coloca ela na queue com a prioridade pelo idx

        if(pq.empty() && k<n) pq.push(vacas[k++]);
    }
    cout << maximo << endl;
    return 0;
}