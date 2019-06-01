    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting_function(int n,int mass[], int *perm,int *comp){  //Сортировка Шелла
        int i,j,step,tmp;
        for(step=n/2;step>0;step/=2){
                for(i=step;i<n;i++){
                        tmp=mass[i];
                        for(j=i;j>=step;j-=step){
                                (*comp)++;
                                if(tmp<mass[j-step])mass[j]=mass[j-step];
                                else break;
                        }
                        mass[j]=tmp;
                        (*perm)++;
                }
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
        for(int i=0;i<n;i++){arr[i]=rand()%(2*n)+1;} // для наилучшего варианта {arr[i]=n + i - 199;} // для наихудшего варианта {arr[i]=n-i};
        sorting_function(n,arr,&perm,&comp);
        for(int i=0;i<n;i++){ printf("%d ", arr[i]); }// выврд отсортированного массива
        printf("\n");
        printf("Sravneniy: %d\n",comp);
        printf("Perestanovok: %d\n",perm);
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