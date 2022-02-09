using namespace std;

#include "iostream"
#include "cstdlib"

int *generateNumbers(int);

int main(){
    int n;
    cin >> n;
	
    int *array = generateNumbers(n);

    for(int i=0; i<n; i++)
        cout << array[i] << " ";
    
    cout << endl;
    delete[] array;
	return 0;
}

int *generateNumbers(int n){
    srand(time(NULL));
    int *array = new int[n];
    for(int i=0; i<n; i++)
        array[i] = rand() % 10 + 1;
    return array;
}