#ifndef TABLE_POINTERS_H
#define TABLE_POINTERS_H
#include <iostream>

template <typename T> class TablePointers{
public:
    TablePointers(int n);
    TablePointers(): table(0), size(0) {}
    TablePointers(const TablePointers &copy);
    TablePointers &operator=(const TablePointers &left);
    int getSize() const { return size;}
    void addElement(T* element);
    void removeElement(int index);
    void removeAll();
    T* operator[](std::size_t n) const { return table[n];}
    ~TablePointers() { removeAll(); delete[] table;}
private:
    T **table;
    int size;
};

template <typename T> TablePointers<T>::TablePointers(int n) {
    size = n;
    table = new T*[n];
    for (int i = 0; i < n; ++i) {
        table[i] = new T;
    }
}

template <typename T> TablePointers<T>::TablePointers(const TablePointers &copy){
    size = copy.size;
    table = new T*[size];
    for (int i = 0; i < size; ++i) {
        table[i] = copy.table[i];
    }
}

template <typename T> TablePointers<T> &TablePointers<T>::operator=(const TablePointers &right) {
    size = right.size;
    table = new T*[size];
    for (int i = 0; i < size; ++i) {
        table[i] = right.table[i];
    }
    return *this;
}

template <typename T> void TablePointers<T>::addElement(T *element) {
    T** newTab = new T*[size+1];
    for(int i=0; i<size; ++i){
        newTab[i] = table[i];
    }
    if(size) delete[] table;http://www.onet.pl/
    table = newTab;
    ++size;
    table[size-1]=element;
}

template <typename T> void TablePointers<T>::removeElement(int index) {
    T** newTab = new T*[size-1];
    size--;
    for(int i=0; i<index; ++i){
        newTab[i] = table[i];
    }
    for(int i=index; i<size; ++i){
        newTab[i] = table[i+1];
    }
    table = newTab;
}

template <typename T> void TablePointers<T>::removeAll() {
    for (int i = 0; i < size; ++i) {
        delete table[i];
    }
}

template <typename T> std::ostream &operator<<(std::ostream &os, const TablePointers<T> &table){
    for (int i = 0; i < table.getSize(); ++i) {
        os<<"ID: "<<i<<" "<<*(table[i])<<"\n\n";
    }
    return os;
}

#endif


