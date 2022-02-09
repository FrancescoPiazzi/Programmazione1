using namespace std;

#include "iostream"

int main(){
    int h, m, s;
    cout << "Ore: ";
    cin >> h;
    cout << "Minuti: ";
    cin >> m;
    cout << "Secondi: ";
    cin >> s;
    cout << "Secondi a mezzanotte: " << 86400 - (h*3600+m*60+s) << endl;
    return 0;
}
