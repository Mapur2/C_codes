#include<stdio.h>

//function prototypes
void shiftdown(int[], int, int);
void heapsort(int[], int);
void printArray(int[], int);

// main function
int main()
{
    int arr[100], n, i;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("Enter the array elements: ");
	for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

	heapsort(arr, n);

	printf("Sorted array: \n");
	printArray(arr, n);

	return 0;
}

void shiftdown(int a[], int k, int n)
{
    int f,s,x;

    x=a[f=k];
    while((s=f+f+1)<n)
    {
        if(s<n-1 && a[s+1]>a[s]) s++;
        if(x>=a[s]) break;
        a[f]=a[s];
        f=s;
    }
    a[f]=x;
}

void heapsort(int a[], int n)
{
    int i,t;

    for(i=n/2-1;i>=0;i--)
        shiftdown(a,i,n);

    for(i=n-1;i>0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        shiftdown(a,0,i);
    }
}


/* Function to print an array */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
