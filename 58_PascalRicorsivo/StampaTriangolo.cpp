using namespace std;

#include "iostream"

int pascal(int, int);
void stampaTriangolo(int, int);

int main(int argc, char *argv[]){
    stampaTriangolo(atoi(argv[1]), 0);
    cout << endl;
	return 0;
}

void stampaTriangolo(int R, int C){
    if(R>0){
        if(C<=R){
            cout << pascal(R, C) << " ";
            stampaTriangolo(R, C+1);
        }
        else{
            cout << endl;
            C=0;
            R--;
            cout << pascal(R, C) << " ";
            stampaTriangolo(R, C+1);
        }
    }
}

int pascal(int r, int c){
    if(c==0 || r==c)
        return 1;
    else
        return pascal(r-1, c-1)+pascal(r-1, c);
}