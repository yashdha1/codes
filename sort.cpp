
#include<iostream>
using namespace std;

//Function to read the array from user input
void readArray(int arr[],int n){
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

//Function to diplay the array
void displayArray(int arr[],int n){
    cout<<"Array elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Function to swap two elements
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

//Function to sort the array using Bubble sort algorithm
void sortArray(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);  //Swap if the current element is greater then the next
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of the elements in the array: ";
    cin>>n;

    int arr[n];
    readArray(arr,n); //Read the array
    cout<<"Before sorting: ";
    displayArray(arr,n); //Display the array before sorting

    sortArray(arr,n);  //Sort the array using Bubble sort

    cout<<"After sorting: ";
    displayArray(arr,n);  //Display the array after sorting

    return 0;
}