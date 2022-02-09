using namespace std;

#include "iostream"
#include "cstdlib"

void initArray(int a[], int);
void printArray(int a[], int);

int main(){
    const int SIZE = 10;
    int a[SIZE];
    initArray(a, SIZE);
    printArray(a, SIZE);
    cout << endl;
}

void initArray(int a[], int size){
    srand(time(NULL));
    for(int i=0; i<size; i++)
        a[i]=rand()%100+1;
}

void printArray(int a[], int size){
    for(int i=0; i<size; i++)
        cout << a[i] << " ";
}
