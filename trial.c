#include<stdio.h>
#include<stdlib.h>

int main(){

  
    int n = 5;int *ptr,*ctr;
    for(int i=0;i<110000;i++){
    
     ptr = malloc(i*sizeof(int));
     ctr = calloc(n,sizeof(int));
    }

    // printf("%d %d",sizeof(ptr),sizeof(ctr));
    // for(int i=0;i<n;i++){
    //     scanf("%d",&ptr[i]);
    // }
    // free(ptr);
    // for(int i=0;i<n;i++){
    //     printf("%d ",ptr[i]);
    // }

   
    return 0;
}