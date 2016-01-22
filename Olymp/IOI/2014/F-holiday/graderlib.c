#include <stdio.h>
#include "grader.h"

#if ( _WIN32 || __WIN32__ )
  #define LLD "%I64d"
#else
  #define LLD "%lld"
#endif

static int n, start, d;
static int attraction[100000];
static int i, n_s;


int _main(findMaxAttractionFunction findMaxAttraction) {
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    #endif
    n_s = scanf("%d %d %d", &n, &start, &d);
    for (i = 0 ; i < n; ++i) {
    n_s = scanf("%d", &attraction[i]);
    }
    printf(LLD"\n", findMaxAttraction(n, start, d, attraction));
    return 0;
}
