#include "headers.h"

int StudentInfo::countOfStudents = 0;

StudentInfo::StudentInfo(string _surname, int _age, double _mid) {
    surname = new string[sizeof(_surname)];
    *surname = _surname;
    age = _age;
    mid = _mid;
    countOfStudents++;
}

StudentInfo::StudentInfo(string _surname, int _age) {
    surname = new string[sizeof(_surname)];
    *surname = _surname;
    age = _age;
    mid = 0;
    ++countOfStudents;
}

StudentInfo::StudentInfo(string _surname) {
    surname = new string[sizeof(_surname)];
    *surname = _surname;
    age = 0;
    mid = 0;
    ++countOfStudents;
}
StudentInfo::StudentInfo() {
    surname = new string[sizeof(base)];
    *surname = base;
    age = 0;
    mid = 0;
    ++countOfStudents;
}
StudentInfo::StudentInfo(const StudentInfo& student) {
    surname = new string[sizeof(student.surname)];
    *surname = *(student.surname);
    age = student.age;
    mid = student.mid;
    ++countOfStudents;
}
StudentInfo::~StudentInfo() {
    delete[] surname;
    --countOfStudents;
}

void StudentInfo::displayInfo() const {
    cout << "Surname: " << *surname << ", Age: " << age << ", Mid: "<< mid << endl;
}

void StudentWithFullName::displayInfo() const {
    cout << "Surname: " << *surname << ", First Name: " << firstName << ", Patronymic: " << patronymic << ", Age: " << age << ", Mid:" << mid << endl;
}

void StudentWithSpecialty::displayInfo() const {
    cout << "Surname: " << *surname << ", Age: " << age << ", Mid: " << mid << ", Specialty: " << specialty << endl;}

StudentInfo StudentInfo::operator+(const StudentInfo& other) const {
    return StudentInfo(*surname, age + other.age, mid + other.mid);
}
StudentInfo operator-(const StudentInfo& s1, const StudentInfo& s2) {
    return StudentInfo(*(s1.surname), s1.age - s2.age, s1.mid - s2.mid);
}
StudentInfo& StudentInfo::operator++() {
    ++age;
    return *this;
}
StudentInfo StudentInfo::operator++(int) {
    StudentInfo temp = *this;
    age++;
    return temp;
}
StudentInfo::operator int() const {
    return mid;
}


ofstream& operator << (ofstream& os, StudentInfo &p){
    os<<*p.surname <<" "<< p.age <<" "<< p.mid << endl;
    return os;
}
ifstream& operator >> (ifstream& is, StudentInfo &p){
    is>>*p.surname>>p.age>>p.mid;
    return is;
}
ostream& operator << (ostream& os, StudentInfo &p){
    os<<*p.surname <<" "<< p.age <<" "<< p.mid << endl;
    return os;
}
istream& operator >> (istream& is, StudentInfo &p){
    is>>*p.surname>>p.age>>p.mid;
    return is;
}

void bin_write(ofstream& f1, StudentInfo& student){
    f1.write((char *) &student, sizeof(StudentInfo));
}
void bin_read(ifstream& f1, StudentInfo& student){
    f1.read((char *) &student, sizeof(StudentInfo));
}
string StudentInfo::get_Surname() { return *surname; }
int StudentInfo::get_Age() { return age; }
double StudentInfo::get_Mid() { return mid; }
int StudentInfo::getCountOfStudents(){
    return countOfStudents;
}
void StudentInfo::set_Age(int _age) { age = _age; }
void StudentInfo::set_Mid(double _mid) { mid = _mid; }
void StudentInfo::set_Surname(string _surname) {
    delete[] surname;
    surname = new string[sizeof(_surname)];
    *surname = _surname;
}
