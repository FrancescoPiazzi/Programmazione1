using namespace std;

#include "iostream"

int main(){
	int inizio;
	int fine;

	do{
		cin >> inizio >> fine;
	}while(inizio < (int)'a' || inizio >= (int)'z' ||
		fine <= (int)'a' || fine > (int)'z'||
		inizio > fine);

	for(int i=(int)inizio; i<=(int)fine; i++){
		cout << (char)i << " ";
	}

	cout << endl;
	return 0;
}
