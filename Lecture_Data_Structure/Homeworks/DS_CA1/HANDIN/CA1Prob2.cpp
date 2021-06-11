#include <iostream>
#include <string>

//showPrime function
using namespace std;

//isPrime function (I build it for a clean page and more easy to think)
bool isPrime(int n){
    if (n < 2) {return false;}
    if (n % 2 == 0) {return n == 2;}

    for (int i = 3; ; i += 2){
        if (i > n / i) {break;}
        if (n % i == 0) {return false;}
    }
    return true;
}

int* showPrime(int p){

    static int pp[2] = {0,0};
    if (isPrime(p) == true){
        pp[0] = p;
    }

    else{
        int i = 1;
        int j = 1;
        while(i > 0){
            pp[0] = p - i;
            if (isPrime(pp[0]) == true){
                break;
            }
            else{
                i = i+1;
            }
        }

        while(j > 0){
            pp[1] = p + j;
            if (isPrime(pp[1]) == true){
                break;
            }
            else{
                j = j+1;
            }
        }
    }
    return pp;
}
