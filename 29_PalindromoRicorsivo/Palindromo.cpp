using namespace std;

#include "iostream"

bool palindromo(int);
int primaCifra(int);
int tagliaCifre(int);

int main(){
	cout << palindromo(121) << endl;
	return 0;
}

bool palindromo(int n){
    if(n<10){
        return true;
    }
    if(n%10!=primaCifra(n)){
        return false;
    }
    else{
        return true && palindromo(tagliaCifre(n));
    }
}

int primaCifra(int n){
    while(n>=10)
        n/=10;
    return n;
}

int tagliaCifre(int n){
    int m=0;
    n /= 10;
    while(n > 0){
        m+=n%10;
        m*=10;
        n/=10;
    }
    m/=100;
    return m;
}
