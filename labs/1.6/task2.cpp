/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.6
*/

int main() {
    int intA;
    float flB;
    unsigned short wC;

    intA = 9742;
    flB = -3.54e3;
    wC = 34033;

    double dbD;
    int intE;
    char chF;

    //implicit casting
    dbD = intA;
    intE = flB;
    chF = wC;

    //explicit casting
    dbD = (double)intA;
    intE = (int)flB;
    chF = (char)wC;

    //using pointers
    void *pV;
    double *pDbl;
    pV = &intA;
    pDbl = (double*)pV;
    dbD = *pDbl;

    int *pInt;
    pV = &flB;
    pInt = (int*)pV;
    intE = *pInt;

    char *pChar;
    pV = &wC;
    pChar = (char*)pV;
    chF = *pChar;

    return 0;
}