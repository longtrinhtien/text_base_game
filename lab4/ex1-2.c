#include <stdio.h>
  
// TODO: Implement swap function here
void swap(int* num1,int* num2){
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}
int main() {
   int num1, num2;
   scanf("%d", &num1);
   scanf("%d", &num2);
   
   //Call swap function
    swap(&num1,&num2);    
   printf("%d %d", num1, num2);
  
   return 0;
}

