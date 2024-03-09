#include<stdio.h>

void merge(int a[], int low, int high, int mid);
void mergesort(int a[], int low, int high);

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

    mergesort(arr, 0, n-1);

    printf("\nSorted List:\n");
    for(i=0; i<n; i++)
        printf("%-5d", arr[i]);

    return 0;
}

void merge(int a[], int low, int high, int mid)
{
    int i = low, j = mid+1, k = low, c[100];
    while((i<=mid)&&(j<=high))
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        c[k++]=a[i++];
    }
    while(j<=high)
    {
        c[k++]=a[j++];
    }
    for(i=low;i<k;i++)
    {
        a[i]=c[i];
    }
}

void mergesort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, high, mid);
    }
}
