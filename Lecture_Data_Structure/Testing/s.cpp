#include <iostream>
#include <string>
using namespace std;

class people{
private:
	bool gender;
	bool sexual_orientation;
	int age;
	int color;
	char Name[];
	string Country;
	people* father;
	people* mother;
	people* children[];


};

int main(){
	cout << "Hello world!" << endl;
	return 0;
}