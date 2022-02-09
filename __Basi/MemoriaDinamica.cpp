using namespace std;

#include "iostream"
#include "cstdlib"

int *generateArray(int);
int ** generateMatrix(int, int);

int main(){	
    int* array = generateArray(10);
    delete[] array;

    int** matrix = generateMatrix(10, 5);
    for(int i=0; i<10; i++)
        delete[] matrix[i];
    delete[] matrix;

	return 0;
}

int *generateArray(int n){
    int *array = new int[n];
    for(int i=0; i<n; i++)
        array[i] = i*i;
    return array;
}

int **generateMatrix(int R, int C){
    srand(time(NULL));

    int **matrix = new int*[R];
    for(int i=0; i<R; i++)
        matrix[i] = new int[C];

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            matrix[i][j] = rand() % 10 + 1;

    return matrix;
}