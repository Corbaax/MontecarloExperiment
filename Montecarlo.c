#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
int valuta(){
	double x = (double)rand() / RAND_MAX;
	double y = (double)rand() / RAND_MAX;
	double y_f = sqrt(1-(x*x));
	return y_f > y ? 1 : 0;
}

int main(int argc, char*argv[]){
	clock_t start,end;

	int n = 0;
	if (sscanf (argv[1], "%i", &n) != 1) {
    		fprintf(stderr, "error - not an integer");
		return 1;
	}

	srand(time(NULL));
	int sum = 0;
	int i = 0;
	start = clock();
	for(i = 0; i<n; i++){
		sum += valuta();
	}
	end = clock();

	double area = (double) sum/i;
	area *= 4.0;
	printf("%.8f \n", area);
	printf("%d, %d \n",i,sum);
	printf("exec time: %.3f\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
};
