using namespace std;

#include <iostream>

int main(){
    int x=1;
    int y=10;
    int &z=x;

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;

    cout << "Incrementata x" << endl;
    x++;

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;

    cout << "Incrementata z" << endl;
    z++;

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;

    z = y;
    cout << "Assegnato z a y" << endl;

    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
}
