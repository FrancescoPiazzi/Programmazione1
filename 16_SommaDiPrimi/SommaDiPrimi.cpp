using namespace std;

#include "iostream"

int main(){
	
    int n, n2=0, n3=0, sum=0;
    cin >> n;

    if(n<2){
        cout << "Non si può";
    }

    while(sum < n){
        if(sum+3==n){
            n3 = 1;
            sum += 3;
        }
        else{
            sum += 2;
            n2 += 1;
        }
    }

    for(int i=0; i<n2; i++){
        cout << "2 + "; 
    }
    if(n3) cout << "3";

    cout << endl;

	return 0;
}
