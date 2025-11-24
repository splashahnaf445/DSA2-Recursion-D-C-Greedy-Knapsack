#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Employee{
    string name;
    double salary;

public:
    int id;
    Employee(string n,int id,double s):name(n),id(id),salary(s){

    }
    double getsalary(){
        return salary;
    }

    void display(){
    cout<<"Name: "<<name<<" ID:"<<id<<" Salary:"<<salary<<endl;
    }

    void Increment(double percentage){
    salary += (salary * percentage)/100;
}

};
void print(vector <Employee> emp){
    for(Employee e:emp){
        e.display();
    }
}

bool compareid(Employee e1,Employee e2){
    return e1.id<e2.id;
}

bool comparesalary(Employee e1,Employee e2){
    return e1.id>e2.id;
}

int main(){

vector <Employee> emp={ Employee("Rahim", 2, 8000),
                                Employee("Karim", 1, 15000),
                                Employee("Abir",4,9000),
                                Employee("Roni", 3, 18000),
};
print(emp);

cout<<endl<<"---Add an additional CEO---";
cout<<"Name: ";
string n;
cin>>n;

Employee e1(n,5,120000);
emp.push_back(e1);

print(emp);

cout<<endl<<"Empoyees with salary more than 10000: "<<endl;
for(Employee e:emp){
    if(e.getsalary()>=10000){
        e.display();
    }
}

cout<<"These employees' salary has been increased:"<<endl;

for(Employee &e:emp){
    if(e.getsalary()>=15000){
        e.Increment(15);
    }else{
         e.Increment(10);
    }
}

cout<<endl<<"After salary increment:"<<endl;
print(emp);

cout<<endl<<"---Sorted the employees by id (ascending)---"<<endl;
sort(emp.begin(),emp.end(),compareid);

print(emp);

cout<<endl<<"---Sorted the employees by salary (descending)---"<<endl;
sort(emp.begin(),emp.end(),comparesalary);

print(emp);

cout<<endl<<"---*Employee with the highest salary*---"<<endl;
emp[0].display();

}
