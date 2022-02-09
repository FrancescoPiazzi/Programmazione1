using namespace std;

#include "iostream"

double potenza(int, int);

int main(){
	int b, e;
    cin >> b >> e;
    cout << potenza(b, e) << endl;
	return 0;
}

double potenza(int b, int e){
    if(e==0)
        return 1;

    else if(e>0){
        if(e==1)
            return b;
        else
            return b*potenza(b, e-1);
    }
    else{
        if(e==-1)
            return 1.0/b;
        else
            return (1.0/b)*potenza(b, e+1);
    }     
}
