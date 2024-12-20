#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string sap_id;
    Student* next;
};

void insertStudent(Student*& head, string name, string sap_id) {
    Student* newStudent = new Student{name, sap_id, NULL};
    
    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void deleteStudent(Student*& head, int position) {
    if (head == NULL || position <= 0) return;

    Student* temp = head;

    if (position == 1) {
        head = head->next;
        delete temp;
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Student* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void displayStudents(Student* head) {
    Student* temp = head;
    int count = 1;
    while (temp != NULL) {
        cout << "Student " << count << ": " << temp->name << " (SAP ID: " << temp->sap_id << ")" << endl;
        temp = temp->next;
        count++;
    }
}

int main() {
    Student* head = NULL;

    int numStudents = 5;
    for (int i = 0; i < numStudents; i++) {
        string name, sap_id;
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter SAP ID of student " << i + 1 << ": ";
        getline(cin, sap_id);
        insertStudent(head, name, sap_id);
    }

    cout << "\nOriginal List of Students:" << endl;
    displayStudents(head);

    deleteStudent(head, 5);
    deleteStudent(head, 2);

    cout << "\nList of Students after deleting 2nd and 5th students:" << endl;
    displayStudents(head);

    return 0;
}

