#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int a,b;
	cin>>a>>b;
	double A,G;
	A=(a+b)/2;
	cout<<"Arithmetic mean "<<A<<endl;
	G=sqrt(a*b);
	cout<<"Geometric mean "<<G<<endl;
	return 0;
	}
