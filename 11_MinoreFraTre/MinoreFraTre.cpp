using namespace std;

#include "iostream"

int main(){
	float a, b, c;
    cin >> a >> b >> c;

    cout << ((a>b && b>c)||(a<=b && a>c))*c + (a>b && b<=c)*b + 
            (a<=b && a<=c)*a << endl;

    if (a>b){
        if(b>c)
            cout << c;
        else
            cout << b;
    }
    else{
        if(a>c)
            cout << c;
        else
            cout << a;
    }
    cout << endl;
	return 0;
}
