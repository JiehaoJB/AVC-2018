
#include "functions.h"

clock_t sTime; //Initial start time

int ALL_BLACK = -10000;
int ALL_WHITE = 10000;
int WHITE_LEFT = -15000;
int WHITE_RIGHT = 15000;

int counter = 0;
int whitePixels = 0;
int averagePixels = 0;

int quadrant = 3;
int main() {
	init();

	sTime = clock();
	//quadThree();



	while(true){
	    switch(quadrant){
	        case 1:
	        	if(quadOne()){
	        		quadrant++;
	        	}
	            break;
	        case 2:
                if(quadTwo()){
                    quadrant++;
                }

	            break;
	        case 3:
	            quadThree();
	            //Quadrant three code
	            break;
	        case 4:
	            //Quadrant four code
	            break;
	        default:
				get_error();
				sleep1(1,0);
				break;
	    }

        //Failsafe code
        if((double)(clock() - sTime) / CLOCKS_PER_SEC > 2.5){
            set_motor(MOTOR_LEFT, 0);
            set_motor(MOTOR_RIGHT, 0);
            return 0;
        }
	}
	postLoop:
    return 0;
}
