#include <bits/stdc++.h> 
using namespace std; 
const int MaxN = 1e5 + 17; 
const int INF = 1e9 + 17; 
long long x, n = 2e5, Sum, Min = 1e9, u[1100][1100]; 
int main () 
{ 

freopen ("in", "w", stdout); 
srand (time (0));
ios_base :: sync_with_stdio (0);
cout << n << endl; 
while (1) 
{ 
int i = rand () % 1000 + 1; 
int j = rand () % 1000 + 1; 
if (!u[i][j]) 
{ 
cout << i << ' ' << j << endl; 
u[i][j] = 1; 
n--; 
if (n == 0) 
break; 
} 
} 
cout << endl; 
return 0; 
}