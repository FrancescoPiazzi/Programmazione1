#include "iostream"
#include "Strings.hpp"

using namespace std;

int main(){
    char buffer[256];
    cin >> buffer;

    cout << "Lunghezza totale: " << size(buffer) << endl;

    int size;
    int* sizes;
	char** splittedString = split(buffer, ',', size);

    cout << size << "sottostringhe: " << endl;

    for(int i=0; i<size; i++)
        cout << "  " << splittedString[i] << endl;

    for(int i=0; i<size; i++)
        delete[] splittedString[i];
    delete[] splittedString;

    cout << endl;
    cout << substringFrom(buffer, 2) << endl;
    cout << substringFromTo(buffer, 2, 5) << endl;
    cout << substringTo(buffer, 5) << endl;

	return 0;
}