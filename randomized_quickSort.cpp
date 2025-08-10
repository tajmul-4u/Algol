#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low -1;

    for(int j = low; j < high ; j++){
        if(arr[j] < pivot){
            i++;
            //Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;

        }
    }

    //Swap arr[i+1] and arr[high]
    int temp =  arr[i + 1];
    arr[i+1] = arr[high];
    arr[high]= temp;

    return i+1;
}

int randomPartition(int arr[],int low,int high) {
    //Generate random index between low and high

    int random = low + rand() % (high - low+1);

    //Swap arr[random]with arr[high]
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;

    return partition(arr,low,high);
}

void randomizedQuickSort(int arr[],int low,int high){
    if(low < high){
        int pi =  randomPartition(arr,low,high);

        randomizedQuickSort(arr,low,pi -1);
        randomizedQuickSort(arr,pi+1,high);

    }
}

void printArray(int arr[],int n){
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    srand(time(0));//Seed for random number generator

    int n;
    cout<<"Enter elements: ";
    cin>>n;
    

    int arr[1000];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Original array: ";
    printArray(arr,n);

    randomizedQuickSort(arr,0,n-1);

    cout<<"Sorted Array : ";
    printArray(arr,n);

    return 0;

}
