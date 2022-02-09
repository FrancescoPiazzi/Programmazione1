using namespace std;

#include "iostream"

int main(){
	float iva;
	float prezzo;

	cout << "Prezzo: ";
	cin >> prezzo;
	cout << "Iva: ";
	cin >> iva;
	cout.precision(2);
	cout << fixed;
	cout << "Prezzo + iva: " << prezzo + prezzo*iva/100.0 << endl;
	return 0;
}
