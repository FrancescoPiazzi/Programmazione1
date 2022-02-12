using namespace std;

#include <iostream>
#include <cstdlib>

void fill(int[10][10], int[10][10]);
void print(int[10][10]);
int isole(int[10][10], int[10][10]);
int checkIsola(int[10][10], int[10][10], int, int);
void setStartEnd(int, int, int &, int &, int &, int &);
void copyMatrix(int[10][10], int[10][10]);

int main(int argc, char *argv[]){
    int m[10][10];
    int m2[10][10];

    fill(m, m2);
    print(m);

    cout << isole(m, m2) << endl;

	return 0;
}

int isole(int m[10][10], int m2[10][10]){
    int nIsole = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(m[i][j] && m2[i][j]!=2){
                nIsole += checkIsola(m, m2, i, j);
            }
        }
    }
    return nIsole;
}

int checkIsola(int m[10][10], int m2[10][10], int row, int col){
    bool isola = false;
    m2[row][col] = 1;
    int m1[10][10];
    copyMatrix(m, m1);

    while(!isola){
        // definisco il contorno della cella
        int rowStart, rowEnd, colStart, colEnd;
        setStartEnd(row, col, rowStart, rowEnd, colStart, colEnd);

        isola = true;
        for(int i=rowStart; i<=rowEnd; i++){
            for(int j=colStart; j<=colEnd; j++){
                if(m1[i][j] && !(i==row && j==col)){
                    if(m2[i][j]==2){    // il vicino è un'altra isola
                        m2[row][col] = 2;
                        return 0;   // uscire da 3 cicli è un casino
                    }
                    else{   // il vicino è una terra inesplorata
                        m2[i][j] = 1;
                        m1[row][col] = 0;

                        row = i;
                        col = j;
                        isola = false;
                    }
                }
            }
        }
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(m2[i][j] == 1){
                m2[i][j] = 2;
            }
        }
    }

    return 1;
}

void setStartEnd(int row, int col, int &rowStart, int &rowEnd, int &colStart, int &colEnd){
    rowStart = (row-1) >= 0 ? row-1 : 0;
    rowEnd = (row+1) < 10 ? row+2 : 10;
    colStart = (col-1) >= 0 ? col-1 : 0;
    colEnd = (col+1) < 10 ? col+2 : 10;
    rowEnd--;
    colEnd--;
}

void copyMatrix(int m[10][10], int m1[10][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            m1[i][j] = m[i][j];
        }
    }
}

void fill(int m[10][10], int m2[10][10]){
    srand(time(NULL));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            m[i][j] = (int)(rand()%4 == 0);
            m2[i][j] = 0;
        }
    }
}


void print(int m[10][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}