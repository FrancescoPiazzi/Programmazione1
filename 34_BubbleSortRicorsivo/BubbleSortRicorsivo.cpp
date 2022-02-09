using namespace std;

#include "iostream"
int n=0;
void bubbleSort(int[], int, int, int);
void bubbleSortWrapper(int[], int);

int main(){
	int a[] = {2, 3, 5, 1, 6, 0, 11, 12, 13, 14, 23, 41, 3, 65, 32, 112};

    for(int i=0; i<16; i++){
        bubbleSortWrapper(a, i);
        for(int j=0; j<i; j++){
            cout << a[j] << " ";
        }
        cout << endl;
        cout << i << "->" << n << endl << endl;
        n=0;
    }
	return 0;
}

void bubbleSortWrapper(int a[], int size){
    bubbleSort(a, 0, size, 0);
}

void bubbleSort(int a[], int index, int size, int iterations){
    n++;
    if(a[index] > a[index+1]){
        int t;
        t = a[index];
        a[index] = a[index+1];
        a[index+1] = t;
    }
    if(index<size-2){
        bubbleSort(a, index+1, size, iterations);
    }
    if(iterations < size){
        bubbleSort(a, 0, size-1, iterations+1);
    }
}
