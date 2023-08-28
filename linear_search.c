#include<stdio.h>
  
int main()
{
    int a[20],i,x,n,step_count=0;
    printf("Dhruv Varshney");
    printf("\nA2305221157");

    printf("\nHow many elements?");            /*1*/
    scanf("%d",&n);                          /*1*/
    
     
    printf("Enter array elements:\n");      /*1*/
    for(i=0;i<n;++i)                        /*n+1*/
        scanf("%d",&a[i]);                  /*n*/
     
    printf("\nEnter element to search:");   /*1*/
    scanf("%d",&x);                         /*1*/
     
    for(i=0;i<n;++i){                       /*n+1*/
        if(a[i]==x)                         /*n*/
            break;                              /*1*/
    }
     
    if(i<n)                                 /*1*/   
        printf("Element found at index %d",i);
    else
        printf("Element not found");
  
    return 0;                              /*1*/ 
}
/*Time Complexity: O(n)*/