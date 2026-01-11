#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class chocolate{

public:

string type;
int amount;
int price;
int priceperunit;

chocolate(string t, int a, int p):type(t),amount(a),price(p),priceperunit(p/a){

}

void display(){
    cout<<"choclate:    "<<type<<", amount:  "<<amount<<", price: "<<price<<",  unit price:    "<<priceperunit<<endl;
}


};
bool compareunit(chocolate c1,chocolate c2){
    return c1.priceperunit<c2.priceperunit;
}



void knapsack(vector<chocolate> v,int n,int w){

sort(v.begin(),v.end(),compareunit);

cout<<"After sorted : "<<endl;

for(chocolate c:v){
    c.display();


}
cout<<endl<<endl;

int amounttake=0;
int i=0;

while(w>0 && i<n){
    if(v[i].price<=w){
        amounttake+=v[i].amount;
        w-=v[i].price;
        cout<<"chocolate:    "<<v[i].type<<", amount:  "<<v[i].amount<<", price: "<<v[i].price<<",  unit price:    "<<v[i].priceperunit<<endl;

    }
    else{
        int pricetaken=w;
        int amounttaken=pricetaken/v[i].priceperunit;
        amounttake+=amounttaken;
        w=0;
        string typeq=v[i].type;
        int perunit=v[i].priceperunit;
        int pricetook=amounttaken*v[i].priceperunit;
        cout<<"chocolate:    "<<typeq<<", amount:  "<<amounttaken<<", price: "<<pricetook<<",  unit price:    "<<perunit<<endl;

    }
    i++;
}

cout<<"Maximum chocolates:  "<<amounttake;

}
int main(){


vector<chocolate> ch = {chocolate("Mr. mango",30,30),chocolate("Toffee",4,12),chocolate("Milk candy",5,10),chocolate("Kitkat",10,40)};

for(chocolate c:ch){
    c.display();
}
int n=ch.size();
knapsack(ch,n,50);

}
