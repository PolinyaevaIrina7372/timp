#include <stdio.h>
#include <stdlib.h>

//сортировка расчёской
int sorting_function(int *arr, int arr_len){
    //сортируем по возрастанию
    int step=arr_len-1,c;
    while(step>=1){
        for(int i=0;i<arr_len-step;i++){
            if(arr[i]>arr[i+step]){
                c=arr[i];
                arr[i]=arr[i+step];
                arr[i+step]=c;
            }
        }
        step--;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sorting_function(arr,n);

    //отсортированный массив
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
