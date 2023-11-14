//DESCRIPTION:
//The company's control system.
//There are 3 classes : Company, Department, Employee.
//We can add new employees, save information about them in a container,
//delete them, create new departments, display a list of all departments and /or employees,
//Change information about employees.
#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <icu.h>
#include <cstring>
using namespace std;
int f();
int numEmp{};
string strEmployees;
vector<string> listEmployees;
vector<string> listNames;
vector<string> listSalaries;
vector<string> listPosts;
set<string> listDepartment;
vector<string> StringListDepartmmnet;
class Employee {
public:
	Employee(string name, string salary, string post, string numDep) {
		this->name = name;
		this->salary = salary;
		this->post = post;
		this->numDep = numDep;
		numEmp++;
		listNames.push_back(name);
		listSalaries.push_back(salary);
		listPosts.push_back(post);
		StringListDepartmmnet.push_back(numDep);
		listDepartment.insert(numDep);
	}

	string setEmployee() { strEmployees = ""; strEmployees.append(to_string(numEmp) + " " + name + " " + salary + " " + post + " " + numDep); return strEmployees; }
	/*~Employee() {
		cout << "Employee Hired!";
	}*/
private:
	string name;
	string salary;
	string post;
	string numDep;
};

class Department {
public:
	Department(int x) {
		this->x = x;
	};
	void searchEmployee(int indexEmployee) {
		string infoWorker = listEmployees[indexEmployee];
		while (!listEmployees.empty()) {
			int i = 0;
			f();
			cout << "Employee Number: ";

			while (infoWorker[i] != ' ') {
				cout << infoWorker[i];
				i++;
			}
			i++;
			f();
			cout << "Name: ";

			while (infoWorker[i] != ' ') {
				cout << infoWorker[i];
				i++;
			}
			i++;
			f();
			cout << "Salary: ";

			while (infoWorker[i] != ' ') {
				cout << infoWorker[i];
				i++;
			}
			i++;
			f();
			cout << "Post: ";
			while (infoWorker[i] != ' ') {
				cout << infoWorker[i];
				i++;
			}
			i++;
			f();
			cout << "Number of Department: ";

			while (i <= infoWorker.size()) {
				cout << infoWorker[i];
				i++;

			}
			break;
		}
	}

private:
	int x;
};

class Company {
public:
	Company() {
	}

	int addNewDepartment() {
		cout << "Which department do you want to create?" << endl;
		string NewDepartment;
		cin >> NewDepartment;
		listDepartment.insert(NewDepartment);
		return 0;
	}
	int changeInformation() {

		cout << "Which employee would you like to change the information about?" << endl;
	label:
		cout << "Enter Number of Employee(0 - nothing changes): ";
		f();
		for (int y = 1; y <= listEmployees.size(); y++) {
			cout << "Employee #" << y << endl;
		}
		int numberEmployee;
		cin >> numberEmployee;
		if (numberEmployee > listEmployees.size() || numberEmployee < 0) {
			cout << "We don't have such an employee. Try again!";
			goto label;
		}
		else if (numberEmployee == 0) {
			return 0;
		}
		else {
		tryAgain:
			cout << "What information about this employee do you want to change?" << endl;
			cout << "name,numdep,salary or post" << endl;
			string answerChangeINfo;
			cin >> answerChangeINfo;
			string newName, newSalary, newPost, newNumdep;
			for (int x = 0; x < answerChangeINfo.size(); x++)
			{
				answerChangeINfo[x] = tolower(answerChangeINfo[x]);
			}
			if (answerChangeINfo == "name" || answerChangeINfo == "salary" || answerChangeINfo == "post" || answerChangeINfo == "numdep") {
				if (answerChangeINfo == "name") {
					cout << "Enter new name: ";
					cin >> newName;
					listEmployees[numberEmployee - 1] = to_string(numberEmployee) + " " + newName + " " + listSalaries[numberEmployee - 1] + " " + listPosts[numberEmployee - 1] + " " + StringListDepartmmnet[numberEmployee - 1];
				}
				else if (answerChangeINfo == "salary") {
					cout << "Enter new salary: ";
					cin >> newSalary;
					listEmployees[numberEmployee - 1] = to_string(numberEmployee) + " " + listNames[numberEmployee - 1] + " " + newSalary + " " + listPosts[numberEmployee - 1] + " " + StringListDepartmmnet[numberEmployee - 1];

				}
				else if (answerChangeINfo == "post") {
					cout << "Enter new post: ";
					cin >> newPost;
					listEmployees[numberEmployee - 1] = to_string(numberEmployee) + " " + listNames[numberEmployee - 1] + " " + listSalaries[numberEmployee - 1] + " " + newPost + " " + StringListDepartmmnet[numberEmployee - 1];
				}
				else {
					cout << "Enter new number of department: ";
					cin >> newNumdep;
					listEmployees[numberEmployee - 1] = to_string(numberEmployee) + " " + listNames[numberEmployee - 1] + " " + listSalaries[numberEmployee - 1] + " " + listPosts[numberEmployee - 1] + " " + newNumdep;
				}
			}

			else {
				cout << "The data is entered incorrectly, please try again";
				goto tryAgain;
			}
		}

	}

};

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Instructions: ";
	cout << "\nEnter the command, \n1 - enter data for a new employee, \n2 - delete data about any employee, \n3 - search for employees, \n";
	cout << "4 - display information about all employees, \n5 - display a list of departments, \n6 - add a new department, \n7 - change employee information, \n8 - request instructions again, \n0 - exit from programm: ";
	f(); f();
	int x;
	int y = 0;
	Department department(y);
	Company company;
	vector<string> listOfEmployees;
	while (true) {
		cin >> x;
		switch (x) {
		case 1: {
			string salary, numdep; string name, post;
			cout << "Enter name of new employee: ";
			cin >> name;
			cout << endl << "Enter salary of new employee: ";
			cin >> salary;
			cout << endl << "Enter post of new employee: ";
			cin >> post;
			cout << endl << "Enter number of department of your new employee: ";
			cin >> numdep; f();
			Employee employee(name, salary, post, numdep);
			listEmployees.insert(listEmployees.cend(), employee.setEmployee());
			break; }
		case 2: {

			if (listEmployees.empty()) { cout << "We haven't employees, boss"; }
			else {
				cout << "Who are we firing, boss?" << endl;
				for (int i{ 1 }; i <= listEmployees.size(); i++) {
					cout << "Employee #" << i << endl;
				}
				cout << "Choose the number of employee (enter 666 - No one is fired; 0 - all dismissed): " << endl;
				int x;
				cin >> x;
				if (x == 0) {
					listEmployees.clear();
				}
				else if (x != 666) {
					listEmployees.erase(listEmployees.cbegin() + x - 1);
				}
			}
		}
			  break;
		case 3: {
			cout << "choose employee what get info about them"; f();
			for (int i{ 1 }; i <= listEmployees.size(); i++) {
				cout << "Employee #" << i << endl;
			}
			int j;
			cin >> j;
			department.searchEmployee(j - 1);
			f();
			break;
		}
		case 4: {
			for (int i = 0; i < listEmployees.size(); i++) {
				department.searchEmployee(i); cout << endl;
			}
			f();
			break;
		}
		case 5: {
			for (string n : listDepartment)
			{
				cout << n << " Department" << "\t";
			}
			cout << "\n";
			break; }
		case 6: {
			company.addNewDepartment();
			break;
		}
		case 7: {
			company.changeInformation();
			break;

		}
		case 8:
		{
			cout << "Instructions: ";
			cout << "\nEnter the command, \n1 - enter data for a new employee, \n2 - delete data about any employee, \n3 - search for employees, \n";
			cout << "4 - display information about all employees, \n5 - display a list of departments, \n6 - add a new department, \n7 - change employee information, \n8 - request instructions again, \n0 - exit from programm: ";
			f(); f();
			break;
		}
		case 0:
			break;
		default: {
			cout << "Values is incorrect!!!";
			f(); }
		}
	}
}

int f() {
	cout << endl;
	return 0;
}