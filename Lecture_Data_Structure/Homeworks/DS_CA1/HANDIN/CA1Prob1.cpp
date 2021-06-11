/**
*  @author      Samuel You
*  @ID          b08505018
*  @Department  Engineering Science and Ocean Engineering
*  @Affiliation National Taiwan University
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dotProduct(int a[],int b[],int n){
    int k(0);
    int i;
    for (i=0 ;i<n ;i++ ){
        k = k + a[i]*b[i];
    }
    return k;
};