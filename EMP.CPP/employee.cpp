 
//  EMPLOYEE MANAGEMENT SYSTEM

#include<iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include<conio.h>
using namespace std;

// structure of employee
struct employee {
    
    string name, id, gender, dob, email;


    string department, designation, doj, location;
    int salary, experience;

    //  Attendance
    float attendance;
    int workingHours;
    int overtimeHours;

    
    string address, contact;
};

employee list[100];
int total = 0;


void saveToFile() {
    ofstream fout("employee_data.txt");
    for (int i = 0; i < total; i++) {
        fout << list[i].name << " " << list[i].id << " " << list[i].gender << " "
             << list[i].dob << " " << list[i].email << " "
             << list[i].department << " " << list[i].designation << " " << list[i].doj << " "
             << list[i].location << " " << list[i].salary << " " << list[i].experience << " "
             << list[i].attendance << " " << list[i].workingHours << " " << list[i].overtimeHours << " "
             << list[i].address << " " << list[i].contact << "\n";
    }
    fout.close();
}


void loadFromFile() {
    ifstream fin("employee_data.txt");
    total = 0;
    while (fin >> list[total].name >> list[total].id >> list[total].gender
               >> list[total].dob >> list[total].email
               >> list[total].department >> list[total].designation >> list[total].doj
               >> list[total].location >> list[total].salary >> list[total].experience
               >> list[total].attendance >> list[total].workingHours >> list[total].overtimeHours
               >> list[total].address >> list[total].contact) {
        total++;
    }
    fin.close();
}


void  employeedata() {
    int choice;
    cout << "How many employees data do you want to enter? ";
    cin >> choice;
    cin.ignore(); // buffer clear

    for (int i = total; i < total + choice; i++) {
        cout << "\n\n ======= Enter data for Employee ========= " << i + 1 << " =====" << endl;

        cout << "Employee Name : ";
        getline(cin, list[i].name);
        cout << "ID : ";
        getline(cin, list[i].id);
        cout << "Gender : ";
        getline(cin, list[i].gender);

        cout << "Date of Birth (DD/MM/YYYY): ";
        getline(cin, list[i].dob);
        cout << "Email ID : ";
        getline(cin, list[i].email);
        cout << "Department : ";
        getline(cin, list[i].department);
        cout << "Designation : ";
        getline(cin, list[i].designation);

        cout << "Date of Joining : ";
        getline(cin, list[i].doj);

        cout << "Work Location : ";
        getline(cin, list[i].location);

        cout << "Salary : ";
        cin >> list[i].salary;

        cout << "Experience (Years): ";
        cin >> list[i].experience;

        cout << "Attendance % : ";
        cin >> list[i].attendance;

        cout << "Working Hours : ";
        cin >> list[i].workingHours;

        cout << "Overtime Hours : ";
        cin >> list[i].overtimeHours;

        cin.ignore(); // buffer clear

        cout << "Address : ";
        getline(cin, list[i].address);

        cout << "Contact : ";
        getline(cin, list[i].contact);
    }
    total += choice;
    saveToFile();
}




void show() {
    if (total != 0) {
        for (int i = 0; i < total; i++) {
            cout << "\n ===== Data of Employee " << i + 1 << " =====" << endl;
            cout << "Name : " << list[i].name << endl;
            cout << "ID : " << list[i].id << endl;
            cout << "Gender : " << list[i].gender << endl;
            cout << "DOB : " << list[i].dob << endl;
            cout << "Email : " << list[i].email << endl;

            cout << "Department : " << list[i].department << endl;
            cout << "Designation : " << list[i].designation << endl;
            cout << "Date of Joining : " << list[i].doj << endl;
            cout << "Work Location : " << list[i].location << endl;

            cout << "Salary : " << list[i].salary << endl;
            cout << "Experience : " << list[i].experience << " years" << endl;

            cout << "Attendance : " << list[i].attendance << "%" << endl;
            cout << "Working Hours : " << list[i].workingHours << endl;
            cout << "Overtime Hours : " << list[i].overtimeHours << endl;

            cout << "Address : " << list[i].address << endl;
            cout << "Contact : " << list[i].contact << endl;
        }
    } else {
        cout << "No employee records available....!" << endl;
    }
}


void search() {
    if (total != 0) {
        string id;
        cout << "Enter Employee ID to search : ";
        cin >> id;
        for (int i = 0; i < total; i++) {
            if (id == list[i].id) {
                cout << "\n========= Record found for=========== " << list[i].name << endl;
                cout << "ID : " << list[i].id << endl;
                cout << "Department : " << list[i].department << endl;
                cout << "Designation : " << list[i].designation << endl;
                cout << "Salary : " << list[i].salary << endl;
                return;
            }
        }
        cout << "No such employee found!" << endl;
    } else {
        cout << "Record is empty!" << endl;
    }
}
 
void update() {
    if (total != 0) {
        string id;
        cout << "Enter Employee ID to update : ";
        cin >> id;
        for (int i = 0; i < total; i++) {
            if (id == list[i].id) {
                cout << "\n Previous Data for " << list[i].name << endl;
                cout << "Salary : " << list[i].salary << endl;

                cout << "\n Enter new data :" << endl;
                cout << "Name : ";
                 cin >> list[i].name;
                cout << "Salary : "; 
                cin >> list[i].salary;

                saveToFile();
                return;
            }
        }
        cout << "No such employee found !" << endl;
    } else {
        cout << "Record is empty........!" << endl;
    }
}


void del() {
    if (total != 0) {
        char user;
        cout << "Press 1 to delete full record :" << endl;
        cout << "Press 2 to delete specific record :" << endl;
        user = getch();
        if (user == '1') {
            total = 0;
            saveToFile();
            cout << "All records deleted." << endl;
        } else if (user == '2') {
            string id;
            cout << "Enter Employee ID to delete : ";
            cin >> id;
            for (int i = 0; i < total; i++) {
                if (id == list[i].id) {
                    for (int j = i; j < total - 1; j++) {
                        list[j] = list[j + 1];
                    }
                    total--;
                    saveToFile();
                    cout << "Record deleted........." << endl;
                    return;
                }
            }
            cout << "Employee not found." << endl;
        }
    } else {
        cout << "Record is empty .....!" << endl;
    }
}


int main() {
    loadFromFile();

    cout << "\n\n\n\t =============Employee Management System=============== ";
    cout << "\n\n\n\t Sign up " << endl;
    string username, password;
    cout << " Enter username : ";
     cin >> username;
    cout << " Enter password : "; 
    cin >> password;

    cout << " Creating ID please wait ";
    for (int i = 0; i < 8; i++) { cout << ". "; Sleep(200); }
    cout << " \n ID created successfully!" << endl;
    system("cls");

Start:
    system("CLS");
    cout << "\n\n\n\t============ Login===============" << endl;
    string username1, password1;
    cout << " username : "; cin >> username1;
    cout << " password : "; cin >> password1;
    if (username1 == username && password1 == password) {
        cout << "\n Login Successful!\n";
        system("CLS");
        char user;
        while (1) {
            cout << "\n\n Press 1 to enter data " << endl;
            cout << " Press 2 to show data " << endl;
            cout << " Press 3 to search data " << endl;
            cout << " Press 4 to update data " << endl;
            cout << " Press 5 to delete data " << endl;
            cout << " Press 6 to logout " << endl;
            cout << " Press 7 to exit " << endl;

            user = getch();
            system("CLS");
            switch (user) {
                case '1': 
                employeedata();
                 break;
                case '2': 
                show();
                 break;
                case '3':
                 search(); 
                 break;
                case '4':
                 update(); 
                 break;
                case '5': 
                del(); 
                break;
                case '6': 
                goto Start;
                case '7':
                 exit(0);
                default: cout << " Invalid input " << endl; break;
            }
        }
    } else {
        cout << "\n\n\t Username or Password incorrect. " << endl;
        Sleep(1000);
        goto Start;
    }
}
