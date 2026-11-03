#include <stdio.h>
#include <stdlib.h>

int removeduplicates(int arr[], int n){
    int k = 0;
    for(int i = 0; i<n ; i++){
        int dup = 0;
        for(int j = 0; j<k ; j++){
            if(arr[i] == arr[j]){
                dup = 1;
                break;
            }
        }
        if (!dup){
            arr[k++] = arr[i];
        }
    }

    return k;

}

void display(int arr[],int n){

    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main(){
    
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter elements");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }


    int newSize = removeduplicates(arr, n);

    printf("Resultant array: ");
    display(arr, newSize);
    return 0;
}
