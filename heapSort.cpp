#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    //If left child is larger than root
    if (left < n && arr[left]>arr[largest])
    largest = left;

    //If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    largest = right;

    //If largest is not root
    if (largest !=i){
        //Swap 
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //Recursively heapify the affected sub-tree
        heapify(arr,n,largest);

    }
}

void heapSort(int arr[],int n){
    //Build heap (rearrange array)
    for (int i = n/2-1; i>=0;i--){
        heapify(arr,n,i);
    }
    //Extract elements from heap one by one
    for(int i = n-1; i > 0;i--){
        //Move current root to end
        int temp = arr[0];
        arr[0]=arr[i];
        arr[i]= temp;

        //Call heapify on the reduced heap
        heapify(arr,i,0);
    }

}

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[1000];
    cout<<"Enter element: ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Original Arrau: ";
    printArray(arr,n);
    heapSort(arr,n);
    cout<<"Sorted array: ";
    printArray(arr,n);

    return 0;
}