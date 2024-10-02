/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 2.2
*/

//Варіант 4

#include "iostream"
#include "vector"

using std::vector;
using std::cout;

enum Names {
    David,
    Tom,
    Andrew,
    Alex,
    Kate,
    Mary,
    Olga,
};

struct Student1 {
    Names Name;
    float AverageGrade;
    bool Dances;
};

struct Student2 {
    Names Name;
    int YearOfStudy;
    bool IsInArmy;
};

int main() { 
    const float EXCELLENT_GRADE = 85;
    vector<Student1> myStudents1(7);
    myStudents1[0] = {Tom,90.2,false};
    myStudents1[1] = {Andrew, 96.5,false};
    myStudents1[2] = {David,42.0,false};
    myStudents1[3] = {Alex,69.0,true};
    myStudents1[4] = {Kate,87.7,true};
    myStudents1[5] = {Mary, 79.5,false};
    myStudents1[6].Name = Olga;
    myStudents1[6].AverageGrade = 56.1;
    myStudents1[7].Dances = true;
    int count = 0;
    for(Student1 i : myStudents1) {
        if(i.AverageGrade >= EXCELLENT_GRADE && i.Dances) {
            count++;
        }
    }
    cout << "Percentage of straight-A students that also do dancing is " << ((float)count / 7 * 100) << "%\n";

    vector<Student2> myStudents2(7);
    myStudents2[0] = {Tom,1,true};
    myStudents2[1] = {Andrew,4,true};
    myStudents2[2] = {David,2,false};
    myStudents2[3] = {Alex,2,true};
    myStudents2[4] = {Kate,2,false};
    myStudents2[5] = {Mary,1,true};
    myStudents2[6].Name = Olga;
    myStudents2[6].YearOfStudy = 2;
    myStudents2[6].IsInArmy = false;
    count = 0;
    for(Student2 i : myStudents2) {
        if(i.YearOfStudy == 2 && !i.IsInArmy) {
            count++;
        }
    }
    cout << "Percentage of year 2 students that did not serve the army is " << ((float)count / 7 * 100) << "%\n";
    return 0;
}