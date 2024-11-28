#include "headers.h"
int main() {
    StudentInfo s1("a");
    StudentWithFullName s2("b",19,"Vova", "Ivanovich");
    StudentWithFullName s3("c",19, "Maks", "Ivanovich");
    StudentWithFullName s4("d",19, "Igor", "Ivanovich");
    StudentInfo s5("e");
    StudentWithSpecialty s6("f",19, 3.4, "Frontend");
    StudentInfo s7("g");
    StudentWithFullName s8("h",19, "Oleg", "Ivanovich");
    StudentInfo s9("i");
    StudentWithSpecialty s10("j",19, 3.4, "Backend");
    StudentWithSpecialty s11("k",19, 3.4, "AIdeveloper");
    StudentInfo s12("l");
    StudentInfo* students[]={&s1,&s2,&s3, &s4,&s5,&s6,&s7,&s8,&s9,&s10,&s11,&s12};
    Binary_Tree<StudentInfo> tree1;
    tree1.first_node(students[0]);
    for(int i=1; i<12;i++){
        tree1.insert(students[i]);
    }
    tree1.draw_a_tree();
    tree1.delete_by_number(4);
    tree1.draw_a_tree();
    StudentInfo s13("m");
    tree1.insert_by_number(&s13, 16);
    tree1.draw_a_tree();
    StudentInfo s14("n");
    tree1.insert_by_number(&s14, 8);
    tree1.draw_a_tree();
    StudentInfo s15("o");
    tree1.insert_by_number(&s15, 4);
    tree1.draw_a_tree();
    StudentInfo* misterX = tree1.search("i");
    misterX->short_Info();
    cout<<endl;

    int W=1;
    int A=2;
    int S=3;
    int D=4;
    int Z=5;
    int* numbers[]={&W,&A,&S,&D,&Z};
    Binary_Tree<int> tree_int;
    tree_int.first_node(numbers[0]);
    for(int i=1; i<5;i++){
        tree_int.insert(numbers[i]);
    }
    tree_int.draw_a_tree_not_class();
    int* find=tree_int.search(3);
    cout<<*find<<endl;


    double X=1.01;
    double C=2.02;
    double V=3.03;
    double B=4.04;
    double N=5.05;
    double* numbers_double[]={&X,&C,&V,&B,&N};
    Binary_Tree<double> tree_double;
    tree_double.first_node(numbers_double[0]);
    for(int i=1; i<5;i++){
        tree_double.insert(numbers_double[i]);
    }
    tree_double.draw_a_tree_not_class();
}