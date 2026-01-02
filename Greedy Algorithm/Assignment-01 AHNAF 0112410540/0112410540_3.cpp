#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Product{
public:
    string name;
    int weight,wholesale,retailperkg;
    double wholesaleperkg,profitperkg;

    Product(string n,int w, int wh, int ret): name(n),weight(w),wholesale(wh),retailperkg(ret),wholesaleperkg(wh/w),profitperkg(ret-(wh/w)){
    }


    void display(){
        cout<<"Product :  "<<name<<"   Weight: "<<weight<<"  Wholesale price:  "<<wholesale<<"  Retail price/kg: "<<retailperkg<<"  Wholesale price/kg:  "<<wholesaleperkg<<"  Profit/kg:  "<< profitperkg<<endl;
    }

};

bool compareprofit(Product p1, Product p2){
    return p1.profitperkg>p2.profitperkg;
}

void profitknapsack(vector<Product> P, int n, int wcap){

sort(P.begin(),P.end(),compareprofit);

for(Product x:P){
    x.display();
}

int i=0;
double profit=0;

cout<<"Selected items:  "<<endl;

while(wcap>0 && i<n){
    if(P[i].weight<=wcap){
        profit+=P[i].profitperkg*P[i].weight;
        wcap-=P[i].weight;
        P[i].display();
    }
    else{
        double weighttaken=wcap;
        double p=P[i].profitperkg*weighttaken;
        wcap=0;
        string name=P[i].name;
        double perunit=P[i].profitperkg;
        double whole = P[i].wholesale;
        double retail = P[i].retailperkg;
        cout<<"Product :  "<<name<<"  Weight taken: "<<weighttaken<<"  Wholesale price:  "<<whole<<"  Retail price/kg: "<<retail<<"  Profit added: "<< p<<endl;
    }
    i++;
}

cout<<"Maximum Profit:  "<<profit;

}

int main(){

vector<Product> products = {Product("Rice",100,4000,55),Product("Sugar",200,9000,62),Product("Wheat",350,7000,30),Product("Onion",250,12000,80)

};

int n=products.size();

profitknapsack(products,n,600);

}
