#include <iostream>
#include <vector> 
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 2 * 10 ^ 5 + 10;
 
 
int main(){
	int k; cin >> k;
	while (k > 0) {
		long long n,m; cin >> n >> m;
		vector<vector<int>> num (n,vector<int> (m));
		vector<long long> soma(n);
		vector<long long> razao(n);
		for(int i=0;i<n;i++){
		    for(int j=0;j<m;j++){
		        cin >> num[i][j];
		    }
		}
		for(int i=0;i<n;i++){
		   for(int j=0;j<m;j++){
		       razao[i] += m*num[i][j];
		       soma[i] += num[i][j]*(m-j);
		   }
		}
		sort(razao.begin(),razao.end());
		long long ans=0;
		for(int i=0;i<n;i++){
		    ans += soma[i] + razao[i]*i;
		}
		cout << ans << endl;
		k--; 
	}
}