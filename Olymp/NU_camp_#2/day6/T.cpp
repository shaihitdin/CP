#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a,b,ans_a,ans_b,time_a,time_b;
int main() {
	scanf("%d %d",&a,&b);            
	if (a<b) {                              
		for (time_b=b; ;) {                          
			if (time_a+a<time_b) ans_a+=a, time_a+=a;
			else
			if (time_a+a>time_b) ans_b+=time_b-time_a, time_a+=a, ans_a+=time_a-time_b, time_b+=b;
			else                                
			if (time_a+a==time_b) {
				ans_b+=time_b-time_a; break;
			}	                           
		}
	}
	else {
		swap(a,b);                           
		for (time_b=b; ;) {                          
			if (time_a+a<time_b) ans_a+=a, time_a+=a;
			else
			if (time_a+a>time_b) ans_b+=time_b-time_a, time_a+=a, ans_a+=time_a-time_b, time_b+=b;
			else                                
			if (time_a+a==time_b) {
				ans_b+=time_b-time_a; break;
			}	                           
		}
		swap(ans_a,ans_b);
	}                                                           
	printf(ans_a>ans_b ? "Dasha" : (ans_a<ans_b ? "Masha" : (ans_a==ans_b ? "Equal" : "U kotoroi siski bolshe")));
	return 0;
}