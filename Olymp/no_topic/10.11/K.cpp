#include <iostream>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m;
    int a[n][m];
    k=0;
    for(int i=0; i<n; i++){
        if(i%2!=0){
            for(int j=m-1; j>=0; j--){
                a[i][j]=k;
                k++;
                }
            }
        if(i%2==0){
            for(int j=0; j<m; j++){
                a[i][j]=k;
                k++;
                }
            }
        }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
            }
        cout<<endl;
        }
    return 0;
}