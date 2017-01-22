#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[2*n+1][2*n+1];
    int p=(2*n+1)*(2*n+1) - 1;
    n = 2*n + 1;
    for(int k=0; k<2*n+1; k++){
        for(int i=k; i<n-k; i++){
            a[k][i]=p;
            p--;
            }
        for(int i=k+1; i<n-k; i++){
            a[i][n-k-1]=p;
            p--;
            }
        for(int i=n-2-k; i>=k; i--){
            a[n-1-k][i]=p;
            p--;
            }
        for(int i=n-2-k; i>k; i--){
            a[i][k]=p;
            p--;
            }
        }
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            cout<<a[j][i]<<" ";
                }
            cout<<endl;
            }
 
    return 0;
}