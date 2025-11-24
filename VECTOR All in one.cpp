#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){

vector <int> v={5,67,48};

cout<<"Initial vector : ";
for(int x:v){
    cout<<x<<" ";
}

cout<<endl<<"Enter value to append:   ";
int a;
cin>>a;

v.push_back(a);

cout<<endl<<"After appending : ";
for(int x:v){
    cout<<x<<" ";
}

cout<<"Enter value to insert first:    ";
cin>>a;
v.insert(v.begin(),a);
cout<<endl<<"After inserting at first : ";
for(int x:v){
    cout<<x<<" ";
}

cout<<"Enter value and position to insert:    ";
int x,y;
cin>>x;
cin>>y;
if(y==0){
    v.insert(v.begin(),x);
} else{
v.insert(v.begin()+y,x);
}
cout<<endl<<"After inserting "<<x<<" at index "<<y<<endl;
for(int x:v){
    cout<<x<<" ";
}

cout<<"Enter value to insert last:    ";
cin>>a;
v.insert(v.end(),a);
cout<<endl<<"After inserting at last : ";
for(int x:v){
    cout<<x<<" ";
}

cout<<"Enter the index to remove from vector:       ";
int b;
cin>>b;
v.erase(v.begin()+b);
cout<<endl<<"After deleting value of index"<<b<<endl;
for(int x:v){
    cout<<x<<" ";
}
cout<<endl<<"---Counting the sum of the vector---";
int sum=0;
for(int x:v){
    sum+=x;
}

cout<<endl<<"Sum="<<sum;
cout<<endl<<"---The vector sorted in ascending order---"<<endl;
sort(v.begin(),v.end());
for(int x:v){
    cout<<x<<" ";
}

cout<<endl<<"---The vector sorted in descending order---"<<endl;
sort(v.rbegin(),v.rend());
for(int x:v){
    cout<<x<<" ";
}
}
