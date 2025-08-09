#include<iostream>

using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[high]; //Choose last element pivot

    int i = low - 1;
    for (int j = low; j<high;j++){
        if(arr[j]<=pivot){
            i++;
            //Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //Swap arr[i + 1] and arr[high] (pivot)

    int temp = arr[i+1];
    arr[i+1]=arr[high];
    arr[high]= temp;

    return i+1;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);

        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
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
    cout<<"Enter elements: ";

    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Original Array: ";
    printArray(arr,n);

    quickSort(arr,0,n-1);
    cout<<"Sorted Array: ";
    printArray(arr,n);

    return 0;
}