using namespace std;

#include "iostream"

int main(){
  string n;

  cin >> n;

  cout << ((n == "ciao")?
	   ("Hai scritto ciao"):
	   ("Hai scritto qualcosa che non è ciao")) << endl;
  /*if(n == "ciao")
    cout << "Hai scritto una c :D" << endl;*/
  
  cout << "Flag fail: " << cin.fail() << endl;
  cout << "Valore letto: " << n << endl;

  return 0;
}
