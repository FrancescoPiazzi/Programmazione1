using namespace std;

#include "iostream"

float temperatura(float);
float peso(float);

int main(){
	int unita;
	float valore;

	cout << "Unità da convertire: \n 1)Temperatura\n 2)Peso\n 3)Volume\n 4)Lunghezza\n";
	cin >> unita;
	cout << "Valore: ";
	cin >> valore;
	
	cout << "Il valore convertito è ";
	switch(unita){
		case 1:
			cout << temperatura(valore);
			break;
		case 2:
			cout << peso(valore);
			break;
		case 3:
			cout << peso(valore);
			break;
		case 4:
			cout << peso(valore);
			break;

	}

	cout << endl;
	return 0;
}

float temperatura(float t){
	return (t-32.0)/1.8;
}

float peso(float t){
	return (t-32.0)/1.8;
}
