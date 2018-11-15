/*
 Sort elements of juggle's sequence wrt the absolute value of the difference with a_0 using insertion sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Creates the array
int Create(int *arr,int a){
    arr[0]=a;
    int i=1;
    while (1){
        arr=(int*)realloc(arr,(i+1)*sizeof(int));
        if (a%2 == 0){
            a=floor(sqrt(a));
        }
        else{
            a = floor(sqrt(a)*sqrt(a)*sqrt(a));
        }
        arr[i]=a;
        i++;
        if(a==1) break;
    }
    return i;
}

void CreateDiff(int *arr,int *difference, int n){
    for(int i=0;i<n;i++){
        difference[i]=abs(arr[i]-arr[0]);
    }
}

void printArray(int *arr, int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%4d ", arr[i]);
    printf("\n");
}
void insertionSort1(int *arr, int n){
    for (int i = 1; i < n; i++) {
        int key = abs(arr[i] - arr[0]);
        // Insert arr[i] at correct place
        int j = i - 1;
        int temp = arr[i];
        while (abs(arr[j] - arr[0]) > key && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        
    }
}

int main(){
    int a;
    
    printf("Enter an integer");
    scanf("%d",&a);
    int *arr = (int*)malloc(sizeof(int));
    int n=Create(arr,a);
    printf("Array: \n");
    printArray(arr, n);
    int *difference = (int*)malloc(n*sizeof(int));
    CreateDiff(arr,difference,n);
    printf("Difference: \n");
    printArray(difference, n);
    insertionSort1(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

