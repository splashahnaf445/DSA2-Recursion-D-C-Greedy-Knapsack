#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Employee{
    string name;
    double salary;

    public:
    int id;

    Employee(string n,double s,int i){
        name=n;
        salary=s;
        id=i;
    }

    void display(){
        cout<<"Name:    "<<name<<" ID:  "<<id<<" Salary:    "<<salary<<endl;
    }

    double getsalary(){
        return salary;
    }

    void Increment(double percentage){
        salary+=salary*percentage/100;
    }


};

void print(vector<Employee> emp){
    for(Employee e:emp){
        e.display();
    }
}

bool compareid(Employee e1, Employee e2){
    return e1.id<e2.id;
}

bool comparesal(Employee e1, Employee e2){
    return e1.getsalary()>e2.getsalary();
}

int main() {

  vector <Employee> emp={Employee("Rahim",8000,2),
                        Employee("Karim",15000,1),
                        Employee("Abir",9000,4),
                        Employee("Roni",18000,3),
  };

print(emp);

cout<<"Employees with salary more than 10000$ :   "<<endl<<endl<<endl;

for(Employee e:emp){
    if(e.getsalary()>=10000){
        e.display();
    }
}

cout<<"Employees have got increase in salary by 15% and 10% :   "<<endl<<endl<<endl;

for(Employee &e:emp){
    if(e.getsalary()>=15000){
        e.Increment(15);
    }
    else{
        e.Increment(10);
    }
}

print(emp);

sort(emp.begin(),emp.end(),compareid);

cout<<"Employees sorted by ID :   "<<endl<<endl<<endl;
print(emp);

sort(emp.begin(),emp.end(),comparesal);

cout<<"Employees sorted by salary :   "<<endl<<endl<<endl;
print(emp);

cout<<"Employee with highest salary:    ";
emp[0].display();

}
