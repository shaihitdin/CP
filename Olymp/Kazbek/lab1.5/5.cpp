#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int a,b,c;
	cin>>a>>b;
	c = sqrt (pow (a, 2) + pow (b, 2));
	cout<<"Hypotenuse is "<<c<<endl;
	double A;
	A=a*b/2;
	cout<<"Area is "<<A<<endl;
	return 0;
	}