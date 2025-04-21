#include <iostream>
#include <vector> 
using namespace std;
 
 
int main(){
	int n; cin >> n;
	string palavra;
	while (n > 0) {
		cin >> palavra;
		palavra.pop_back(); palavra.pop_back();
		palavra.push_back('i');
		cout << palavra << endl;
		n--;
	}
}
 