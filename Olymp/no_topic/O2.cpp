#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int x = 0; x <= n; ++x) {
        if (n == x + (x + 1) + (x + 2)) {
            cout << x  << " " << x - 1 << " " << x - 2 << "\n";
            exit(0);
        }
    }
    cout << -1 << endl;
    return 0;
}