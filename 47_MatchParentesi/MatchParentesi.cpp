using namespace std;

#include "iostream"

bool checkParentesi(char[], int);

int main(){
	char parentesi1[] = {'(', '(', ')', '(', ')', ')', '(', ')'};
    char parentesi2[] = {'(', '(', '(', '(', '(', ')', '(', ')'};
    char parentesi3[] = {')', '(', ')', '(', ')', ')', '(', ')'};

    cout << checkParentesi(parentesi1, 8) << endl;
    cout << checkParentesi(parentesi2, 8) << endl;
    cout << checkParentesi(parentesi3, 8) << endl;
    
	return 0;
}

bool checkParentesi(char parentesi[], int length){
    int parentesiAperte = 0;
    bool formulaCorretta = true;

    for(int i=0; i<length && formulaCorretta; i++){
        parentesi[i] == '(' ? parentesiAperte++ : parentesiAperte--;
        if(parentesiAperte < 0)
            formulaCorretta = false;
    }
    if(parentesiAperte != 0)
        formulaCorretta = false;

    return formulaCorretta;
}