#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findmax(vector<int> v,int l, int r,int w){

if(l==r){
    if(w<=v[l]){
            return -1;
    }
    else{
        return v[l];
    }
}

int mid=(l+r)/2;

int left=findmax(v,l,mid,w);
int right=findmax(v,mid+1,r,w);

int res=max(left,right);

return res;

}

int main(){

vector<int> gift={1200,1350,1550,1400,1140,3500,850};

int n=gift.size();

int res=findmax(gift,0,n-1,400);

if(res==-1){
    cout<<"No gift available within this budget";

}
else{
    cout<<"Most expensive gift within this budget:  "<<res;
}

}
