using namespace std;

#include "iostream"

void sommaDiDuePrimi(int);
bool primo(int);

int main(){
    int n;
	cin >> n;
    sommaDiDuePrimi(n);
    cout << endl;
	return 0;
}

void sommaDiDuePrimi(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i+j==n && primo(i) && primo(j))
                cout << i << " + " << j << " = " << n << endl;
        }
    }
}

bool primo(int n){
    bool primo=true;

    if(n==1 || n==0){
        primo = false;      // qui ci andrebbe un return ma non si possono usare :)
    }
    else{
        for(int i=2; i<=n/2 && primo; i++){
            if(n%i==0){
                primo = false;    // qui ci andrebbe un return ma non si possono usare :)
            }
        }
    }

    return primo;
}