#include<iostream>
#include<vector>
using namespace std;

class graph{
    int n;
    vector<vector<int>> mat;
    bool directed;
    vector<int> Q,key,P;

public:

    graph(int n,bool d):n(n),directed(d){
    mat= vector<vector<int>> (n,vector<int>(n,0));
    Q=vector<int> (n);
    key=vector<int> (n);
    P=vector<int> (n);

    }
    void addedge(int u, int v, int w){
        mat[u][v]=w;
        if(!directed){
            mat[v][u]=w;
        }
    }
    bool hasedge(int u, int v){
         if(mat[u][v]!=0){
            return true;
        }else{
            return false;
        }
    }
    int ExtractMin(){
        int m=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(key[i]<m && Q[i]==1){
                m=key[i];
                idx=i;
            }
        }
        return idx;
    }
    void MSTPrim(int r){

        for(int i=0;i<n;i++){
            Q[i]=1;
            key[i]=INT_MAX;
            P[i]=-1;
        }
        key[r]=0;
        for(int i=1;i<=n;i++){
            int u=ExtractMin();
            if(u==-1)break;
            Q[u]=0;

            for(int v=0;v<n;v++){
                if(hasedge(u,v)){
                    if(Q[v]==1 && key[v]>mat[u][v]){
                        key[v]=mat[u][v];
                        P[v]=u;
                    }
                }
            }
        }

        int cost=0;
    cout<<"Chosen edges for MST:    "<<endl;
    for(int i=0;i<n;i++){
        if(i!=r){
            cout<<"("<<i<<" , "<<P[i]<<" , "<<key[i]<<")"<<endl;
            cost+=key[i];
        }
    }
    cout<<"Cost of MST: "<<cost<<endl;
    }


};


int main(){

graph g(5,false);

g.addedge(0,1,4);
g.addedge(0,2,5);
g.addedge(1,3,3);
g.addedge(1,4,1);
g.addedge(2,3,6);
g.addedge(3,4,2);

g.MSTPrim(2);

}
