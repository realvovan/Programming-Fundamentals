/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 2.1
*/

//варіант 4

#include "iostream"
#include "vector"
#include "string"
#include "stdlib.h"
#include "time.h"

using std::cout;
using std::vector;

template <typename T>
void printVector(std::string title,vector<T> sequence) {
    cout << title;
    for(T i : sequence) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T>
void print2dVector(std::string title,vector<vector<T>> sequence) {
    cout << title << "\n";
    for(int i = 0; i < sequence.size(); i++) printVector("Sequence " + std::to_string(i) + ": ",sequence[i]);
}

template <typename T>
void populate2dVector(vector<vector<T>> &sequence, int size) {
    for(vector<T> &i : sequence) {
        i.resize(size);
        for(int j = 0; j < size; j++) {
            i[j] = rand() % 100;
        }
    }
}

void task1() {
    cout << "=================================\nTask 1\n";
    vector<float> vec(9);
    //initialize the vector
    for(int i = 0; i < vec.size(); i++) vec[i] = i % 2 == 0 ? (-6.2 + i) : (i + 5.1);
    //bubble sort the vector in descending order
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
    printVector("Sorted vector: ",vec);
}

void task2() {
    cout << "=================================\nTask 2\n";
    vector<char> vec1(10), vec2(10), vec3(10);
    //initialize the vectors
    for(int i = 0; i < vec1.size(); i++) vec1[i] = 2 * i + 23;
    for(int i = 0; i < vec2.size(); i++) vec2[i] = 49 - 2 * i;
    //initialize the third vector with matching values from vec1 and vec2
    int k = 0;
    for(char i : vec1) {
        for(char j : vec2) {
            if(i == j) {
                vec3[k] = i;
                k++;
                break;
            }
        }
    }
    printVector("Vector 1: ",vec1);
    printVector("Vector 2: ",vec2);
    printVector("Vector 3: ",vec3);
    //now find the difference of the max and min values of the third vector (as per the task)
    int min = vec3[0],
        max = vec3[0];
    for(int i : vec3) {
        if(min > i) min = i;
        if(max < i) max = i;
    }
    int delta = max - min;
    cout << "The difference between the max and min values is " << delta << "\n";
}

void task3() {
    cout << "=================================\nTask 3\n";
    srand(time(NULL));
    vector<vector<float>> vec1_2d(4);
    vector<vector<int>> vec2_2d(4);
    vector<float> vec1_1d(4);
    vector<int> vec2_1d(4);
    //populate the vectors with random values and print them in the output
    populate2dVector(vec1_2d,5);
    populate2dVector(vec2_2d,4);
    print2dVector("2D Vector1:",vec1_2d);
    print2dVector("2D Vector2:",vec2_2d);

    for(int i = 0; i < vec1_2d.size(); i++) {
        float product = 1;
        for(float j : vec1_2d[i]) product *= j;
        vec1_1d[i] = product;
    }

    for(int i = 0; i < vec2_2d.size(); i++) {
        int max = vec2_2d[i][0];
        for(int j : vec2_2d[i]) if(max < j) max = j;
        vec2_1d[i] = max;
    }

    printVector("Vector 1: ",vec1_1d);
    printVector("Vector 2: ", vec2_1d);
}

int main() {
    task1();
    task2();
    cout << "!!!Some symbols may not appear in the VS Code terminal window, please run this in the default windows cmd!\n";
    task3();
    system("pause");
    return 0;
}