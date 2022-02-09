using namespace std;

#include "iostream"

#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main(){
    int n=30;
    int delay=10000;

	while (true){
        for(int i=0; i<n; i++){
            usleep(delay);
    		for(int j=0; j<=n-i; j++){
    			cout << " ";
    		}
    		for(int j=0; j<=i; j++){
    			cout << "* ";
    		}
    		cout << endl;
    	}
        for(int i=n; i>0; i--){
            usleep(delay);
    		for(int j=0; j<=n-i; j++){
    			cout << " ";
    		}
    		for(int j=0; j<=i; j++){
    			cout << "* ";
    		}
    		cout << endl;
    	}
    }
}
