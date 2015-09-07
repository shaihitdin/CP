#include <bits/stdc++.h>

using namespace std;

const int N = 300;

int d[2][N][N];
string al;
int limit[N];

//V = 0, C = 1;

inline int tt (const char &aaaa) {
    if (aaaa == 'V')
        return 0;
    return 1;
}

bool banned[N][2];

int main () {

    #ifdef LOCAL
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif

    cin >> al;

    int alpha = al.size ();
    
    int n, m;

    cin >> n;

    cin >> m;

    memset (d, -1, sizeof (d));
    
    for (int i = 1; i <= m; ++i) {
        int pos1, pos2;
        char t1, t2;
        cin >> pos1 >> t1 >> pos2 >> t2;
        t1 = tt (t1);
        t2 = tt (t2);
        d[t1][pos1][pos2] = t2;
    }

    for (int ll = 0; ll <= 1; ++ll)
        for (int i = 1; i <= n; ++i)
            d[ll][i][i] = ll;
    for (int k = 1; k <= n; ++k) {
        for (int ll = 0; ll <= 1; ++ll) {
            for (int i = 1; i <= n; ++i) {
                if (d[ll][i][k] != -1) {
                    int val = d[ll][i][k];
                    for (int j = 1; j <= n; ++j) {
                        int val2 = d[val][k][j];
                        if (val2 == -1)
                            continue;
                        if (d[ll][i][j] == -1) {
                            d[ll][i][j] = val2;
                        } else {
                            if (val2 != d[ll][i][j]) {
                                banned[i][ll] = 1;
                                //cerr << i << " " << ll << " " << k << " " << val << " " << j << "\n";
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int ll = 0; ll <= 1; ++ll) {
            if (banned[i][ll])
                continue;
            for (int j = 1; j <= n; ++j) {
                int val = d[ll][i][j];
                if (val == -1)
                    continue;
                if (banned[j][val])
                    banned[i][ll] = 1;
            }
        }
    }   
    
    /*
    for (int j = 0; j <= 1; ++j) {
        for (int i = 1; i <= n; ++i) {
            cerr << banned[i][j] << " ";
        }
        cerr << "\n";
    }   
    */
    string s;

    cin >> s;

    s = '#' + s;
    
    for (int len = n + 1; len >= 1; --len) {
        //cerr << "\nOK1 ";
        memset (limit, -1, sizeof (limit));
        for (int i = len + 1; i <= n; ++i)
            s[i] = ' ';
        bool flag = 1;
        for (int i = 1; i < len; ++i)
            limit[i] = tt (al[s[i] - 'a']);
        for (int i = 1; i < len && flag; ++i) {
            if (banned[i][limit[i]])
                flag = 0;
            for (int j = 1; j <= n && flag; ++j) {
                if (d[limit[i]][i][j] == -1)
                    continue;
                int val2 = d[limit[i]][i][j];
                if (banned[j][val2])
                    flag = 0;
                if (limit[j] != -1) {
                    if (limit[j] != d[limit[i]][i][j]) {
                        flag = 0;
                        break;
                    }
                } else {
                    limit[j] = d[limit[i]][i][j];
                }
            }
        }
        if (!flag)
            continue;
        for (int i = len; i <= n; ++i) {
            int ch;
            if (s[i] == ' ') {
                ch = 'a';
            } else {
                ch = s[i] + 1;
            }
            for (; ch < 'a' + alpha; ++ch) {
                int val = tt (al[ch - 'a']);
                bool flag2 = 1;
                if (limit[i] != -1 && limit[i] != val)
                    continue;
                if (banned[i][val])
                    continue;
                for (int j = 1; j < i; ++j) {
                    if (d[val][i][j] == -1)
                        continue;
                    if (d[val][i][j] != limit[j])
                        flag2 = 0;
                }
                if (!flag2)
                    continue;
                for (int j = i; j <= n; ++j) {
                    if (d[val][i][j] == -1)
                        continue;
                    int val2 = d[val][i][j];
                    if (banned[j][val2])
                        flag = 0;
                    if (limit[j] == -1)
                        continue;
                    if (limit[j] != d[val][i][j])
                        flag2 = 0;
                }
                if (!flag2)
                    continue;
                else
                    break;
            }
            if (ch == 'a' + alpha) {
                flag = 0;
                break;
            }
            s[i] = ch;
            limit[i] = tt (al[ch - 'a']);
            for (int j = i + 1; j <= n; ++j) {
                if (d[limit[i]][i][j] == -1)
                    continue;
                if (limit[j] == -1)
                    limit[j] = d[limit[i]][i][j];
            }
            //cerr << "OK2";
        }
        if (!flag)
            continue;
        for (int i = 1; i <= n; ++i)
            cout << s[i];
        return 0;
    }
    
    cout << -1;
    
    return 0;
}