#include "headers.h"
int main() {    // Создаем объекты каждого типа
    StudentInfo basicStudent("Ivanov", 19, 4.3);
    StudentWithFullName fullNameStudent("Petrov", 20, 3.9, "Petr", "Petrovich");
    StudentWithSpecialty specialtyStudent("Sidorov", 21, 4.5, "Mathematics");
    // Демонстрация работы виртуальных функций
    StudentInfo* students[] = {&basicStudent, &fullNameStudent, &specialtyStudent};
    cout << "Displaying information for each student type using virtual function:" << endl;
    for (int i;i<3;i++) {
        StudentInfo* student = students[i];
        student->displayInfo();
    }
    // Демонстрация копирования объектов
    StudentWithFullName copiedFullNameStudent = fullNameStudent;
    StudentWithSpecialty copiedSpecialtyStudent = specialtyStudent;
    cout << "\nCopied Full Name Student:" << endl;
    copiedFullNameStudent.displayInfo();
    cout << "\nCopied Specialty Student:" << endl;
    copiedSpecialtyStudent.displayInfo();
    return 0;}