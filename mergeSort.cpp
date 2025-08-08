#include<iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[100],rightArr[1000];

    //Copy data to temp arrays

    for(int i = 0; i<n1;i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j<n2;j++){
        rightArr[j] = arr[mid + 1 +j];
    }

    //Merge the temp arrays back

    int i = 0;int j = 0; int k = left;

    while(i < n1 && j <n2){
        if(leftArr[i]<= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //Copy remaining elements

    while(i<n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = left + (right - left) / 2 ;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void printArray(int arr[],int n){
    for(int i = 0;i < n; i++){
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

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"Original Array: ";
    printArray(arr,n);

    mergeSort(arr,0,n-1);

    cout<<"Sorted Array: ";
    printArray(arr,n);

    return 0;
}