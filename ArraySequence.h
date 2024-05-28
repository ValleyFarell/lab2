#pragma once
#include"Sequence.h"
#include"DynamicArray.h"

template<class T>
class ArraySequence : public Sequence<T> {
    private:
        DynamicArray<T> baseArray;
    public:
        ArraySequence(const ArraySequence<T>& array) {
            this->baseArray = array.baseArray;
        }
        ArraySequence(T* items, size_t count) {
            DynamicArray<T> tmpArr(items, count);
            this->baseArray = tmpArr;
        }
        ArraySequence(size_t size) {
            this->baseArray = DynamicArray<T>(size);
        }
        ArraySequence() {
            this->baseArray = DynamicArray<T>();
        }
        T GetFirst() {
            return baseArray.Get(0);
        }
        T GetLast() {
            return baseArray.Get(baseArray.GetSize());
        }
        T Get(size_t index) {
            return baseArray.Get(index);
        }
        Sequence<T>* GetSubsequence(int startIndex, int endIndex) {
            ArraySequence<T>* newSeq = new ArraySequence<T>;
            newSeq->baseArray = *(this->baseArray.GetSubArray(startIndex, endIndex));
            return newSeq;
        }
        size_t GetLength() {
            return baseArray.GetSize();
        }

        Sequence<T>*Append(T item) {
            baseArray.Resize(baseArray.GetSize() + 1);
            baseArray.Set(baseArray.GetSize() - 1, item);
            return this;
        }

        Sequence<T>*Prepend(T item) {
            this->InsertAt(item, 0);
            return this;
        }

        Sequence<T>*InsertAt(T item, int index) {
            baseArray.Resize(baseArray.GetSize() + 1);
            for (size_t i = baseArray.GetSize() - 1; i > index; --i)
                baseArray.Set(i, baseArray.Get(i - 1));
            baseArray.Set(index, item);
            return this;
        }

        ArraySequence <T>*Concat(Sequence<T>* array) {
            ArraySequence<T> *tmpArray = static_cast<ArraySequence<T>*>(array);
            for (size_t i = 0; i < tmpArray->GetLength(); ++i)
                this->Append(tmpArray->Get(i));
            return this;
        }

        T operator [] (size_t index) {
            return this->baseArray.Get(index);
        }
};