#include "headers.h"
int main() {
//    try {
//        StudentInfo student1("Ivanov", 20, 4.5);
//        StudentInfo student2("Petrov", 25);
//        StudentInfo student3("Sidorov", 150, 3.0); // Некорректный возраст
//    } catch (const exception& e) {
//        cerr << "Common error" << e.what() << endl;
//    }
    try {
        StudentInfo student4("Kuznetsov", 22, 4.0);
        student4.set_Mid(-10.0); // Некорректный возраст
    } catch (const out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
    }
//    try {
//        StudentWithFullName studentFull("Smirnov", 18, 4.8, "Ivan", "Petrovich");
//        StudentWithFullName studentError("Error", -1, 6.0, "Error", "Errorovich"); // Ошибка
//    } catch (const exception& e) {
//        cerr << "Error: " << e.what() << endl;
//    }
}