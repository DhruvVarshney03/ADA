// C program to implement recursive Binary Search
#include <stdio.h>


int binarySearch(int arr[], int lb, int ub, int x)
{
	if (ub >= lb) {
		int mid = lb + (ub - lb) / 2;               


		if (arr[mid] == x)
			return mid;                             


		if (arr[mid] > x)
			return binarySearch(arr, lb, mid - 1, x);            

		return binarySearch(arr, mid + 1, ub, x);
	}


	return -1;
}


int main()
{
	int a[100],lb=0,ub,n,x,i;
    printf("How many elements?");               
    scanf("%d",&n);                             
     
    printf("Enter array elements:\n");          
    for(i=0;i<n;++i)                            
        scanf("%d",&a[i]);                      

    printf("\nEnter element to search:");       
    scanf("%d",&x);       
	int result = binarySearch(a, 0, n - 1, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
