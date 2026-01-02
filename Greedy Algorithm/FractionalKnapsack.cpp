#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Item{

public:
    string name;
    double weight,value,perunitvalue;

    Item(string n,double w,double v):
        name(n),weight(w),value(v),perunitvalue(v/w){
        }

        void display(){
            cout<<"Name:    "<<name<<"  Weight:   "<<weight<<"  Value:  "<<value<<"   Value/unit:    "<<perunitvalue<<endl;
        }

};

bool compareperunitval(Item i1,Item i2){
    return i1.perunitvalue>i2.perunitvalue;
}

void Knapsack(vector <Item> itemlist, int n, int w){
        // selects items for maximum profit
        sort(itemlist.begin(),itemlist.end(),compareperunitval);

        for(Item i:itemlist){
            i.display();
        }

        int i=0;
        double profit=0;
        cout<<"Selected items:  "<<endl;


        while(w>0 && i<n){
            if(itemlist[i].weight<=w){
                //can take the entire item
                profit+=itemlist[i].value;
                w-=itemlist[i].weight;
                itemlist[i].display();
            }
            else{
                // cant take the entire team
                int weighttaken= w;
                double p=weighttaken*itemlist[i].perunitvalue;
                profit+=p;
                w=0;
                string name=itemlist[i].name;
                double perunit=itemlist[i].perunitvalue;
                cout<<"name= "<<name<<" weight: "<<weighttaken<<" Profit added:    "<<p<<" Unit value: "<<perunit;
            }
            i++;
        }

        cout<<endl<<"Maximum profit:  "<<profit;
}

int main(){

vector<Item> items={
    Item("Potato",3,60),Item("Onion",2,160),Item("Sugar",3,300),Item("Salt",6,90)
};

int n=items.size();
int w=12 ; //knapsack capacity

Knapsack(items, n,w);

}
