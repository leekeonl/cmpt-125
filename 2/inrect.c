#include <stdio.h>
int InRectangle( float pt[2], float rect[4] );

float position1, position2, position3, position4;
int InRectangle( float pt[2], float rect[4] ){
	if(rect[1]>rect[3]){
		position3 = rect[1];
		position4 = rect[3];
		rect[1] = position4;
		rect[3] = position3;
}
	if (rect[0]>rect[2]){
		position1 = rect[0];
		position2 = rect[2];
		rect[0] = position2;
		rect[2] = position1;
		}

	if (pt[1]>=rect[1] && pt[1]<=rect[3] && pt[0] <=rect[2] && pt[0] >= rect[0]){return 1;}
return 0;
}
