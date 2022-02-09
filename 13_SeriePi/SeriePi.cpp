using namespace std;

#include "iostream"
#include "cmath"

int main(){
	const int APPROSSIMAZIONE=50000;
    double pi=0.0;

    for(int i=1; i<APPROSSIMAZIONE; i++){
        pi += 1.0/(i*i);
    }

    cout.precision(10);
    cout << sqrt(pi*6.0) << endl;
	return 0;
}
