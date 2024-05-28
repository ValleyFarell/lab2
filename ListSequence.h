#pragma once
#include"Sequence.h"
#include"LinkedList.h"

template<class T>
class ListSequence : public Sequence<T> {
    private:
        LinkedList<T> listBase;
    public:
        ListSequence(const ListSequence<T> & list) {
            this->listBase = list.listBase;
        }
        ListSequence (T* items, size_t count) {
            listBase = LinkedList<T>(items, count);
        }
        ListSequence() {
            this->listBase = LinkedList<T>();
        }
        T GetFirst() {
            return listBase.GetFirst();
        }

        T GetLast() {
            return listBase.GetLast();
        }

        T Get(size_t index) {
            return listBase.Get(index);
        }

        ListSequence<T> *GetSubsequence(int startIndex, int endIndex) {
            LinkedList<T> *newList = this->listBase.GetSubList(startIndex, endIndex);
            ListSequence<T> *newSeq = new ListSequence<T>;
            newSeq->listBase = *newList;
            return newSeq;
        }

        size_t GetLength() {
            return listBase.GetLength();
        }

        Sequence<T>*Append(T item) {
            listBase.Append(item);
            return this;
        }

        Sequence<T>*Prepend(T item) {
            listBase.Prepend(item);
            return this;
        }

        Sequence<T>*InsertAt(T item, int index) {
            listBase.InsertAt(item, index);
            return this;
        }

        ListSequence <T> *Concat(Sequence<T>* list) {
            ListSequence<T> *tmpList = static_cast<ListSequence<T>*>(list);
            this->listBase.Concat(tmpList->listBase);
            return this;
        }
};
