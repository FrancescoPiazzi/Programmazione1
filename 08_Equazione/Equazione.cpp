using namespace std;

#include "iostream"
#include "cmath"

int main(){
	double a, b, c;
    cin >> a >> b >> c;
    double delta = b*b-4.0*a*c;

    if(a==0) {
        if(b!=0){
            cout << "Il delta doveva essere maggiore di zero ma ok, la soluzione è ";
            cout << -c/b;
        }
        else if(c==0){
            cout << "???";
        }
        else{
            cout << "Sorpresa sorpresa y=" << c << " non vale mai 0";
        }
        cout << endl;
    }
    else{
        if(delta > 0){
        cout << "(" << a << ")x^2 + (" << b << ")x + (" << c << ") = " << 
            ((-1.0)*b+sqrt(delta))/(2.0*a) << " " << ((-1.0)*b-sqrt(delta))/(2.0*a);
        }
        else if(delta == 0){
            cout << "(" << a << ")x^2 + (" << b << ")x + (" << c << ") = " << 
                ((-1.0)*b+sqrt(delta))/(2.0*a);
        }
        else{
            cout << "Non ci sono soluzioni per questa equazione :(";
        }
        cout << endl;
    }
    return 0;
}
