#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>	

	void display(double out)
	//display value of fOut in format of 0.XX
	{
		if (out == 1){
			printf("1");
		}
		else{
			printf("%.2f",out);
		}
	}
	
	//for checking paladin state
	int isPrime(int n) {
	    if (n <= 1) {
	        return 0;//return false
	    }
	    //check until i>sqrt(n)
	    for (int i = 2; i * i <= n; i++) {
	        if (n % i == 0) {
	            return 0;//return false
	        }
	    }
	    return 1;//true
	}

	int find_nearest_fibonacci(int n) {
	    int a = 1, b = 1, c;
	    //a<b -> stop when n is between 2 nearest fibonacci number a and b
	    while (b < n) {
	        c = a + b;
	        a = b;
	        b = c;
	    }
	    if (abs(n - a) < abs(n - b)) {
	        return a;
	    } else {
	        return b;
	    }
	}
	
	void check_realHP(int num,double *realHP) {
		if(num == 1){
			if(*(realHP) > 999 ){
				*(realHP) = 999;    	
			}
			if(*(realHP) < 1 ){
				*(realHP) = 1;    	
			}			
		} else if(num == 2){
			if(*(realHP) > 888 ){
				*(realHP) = 888;    	
			}			
		}	
	}
	
	double final_calculation(double realHP1, double realHP2) {
	    double result = (realHP1 - realHP2 + 999.0) / 2000.0;
	    return result;
	}
	
	int isPerfect(int strengthOfWeapon,int baseHP) {
    int sum = 0;
    for (int i = 1; i < strengthOfWeapon+baseHP; i++) {
        if ((strengthOfWeapon+baseHP) % i == 0) {
            sum += i;
        }
    }
    if(sum == (strengthOfWeapon+baseHP)){
    	//upgrade new HP when a match is avalaible 
    	return sum;
	} else {
		//keep its strength if no weapon is valid
		return 0;
	}
	}
	

	int sumMaxRowAndColumn(int arr[100][100], int rows, int cols) {
    int maxRowSum = 0, maxRowIndex = -99;
    int maxColSum = 0, maxColIndex = -99;

    // Calculate the max sum of row and col
    for(int i = 0; i < rows; i++) {
        int rowSum = 0; //reset when change to next row

        for(int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }

        if(rowSum > maxRowSum) {
            maxRowSum = rowSum;
            maxRowIndex = i;
        }
    }

    for(int j = 0; j < cols; j++) {
        int colSum = 0;

        for(int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }

        if(colSum > maxColSum) {
            maxColSum = colSum;
            maxColIndex = j;
        }
    }

    int sum = maxRowSum + maxColSum - arr[maxRowIndex][maxColIndex];
    return sum;
}

	void castSpell(char spell[], double *realHP1, double *realHP2, int *wp1) {
    int spell_length = strlen(spell);
    int s_count = 0, a_count = 0, x_count = 0, o_count = 0, n_count = 0;
    for (int i = 0; i < spell_length; i++) {
        if (spell[i] == 's') {
            s_count++;
        }
        if (spell[i] == 'a') {
            a_count++;
        }
        if (spell[i] == 'x') {
            x_count++;
        }
        if (spell[i] == 'o') {
            o_count++;
        }
        if (spell[i] == 'n') {
            n_count++;
        }
    }

    if (spell_length > 8) {
        *realHP1 -= 50;
        if (*realHP1 < 1) {
            *realHP1 = 1;
        }
    }

    if ((s_count + a_count + x_count + o_count + n_count) > 3) {
        *realHP2 += 50;
        if (*realHP2 > 888) {
            *realHP2 = 888;
        }
    }

    if (strstr(spell, "Arthur") != NULL || strstr(spell, "arthur") != NULL) {
        if (*wp1) {
            *wp1 = 0;
        }
    }
}


int main() {

	//read data from input to corresponding variables
	int baseHP1, baseHP2, wp1, wp2, ground;
	double out = 0.0;
	scanf("%d %d %d %d %d",&baseHP1, &wp1, &baseHP2, &wp2, &ground);
	if (baseHP1 < 99 || baseHP1 > 999)
		return 1;
	if (wp1 < 0 || wp1 > 3)
		return 1;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 1;
	if (wp2 < 0 || wp2 > 3)
		return 1;
	if (ground < 1 || ground > 999)
		return 1;
    
    //write your code here
    double realHP1 = 0, realHP2 = 0;
    enum State
	{
		START,
    	CHECK_BASE1,
    	CHECK_BASE2,
    	CHECK_PALADIN_1W2,
    	CHECK_GROUND,
    	NORMAL_CALCULATION_FOR_REALHP1,
    	NORMAL_CALCULATION_FOR_REALHP2,
    	FINAL_CALCULATION,
    	EXIT,
	};
//    int currentState; //remember to // this line
    enum State currentState = START;
	while(currentState!=EXIT){
    switch(currentState){
    	case START:
    		currentState = CHECK_BASE1;
    		break;
    	case CHECK_BASE1:
    		if (baseHP1 == 999) {
    			out = 1;
    			currentState = EXIT;
			} else {
				currentState = CHECK_BASE2;
			}
    		break;
    	case CHECK_BASE2:
    		if (baseHP2 == 888) {
  				out = 0;
  				currentState = EXIT;
  			} else {
  				currentState = CHECK_PALADIN_1W2;
			}
    		break;
    	case CHECK_PALADIN_1W2:
    		if(isPrime(baseHP1)==1){
    			if(isPrime(baseHP2)==1){
    				if(baseHP1==baseHP2){
    					out = 0.5;
    					currentState = EXIT;
					} else if(baseHP1>baseHP2){
						out = 0.99;
						currentState = EXIT;
					} else {
						out = 0.01;
						currentState = EXIT;
					}
				} else {
					out = 0.99;
					currentState = EXIT;
				}
			} else if(isPrime(baseHP2)==1) {
				out = 0.01;
				currentState = EXIT;
			} else {
				currentState = CHECK_GROUND;
			}
    		break;
    	case CHECK_GROUND:
    		if(ground == 666){
    			realHP1 = find_nearest_fibonacci(baseHP1);
    			realHP2 = find_nearest_fibonacci(baseHP2);
    			currentState = FINAL_CALCULATION;
			}
			
			if(ground == 777){
//				int isPerfectValid = 0;//when a match avalaible, this variable change to 1 -> skip calculating for realhp2
				int n;// number of weapons
				int godWeapon[100];
				scanf("%d",&n);
				for (int i =0;i<n;i++){
					scanf("%d", &godWeapon[i]);
					if(isPerfect(godWeapon[i],baseHP2)!=0){
//						isPerfectValid = 1;
						if(realHP2 <= isPerfect(godWeapon[i],baseHP2)){
							realHP2 = isPerfect(godWeapon[i],baseHP2);
						}
					}
				}
				currentState = NORMAL_CALCULATION_FOR_REALHP1;
			}
			
			if(ground == 888){
			    int n, a[100][100];
			    scanf("%d", &n);
			    for (int i = 0; i < n; i++) {
			        for (int j = 0; j < n; j++) {
			            scanf("%d", &a[i][j]);
			        }
			    }				
				if(sumMaxRowAndColumn(a,n,n)>5000){
					wp1 = 3;//get the Zeus's weapon
				}
				currentState = NORMAL_CALCULATION_FOR_REALHP1;
			}
			//ground == 999 will be used after calculate real1 and real2
			if(ground!=666&&ground!=777&&ground!=888){
				currentState = NORMAL_CALCULATION_FOR_REALHP1;
			}
    		break;
    	case NORMAL_CALCULATION_FOR_REALHP1:
    		if(realHP1==0){
    			//TODO
    			if(wp1 == 1|| wp1 == 2 || wp1 == 3){
    				realHP1 = baseHP1;
				}
				if(wp1 == 0){
					realHP1 = (double)(baseHP1)/10;
				}
				if(ground == baseHP1){
					realHP1 *= 1.1; 
				}
				//has sword
				if(wp1==3){
					realHP1 *= 2;
				}
				check_realHP(1,&realHP1);
				currentState = NORMAL_CALCULATION_FOR_REALHP2;
			} else {
				check_realHP(1,&realHP1);
				currentState = NORMAL_CALCULATION_FOR_REALHP2;
			}    		
    		break;
    	case NORMAL_CALCULATION_FOR_REALHP2:
    		if(realHP2==0){
    			//TODO
    			if(wp2 == 1|| wp2 == 2 || wp2 == 3){
    				realHP2 = baseHP2;
				}
				if(wp2 == 0){
					realHP2 = (double)(baseHP2)/10;
				}
				if(ground == baseHP2){
					realHP2 *= 1.1; 
				}
				check_realHP(2,&realHP2);  
				currentState = FINAL_CALCULATION;  			
			} else {
				check_realHP(2,&realHP2);
				currentState = FINAL_CALCULATION;
			}
    		break;
    	case FINAL_CALCULATION:
			if(ground == 999){
			    char spell[100];
			    scanf("%s", spell);				
				castSpell(spell,&realHP1,&realHP2,&wp1);
			}
			//armor activated
			if(wp1 == 2 && (realHP1<realHP2)){
				out = 0.5;
				currentState = EXIT;
			}
			//wp1 = 3 deactivate wp2 = 2  
			if(wp2 == 2 && (realHP2<realHP1) && wp1!=3){
				out = 0.5;
				currentState = EXIT;
			}
			if(currentState!= EXIT){
				out = final_calculation(realHP1,realHP2);	
				currentState = EXIT;			
			}
    		break;
    	case EXIT:
    		
    		break;
    	default:
    		break;
	}
}

    display(out);
    return 0;
}
