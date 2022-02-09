using namespace std;

#include "iostream"
#include "cmath"

void binario(int);

int main(){
    int n;
    cin >> n;
	binario(n);
    cout << endl;
	return 0;
}

void binario(int n){
    if(n==1){
        cout << "1";
        return;
    }
    binario(n/2);
    cout << n%2;
}
        
        
