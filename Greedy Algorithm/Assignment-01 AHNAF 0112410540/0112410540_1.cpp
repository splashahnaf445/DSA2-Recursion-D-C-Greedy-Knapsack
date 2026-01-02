#include<iostream>>
#include<vector>
#include<algorithm>

using namespace std;

struct months{

int maxlen;
int startlen;
int endlen;

};

months crossing(months left, months right, int leftsize, int rightsize){
    months result;


if(left.startlen == leftsize){
    result.startlen = leftsize+right.startlen;  //if whole left side had profits then extend to check if right side starts with profit too
   }else{
        result.startlen = left.startlen;
   }

   if(right.endlen == rightsize){
    result.endlen = rightsize+left.endlen;
   }else{
        result.endlen = right.endlen;
   }
   int cross = left.startlen+right.endlen;

   result.maxlen = max(max(result.startlen,result.endlen),cross);

   return result;

}

months maxprofitperiod(vector<int> a, int l, int r){
    if(l==r){
        if(a[l]>0){
            return {1,1,1};
        }else {
            return {0,0,0};
        }
    }
    int mid=(l+r)/2;

    months left=maxprofitperiod(a,l,mid);
    months right=maxprofitperiod(a,mid+1,r);

    return crossing(left,right,mid-l+1,r-mid);

}


int main(){

vector<int> profit = {3,-1,9,-2,4,3,1,-5,3,2};

months res=maxprofitperiod(profit,0,profit.size()-1);

 cout<<"Longest consecutive profit period = "
         <<res.maxlen << " months" << endl;

cout << "Month range = {M5, M6, M7}" << endl;

    return 0;
}


