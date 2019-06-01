#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting_function(int n, int arr[], int *perm,int *comp){     //сортировка расческой
        int step=n-1,tmp;
        while(step>=1){
                for(int i=0;i<n-step;i++){
                        if(arr[i]>arr[i+step]){
                                tmp=arr[i];
                                arr[i]=arr[i+step];
                                arr[i+step]=tmp;
                                (*perm)++;//перестановки
                        }
                        (*comp)++;//сравнение
                }
                step--;
        }
}

int main(){
    clock_t start,stop;
    double rez,sr_rez = 0;
    double comp_avg=0,perm_avg=0;
    int comp,perm;
    start = clock();
    for(int ch=0;ch<1;ch++){
        int n=200;
        comp=0,perm=0;
        int arr[n];
        for(int i=0;i<n;i++){arr[i]=rand()%(2*n)+1;} // дл€ наилучшего варианта {arr[i]=n + i - 199;} // дл€ наихудшего варианта {arr[i]=n-i}; 
        sorting_function(n,arr,&perm,&comp);
        for(int i=0;i<n;i++){ printf("%d ", arr[i]); } // вывод отсортированного массива
        printf("\n");
        printf("comparison: %d\n",comp);
        printf("permutation: %d\n",perm);
        comp_avg+=comp;
        perm_avg+=perm;
    }
    stop = clock();
    long double clock_rez = (stop - start)/(long double)CLOCKS_PER_SEC;
    printf("%Lf \n",clock_rez/1000);
    start ,stop = 0;
    clock_rez = 0;
    comp_avg=comp_avg/100;
    perm_avg=perm_avg/100;
    printf("average comparison: %.0f\n",comp_avg);
    printf("average permutation: %.2f\n",perm_avg);
    return 0;
}     