using namespace std;

#include "iostream"

int main(){
    int b, e, n;
    cin >> b >> e;
    n=b;

    for(int i=0; i<e; i++){
        cout << n << "  ";
        n *= b;
    }
    cout << endl;
	return 0;
}
