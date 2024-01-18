#include <stdio.h>

#define MAX_SIZE 100 // Maximum array size

int main()
{
    int arr[MAX_SIZE];
    int N;
    int * ptr = arr;  

    //TODO
    scanf("%d",&N);
    for(int i= 0;i<N;i++){
        scanf("%d",arr+i);
    }
    for(int i= 0;i<N-1;i++){   
 	   printf("%d, ",*(ptr+i));
	}
	printf("%d", *(ptr+N-1));
     return 0;
}
