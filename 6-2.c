#include <stdio.h>
#include <stdlib.h>

//Сортировка Шелла
int sorting_function(int *arr, int arr_len){
    //сортируем по возрастанию
    int i,j,step,tmp;
    for(step=arr_len/2;step>0;step/=2){
        for(i=step;i<arr_len;i++){
            tmp=arr[i];
            for(j=i;j>=step;j-=step){
                if(tmp<arr[j-step])arr[j]=arr[j-step];
                else break;
            }
            arr[j]=tmp;
        }
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
