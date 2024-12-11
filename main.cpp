#include "headers.h"
int main() {

    StudentInfo student1("Ivanov", 20, 4.5);
    StudentInfo student2("Petrov", 4); // Некорректный возраст
    StudentInfo student3("Sidorov", 23, -3.0); // Некорректный балл

    StudentInfo student4("Kuznetsov", 22, 4.0);
    student4.set_Mid(-10.0); // Некорректный балл

    StudentWithFullName studentFull("Smirnov", 18, 4.8, "Ivan", "Petrovich");
    StudentWithFullName studentError("Error", 19, 6, "Error", "Errorovich"); // Некорректный балл
}