#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

int findSample(int n,int confidence[],int host[],int protocol[]);

typedef int (*findSampleFunction)(int n,int confidence[],int host[],int protocol[]);

#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
