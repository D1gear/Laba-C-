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
    virtual ~StudentInfo();

    virtual void displayInfo() const;

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
protected:
    string* surname;
    int age;
    double mid;
    string base = "unsigned";
    static int countOfStudents;
};

class StudentWithFullName : public StudentInfo{
public:
    StudentWithFullName(string _surname, int _age, double _mid, string _firstName, string _patronymic)
            : StudentInfo(_surname, _age, _mid), firstName(_firstName), patronymic(_patronymic) {}
    StudentWithFullName(string _surname, int _age, string _firstName, string _patronymic)
            : StudentInfo(_surname, _age), firstName(_firstName), patronymic(_patronymic) {}
    void displayInfo() const override;
    string getFirstName() const { return firstName; }
    string getPatronymic() const { return patronymic; }
    void setFirstName(const string& _firstName) { firstName = _firstName; }
    void setPatronymic(const string& _patronymic) { patronymic = _patronymic; }

private:
    string firstName;
    string patronymic;
};
class StudentWithSpecialty : public StudentInfo {
public:
    StudentWithSpecialty(string _surname, int _age, double _mid, string _specialty)
            : StudentInfo(_surname, _age, _mid), specialty(_specialty) {}

    StudentWithSpecialty(string _surname, int _age, string _specialty)
            : StudentInfo(_surname, _age), specialty(_specialty) {}

    void displayInfo() const override;  // Переопределенный метод displayInfo — добавлено

    string getSpecialty() const { return specialty; }
    void setSpecialty(const string& _specialty) { specialty = _specialty; }

private:
    string specialty;
};