#include<iostream>
#include<algorithm>
using namespace std;

//Function to perform Linear search
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i; //Return index if the key is found
        }
    }
    return -1; //Return -1 if the key is not found
}

//Function to perform Binary search
int binarySearch(int arr[],int n,int key){
    int low =0, high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2; //To avoid potential overflow
        if(arr[mid]==key){
            return mid; //eturn the index if the key is found
        }
        else if(arr[mid]<key){
            low=mid+1; //Search the right half
        }
        else{
            high= mid-1; //search the left half
        }
    }
    return -1; //Return -1 if the key is not found
}

int main(){
    int n, key, choice;

    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    cout<<"Enter the key to search for: ";
    cin>>key;

    cout<<"Choose the search algorithm: \n";
    cout<<"1. Linear Search\n";
    cout<<"2. Binary Search(Array must be sorted)\n";
    cin>>choice;

    int result;
    switch (choice)
    {
    case 1:
    result = linearSearch(arr,n,key);
    if(result != -1){
        cout<<"Key found at index: "<<result<<endl;
    }else{
        cout<<"Key is not found"<<endl;
    }
        break;
    case 2:
    //Sorting the array for Binary Search
    sort(arr,arr+n);
    result = binarySearch(arr,n,key);
    if(result !=-1){
        cout<<"Key is fount at index: "<<result<<endl;
    }else{
        cout<<"Key not found"<<endl;
    }
    break;

    default:
    cout<<"Invalid choice"<<endl;
        break;
    }
    return 0;
} 