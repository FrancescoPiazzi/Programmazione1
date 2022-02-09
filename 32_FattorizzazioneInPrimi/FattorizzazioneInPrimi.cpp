using namespace std;

#include "iostream"

void fattorizzazione(int);
int prime(int, int);

int main(){
    int n;
    cin >> n;
    cout << n << " = ";
	fattorizzazione(n);
    cout << endl;
	return 0;
}

void fattorizzazione(int n){
    int primeN = prime(n, 2);
    
    if(primeN == 1){
        cout << n << "*";
    }
    else{
        fattorizzazione(n/primeN);
        fattorizzazione(primeN);
    }
}

int prime(int n, int m){
    if(m>n/2){
        return 1;
    }
    if(n%m==0){
        return m;
    }
    prime(n, m+1);

    return 1;  // Serve a silenziare il warning di g++
}
