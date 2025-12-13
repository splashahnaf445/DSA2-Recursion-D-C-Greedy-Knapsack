#include<iostream>
#include<vector>

using namespace std;

struct subarray{
int sum,Lidx,Ridx;

};

subarray maxcrosssumarray(vector<int> a, int low, int mid, int high){
    int sum=0;
    int left_sum = INT_MIN; //INT_MIN : Negative infinity
    int left_idx=-1;
    for(int i=mid;i>=low;i--){
        sum+=a[i];
        if(sum>left_sum){
            left_sum=sum;
            left_idx=i;
        }
    }
    sum=0;
    int right_sum=INT_MIN;
    int right_idx=-1;

    for(int j=mid+1;j<=high;j++){
        sum+=a[j];
        if(sum>right_sum){
            right_sum=sum;
            right_idx=j;
        }
    }

    return {left_sum+right_sum,left_idx,right_idx};
}

subarray maxsumsubarray(vector<int> a, int low, int high){
if(low==high){
    return {a[low],low,high};
}

int mid=(low+high)/2;

subarray left=maxsumsubarray(a,low,mid);
subarray right=maxsumsubarray(a,mid+1,high);

subarray cross=maxcrosssumarray(a,low,mid,high);
    if(left.sum>=right.sum && left.sum>=cross.sum) return left;
    else if(right.sum>=left.sum && right.sum>=cross.sum) return right;
    else return cross;
}

int main(){


    vector<int> a ={-2,5,-1,4,3,-7,6};
    int n=a.size();

    subarray maxsub=maxsumsubarray(a,0,n-1);
    int sum=maxsub.sum;
    int l=maxsub.Lidx;
    int r=maxsub.Ridx;

    cout<<"Maximum subarray sum:    "<<sum<<endl;
    for(int i=l;i<=r;i++){
        cout<<a[i]<<" ";

    }


}
