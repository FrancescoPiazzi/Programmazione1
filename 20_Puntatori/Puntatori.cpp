using namespace std;

#include <iostream>

int main(){
    int x=0;
    int y=0;

    int *px = &x;
    int *py = &y;

    cout << "Valore nell'indirizzo "<< px << ": " << *px << endl;
    cout << "Valore nell'indirizzo "<< py << ": " << *py << endl << endl;

    (*px)++;
    cout << "Incrementato di 1 il valore nell'indirizzo " << px << endl;

    cout << "Valore nell'indirizzo " << px << ": " << *px << endl << endl;

    *py = *px;
    cout << "Assegnato il valore in " << px << " a " << py << endl;

    cout << "Valore nell'indirizzo "<< px << ": " << *px << endl;
    cout << "Valore nell'indirizzo "<< py << ": " << *py << endl << endl;
}
