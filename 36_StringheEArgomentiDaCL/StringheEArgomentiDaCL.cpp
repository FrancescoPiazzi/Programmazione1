using namespace std;

#include "iostream"

int main(int argc, char *argv[]){
    cout << "Cose passate da linea di comando: " << endl;

    for(int i=0; i<argc; i++)
        cout << i+1 << ") " << argv[i] << endl;

	char myString[255];
    cout << "Scrivi qualcosa: ";
    cin >> myString;

    cout << myString << endl;
	return 0;
}
