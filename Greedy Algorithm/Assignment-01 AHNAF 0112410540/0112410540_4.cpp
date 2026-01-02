#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

struct result{
    int sum;
    int start;

};

result max3daysum(vector<int> a, int l, int r){

if(r-l+1 < 3){
    return {INT_MIN, -1};
}

if(r-l+1 == 3){
    int s = a[l]+a[l+1]+a[l+2];
    return {s,l};
}

int mid=(l+r)/2;

result left=max3daysum(a,l,mid);
result right=max3daysum(a,mid+1,r);

result cross = {INT_MIN, -1};
for(int i=mid-2;i<=mid;i++){
    if(i>=l && i+2<=r){
        int s=a[i]+a[i+1]+a[i+2];
        if(s>cross.sum){
            cross.sum=s;
            cross.start=i;
        }
    }
}

if(left.sum > right.sum && left.sum > cross.sum ) return left;
else if(right.sum > left.sum && right.sum > cross.sum ) return right;
else return cross;

}

int main(){

vector<int> temp = {28,31,29,34,30,33,27,35,32};

result res = max3daysum(temp, 0, temp.size()-1);

cout<<"The maximum total temperature is:    "<<res.sum<<endl;
cout<<"The 3-day subarray with the maximum total temperature is:   "<<endl;

for(int i=res.start; i<=res.start+2;i++){
    cout<<temp[i]<<" ";
}

}
