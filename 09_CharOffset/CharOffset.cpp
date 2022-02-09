using namespace std;

#include "iostream"

int main(){
    const int OFFSET=-32;
	char c;
    cout << "Inserisci un carattere: ";
    cin >> c;
    cout << "Il carattere + (" << OFFSET <<  ") posizioni è: " << (char)(c+OFFSET) << endl;
	return 0;
}
