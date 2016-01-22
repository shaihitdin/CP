#include <stdio.h>
#include <assert.h>
#include "grader.h"

#define __MAXSIZE__ 100002

static int confidence[__MAXSIZE__];
static int host[__MAXSIZE__];
static int protocol[__MAXSIZE__];

int _main(findSampleFunction findSample)
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&confidence[i]);
	for(i=1;i<n;i++)
		scanf("%d %d",&host[i],&protocol[i]);
	printf("%d\n",findSample(n,confidence,host,protocol));
	return 0;
}
