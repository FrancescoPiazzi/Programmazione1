using namespace std;

#include "iostream"

int** generateMatrix(int, int);
int labirinto(int**, int, int, int, int, int, int);
bool isValid(int**, int, int, int, int);

int main(int argc, char *argv[]){
    int** matrix = generateMatrix(5, 5);
    cout << labirinto(matrix, 5, 5, 0, 0, 4, 4) << endl;
	return 0;
}

int labirinto(int** matrix, int R, int C, int startX, int startY, int endX, int endY){
    if(startX == endX && startY == endY)
        return 1;

    matrix[startX][startY] = 1;

    if(isValid(matrix, R, C, startX+1, startY))
        if(labirinto(matrix, R, C, startX+1, startY, endX, endY))
            return 1;
    if(isValid(matrix, R, C, startX, startY+1))
        if(labirinto(matrix, R, C, startX, startY+1, endX, endY))
            return 1;
    if(isValid(matrix, R, C, startX-1, startY))
        if(labirinto(matrix, R, C, startX-1, startY, endX, endY))
            return 1;
    if(isValid(matrix, R, C, startX, startY-1))
        if(labirinto(matrix, R, C, startX, startY-1, endX, endY))
            return 1;

    return 0;
}

bool isValid(int** matrix, int R, int C, int r, int c){
    return (r>=0 && r<R && c>=0 && c<C && matrix[r][c]==0);
}

void copyMatrix(int **m, int **m1, int R, int C){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            m1[i][j] = m[i][j];
        }
    }
}

int** generateMatrix(int R, int C){
    srand(time(NULL));
    int **m = new int*[R];
    for(int i=0; i<R; i++)
        m[i] = new int[C];

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            m[i][j] = (int)(rand()%3 == 0);
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return m;
}