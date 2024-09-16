/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.5
*/
#include "iostream"
using std::cout;
using std::boolalpha;
//variant 4
int main() {
    //part 1
    //<УЛО1> (<УЛО2> (A<ОВ1>B) <БЛО> (<УЛО3> (C<ОВ2>D)))
    //!(!(A != B) && (C < D))
    {
        //expression 1
        int a = 66;
        float b = 12.9;
        int c = 62,
            d = 59;
        bool result = !(!(a != b) && (c<d));
        cout << "Part 1 | Expression 1 res: " << boolalpha << result << "\n";
    }
    {
        //expression 2
        float a = 3.56,
              b = 89.45;
        int c = 15;
        float d = 56.2;
        bool result = !(!(a != b) && (c<d));
        cout << "Part 1 | Expression 2 res: " << boolalpha << result << "\n";
    }
    //part 2
    //A <БО1> <УО> B <АО1> <СО> C <ОВ> D <АО2> E <БО2> <БазО> F
    //A ^ -B / *C < D * E >> sizeof(F)
    {
        const int A = 593;
        int b = -145;
        float c;
        int e = 891;

        float *pC = &c;
        *pC = 9.23;

        bool result = ((A ^ -b) / *pC) < ((43 * e) >> sizeof(short));
        cout << "Part 2 res: " << boolalpha << result << "\n";
    }
    return 0;
} 