using namespace std;

#include <iostream>

int main(){
    int n;
    bool sommaTrovata=false;
    cin >> n;

    for(int p1=2; p1<n && !sommaTrovata; p1++){     // Per tutti i numeri p1 da 2 a n
        bool isP1Prime = true;
        for(int i=2; i<=p1/2 && isP1Prime; i++){    // Faccio i conti per sapere se è primo
            if(p1%i==0){
                isP1Prime = false;
            }
        }
        if(isP1Prime){
            // In questo blocco so che p1 è primo, cerco un primo p2 | p1+p2=n
            for(int p2=2; p2<n && !sommaTrovata; p2++){     // Per tutti i numeri p2 da 2 a n
                bool isP2Prime = true;
                for(int i=2; i<=p2/2 && isP2Prime; i++){    // Faccio i conti per sapere se è primo
                    if(p2%i==0){
                        isP2Prime = false;
                    }
                }
                if(isP2Prime && p1+p2==n){      // Se anche p2 è primo vedo se la loro somma fa n
                    sommaTrovata = true;
                    cout << p1 << " + " << p2 << " = " << n << endl;
                }
            }
        }
    }
    if(!sommaTrovata)
        cout << "Non esistono due numeri primi che sommati sono uguali a " << n << endl;
}
