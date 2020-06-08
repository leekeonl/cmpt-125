#include <stdio.h>
#include <math.h>

int main(){
	double number;
	scanf("%lf" , &number);
	printf("%0.0lf ", floor(number));
	printf("%0.0lf ", round(number));
	printf("%0.0lf\n", ceil(number));
}
