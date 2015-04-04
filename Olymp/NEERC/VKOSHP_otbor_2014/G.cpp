
/**
    Ќочь собираетс€, и начинаетс€ мой дозор. 
    ќн не окончитс€ до самой моей смерти. 
    я не возьму себе ни жены, ни земель, не буду отцом дет€м. 
    я не надену корону и не буду добиватьс€ славы. 
    я буду жить и умру на своем посту. 
    я - меч во тьме; 
    € - ƒозорный на —тене; 
    € - огонь, который разгон€ет холод; 
    € - свет, который приносит рассвет; 
    € - рог, который будит сп€щих; 
    € - щит, который охран€ет царство людей. 
    я отдаю свою жизнь и честь Ќочному ƒозору в эту ночь и во все гр€дущие. 
**/
 
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <utility>
#include <stack>
#include <queue>
#define F first
#define S second
#define mp make_pair
#define file "merlin."
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int N = 101001;
ll n;
ll a[N];
ll d[N];
ll d1[N];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int mx = a[n - 1];
    for(int i = n - 1; i >= 0; i--)
    {
        d[i] = d[i + 1] + (mx - a[i]);
        //cout << d[i] << endl;
    }
    d1[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        d1[i] = d1[i - 1] + a[i];
    }
    //cout << d[1];
    if(d[0] == 0)
        cout << 0;
    else
    {
        long long sum = 0, sum1 = 0;    
        long long  pos1 = INF, c = 0;
        for(int i = 0; i < n; i++)
        {
            sum += a[i];
            if(sum >= d[i + 1])
            {
                pos1 = i + 1;
                break;
            }
        }
        long long mx1;
        for(int i = n - 1; i > 0; i--)
        {
            c++;
            sum1 += a[i];
            mx1 = i * (a[i - 1]);
            if(sum1 >= mx1 - d1[i - 1])
            {
                break;
            }
        }
        cout << min(pos1, c);
    }
    return 0;
}