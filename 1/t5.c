#include <stdio.h>
#include <math.h>

int main(){
	double number;
	while(1){
	int input = scanf("%lf", &number);
	if(input != 1){
		printf("Done.\n");
		break;}
	else{
		printf("%0.0lf ", floor(number));
		printf("%0.0lf ", round(number));
		printf("%0.0lf\n", ceil(number));
}	
}
}
