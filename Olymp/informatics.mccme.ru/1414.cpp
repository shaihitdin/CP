#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 11;
int n;
bool u[N];
 
inline void Plus (const int &n) {
    if (u[n])
        return;
    printf ("%d ", n);
    u[n] = 1;
}
 
inline void Minus (const int &n) {
    if (!u[n])
        return;
    printf ("-%d ", n);
    u[n] = 0;
}
 
inline void add (const int &n);
 
inline void del (const int &n) {
    if (!u[n])
        return;
    if (n == 1)  {
        Minus (1);
        return;
    }
    add (n - 1);
    for (int i = n - 2; i; --i)
        del (i);
    Minus (n);
}
 
inline void add (const int &n) {
    if (u[n])
        return;
    if (n == 1) {
        Plus (1);
        return;
    }
    add (n - 1);
    for (int i = n - 2; i; --i)
        del (i);
    Plus (n);
}
int main () {
    /*
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    */
    cin >> n;
    for (; n; --n)
        add (n);
    return 0;
}
