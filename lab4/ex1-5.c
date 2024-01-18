#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int N = 0, sum = 0;
    int input;
	arr = (int*) malloc(1 * sizeof(int));
    while (scanf("%d", &input) == 1) {
        N++;
        arr = (int*) realloc(arr, N * sizeof(int));
        arr[N-1] = input;
        sum += input;
    }

    printf("%d", sum);

    free(arr);
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int *arr;
//    int N = 0, sum = 0;
//    int input;
//	arr = (int*) malloc(1 * sizeof(int));
//    printf("Enter the elements (separated by spaces):\n");
//    while (scanf("%d", &input) == 1) {
//        N++;
//        arr = (int*) realloc(arr, N * sizeof(int));
//        arr[N-1] = input;
//        sum += input;
//    }
//
//    printf("The sum of the elements is: %d\n", sum);
//
//    free(arr);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    int *ptr, i , n1, n2;
//    printf("Nhap so luong phan tu: ");
//    scanf("%d", &n1);
//    ptr = (int*) malloc(n1 * sizeof(int));
//    printf("Dia chi cua vung nho vua cap phat: %u", ptr);
//    
//    printf("\nNhap lai so luong phan tu: ");
//    scanf("%d", &n2);
//    // phân b? l?i vùng nh?
//    ptr = (int*) realloc(ptr, n2 * sizeof(int));
//    printf("Dia chi cua vung nho duoc cap phat lai: %u", ptr);
//    // gi?i phóng
//    free(ptr);
//    return 0;
//}
