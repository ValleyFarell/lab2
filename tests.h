#include"ArraySequence.h"
#include"ListSequence.h"
#include <cassert>

bool listCreateTest() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
    }
    ListSequence<int> list1(arr, 10);
    for (size_t i = 0; i != 10; ++i)
        cout << list1.Get(i) << "   " << arr[i] << endl;
    return true;
}

bool listAppendTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    list.Append(tmp);
    assert(list.GetLast() == tmp);
    return true;
}

bool listPrependTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    list.Prepend(tmp);
    assert(list.GetFirst() == tmp);
    return true;
}

bool listGetLastTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    list.Append(tmp);
    assert(list.GetLast() == list.Get(list.GetLength() - 1));
    return true;
}

bool listGetFirstTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    list.Append(tmp);
    assert(list.GetFirst() == list.Get(0));
    return true;
}

bool listGetTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    int tmp_ind = rand() % 10;
    list.Set(tmp_ind, tmp);
    assert(list.Get(tmp_ind) == tmp);
    return true;
}

bool listSetTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    int tmp_ind = rand() % 10;
    list.Set(tmp_ind, tmp);
    assert(list.Get(tmp_ind) == tmp);
    return true;
}

bool listGetSubTest() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
    }
    ListSequence<int> list(arr, 10);
    ListSequence<int> list2(*(list.GetSubsequence(2, 7)));
    for (size_t i = 2; i != 7; ++i)
        assert(list2.Get(i - 2) == arr[i]);
    return true;
}

bool listInsertTest() {
    ListSequence<int> list(10);
    int tmp = rand() % 100;
    int tmp_ind = rand() % 10;
    list.InsertAt(tmp,tmp_ind);
    assert(list.Get(tmp_ind) == tmp);
    return true;
}

bool listConcatTest() {
    int arr[10], arr2[5];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
        arr2[i] = rand() % 1000 - 1000;
    }
    ListSequence<int> list1(arr, 10);
    ListSequence<int> list2(arr2, 5);
    ListSequence<int> list3(*(list1.Concat(&list2)));
    for (size_t i = 0; i != 10; ++i)
        assert(list3.Get(i) == arr[i]);
    for (size_t i = 10; i != 15; ++i)
        assert(list3.Get(i) == arr2[i - 10]);
    return true;
}

bool arrayCreateTest() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
    }
    ArraySequence<int> array1(arr, 10);
    for (size_t i = 0; i != 10; ++i)
        assert(array1.Get(i) == arr[i]);
    return true;
}

bool arrayCreateBasedTest() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
    }
    ArraySequence<int> array1(arr, 10);
    ArraySequence<int> array2(array1);
    for (size_t i = 0; i != 10; ++i)
        assert(array2.Get(i) == arr[i]);
    return true;
}

bool arrayAppendTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    array.Append(tmp);
    assert(array.GetLast() == tmp);
    return true;
}

bool arrayPrependTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    array.Prepend(tmp);
    assert(array.GetFirst() == tmp);
    return true;
}

bool arrayGetLastTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    array.Append(tmp);
    assert(array.GetLast() == array.Get(array.GetLength() - 1));
    return true;
}

bool arrayGetFirstTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    array.Append(tmp);
    assert(array.GetFirst() == array.Get(0));
    return true;
}

bool arrayGetTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    int tmp_ind = rand() % 10;
    array.Set(tmp_ind, tmp);
    assert(array.Get(tmp_ind) == tmp);
    return true;
}

bool arraySetTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    int tmp_ind = rand() % 10;
    array.Set(tmp_ind, tmp);
    assert(array.Get(tmp_ind) == tmp);
    return true;
}

bool arrayGetSubTest() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
    }
    ArraySequence<int> array(arr, 10);
    ArraySequence<int> array2(*(array.GetSubsequence(2, 7)));
    for (size_t i = 2; i != 7; ++i)
        assert(array2.Get(i - 2) == arr[i]);
    return true;
}

bool arrayInsertTest() {
    ArraySequence<int> array(10);
    int tmp = rand() % 100;
    int tmp_ind = rand() % 10;
    array.InsertAt(tmp,tmp_ind);
    assert(array.Get(tmp_ind) == tmp);
    return true;
}

bool arrayConcatTest() {
    int arr[10], arr2[5];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
        arr2[i] = rand() % 1000 - 1000;
    }
    ArraySequence<int> array1(arr, 10);
    ArraySequence<int> array2(arr2, 5);
    ArraySequence<int> array3(*(array1.Concat(&array2)));
    for (size_t i = 0; i != 10; ++i)
        assert(array3.Get(i) == arr[i]);
    for (size_t i = 10; i != 15; ++i)
        assert(array3.Get(i) == arr2[i - 10]);
    return true;
}

bool (*testFunctions[])() = {
    listCreateTest, 
    listAppendTest, 
    listPrependTest, 
    listGetLastTest, 
    listGetFirstTest, 
    listGetTest, 
    listSetTest,
    listGetSubTest,
    listInsertTest, 
    listConcatTest, 
    arrayCreateTest,
    arrayCreateBasedTest,
    arrayAppendTest,
    arrayPrependTest,
    arrayGetLastTest,
    arrayGetFirstTest,
    arrayGetTest,
    arraySetTest,
    arrayGetSubTest,
    arrayInsertTest,
    arrayPrependTest,
    arrayConcatTest
};

void testsLoop () {
    for (size_t i = 0; i < sizeof(testFunctions) / sizeof(testFunctions[0]); ++i) {
        if (testFunctions[i]()) {
            cout << " >>> " << i + 1 << ". Test passed!\n";
        } else {
            cout << " >>> " << i + 1 << ". Test failed!\n";
        }
    }
}

