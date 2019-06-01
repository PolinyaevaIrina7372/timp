#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorting_function(int *a, int *b){ // Пирамидальная сортировка
        int tmp = *a;
        *a = *b;
        *b = tmp;
        return 0;
}
int main(){
    clock_t start,stop;
    double rez,sr_rez = 0;
    double comp_avg=0,perm_avg=0;
    int comp,perm;
    start = clock();
    for(int ch=0;ch<1;ch++){
        comp=0,perm=0;
        int n=200,step=0,b;
        int a[n];
	for(int i=0;i<n;i++){a[i]=rand()%(2*n)+1;} // для наилучшего варианта {a[i]=n + i - 199;} // для наихудшего варианта {a[i]=n-i;}
        while (1) {
                b=0;
                for (int i=0;i<n;++i){
                        if (i*2 +2 +step<n){
                                if (a[i +step] > a[i*2 +1 +step] || a[i +step] > a[i*2 +2 +step]){
                                        comp++;
                                        if (a[i*2 +1 +step] < a[i*2 +2 +step]){
                                                sorting_function(&a[i +step], &a[i*2 +1 +step]);
                                                b=1;
                                                perm++;
                                        }
                                        else{
                                            comp++;
                                            if (a[i*2+2+step] < a[i*2+1+step]){
                                                sorting_function(&a[i+step],&a[i*2+2+step]);
                                                b=1;
                                                perm++;
                                            }
                                        }
                                }
                        }
                        else if (i*2 +1 +step<n){
                                comp++;
                                if (a[i +step] > a[i*2 +1 +step]){
                                        sorting_function(&a[i +step], &a[i*2 +1 +step]);
                                        b=1;
                                        perm++;
                                }
                        }
                }
                if (!b) step++;
                if (step+2>=n) break;
       comp_avg+=comp;
        perm_avg+=perm;
        }
        for (int i=0;i<n;i++) printf("%d ", a[i]);
        printf ("\n");
    }
	stop = clock();

    	long double clock_rez = (stop - start)/(long double)CLOCKS_PER_SEC;
    	printf("%Lf \n",clock_rez/1000);
   	 start ,stop = 0;
   	 clock_rez = 0;

        comp_avg=comp_avg/100;
        perm_avg=perm_avg/100;
        printf("Srednee Sravn: %.2f\n",comp_avg);
        printf("Srednee Perest: %.2f\n",perm_avg);
        return 0;
}