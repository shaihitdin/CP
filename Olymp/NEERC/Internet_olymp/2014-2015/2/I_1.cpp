/*                                                                       
nikto ne smeet obijat' malen'kogo begemotika
  _ _ _ _
 /.  _  .\
|   /_\   |
|_ _ _ _ _|
   NIKTO                                                             
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <cassert>
#include <math.h>
#include <vector>
#include <time.h>
using namespace std;           
#define forn(i, x, n) for(int i = x; i <= n; ++i)
#define for1(i, n, x) for(int i = n; i >= x; --i)
#define file "oddoreven."
 
typedef long long ll;
                                              
const int maxn = 5000100; 
const int INF = int(2e9) + 7;                      
              
int n;
char s[maxn], par_x[4], par_y[4];
int pos[maxn], p_sz;
 
///0 - Odd
///1 - Even
bool oddOrEven(int i) {
    if (s[i] == 'x') return par_x[0] == 'E';
    if (s[i] == 'y') return par_y[0] == 'E';  
    return (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8');
}
 
int dp(int i) {                                         
    int a = 0, b = 0;
    if (i == p_sz + 1) {
        return oddOrEven(n - 1);
    }
    if (s[pos[i]] == '-' || s[pos[i]] == '+') { 
        a = oddOrEven(pos[i] - 1), b = dp(i + 1);  
        return (a == b);    
    }               
    if (s[pos[i]] == '*') {
        a = (oddOrEven(pos[i] - 1) | oddOrEven(pos[i + 1] - 1));
        if (i == p_sz) return a;
        b = dp(i + 2);
        if (s[pos[i + 1]] == '-' || s[pos[i + 1]] == '+') 
            return (a == b);    
        if (s[pos[i + 1]] == '*') 
            return (a | b);       
    }
    assert(0);
}
 
int main() {
/*  */                                                           
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);       
                                           
    scanf("%s\n%s\n%s", s, par_x, par_y);   
    n = strlen(s);
    if (s[n - 1] == '-' || s[n - 1] == '+' || s[n - 1] == '*')
        assert(0);
                     
    forn(i, 0, n - 1) {
        if (s[i] == '-' || s[i] == '+' || s[i] == '*')
            pos[++p_sz] = i;
    }
    pos[p_sz + 1] = n;
 
    printf(dp(1) ? "Even" : "Odd");
 
    return 0;   
}
