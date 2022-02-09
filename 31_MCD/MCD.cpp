using namespace std;

#include "iostream"

int MCD(int, int);

int main(){
	int m, n;
    cin >> m >> n;
    
    cout << MCD(m, n) << endl;
    
	return 0;
}

int MCD(int m, int n){
    if(m%n == 0){
        return n;
    }
    return MCD(n, m%n);
}
