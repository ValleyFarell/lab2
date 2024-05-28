#include<iostream>
#include"ArraySequence.h"
#include"ListSequence.h"
#include"ImmutableArraySequence.h"

using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    ArraySequence<int> array(a, 5);
    ImmutableArraySequence<int> imArray(a, 5);
    for (size_t i = 0; i < array.GetLength(); ++i) {
        cout << array[i] << " ";
    }
}
