#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
int valuta(unsigned int *seed){
  	double x = (double)rand_r(seed) / RAND_MAX;
    double y = (double)rand_r(seed) / RAND_MAX;
	double y_f = sqrt(1-(x*x));
	return y_f > y ? 1 : 0;
}

int main(int argc, char*argv[]){

	long n = 0;
	int th = 0;
	if (sscanf (argv[1], "%ld", &n) != 1) {
    		fprintf(stderr, "error - not an integer");
		return 1;
	}
	if (sscanf (argv[2], "%i", &th) != 1) {
    		fprintf(stderr, "error - not an integer");
		return 1;
	}

	srand(time(NULL));
	long sum = 0;
	long count = 0;


	omp_set_num_threads(th);
	double start = omp_get_wtime();

	#pragma omp parallel
    {
        unsigned int seed = time(NULL) ^ omp_get_thread_num();

        #pragma omp for reduction(+:sum, count)
        for (long i = 0; i < n; i++) {
            sum += valuta(&seed);
            count++;
        }
    }

	double end = omp_get_wtime();

	double area = 4.0 * ((double)sum / count);
	printf("%.8f \n", area);
	printf("%ld, %ld \n",count,sum);
	printf("exec time: %.3f\n", end - start);
	return 0;
};