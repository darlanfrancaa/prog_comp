#include <iostream>
#include <vector> 
using namespace std;
 
 
int main(){
	int n; cin >> n;
	string palavra;
	while (n > 0) {
		bool validador = false;
		cin >> palavra;
		for (int i = 0; i < palavra.size() - 1; i++) {
			if (palavra[i] == palavra[i + 1]) validador = true;
		}
		if (validador) cout << 1 << endl;
		else cout << palavra.size() << endl;
		n--;
	}
}
 