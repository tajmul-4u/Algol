#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i = 1; i < n;i++){
        int key = arr[i];
        int j = i -1;

        //Move elements greater than key one Position added

        while (j >= 0 && arr[j]>key)
        {
           arr[j+1] = arr[j];
           j--;
        }
        arr[j+1] = key;

        
    }
}

void printArray(int arr[],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;

    int arr[1000];
    cout<<"Enter elements: ";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    cout<<"Original Array: ";
    printArray(arr,n);

    insertionSort(arr,n);

    cout<<"Sorted array: ";
    printArray(arr,n);

    return 0;
}
