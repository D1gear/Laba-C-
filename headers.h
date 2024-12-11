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
    virtual void short_Info() const;
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
    void short_Info() const override;
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

    void displayInfo() const override;
    void short_Info() const override;
    string getSpecialty() const { return specialty; }
    void setSpecialty(const string& _specialty) { specialty = _specialty; }

private:
    string specialty;
};
template <class Data>
class Binary_Tree{
public:
    void first_node(Data* stud_ptr){
        massive[1]=stud_ptr;
    }
    void insert(Data* stud_ptr){
        for(int i=1; i<100;i++){
            if(massive[i]==nullptr){ //поиск первого nullptr для последующей вставки
                massive[i]=stud_ptr;
                break;
            }
        }
    }
    void insert_by_number(Data* stud_ptr, int number){
        if(number%2==0){
            if(massive[number/2]!=nullptr){
                massive[number]=stud_ptr;
            }
            else{
                cout<<"There is no parent for this root."<<endl;
            }
        }
        else{
            if(massive[(number-1)/2]!=nullptr){
                massive[number]=stud_ptr;
            }
            else{
                cout<<"There is no parent for this root."<<endl;
            }
        }
    }
    void delete_by_number(int number){
        if (massive[number * 2] == nullptr && massive[(number * 2 + 1)] == nullptr) {
            massive[number] = nullptr;
        } else if (massive[number * 2] == nullptr && massive[(number * 2 + 1)] != nullptr) {
            massive[number] = massive[(number * 2 + 1)];
            delete_by_number((number * 2 + 1));
        } else {
            massive[number] = massive[number * 2];
            delete_by_number(number * 2);
        }
    }
    int find_last_number(){
        int marker=0;
        for(int i=99;i>0;i--){
            if(massive[i]!=nullptr){
                marker=i;
                return marker;
            }
        }
    }
    Data* search(string sur_f)
    {
        int i=1;
        for(;i<100;i++){
            if(massive[i]->get_Surname()==sur_f){
                return massive[i];
            }
        }
        if(i==100){
            cout<<"No found.";
            return nullptr;
        }
    }
    void draw_a_tree()
    {
        int marker=find_last_number();
        int n=0;
        int n_on_the_level=1;
        for(int i=1; i<=marker;){
            n=0;
            for(n, n_on_the_level;n<n_on_the_level;n++, i++){
                if(massive[i]!=nullptr){
                    cout<<"("<<i<<")";
                    massive[i]->short_Info();
                    cout<<"  ";
                }
                else{
                    cout<<"("<<i<<")"<<"0"<<"  ";
                }
            }
            cout<<endl;
            n_on_the_level*=2;
        }
    }
    Data* search(Data sur_f)
    {
        int i=1;
        for(;i<100;i++){
            if(*massive[i]==sur_f){
                return massive[i];
            }
        }
        if(i==100){
            cout<<"No found.";
            return nullptr;
        }
    }
    void draw_a_tree_not_class()
    {
        int marker=find_last_number();
        int n=0;
        int n_on_the_level=1;
        for(int i=1; i<=marker;){
            n=0;
            for(n, n_on_the_level;n<n_on_the_level;n++, i++){
                if(massive[i]!=nullptr){
                    cout<<"("<<i<<")";
                    cout<<*massive[i];
                    cout<<"  ";
                }
                else{
                    cout<<"("<<i<<")"<<"0"<<"  ";
                }
            }
            cout<<endl;
            n_on_the_level*=2;
        }
    }
private:
    Data* massive[100]={nullptr};
};
