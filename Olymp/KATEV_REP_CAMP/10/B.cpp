#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

map <long long, int> Map;

long long st[N], sum, x;
int stq, enq;
int k;
char q;

int main () {
    freopen ("cars.in", "r", stdin);
    freopen ("cars.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> q;
        if (q == '+') {
            cin >> x;
            st[enq++] = x;
            sum += x;
            ++Map[x];
        } else if (q == '-') {
            --Map[st[stq]];
            sum -= st[stq++];
        } else {
            if (sum % (enq - stq))
                cout << 0 << "\n";
            else
                cout << Map[sum / (enq - stq)] << "\n";
        }
    }
    return 0;
}