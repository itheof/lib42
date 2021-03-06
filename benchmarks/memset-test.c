#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "memory_42.h"

#define MAX_ITERATION	10000000U
#define MAX_ITER_STR	"10.000.000"
#define ALLOC_SIZE		4096U

/*
 * Source:
 * http://stackoverflow.com/questions/2349776/how-can-i-benchmark-c-code-easily
 * https://github.com/macmade/LibC-String-Optimisations/blob/master/source/memset-test.c
 */

static double get_time()
{
	struct timeval t;
	struct timezone tzp;
	gettimeofday(&t, &tzp);
	return t.tv_sec + t.tv_usec*1e-6;
}

int main(void)
{
	void	*p = malloc(ALLOC_SIZE);
    double	t1;
    double	t2;
    double	t3;
    
	printf("==== memset | Iteration: %s\n", MAX_ITER_STR);
    t1 = get_time();
    for(size_t i = 0; i < MAX_ITERATION; i++)
        memset(p, i % 256, ALLOC_SIZE);
    t2 = get_time();
    for(size_t i = 0; i < MAX_ITERATION; i++)
        ft_memset(p, i % 256, ALLOC_SIZE);
    t3 = get_time();
    
    printf("memset:\t\t%f\n", t2 - t1);
    printf("ft_memset:\t%f\n", t3 - t2);
}
