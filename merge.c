#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void merge(int* array, int start, int mid, int end){
    int* tmp=(int*)malloc(sizeof(int)*(end-start+1));
    int tmp_index=0;
    int p=start,q=mid+1;
    int i;
 
    for(i=tmp_index; i<=end-start; i++){
        while(p<=mid && q<=end){
            if(array[p]>array[q]){
                tmp[tmp_index]=array[q];
                q++;
            }else{
                tmp[tmp_index]=array[p];
                p++;
            }
            tmp_index++;
        }
 
        if(p>mid){
            while(q<=end){
                tmp[tmp_index]=array[q];
                q++;
                tmp_index++;
            }
        }
        else{
            while(p<=mid){
                tmp[tmp_index]=array[p];
                p++;
                tmp_index++;
            }
        }
    }//end for
 
    for(i=start; i<=end; i++){
        array[i]=tmp[i-start];
    }
 
    free(tmp);
}
 
void merge_sort(int* array, int start, int end){
    if(start>=end) return;
 
    int mid=(start+end)/2;
 
    merge_sort(array,start,mid);
    merge_sort(array,mid+1,end);
 
    merge(array,start,mid,end);
}
 
int main(void){
    int array[100];
    int i;
 
    srand(time(NULL));
    for(i=0; i<100; i++){
        array[i]=rand()%1000;
    }
 
    merge_sort(array,0,sizeof(array)/sizeof(int)-1);
 
    for(i=0; i<100; i++){
        printf("%4d\n",array[i]);
    }
    return 0;
}


출처: https://milvus.tistory.com/69 [Milvus Migrans]
