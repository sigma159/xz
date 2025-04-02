#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    vector<int> grades;
    int year;
};

class studentManager {
public:
    void printStudents() {
        for (auto item : students) {
            cout << "\033[32m" << item.first << "\033[0m | ";
            for (int grade : item.second.grades) {
                cout << "\033[34m" << grade << "\033[0m ";
            }
            cout << " | " << "\033[31m" << item.second.year << " year\033[0m" << endl;
        }
    }

    void addStudent() {
        string student;
        int grade, year;
        vector<int> grades;

        cout << "\033[32madd student to system - \033[0m";
        cin >> student;
        cout << "\033[32madd his grades (Please write from 1 to 12, enter -1 to stop) - \033[0m";
        while (true) {
            cin >> grade;
            if (grade == -1) break;
            grades.push_back(grade);
        }
        cout << "\033[32madd his year - \033[0m";
        cin >> year;
        students[student] = { grades, year };

        printStudents();
    }

    void deleteStudent() {
        string student;
        cout << "\033[31mstudent for erase: \033[0m";
        cin >> student;
        students.erase(student);
        printStudents();
    }

    void findStudent() {
        string student;
        cout << "\033[34menter name of student what you need to find -\033[0m\n";
        cin >> student;

        auto it = students.find(student);
        if (it != students.end()) {
            cout << "\033[32mresult: \033[0m\n" << it->first << " | ";
            for (int grade : it->second.grades) {
                cout << "\033[34m" << grade << "\033[0m ";
            }
            cout << "| " << "\033[31m" << it->second.year << " year\033[0m" << endl;
        }
        else {
            cout << "\033[31mthere is no student like this!\033[0m" << endl;
        }
    }

    void editStudent() {
        string student, new_student;
        int grade, year;
        vector<int> new_grades;
        cout << "\033[34mstudent to edit - \033[0m" << endl;
        cin >> student;

        auto it = students.find(student);
        if (it != students.end()) {
            cout << "\033[32mEnter new student: \033[0m";
            cin >> new_student;

            cout << "\033[32mEnter student's grades (enter -1 to stop) - \033[0m";
            while (true) {
                cin >> grade;
                if (grade == -1) break;
                new_grades.push_back(grade);
            }

            cout << "\033[32mEnter student's year - \033[0m";
            cin >> year;

            students.erase(it);
            students[new_student] = { new_grades, year };

            cout << "\033[32mstudent updated successfully!\033[0m\n";
        }

        printStudents();
    }

    void saveStudents(string filename) {
        ofstream file(filename);
        for (auto& item : students) {
            file << item.first << " ";
            for (int grade : item.second.grades) {
                file << grade << " ";
            }
            file << "-1 " << item.second.year << endl;
        }
        file.close();
    }


    void loadStudents(string filename) {
        ifstream file(filename);
        string student;

        while (file >> student) {
            vector<int> grades;
            int grade, year;

            while (file >> grade && grade != -1) {
                grades.push_back(grade);
            }

            if (!(file >> year)) {
                cerr << "Error with reading Student's year: " << student << endl;
                continue;
            }

            students[student] = { grades, year };
        }
        file.close();
    }


    void honorStudents() {
        bool found = false;
        cout << "\033[34mHonor students (average 10+):\033[0m" << endl;
        for (auto item : students) {
            int sum = 0;
            for (int grade : item.second.grades) {
                sum += grade;
            }
            if (!item.second.grades.empty() && sum / item.second.grades.size() >= 10) {
                cout << "\033[32m" << item.first << "\033[0m | " << "\033[34mAverage: " << sum / item.second.grades.size() << "\033[0m" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "\033[31mNo honor students found!\033[0m" << endl;
        }
    }

private:
    map<string, Student> students;
};

int menuAction() {
    studentManager s;
    int choice;

    s.loadStudents("students.txt");

    while (true) {
        cout << "\033[34m |choice action:| \n 1.add student\n 2.delete student \n 3.find student \n 4.edit student\n 5.list students\n 6.honor students\n |7.save and exit|\033[0m" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.deleteStudent();
            break;
        case 3:
            s.findStudent();
            break;
        case 4:
            s.editStudent();
            break;
        case 5:
            s.printStudents();
            break;
        case 6:
            s.honorStudents();
            break;
        case 7:
            s.saveStudents("students.txt");
            cout << "\033[32mData saved. Exit\033[0m" << endl;
            return 0;
        default:
            cout << "\033[31mtype correct number from list!\033[0m" << endl;
        }
    }
}

int main() {
    menuAction();
}
