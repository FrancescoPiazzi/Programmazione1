using namespace std;

#include "iostream"

int main(){
    int n;
    bool primo=true;

	cin >> n;

    if(n==1 || n==0){
        primo = false;
    }
    else{
        for(int i=2; i<n/2 && primo; i++){
            if(n%i==0){
                primo=false;
            }
        }
    }
    
    cout << "Il numero " << (primo ? "è" : "non è");
    cout << " primo" << endl;
	return 0;
}
