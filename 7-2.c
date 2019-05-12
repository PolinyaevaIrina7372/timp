#include <stdio.h>
#include <stdlib.h>

int swapping(int *a, int *b){
	int tmp= *a;
	*a = *b;
	*b = tmp;
	return 0;
}

//Пирамидальная сортировка
int sorting_function(int *arr, int arr_len){
    //сортируем по возрастанию
    int step=0,b;
    while (1) {
        b=0;
        for (int i=0;i<arr_len;++i){
            if (i*2 +2 +step<arr_len){
                if (arr[i +step] > arr[i*2 +1 +step] || arr[i +step] > arr[i*2 +2 +step]){
                    if (arr[i*2 +1 +step] < arr[i*2 +2 +step]){
                        swapping(&arr[i +step], &arr[i*2 +1 +step]);
                        b=1;
                    }
                    else{
                        if (arr[i*2+2+step] < arr[i*2+1+step]){
                            swapping(&arr[i+step],&arr[i*2+2+step]);
                            b=1;
                        }
                    }
                }
            }
            else if (i*2 +1 +step<arr_len){
                if (arr[i +step] > arr[i*2 +1 +step]){
                    swapping(&arr[i +step], &arr[i*2 +1 +step]);
                    b=1;
                }
            }
        }
        if (!b) step++;
        if (step+2>=arr_len) break;
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
