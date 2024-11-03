#include "headers.h"
void print_p(StudentInfo student) {
    cout << endl;
    cout << "Surname:" << student.get_Surname() << "   ";
    cout << "Age:" << student.get_Age() << "   ";
    cout << "Mid:" << student.get_Mid() << endl;
    cout << endl;
}
int main() {
    StudentInfo Maks("Pavlov", 18, 4.5);
    StudentInfo Vova("Yakushev", 14,3.2);
    StudentInfo Lisa("Volhina", 34, 23.254);
    StudentInfo MisterX;
    StudentInfo MisterX1;
    ofstream f1("objects.txt");
    if (!f1) {
        cout << "Error: unable to write to objects.txt " << endl;
        exit(1);
    }
    f1<<Maks<<Vova;
    f1.close();
    ifstream f2("objects.txt");
    if(!f2){
        cout << "Error: unable to write to objects.txt " << endl;
        exit(1);
    }
    f2>>MisterX>>MisterX1;
    f2.close();
    cout<<"Objects after loading from .txt file:"<<endl;
    cout<<"MisterX: "<<MisterX;
    cout<<"MisterX1: "<<MisterX1;


    ofstream file1("bin.dat") ;
    bin_write(file1, Vova);
    bin_write(file1, Lisa);
    bin_write(file1, Maks);
    file1.close();
    ifstream file2("bin.dat");

    file2.seekg(sizeof(StudentInfo));
    bin_read(file2, MisterX);
    bin_read(file2, MisterX1);
    file2.close();
    cout<<"Objects after loading from binary file:"<<endl;
    cout<<"MisterX: "<<MisterX;
    cout<<"MisterX1: "<<MisterX1;
    return 0;
}
/*#include "headers.h"
void print_p(StudentInfo student) {
    cout << endl;
    cout << "Surname:" << student.get_Surname() << "   ";
    cout << "Age:" << student.get_Age() << "   ";
    cout << "Mid:" << student.get_Mid() << endl;
    cout << endl;
}
int main() {
    cout << "Amount of Students before: " << StudentInfo::getCountOfStudents() << endl;

    StudentInfo Maks("Pavlov", 18, 4.5);
    StudentInfo Vova("Yakushev", 14,3.2);

    cout << "Amount of Students after: " << StudentInfo::getCountOfStudents() << endl << endl;

    cout << "+++ method" << endl;
    StudentInfo combinedStudent = Maks + Vova;
    cout << combinedStudent.get_Age() << endl;
    cout << combinedStudent.get_Mid() << endl;

    cout << "--- friend" << endl;
    StudentInfo resultStudent = Maks - Vova;
    cout << resultStudent.get_Age() << endl;
    cout << resultStudent.get_Mid() << endl;

    cout << endl << "Prefix" << endl;
    cout << "Age Before: " << Maks.get_Age() << endl;
    //++Maks;
    cout << "Age After: " << (++Maks).get_Age() << endl;

    cout << endl << "Postfix" << endl;
    cout << "Age Before: " << Vova.get_Age() << endl;
    Vova++;
    cout << "Age After: " << Vova.get_Age() << endl;

    cout << endl << "to int" << endl;
    cout << "Mid before: " << Vova.get_Mid() << endl;
    int average = Vova;
    cout << "Int mid: " << average << endl << endl;;
    cout << "Amount of Students after all operations: " << StudentInfo::getCountOfStudents() << endl;
    return 0;

}*/