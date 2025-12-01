#include<iostream>
#include<string>

using namespace std;

class car{
public:
string name;
int price;

car(string n,int p){
    name=n;
    price=p;
}

void increaseprice(int v){
    price+=v;
}

void setpriceByValue(int a){
    a+=500;
}

void setpriceByReference(int b){
    b+=500;
}

void details(){
    cout<<"Car name:    "<<name<<",   Price:  "<<price<<"$"<<endl;
}

};

int main(){

car toyota ("Toyota",10000);

toyota.details();

toyota.increaseprice(100);

toyota.details();

int newprice=5000;

toyota.setpriceByValue(newprice);

toyota.details();

toyota.setpriceByReference(newprice);


toyota.details();

}
