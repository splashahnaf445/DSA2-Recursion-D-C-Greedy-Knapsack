#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Glucose{
public:

    string name;
    double bottlesize,glucose,glucoseperLitre;

    Glucose(string n, double b, double g) : name(n),bottlesize(b),glucose(g),glucoseperLitre(g/b){
    };

    void display(){
        cout<<"Name :   "<<name<<"     Bottle size:    "<<bottlesize<<"     Glucose:    "<<glucose<<"   GlucoseperLitre:    "<<glucoseperLitre<<endl;
    }

};

bool compareunit(Glucose g1, Glucose g2){
    return g1.glucoseperLitre<g2.glucoseperLitre;
}

void minknapsack(vector<Glucose>G , int n, int w){

sort(G.begin(),G.end(),compareunit);

cout<<"Sorted by minimum Glucose per liter:     "<<endl;
for(Glucose x:G){
    x.display();
}

int i=0;
double glucintake=0;

cout<<"Selected items:  "<<endl;

while(w>0 && i<n){
    if(G[i].bottlesize<=w){
        glucintake+=G[i].glucose;
        w-=G[i].bottlesize;
        G[i].display();
    }
    else{
        double weighttaken=w;
        double newintake=w*G[i].glucoseperLitre;
        glucintake+=newintake;
        w=0;
        string name=G[i].name;
        double perunit=G[i].glucoseperLitre;
        cout<<"Name:    "<<name<<"      Bottle taken:  "<<weighttaken<<"    Glucose intake:     "<<newintake<<"     Glucose per Unit:   "<<perunit<<endl;
    }

i++;
}

cout<<"Minimum glucose level:      "<<glucintake;

}


int main(){

vector<Glucose> glucose = {Glucose("Galxose-D",3,75), Glucose("Glucomax",4,80), Glucose("Sting",5,150) };

int n=glucose.size();

minknapsack(glucose, n,6);

}
