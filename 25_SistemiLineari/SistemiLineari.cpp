using namespace std;

#include <iostream>

void reduce(float[3][4]);
void order(float[3][4]);
void dictSort(int[3], float[3][4]);
void swap(int[3], float[3][4], int, int);
void print(float[3][4]);

const int SIZE=3;

int main(){
    float a[SIZE][SIZE] = {{1, 1, 1}, {2, 2, 5}, {4, 6, 8}};
    float b[SIZE] = {4, 11, 24};

    float ab[SIZE][SIZE+1] = {
        {a[0][0], a[0][1], a[0][2], b[0]},
        {a[1][0], a[1][1], a[1][2], b[1]},
        {a[2][0], a[2][1], a[2][2], b[2]}
    };

    print(ab);
    
    // while !isMatrixReduced()
    reduce(ab);
    order(ab);

    cout << endl;
    print(ab);

    return 0;
}

void reduce(float a[SIZE][SIZE+1]){ // int start
    for(int i=1; i<SIZE; i++){  // i=start+1
        float e = -1.0 * a[i][0]/a[0][0];
        for(int j=0; j<SIZE+1; j++){    //j=start
            a[i][j] += a[0][j]*e;
        }
    }
}

void order(float a[SIZE][SIZE+1]){
    int zeroes[SIZE];
    for(int i=0; i<SIZE; i++){
        zeroes[i] = 0;
        for(int j=0; j<SIZE && a[i][j]==0; j++)
            zeroes[i]++;
    }
    dictSort(zeroes, a);
}

void dictSort(int key[SIZE], float matrix[SIZE][SIZE+1]){
    for(int i=0; i<SIZE; i++)
        for(int j=i+1; j<SIZE; j++)
            if(key[i] > key[j])
                swap(key, matrix, i, j);
}

void swap(int key[SIZE], float matrix[SIZE][SIZE+1], int i, int j){
    int tmp = key[i];
    key[i] = key[j];
    key[j] = tmp;

    for(int k=0; k<SIZE+1; k++){
        float tmp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = tmp;
    }
}

void print(float a[SIZE][SIZE+1]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE+1; j++){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
