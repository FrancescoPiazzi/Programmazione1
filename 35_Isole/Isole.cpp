using namespace std;

#include "iostream"
#include "cstdlib"

const int ROWS=10;
const int COLS=10;

void init(bool[ROWS][COLS]);
int isole(bool[ROWS][COLS]);
int checkIsola(bool[ROWS][COLS], int, int);
bool checkEsistente(int, int);
void print(bool[ROWS][COLS]);

int main(){
	bool a[ROWS][COLS];
    init(a);
    print(a);
    cout << endl;
    cout << isole(a);
    cout << endl;
	return 0;
}

void init(bool a[ROWS][COLS]){
    srand(time(NULL));
    for (int i=0; i<ROWS; i++)
        for(int j=0; j<COLS; j++)
            a[i][j] = (rand()%4 == 0);
}

int isole(bool a[ROWS][COLS]){
    int nIsole = 0;

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(a[i][j]){
                nIsole += checkIsola(a, i, j);
            }
        }
    }

    return nIsole;
}

int checkIsola(bool a[ROWS][COLS], int i, int j){
    bool isola = true;

    // Il secondo controllo non fa crashare il programma
    // quando lavora sui bordi della matrice per via della lazy evaluation
    if(checkEsistente(i-1, j-1) && a[i-1][j-1]) isola = false;
    if(checkEsistente(i-1, j) && a[i-1][j]) isola = false;
    if(checkEsistente(i-1, j+1) && a[i-1][j+1]) isola = false;

    if(checkEsistente(i, j-1) && a[i][j-1]) isola = false;
    if(checkEsistente(i, j+1) && a[i][j+1]) isola = false;

    if(checkEsistente(i+1, j-1) && a[i+1][j-1]) isola = false;
    if(checkEsistente(i+1, j) && a[i+1][j]) isola = false;
    if(checkEsistente(i+1, j+1) && a[i+1][j+1]) isola = false;

    return int(isola);
}

bool checkEsistente(int i, int j){
    return (i>=0 && i<ROWS && j>=0 && j<COLS);
}

void print(bool a[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            cout << int(a[i][j]) << " ";
        }
        cout << endl;
    }
}