#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Activity{

public:

    int start;
    int finish;
    Activity(int s, int f){
        start=s;
        finish=f;
    }

    void display(){
        cout<<"Start time:  "<<start<<"     Finish time:    "<<finish<<endl;
    }

};

bool comparefinishtime(Activity a1, Activity a2){
    return a1.finish<a2.finish ;
}

void ActivitySelection(vector <Activity> activities){
        //find maximum no of activity
        sort(activities.begin(),activities.end(),comparefinishtime);
        cout<<"After sorted by finish time: "<<endl;
        for(Activity a:activities){
            a.display();
        }

        vector <Activity> selected;
        selected.push_back(activities[0]);
        int l=0;    // l = tracks last chosen activity

        int cnt=1;   // counts no of chosen activities

        for(int m=1;m<activities.size();m++){
            if(activities[l].finish+1<=activities[m].start){   // +1 because assumed needed 1 hour break between each activity
                selected.push_back(activities[m]);
                l=m;
                cnt++;
            }
        }

        cout<<"Maximum no. of activities: "<<cnt<<endl;
        cout<<"Selected activities: "<<endl;
        for(Activity a:selected){
            a.display();
        }
}

int main(){

vector <Activity> activitylist={
        Activity(8,12),Activity(9,10),Activity(8,10),Activity(11,13),Activity(10,12),Activity(13,15)
};

    ActivitySelection(activitylist);

}
