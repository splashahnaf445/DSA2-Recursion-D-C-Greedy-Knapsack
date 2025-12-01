#include<iostream>
#include<string>

using namespace std;

int main(){

// String Functionalities in c++

string str1="The internet is Not working";
string str2;

cout<<"give command:    ";
cin>>str2;

int a = str1.length();
cout<<endl<<"Size of string 1 is :"<<a;

char c = str2.at(3);

cout<<endl<<"Character at index 3 of given string is:   "<<c;

cout<<endl<<endl;



//comparing strings
cout<<endl;
if(str1==str2){
        cout<<"Same";
}else{
    cout<<"Not same";
}

//Convert a string character to upper/lower case
str1[4]=toupper(str1[4]);

str1[16]=tolower(str1[16]);

string str3=str1+" and "+str2;
cout<<str3;

/*Find a substring in a string
bool i = str1.find("isui");

if(i==true){
    return i;
}else{
    return -1;
}
*/

//extract a substring
string ext = str1.substr(0,3);

cout<<endl<<"Extracted substring   : "<<ext;

//inserting a string in a string

string s1="Hello";

s1.insert(5,"world");

cout<<endl<<s1;

//replacing a string (start,size,"string")

s1.replace(0,5,"Mina");

cout<<endl<<s1;

};



