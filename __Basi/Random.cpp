using namespace std;

#include "iostream"
#include "cstdlib"

int main(){
	srand(time(NULL));
    cout << rand() % 6 + 1 << endl;
	return 0;
}
