#include<stdio.h>
void inputElementOfArrayAndDisplay(int *a,int len);

int main(){
    int *p;
    int arr[100];
    int size = 0;
    p = &arr[0];
   inputElementOfArrayAndDisplay(p,size);
    return 0;
}
void inputElementOfArrayAndDisplay(int *a,int len){
printf("Element of this array: \n");
   int i=0;
 for(i=0; scanf("%d",(a+i))!=EOF; i++){
        len++;
        }
 for(i=0; i<len; i++){
     printf("%d\n ",*(a+i));
        }
}