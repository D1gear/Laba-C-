#include "headers.h"
int StudentInfo::countOfStudents = 0;
//конструкторы
StudentInfo::StudentInfo(string _surname, int _age, double _mid) {
    try {
        if (_age < 18 || _age > 100)
            throw out_of_range("Age out of range");
        if (_mid < 0.0 || _mid > 5.0)
            throw out_of_range("Mid out of range");

        surname = new (nothrow) string[sizeof(_surname)];
        if (!surname)
            throw bad_alloc();

        *surname = _surname;
        age = _age;
        mid = _mid;
        countOfStudents++;
    } catch (const out_of_range& e) {
        cerr << "Invalid input: " << e.what() << endl;
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

StudentInfo::StudentInfo(string _surname, int _age) {
    try {
        if (_age < 18 || _age > 100)
            throw out_of_range("Age out of range");
        surname = new string[sizeof(_surname)];
        *surname = _surname;
        age = _age;
        mid = 0;
        ++countOfStudents;
    } catch (const out_of_range& e) {
        cerr << "Invalid input: " << e.what() << endl;
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
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
//displayInfo
void StudentInfo::displayInfo() const {
    cout << "Surname: " << *surname << ", Age: " << age << ", Mid: "<< mid << endl;
}

void StudentWithFullName::displayInfo() const {
    cout << "Surname: " << *surname << ", First Name: " << firstName << ", Patronymic: " << patronymic << ", Age: " << age << ", Mid:" << mid << endl;
}

void StudentWithSpecialty::displayInfo() const {
    cout << "Surname: " << *surname << ", Age: " << age << ", Mid: " << mid << ", Specialty: " << specialty << endl;
}
//short_Info
void StudentInfo::short_Info() const {
    cout << "SN: " << *surname;
}

void StudentWithFullName::short_Info() const {
    cout << "SN: " << *surname << ", FN: " << firstName;
}

void StudentWithSpecialty::short_Info() const {
    cout << "SN: " << *surname<< ", SPL: " << specialty;
}
//перегрузка операторов
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
//перегрузка операторов ввода и вывода
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
//запись и чтение бинарного файла
void bin_write(ofstream& f1, StudentInfo& student){
    f1.write((char *) &student, sizeof(StudentInfo));
}
void bin_read(ifstream& f1, StudentInfo& student){
    f1.read((char *) &student, sizeof(StudentInfo));
}
//get-теры и set-теры
string StudentInfo::get_Surname() { return *surname; }
int StudentInfo::get_Age() { return age; }
double StudentInfo::get_Mid() { return mid; }
int StudentInfo::getCountOfStudents(){
    return countOfStudents;
}
void StudentInfo::set_Age(int _age) {
   try {
       if (_age < 0 || _age > 100)
           throw out_of_range("Age out of range");
       age = _age;
   } catch (const out_of_range& e) {
       cerr << "Out of range: " << e.what() << endl;
   }
}

void StudentInfo::set_Mid(double _mid) {
    try {
        if (_mid < 0.0 || _mid > 5.0)
            throw out_of_range("Mid out of range");
        mid = _mid;
    } catch (const out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
    }
}
void StudentInfo::set_Surname(string _surname) {
    delete[] surname;
    surname = new string[sizeof(_surname)];
    *surname = _surname;
}
/*
//бинарное дерево
template <class Data>
    void Binary_Tree<Data>::first_node(Data* stud_ptr){
        massive[1]=stud_ptr;
}
template <class Data>
void Binary_Tree<Data>::insert(Data* stud_ptr){
    for(int i=1; i<100;i++){
        if(massive[i]==nullptr){ //поиск первого nullptr для последующей вставки
            massive[i]=stud_ptr;
            break;
        }
    }
}
template <class Data>
void Binary_Tree<Data>::insert_by_number(Data* stud_ptr, int number){
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
template <class Data>
void Binary_Tree<Data>::delete_by_number(int number) {
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
template <class Data>
Data* Binary_Tree<Data>::search(string sur_f) {
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
template <class Data>
int Binary_Tree<Data>::find_last_number() {
    int marker=0;
    for(int i=99;i>0;i--){
        if(massive[i]!=nullptr){
            marker=i;
            return marker;
        }
    }
}
template <class Data>
void Binary_Tree<Data>::draw_a_tree() {
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



*/
