#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class DisjointSet{

int n;
vector<int> P,Rank;  //P for Parent array ; Rank to store Ranks

public:

DisjointSet(int n):n(n){
    P=vector<int> (n);
    Rank=vector<int> (n);
}

void MakeSet(int x){
    P[x]=x;
    Rank[x]=0;
}

    int Find(int x){
        if(P[x]!=x){
            P[x]=Find(P[x]);  // setting P[x] using the recursive is actually Path Compression Technique
        }
            return P[x];
    }

    void Union(int x, int y){
        int u=Find(x);
        int v=Find(y); //stored their representative in u and v

        if(u==v){
            return;         //if both has same representative,means they are in same set; then no need to union
        }

        else {
                if(Rank[u]>Rank[v]){
            P[v]=u;                 //Union by rank (The higher rank element becomes the parent)
        }else{
            P[u]=v;
            if(Rank[u]==Rank[v]){
                Rank[v]++;
            }
        }
      }
    }

};



int main(){

int n=7;

DisjointSet ds(n);

for(int i=0;i<n;i++){
    ds.MakeSet(i);
}
// now want to make a set of 2,3 and 5
ds.Union(2,3);
ds.Union(3,5);

cout<<"Checking if 2,3,5 are connected:       "<<endl;
if(ds.Find(2)==ds.Find(3) && ds.Find(3)==ds.Find(5)){
    cout<<"2,3,5 are connected"<<endl;
}

cout<<"Checking if 1 and 3 are connected:       "<<endl;
if(ds.Find(1)==ds.Find(3)){
    cout<<"2,3,5 are connected"<<endl;
}else{
    cout<<"1 and 3 are Not connected";
}


}
