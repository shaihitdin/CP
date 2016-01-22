#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

long long int findMaxAttraction(int n, int start, int d, int attraction[]) ;

typedef long long int (*findMaxAttractionFunction)(int n, int start, int d, int attraction[]) ;

#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
