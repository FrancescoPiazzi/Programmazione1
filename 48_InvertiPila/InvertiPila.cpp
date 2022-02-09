using namespace std;

#include "iostream"
#include "coda.hpp"
#include "pila.hpp"

int main(){
	init();
    coda_init();

    push(1);
    push(2);
    push(3);
    push(4);

    int value;

    while(top(value)){
        coda_enqueue(value);
        pop();
    }

    while(coda_first(value)){
        push(value);
        cout << value << endl;
        coda_dequeue();
    }

    cout << endl;

    deinit();
    coda_deinit();
	return 0;
}
