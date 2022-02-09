using namespace std;

#include <iostream>

int main(){
    const int x=1;
    const int* px=&x;  // Puntatore variabile a costante

    int y=2;
    int* const py=&y;  // Puntatore costante a variabile

    const int z=3;
    const int* const pz = &z; // Const pointer to const int

    px = &y;        // OK
    // *px = 2;     // KO

    // py = &x;     // KO
    *py = 2;        // OK

    // pz = &z;     // KO
    // *pz = 2;     // KO

    cout << "La parte interessante del programma è quando si compila o no,"
         << " gli output sono solo perchè il compilatore non rompa" << endl;

    cout << "Valore nell'indirizzo "<< px << ": " << x << endl;
    cout << "Valore nell'indirizzo "<< py << ": " << y << endl;
    cout << "Valore nell'indirizzo "<< pz << ": " << z << endl;

}
