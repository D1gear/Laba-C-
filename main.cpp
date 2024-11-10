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
    Binary_Tree tree1;
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
     }