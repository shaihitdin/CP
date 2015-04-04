#include<iostream>
using namespace std;
int main()
{
    int n;
    string b[1000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=n;i<=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
