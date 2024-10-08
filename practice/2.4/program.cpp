/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 2.4
*/

#include "iostream"
#include "stdlib.h"
#include "time.h"
#include "vector"
#include "utility"
#include "fstream"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BROWN   "\033[38;5;94m"

using std::string;
using std::vector;

const vector<char> DECORATIONS {'$','@','%','&','#'};
const vector<string> DECORATION_COLORS {RED,YELLOW,BLUE,CYAN,MAGENTA};
const int DECORATION_PROBABILITY = 10;
const int FIRST_LAYER_HEIGHT = 3;

template <typename T>
T getRandomElement(vector<T> array) {
    return array[rand() % array.size()];
}

//returns the trunk of the xmas tree as a string
string constructTrunk(int center) {
    return string(center,' ') + string("*\n") + string(center,' ') + string("*\n");
}

int main() {
    //open the file to write the xmas tree to
    std::ofstream file("christmas_tree.txt");
    if(!file.is_open()) {
        std::cout << "File could not be opened\n";
        return 0;
    }

    srand(time(NULL));
    //get user input for the number of layers in the xmas tree
    int n;
    string christmasTree = "";
    std::cout << "Enter the number of layers in the christmas tree: ";
    std::cin >> n;
    if(n < 1) {
        std::cout << "Number of layers must be greater than 0";
        return 0;
    }
    //calculate where the center of the xmas tree is located
    int center = FIRST_LAYER_HEIGHT + n - 1;

    vector<vector<int>> layers(n);
    for(int i = 0; i < n; i++) {
        int rows = FIRST_LAYER_HEIGHT+i;
        layers[i].resize(rows);
        for(int j = 0; j < rows; j++) {
            //draw a single layer
            layers[i][j] = 1+j*2;
            christmasTree += GREEN+string(center-j,' ');
            file << string(center-j,' ');
            for(int k = 0; k < layers[i][j]; k++) {
                if((rand()%100) > DECORATION_PROBABILITY) {
                    christmasTree += GREEN + string("*");
                    file << "*";
                } else {
                    char decoration = getRandomElement(DECORATIONS);
                    christmasTree += getRandomElement(DECORATION_COLORS) + decoration;
                    file << decoration;
                }
            }
        christmasTree += "\n";
        file << "\n";
        }
    }
    christmasTree += BROWN + constructTrunk(center);
    std::cout << christmasTree;
    file << constructTrunk(center);
    file.close();
}