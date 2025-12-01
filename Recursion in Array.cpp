#include<iostream>

using namespace std;

//prints array elements
void arrayprint(int arr[], int idx){

    if(idx<0){
        return;
    }
    arrayprint(arr,idx-1);
    cout<<arr[idx]<<"   ";

}

//calculate sum of elements in array
int arraysum(int arr[], int idx){
    if(idx<0){
        return 0;
    }
    return arr[idx]+arraysum(arr,idx-1);
}

//Find the largest element of a given array
int largestarr(int arr[], int idx){
    if(idx<0){
        return 0;
    }
    return max(arr[idx],largestarr(arr,idx-1));
}


int main(){

int arr[5]={1,2,14,8,9};

cout<<"Array elements:  "<<endl;
arrayprint(arr,sizeof(arr)/sizeof(int)-1);

int sum=arraysum(arr,sizeof(arr)/sizeof(int)-1);
cout<<"Sum of Array elements:  "<<sum<<endl;

cout<<"Largest element: "<<largestarr(arr,sizeof(arr)/sizeof(int)-1);


}
