/*
Find minimum and maximum element in the array using decrease and conquer technique
*/

#include <stdio.h>
int max,min;
void minmax(int a[], int l, int h)
{
    //printf("max=%d,min=%d\n",max,min);
    if(l>h)
    return;
    if(h-l==1)
    {
        if(max<a[l])
        max=a[l];
        if(max<a[h])
        max=a[h];
        if(min>a[l])
        min=a[l];
        if(min>a[h])
        min=a[h];
        return;
    }
    else if (h-l==0){
        if(a[l]>max)
        max=a[l];
        if(a[l]<min)
        min=a[l];
        return;
    }
    int m=(l+h)/2;
    minmax(a,l,m);
    minmax(a,m+1,h);
}
int main() {
    // Write C code here
    //printf("Try programiz.pro");
    int a[]={4,63,-2,-10,7,1};
    int n=sizeof(a)/sizeof(a[0]);
    n=n-1;
    //printf("%d",n);
    max=a[0];
    min=a[0];
    minmax(a,0,n);
    printf("max=%d,min=%d",max,min);
    return 0;
}
