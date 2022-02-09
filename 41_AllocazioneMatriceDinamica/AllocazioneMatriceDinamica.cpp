using namespace std;

#include "iostream"
#include "cstdlib"

int ** generateMatrix(int, int);

int main(){
    int R, C;
    cin >> R >> C;
    int ** matrix = generateMatrix(R, C);

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    for(int i=0; i<R; i++)
        delete[] matrix[i];
    delete[] matrix;

	return 0;
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