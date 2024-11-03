#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
class StudentInfo {
public:
    StudentInfo(string _surname, int _age, double _mid);
    StudentInfo(string _surname, int _age);
    StudentInfo(string _surname);
    StudentInfo();
    StudentInfo(const StudentInfo& student);
    ~StudentInfo();
    string get_Surname() ;
    int get_Age() ;
    double get_Mid() ;
    static int getCountOfStudents();
    void set_Age(int _age);
    void set_Mid(double _mid);
    void set_Surname(string _surname);

    StudentInfo operator+(const StudentInfo& other) const;
    friend StudentInfo operator-(const StudentInfo& s1, const StudentInfo& s2);
    StudentInfo& operator++();
    StudentInfo operator++(int);
    operator int() const;

    friend ofstream& operator<<(ofstream& os, StudentInfo &p);
    friend ifstream& operator >> (ifstream& is, StudentInfo &p);
    friend ostream& operator<<(ostream& os, StudentInfo &p);
    friend istream& operator >> (istream& is, StudentInfo &p);

    friend void bin_write(ofstream& f1, StudentInfo& student);
    friend void bin_read(ifstream& f1, StudentInfo& student);
private:
    string* surname;
    int age;
    double mid;
    string base = "unsigned";
    static int countOfStudents;
};