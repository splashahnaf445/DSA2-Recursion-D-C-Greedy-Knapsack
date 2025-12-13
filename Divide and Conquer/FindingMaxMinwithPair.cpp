#include<iostream>
#include<vector>

using namespace std;

pair<int,int> Findmaxmin(vector <int> a, int l, int r){

if(l==r){
    return {a[l],a[l]};
}

int mid=(l+r)/2;

pair<int , int> left=Findmaxmin(a,l,mid);
pair<int , int> right=Findmaxmin(a,mid+1,r);

int gmax,gmin,hmax,hmin,fmax,fmin;

gmax=left.first;
gmin=left.second;
hmax=right.first;
hmin=right.second;

fmax = max(gmax,hmax);
fmin=min(gmin,hmin);

return {fmax, fmin};

}

int main(){

vector <int> v= {4,34,23,98,6,13,21};

int n = v.size();
pair<int, int> x = Findmaxmin(v, 0, n-1);

cout << "Max: " << x.first << endl;
cout << "Min: " << x.second << endl;

}
