#include<iostream>
#include<math.h>
#include<string>

using namespace std;

//sum of 1 to n numbers : 1+2+3+....+n

int naturalsum(int n){
    if(n==1){
        return 1;
    }
    return naturalsum(n-1)+n;
}

//sum of  2+5+8+....+n

int diff3sum(int n){
    if(n==2){
        return 2;
    }
    return diff3sum(n-3)+n;
}

//1+3+5+.... sum from 1 to nth term (not to n number)

int nthtermsum(int n){
    if(n==1){
        return 1;
    }
    return nthtermsum(n-1)+(2*n-1);
}

// 2+6+10+14+..... find sum of first n terms

int nthterm4diffsum(int n){
    if(n==2){
        return 2;
    }
    return nthterm4diffsum(n-1)+(4*n-2);
}

// 1,4,7,10... find value of nth term
int diff3findn(int n){
    if(n==1){
        return 1;
    }
    return diff3findn(n-1)+3;
}

//print numbers from 1 to n

void printton(int n){
    if(n<=0){
        return;
    }
    printton(n-1);
    cout<<n<<"  ";
}

//factorial of n

int factorial(int n){
    if(n==1){
        return 1;
    }
    return factorial(n-1)*n;
}

//Calculate sum of digits of a given number n
int digitsum(int n){
    if(n==0){
        return 0;
    }
    return n%10+digitsum(n/10);
}

//Count the number of digits of a given number
int countdigit(int n){
    if(n==0){
        return 0;
    }
    return 1+countdigit(n/10);
}

//Find if a number is a power of 4

bool pow4(int n){
    if(n==1)    return true;
    if(n<=0 || n%4 !=0) return false;

    return pow4(n/4);
}

//Check whether a given string is palindrome or not
bool palindrome(string s){
    int l=s.length();

    if(l<=1){
        return true;
    }
    if(s[0]!=s[l-1]){
        return false;
    }
    return palindrome(s.substr(1,l-2));
}

int main(){

cout<<"Enter value of n:    "<<endl;
int n;
cin>>n;

cout<<"Sum of 1 to n numbers:   "<<naturalsum(n)<<endl;

cout<<"Sum of 2+5+8+.... numbers:   "<<diff3sum(n)<<endl;

cout<<"1+3+5+.... sum from 1 to nth term:   "<<nthtermsum(n)<<endl;

cout<<"2+6+10+14+..... sum of first n terms:   "<<nthterm4diffsum(n)<<endl;

cout<<"1,4,7,10..... the nth term of this series is:   "<<diff3findn(n)<<endl;

cout<<"1 to n number is:    ";
printton(n);
cout<<endl<<endl;

cout<<"Factorial of n:   "<<factorial(n)<<endl;

cout<<"Enter new value of n:    "<<endl;
int a;
cin>>a;
cout<<"Sum of the digits of n:   "<<digitsum(a)<<endl;

cout<<"Number of digits in n:   "<<countdigit(a)<<endl;

if(pow4(a)==true){
    cout<<a<<" is a power of 4";
}else{
    cout<<a<<" is Not a power of 4";
}


cout<<endl<<"Enter a string:    ";
string str;
cin>>str;

if(palindrome(str)==true){
    cout<<endl<<"The string is a palindrome";
    }
    else{
        cout<<endl<<"The string is NOT palindrome";
    }
}
