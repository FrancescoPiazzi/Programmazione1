using namespace std;

#include "iostream"
#include "cmath"

int main(){
	double a, b, c;
    cin >> a >> b >> c;

    if(a==0 && b==0 && c==0){
        cout << "???" << endl;
        return 1;
    }
    if(a==0){
        if(b==0){
            cout << "Sorpresa sorpresa y=" << c << " non vale mai 0" << endl;
            return 2;
        }
        else{
            cout << b << "x" << c << -c/b;
            return 3;
        }
    }

    double delta = b*b-4.0*a*c;

    if(delta > 0){
        cout << a << "x^2" << b << "x" << c << " = " << 
            ((-1.0)*b+sqrt(delta))/(2.0*a) << " " << ((-1.0)*b-sqrt(delta))/(2.0*a);
    }
    else if(delta == 0){
        cout << a << "x^2" << b << "x" << c << " = " << 
            ((-1.0)*b+sqrt(delta))/(2.0*a);
    }
    else{
        cout << "Non ci sono soluzioni per questa equazione :(";
    }
    cout << endl;
    return 0;
}
