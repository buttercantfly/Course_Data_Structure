#include <iostream>
#include <string>
#include "CA1Prob1.cpp"

using namespace std;

int main(){
    int a[10] = {-1,0,2,15,7,6,-4,8,21,-13};
    int b[10] = {5,9,-18,16,0,1,-4,18,-2,12};
    cout << dotProduct(a,b,10);
    return 0;
}