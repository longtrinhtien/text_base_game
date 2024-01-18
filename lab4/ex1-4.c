#include <string.h>
#include <stdio.h>

int main(){
    char arr[100]; 
    scanf("%s",arr);
    char* p=arr;
    int count =0;
    while(*p!='\0'){
    	count++;
    	p++;
	}
    printf("%d",count);
    return 0;
}
