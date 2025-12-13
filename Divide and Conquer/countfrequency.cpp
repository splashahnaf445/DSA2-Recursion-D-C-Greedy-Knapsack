#include<iostream>
#include<vector>


using namespace std;

int countfreq(vector<int> a,int l, int r, int t){

if(l==r){
    if(a[l]==t){
        return 1;
    }
    else{
        return 0;
    }
}

int mid=(l+r)/2;

int left=countfreq(a,l,mid,t);
int right=countfreq(a,mid+1,r,t);

return left+right;

}

int main(){

vector <int> v={2,5,1,5,5,1,3};
int n=v.size();



cout<<"The frequency of 5 is:   "<<countfreq(v,0,n-1,5);

}
