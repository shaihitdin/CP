#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int r,R,h;
	cout<<"Enter radius\n";
	cin>>r;
	cout<<"Enter Radius\n";
	cin>>R;
	cout<<"Enter Height\n";
	cin>>h;
	double V , q , S;
	V=M_PI*h/3*(pow(R,2)+pow(r,2)+R*r);
	cout<<V<<endl;
	q =sqrt(pow(h,2)+pow((R-r),2));
	cout<<q<<endl;
	S= M_PI*q*(R+r)+M_PI*(pow(R,2)+pow(r,2));
	cout<<S<<endl;
	return 0;
	}
