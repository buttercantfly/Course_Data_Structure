#include <iostream>
#include "CA1Prob2.cpp"

using namespace std;

int main(){
    int input;
    cin >> input;
    int *test;
    test = showPrime(input);
    cout << test[0] << test[1];
    return 0;
}