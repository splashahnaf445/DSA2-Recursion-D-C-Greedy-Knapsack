#include<iostream>

using namespace std;

/* Example-1:
Suppose that, you are at 0th stair and you have to reach at nth stair.
Each time you can climb 1 or 2 steps. Find out the total number of distinct ways you can climb from 0th to nth stair.
(Fibonacci number)

*/

/*Example-2:
f(n,m) = total no of sandwiches you can make if you have n breads and m eggs.
        n>=2 & m>=3 at least. (needs 2 breads and 3eggs to make a sandwich)
        so base case : if n<2 or m<3 ; then no sandwich can be made > return 0

*/

int distinctfib(int n){
    if(n==1 || n==2){
        return n;
    }
    return distinctfib(n-1)+distinctfib(n-2);
}

int Sandwich(int b,int e){
    if(b<2 || e<3){
        return 0;
    }
    return 1+Sandwich(b-2,e-3);
}

int main(){
int n;

cout<<"Enter value of n:    "<<endl;
cin>>n;

cout<<"Total no. of distinct ways/n th fibonacci number:    "<<distinctfib(n)<<endl;

cout<<"Enter no. of breads:    "<<endl;
int m;
cin>>m;

cout<<"Enter no. of eggs:    "<<endl;
cin>>n;

cout<<"Total no. of Sandwiches:    "<<Sandwich(m,n)<<endl;

}
