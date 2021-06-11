#include <iostream>
#include <string>
#include "CA1Prob4.cpp"

using namespace std;

int main(){

    flower annelise("Annelise",5,10);
    cout << "Constructing flower annelise...... " << endl;
    cout << "The flower's name is: "<< annelise.getName() << "." << endl;
    cout << "The flower has "<< annelise.getPetal() << " petal(s)."<< endl;
    cout << "The flower's price is "<< annelise.getPrice() << "."<< endl << endl;

    annelise.setName("Samuel");
    cout << "Setting annelise's name as Samuel...... " << endl;
    cout << "The flower's name is: "<< annelise.getName() << "." << endl;
    cout << "The flower has "<< annelise.getPetal() << " petal(s)."<< endl;
    cout << "The flower's price is "<< annelise.getPrice() << "."<< endl << endl;

    annelise.setPetal(99);
    cout << "Setting annelise's petal to 99...... " << endl;
    cout << "The flower's name is: "<< annelise.getName() << "." << endl;
    cout << "The flower has "<< annelise.getPetal() << " petal(s)."<< endl;
    cout << "The flower's price is "<< annelise.getPrice() << "."<< endl << endl;

    annelise.setPrice(10000);
    cout << "Setting annelise's price to 10000...... " << endl;
    cout << "The flower's name is: "<< annelise.getName() << "." << endl;
    cout << "The flower has "<< annelise.getPetal() << " petal(s)."<< endl;
    cout << "The flower's price is "<< annelise.getPrice() << "."<< endl;

    return 0;
}