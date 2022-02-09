using namespace std;

#include "iostream"
#include "cstdlib"

void tiraDadi(int &, int &, int &);

int main(){
    int primo1=0, secondo1=0, terzo1=0, primo2=0, secondo2=0, terzo2=0;
    int punti1=0, punti2=0;

    tiraDadi(primo1, secondo1, terzo1);
    tiraDadi(primo2, secondo2, terzo2);

    cout << "Dadi dell'attaccante:\t" << primo1 << " " << secondo1 << " " << terzo1 << endl;
    cout << "Dadi del difensore:\t" << primo2 << " " << secondo2 << " " << terzo2 << endl;

    primo1 > primo2 ? punti1++ : punti2++;
    secondo1 > secondo2 ? punti1++ : punti2++;
    terzo1 > terzo2 ? punti1++ : punti2++;

    cout << "Vince " << (punti1 > punti2 ? "l'attaccante" : "il difensore") << endl;

	return 0;
}

void tiraDadi(int &primo, int &secondo, int &terzo){
    srand(time(NULL));

    for(int i=0; i<3; i++){
        int tiro = rand() % 6 + 1;
        if(tiro > primo){
            terzo = secondo;
            secondo = primo;
            primo=tiro;
        }
        else if(tiro > secondo){
            terzo = secondo;
            secondo=tiro;
        }
        else if(tiro > terzo){
            terzo=tiro;
        }
    }
}