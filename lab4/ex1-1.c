#include <stdio.h>
#include <string.h>
int main()
{
    char str1[50];
    char revstr[50];
    char* stptr = str1;
    char* rvptr = revstr;
    scanf("%s", stptr);
    
    //TODO
    int len = strlen(str1);
    for(int i = 0; i<len;i++){
    	*(rvptr+len-1-i)=*(stptr+i);
	}


	printf("%s",revstr);

    return 0;
}
