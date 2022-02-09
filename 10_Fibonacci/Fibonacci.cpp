using namespace std;

#include "iostream"

int main(){
	const int N = 10;
    unsigned long long int a=0, b=1;

    for(int i=0; i<N; i++){
        cout << a << endl;
        b += a;
        a = b-a;
    }

    cout << endl;
	return 0;
}