/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.3
*/

int main() {
    //Варіант 4
    int nA = 22; //22=00...0001 0110
    int nInverA = ~nA; //~22 = 11...11101001 = -23

    int nB = 93; //      93=0101 1101
    int nC = 126; //    126=0111 1110
    int nBandC = nB & nC; //0101 1100 = 92

    int nD = 138;//    138=1000 1010
    int nE = 69; //     69=0100 0101
    int nDorE = nD | nE; //1100 1111 = 207

    int nF = 38; //       38=0010 0110
    int nG = 82; //       82=0101 0010
    int nFexclG = nF ^ nG; //0111 0100 = 116

    int nH = 911; //         911=0000 0011 1000 1111
    int nI = 5;
    int nLeftShift = nH << nI; //0111 0001 1110 0000
                               //=29152
    int nJ = -91; //           -91=11...1010 0101
    int nK = 5;
    int nRightShift = nJ >> nK; // 11...1111 1101 
                                //=-3
    return 0;
}