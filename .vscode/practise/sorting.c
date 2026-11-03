#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n){

    for(int i = 1 ; i < n-1 ; i++){
        int key = arr[i];
        int j = i -1;
   

        while( j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;

    }
}

int binarysearch(int arr[], int n, int target){

    int low = 0;
    int high = n-1;

    while(low <= high){

        int mid = (low+high)/2;

        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] > target){
            low = mid + 1;
        }else {
            high = mid-1;
        }
    }

    return -1;

}

void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main(){

    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    printf("Original array: ");
    display(arr, n);

    // Sort before searching (Binary Search requires a sorted array)
    insertionSort(arr, n);

    printf("Sorted array:   ");
    display(arr, n);

    int index = binarysearch(arr, n,target);
    if (index != -1){
        printf("found %d at %d \n", target, index);
    }
    else {
        printf("found!!");
    }

    return 0;
}