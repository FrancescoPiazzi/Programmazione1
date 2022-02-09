using namespace std;

#include "iostream"

int divisione(int, int, int*);

int main(){
	int dividendo, divisore;
	int resto;
	cin >> dividendo >> divisore;

	int quoziente = divisione(dividendo, divisore, &resto);
	cout << "Quoziente: " << quoziente << " resto: " << resto <<  endl;

	return 0;
}

int divisione(int dividendo, int divisore, int *resto){
	int quoziente=0;
	while(dividendo >= divisore){
		dividendo -= divisore;
		quoziente++;	
	}
	*resto = dividendo;
	return quoziente;
}
