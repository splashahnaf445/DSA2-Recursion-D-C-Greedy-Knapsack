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

class Graph{
    int n;
    vector<vector<int>> edges;

public:

    Graph(int n):n(n){}
    void addedge(int u, int v,int w){
        edges.push_back({w,u,v});
    }

    void MSTKruskal(){
    vector<vector<int>> T;
    DisjointSet ds(n);
    for(int i=0;i<n;i++){
        ds.MakeSet(i);
    }
    sort(edges.begin(),edges.end());
    for(vector<int> e:edges){
        int w=e[0];
        int u=e[1];
        int v=e[2];
        if(ds.Find(u)!=ds.Find(v)){
            T.push_back({u,v,w});
            ds.Union(u,v);
        }
    }

     int cost=0;
    cout<<"Chosen edges for MST:    "<<endl;

    for(vector<int> e:T){
        int u=e[0];
        int v=e[1];
        int w=e[2];

        cost+=w;
        cout<<u<<","<<v<<" , "<<w<<endl;

    }

     cout<<"Cost of MST: "<<cost;
    }

};



int main(){

    Graph g(3);
    g.addedge(0,2,4);
    g.addedge(1,2,6);
    g.addedge(0,1,2);

    g.MSTKruskal();

}

