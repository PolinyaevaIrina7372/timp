#include <stdio.h>
#include <stdlib.h>

//Быстрая сортировка
int sorting_function(int *arr, int arr_len, int left, int right){
    //сортируем по возрастанию
    int i=left,j=right,d,m=arr[(left+right)/2];
    while(i<=j){
        for(;arr[i]<m;i++);
        for(;arr[j]>m;j--);
        if(i<=j){
            d=arr[i];
            arr[i++]=arr[j];
            arr[j--]=d;
        }
    }
    if(left<j) sorting_function(arr,arr_len,left,j);
    if(i<right) sorting_function(arr,arr_len,i,right);
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sorting_function(arr,n,0,n);

    //отсортированный массив
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
