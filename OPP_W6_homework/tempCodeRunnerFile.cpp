#include<iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
    string emp_id;
    string name;
    int age;
    string address;
    float salary;

public:
    Employee(string emp_id, string name, int age, string address, float salary) {
        this->emp_id = emp_id;
        this->name = name;
        this->age = age;
        this->address = address;
        this->salary = salary;
    }

    // Getter 메서드 추가
    string getEmpID() {
        return emp_id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getAddress() {
        return address;
    }

    float getSalary() {
        return salary;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string emp_id, string name, int age, string address, float salary, int teamSize)
        : Employee(emp_id, name, age, address, salary) {
        this->teamSize = teamSize;
    }

    int getTeamsize(){return teamSize;}
};



int main() {
    Manager employee("EMP001", "김진서", 35, "seoul", 5000.00, 10);
    cout << "Manager Information" << endl;
    cout << "Employee ID: " << employee.getEmpID() << endl;
    cout << "Name: " << employee.getName() << endl;
    cout << "Age: " << employee.getAge() << endl;
    cout << "Address: " << employee.getAddress() << endl;
    cout << fixed << setprecision(2); // 출력 형식을 고정 소수점으로 설정하기.
    cout << "Salary: $" << employee.getSalary() << endl;
    cout << "Team Size: " << employee.getTeamsize() << endl;

    return 0;
}

