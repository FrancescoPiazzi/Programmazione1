using namespace std;

#include "iostream"

bool palindromo(int*, int, int);

int main(){
	int n;
    do{
        cout << "Inserire la lunghezza della sequenza (0-100): ";
        cin >> n;
    } while(n<0 || n>100);

    int *array = new int[n];

    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    cout << "La sequenza ";
    cout << (palindromo(array, 0, n-1) ? "è" : "non è");
    cout << " palindroma" << endl;

    delete[] array;
	return 0;
}

bool palindromo(int *array, int first, int last){
    if(last - first < 1)
        return true;
    else
        return (array[first]==array[last]) && palindromo(array, ++first, --last);
}