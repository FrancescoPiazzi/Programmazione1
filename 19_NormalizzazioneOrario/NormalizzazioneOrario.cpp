using namespace std;

#include "iostream"

void normalizza(int *h, int *m, int *s);

int main(){
	int h, m, s;
    cin >> h >> m >> s;

    normalizza(&h, &m, &s);

    cout << h << " " << m << " " << s << endl;
    
	return 0;
}

void normalizza(int *h, int *m, int *s){
    while(*s >= 60){
        *m++;
        *s -= 60;
    }
    while(*m >= 60){
        *h++;
        *m -= 60;
    }
    
    return;
}
