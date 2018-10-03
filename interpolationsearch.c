#include<stdio.h>
int interpolation_search(int a[], int bottom, int top, int item)

{

    int mid;

    while (bottom <= top) {

        mid = bottom + (top - bottom) * ((item - a[bottom]) / (a[top] - a[bottom]));

        if (item == a[mid])

            return mid + 1;   

        if (item < a[mid])

            top = mid - 1;    

        else        

            bottom = mid + 1; 

    }     

    return -1;

}
