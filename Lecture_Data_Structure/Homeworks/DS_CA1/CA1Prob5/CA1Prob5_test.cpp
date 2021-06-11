#include <iostream>
#include <string>
#include "CA1Prob5.cpp"

using namespace std;

int main(){
    rectangle R1(2,4);
    cout << "Constructing rectangle R1......" << endl << endl;
    cout << "R1's width is "<< R1.getWidth() <<" and length is " << R1.getLength() << "." << endl;
    cout << "R1's parameter is "<< R1.getPerimeter() <<"." << endl;
    cout << "R1's area is "<< R1.getArea() <<"." << endl << endl;

    R1.setDimension(4,8);
    cout << "Setting rectangle R1's dimension to 4*8......" << endl << endl;
    cout << "R1's width is "<< R1.getWidth() <<" and length is " << R1.getLength() << "." << endl;
    cout << "R1's parameter is "<< R1.getPerimeter() <<"." << endl;
    cout << "R1's area is "<< R1.getArea() <<"." << endl << endl;

    R1.setLength(16);
    R1.setWidth(16);
    cout << "Setting rectangle R1's length and width to 16......" << endl << endl;
    cout << "R1's width is "<< R1.getWidth() <<" and length is " << R1.getLength() << "." << endl;
    cout << "R1's parameter is "<< R1.getPerimeter() <<"." << endl;
    cout << "R1's area is "<< R1.getArea() <<"." << endl << endl;

    cout << "Testing if R1 is a square......" << endl;
    cout << "(1 is true, 0 is false.)" << endl;
    cout << R1.isSquare();

    return 0;
}