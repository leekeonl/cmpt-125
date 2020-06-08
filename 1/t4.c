#include <stdio.h>
#include <math.h>

int main(){
	double number;
	int input = scanf("%lf", &number);
	if (input != 1){
		printf("scanf error: (%d)\n",0);}
	else {
		printf("%0.0lf ", floor(number));
		printf("%0.0lf ", round(number));
		printf("%0.0lf\n", ceil(number));
}
}

