#include <stdio.h>

int main(){

	double number;
	double total = 0.0;
	int count = 0;
	double big;
	double small;
	int input;
	while(1){
		input = scanf("%lf",&number);
		if(input==1){
			count++;
			total += number;
			if(count==1){
				small = number;
				big = number;
			}else if(number>big){
				big = number;
			}else if(number<small){
				small = number;
			}
		}else if(input==EOF){
			break;
		}else{
			while(getchar()!='\n');
		}
	}
	printf("%0.2lf %0.2lf %0.2lf\n",small,big,(total/count));
}
