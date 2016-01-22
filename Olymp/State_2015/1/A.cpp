#include<iostream>
#include<cmath>
using namespace std;
long long n;
int cnt;
bool v,u[111];
pair<long long,int>a[100];
int main()
{
    cin>>n;
    int i=2,x=sqrt(n),z=0;
    while(n!=1 && i<=x){
        if(n%i==0){
            n/=i;
            ++z;
        }
        if (n % i != 0 || n == 1) {
            if(z){
                a[cnt].first=i;
                a[cnt].second=z;
                z=0;
                ++cnt;
            }
            ++i;
        }
    }
    if(n > 1){
        a[cnt].first=n;
        a[cnt].second=1;
        ++cnt;
    }
    long long l,r,mul=1,sum=0;
    long long mx=0,q;
    for(i=0;i<cnt;++i){
        l=0;
        r=1;
        for(int j=1;j<=a[i].second;++j){
            r*=a[i].first;
        }
        while (r - l > 1) {
        	long long mid = (r + l) / 2, res = 0;
        	for (long long tmp = mid; tmp > 0; tmp /= a[i].first)
        		res += tmp / a[i].first;
        	if (res >= a[i].second)
        		r = mid;
        	else
        		l = mid;
        }
        mx = max (mx, r);
        /*
        q=(l+r)/2;
        while(!v){
            for(int j=1;mul<=q;++j){
                mul*=a[i].first;
                sum+=(q/mul);
            }
            if(sum==a[i].second || u[q]==1){
                mx=max(mx,q);
                break;
            }
            if(sum>a[i].second){
                u[q]=1;
                --q;
            }
            if(sum<a[i].second){
                u[q]=1;
                ++q;
            }
        }
        mul=1;
        sum=0;
        for(int j=1;j<=r;++j){
            u[j]=0;
        }
        */
    }
    cout<<mx;
    return 0;
}