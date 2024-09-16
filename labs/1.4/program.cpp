/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.4
*/

//варіант 4
int main() {
    unsigned short uA;
    int nB;
    float fC;
    double dD;

    unsigned short *puA;
    int *pnB;
    float *pfC;
    double *pdD;

    void *pV;

    puA = &uA;
    pnB = &nB;
    pfC = &fC;
    pdD = &dD;

    *puA = 87;
    *pnB = 11239;
    *pfC = -532.98987;
    *pdD = 3.9e-41;

    int sizeA = sizeof(uA);
    int sizeB = sizeof(nB);
    int sizeC = sizeof(fC);
    int sizeD = sizeof(dD);
    int size_pA = sizeof(puA);
    int size_pB = sizeof(pnB);
    int size_pC = sizeof(pfC);
    int size_pD = sizeof(pdD);

    pV = &puA;
    return 0;
}