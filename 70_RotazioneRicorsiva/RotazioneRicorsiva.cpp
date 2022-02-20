using namespace std;

#include <iostream>
#include <cstdlib>

void rotateLeft(char*, int, int, int, char);
void rotateLeftWrapper(char*, int, int);

int main(){
    int j, n;
    cin >> j >> n;
    srand(time(NULL));
    char* c = new char[n];
	
    for(int i=0; i<n; i++)
        c[i] = (rand()%('Z'-'A'+1))+'A';

    for(int i=0; i<n; i++)
        cout << c[i] << " ";
    cout << endl;

    rotateLeftWrapper(c, n, j);
    
    for(int i=0; i<n; i++)
        cout << c[i] << " ";
    cout << endl;

    delete[] c;
	return 0;
}

void rotateLeftWrapper(char* c, int size, int i){
    rotateLeft(c, size, i, 0, '.');
}

void rotateLeft(char* c, int size, int i, int pointer, char buffer){
    if(i>=0){
        if(pointer==0){
            char b=c[size-1];
            c[size-1] = c[0];
            rotateLeft(c, size, --i, size-1, b);
        }
        else{
            char b=c[pointer-1];
            c[pointer-1] = buffer;
            rotateLeft(c, size, i, pointer-1, b);
        }
        // rotateLeft(c, size, i--, 0, '0');
    }
    else{
        c[size-1] = buffer;
    }
    
}