using namespace std;

#include "iostream"

long long int fattoriale(int n);

int main(){
    int n;
    cin >> n;
	cout << fattoriale(n) << endl;
	return 0;
}

long long int fattoriale(int n){
    return n==0 ? 1 : n*fattoriale(n-1);
}














































