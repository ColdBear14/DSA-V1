#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "list/XArrayList.h"
#include "list/DLinkedList.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// -------------------- List1D --------------------
template <typename T>
class List1D
{
private:
    IList<T> *pList;

public:
    List1D();
    List1D(int num_elements);
    List1D(const T *array, int num_elements);
    List1D(const List1D<T> &other);
    virtual ~List1D();

    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    string toString() const;

    T removeAt(int index); // add function to remove element at specific index
    void sort(bool ascending, List1D<string> &result);

    friend ostream &operator<<(ostream &os, const List1D<T> &list);
};

// -------------------- List2D --------------------
template <typename T>
class List2D
{
private:
    IList<IList<T> *> *pMatrix;

public:
    List2D();
    List2D(List1D<T> *array, int num_rows);
    List2D(const List2D<T> &other);
    virtual ~List2D();

    int rows() const;
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;

    T removeAt(int index); // add function to remove element at specific index

    friend ostream &operator<<(ostream &os, const List2D<T> &matrix);
};

struct InventoryAttribute
{
    string name;
    double value;
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    string toString() const { return name + ": " + to_string(value); }
};

// -------------------- InventoryManager --------------------
class InventoryManager
{
private:
    List2D<InventoryAttribute> attributesMatrix;
    List1D<string> productNames;
    List1D<int> quantities;

public:
    InventoryManager();
    InventoryManager(const List2D<InventoryAttribute> &matrix,
                     const List1D<string> &names,
                     const List1D<int> &quantities);
    InventoryManager(const InventoryManager &other);

    int size() const;
    List1D<InventoryAttribute> getProductAttributes(int index) const;
    string getProductName(int index) const;
    int getProductQuantity(int index) const;
    void updateQuantity(int index, int newQuantity);
    void addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity);
    void removeProduct(int index);

    List1D<string> query(string attributeName, const double &minValue,
                         const double &maxValue, int minQuantity, bool ascending) const;

    void removeDuplicates();

    static InventoryManager merge(const InventoryManager &inv1,
                                  const InventoryManager &inv2);

    void split(InventoryManager &section1,
               InventoryManager &section2,
               double ratio) const;

    List2D<InventoryAttribute> getAttributesMatrix() const;
    List1D<string> getProductNames() const;
    List1D<int> getQuantities() const;
    string toString() const;
};

// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    XArrayList<T> *list = new XArrayList<T>();
    this->pList = list;
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
    XArrayList<T> *list = new XArrayList<T>();
    for(int i = 0; i < num_elements; i++)
    {
        list->add(0);
    }
    this->pList = list;
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    XArrayList<T> *list = new XArrayList<T>();
    for(int i = 0; i < num_elements; i++)
    {
        list->add(array[i]);
    }
    this->pList = list;
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
    XArrayList<T> *list = new XArrayList<T>(other.pList);
    this->pList = list;
}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
    ~XArrayList<T>();
    delete pList;
}

template <typename T>
int List1D<T>::size() const
{
    // TODO
    return pList->size();
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO
    return pList->get(index);
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    // TODO
    pList->add(index, value);
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    pList->add(value);
}

template <typename T>
string List1D<T>::toString() const
{
    // TODO
    return pList->toString();
}

template <typename T>
ostream &operator<<(ostream &os, const List1D<T> &list)
{
    // TODO
    os << list.toString();
    return os;
}

// -------------------- List1D Method Definitions --------------------
template <typename T>
T List1D<T>::removeAt(int index)
{
    // TODO
    return pList->removeAt(index);
}

template <typename T>
void List1D<T>::sort(bool ascending, List1D<string> &result)
{
    // TODO
    if(ascending)
    {
        // Shell sort
        int n = pList->size();
        for(int gap = n / 2; gap > 0; gap /= 2)
        {
            for(int i = gap; i < n; i += 1)
            {
                T temp = pList->get(i);
                T temp2 = result.get(i);
                int j;
                for(j = i; j >= gap && pList->get(j - gap) > temp; j -= gap)
                {
                    pList->add(j, pList->get(j - gap));
                }
                pList->add(j, temp);
                result.add(j, temp2);
            }
        }
    }
    else
    {
        // Reverse shell sort
        int n = pList->size();
        for(int gap = n / 2; gap > 0; gap /= 2)
        {
            for(int i = gap; i < n; i += 1)
            {
                T temp = pList->get(i);
                T temp2 = result.get(i);
                int j;
                for(j = i; j >= gap && pList->get(j - gap) < temp; j -= gap)
                {
                    pList->add(j, pList->get(j - gap));
                }
                pList->add(j, temp);
                result.add(j, temp2);
            }
        }
    }
}

// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // TODO
    DLinkedList<T> *listMatrix = new DLinkedList<T>();
    this->pMatrix = listMatrix;
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    // TODO
    DLinkedList<T> *listMatrix = new DLinkedList<T>();
    for(int i = 0; i < num_rows; i++)
    {
        listMatrix->add(array[i]);
    }
    this->pMatrix = listMatrix;
}

template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO
    DLinkedList<T> *listMatrix = new DLinkedList<T>(other.pMatrix);
    this->pMatrix = listMatrix;
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    ~DLinkedList<T>();
    delete pMatrix;
}

template <typename T>
int List2D<T>::rows() const
{
    // TODO
    return pMatrix->size();
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // TODO
    pMatrix->add(rowIndex, row);
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
    return pMatrix->get(rowIndex).get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    return pMatrix->get(rowIndex);
}

template <typename T>
string List2D<T>::toString() const
{
    // TODO
    return pMatrix->toString();
}

template <typename T>
ostream &operator<<(ostream &os, const List2D<T> &matrix)
{
    // TODO
    os << matrix.toString();
    return os;
}

// -------------------- List2D Method Definitions --------------------
template <typename T>
T List2D<T>::removeAt(int index)
{
    // TODO
    return pMatrix->removeAt(index);
}

// -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
    this->attributesMatrix = List2D<InventoryAttribute>();
    this->productNames = List1D<string>();
    this->quantities = List1D<int>();    
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
    this->attributesMatrix = matrix;
    this->productNames = names;
    this->quantities = quantities;
}

InventoryManager::InventoryManager(const InventoryManager &other)
{
    // TODO
    this->attributesMatrix = other.attributesMatrix;
    this->productNames = other.productNames;
    this->quantities = other.quantities;
}

int InventoryManager::size() const
{
    // TODO
    return productNames.size();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
    if(index < 0 || index >= this->size())
    {
        throw out_of_range("Index is invalid!");
    }
    return attributesMatrix.getRow(index);
}

string InventoryManager::getProductName(int index) const
{
    // TODO
    if(index < 0 || index >= this->size())
    {
        throw out_of_range("Index is invalid!");
    }
    return productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
    if(index < 0 || index >= this->size())
    {
        throw out_of_range("Index is invalid!");
    }
    return quantities.get(index);
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    if(index < 0 || index >= this->size())
    {
        throw out_of_range("Index is invalid!");
    }
    quantities.set(index, newQuantity);
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // TODO
    productNames.add(name);
    quantities.add(quantity);
    attributesMatrix.setRow(attributesMatrix.rows(), attributes);
}

void InventoryManager::removeProduct(int index)
{
    // TODO
    if(index < 0 || index >= this->size())
    {
        throw out_of_range("Index is invalid!");
    }
    productNames.removeAt(index);
    quantities.removeAt(index);
    attributesMatrix.removeAt(index);
}

List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    // TODO
    List1D<string> result;
    List1D<int> quantities;
    for(int i = 0; i < this->size(); i++)
    {
        bool valid = false;
        for(int j = 0; j < this->attributesMatrix.getRow(i).size(); j++)
        {
            if(this->attributesMatrix.get(i, j).name == attributeName &&
            this->attributesMatrix.get(i, j).value >= minValue &&
            this->attributesMatrix.get(i, j).value <= maxValue &&
            this->quantities.get(i) >= minQuantity)
            {
                valid = true;
                break;
            }
        }
        if(valid)
        {
            result.add(this->productNames.get(i));
            quantities.add(this->quantities.get(i));
        }
    }
    if(ascending)
    {
        quantities.sort(ascending, result);
    }
    else
    {
        quantities.sort(ascending, result);
    }
    return result;
}

void InventoryManager::removeDuplicates()
{
    // TODO
    for(int i = 0; i < this->productNames.size() - 1; i++)
    {
        for(int j = i + 1; j < this->productNames.size(); j++)
        {
            if(this->productNames.get(i) == this->productNames.get(j) && 
            this->attributesMatrix.getRow(i).toString() == this->attributesMatrix.getRow(j).toString())
            {
                int newQuantity = this->quantities.get(i) + this->quantities.get(j);
                this->updateQuantity(i, newQuantity);
                this->removeProduct(j);
            }
        }
    }
}

InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // TODO
    List2D<InventoryAttribute> matrix;
    List1D<string> names;
    List1D<int> quantities;
    for(int i = 0; i < inv1.size(); i++)
    {
        matrix.setRow(matrix.rows(), inv1.getProductAttributes(i));
        names.add(inv1.getProductName(i));
        quantities.add(inv1.getProductQuantity(i));
    }
    for(int i = 0; i < inv2.size(); i++)
    {
        matrix.setRow(matrix.rows(), inv2.getProductAttributes(i));
        names.add(inv2.getProductName(i));
        quantities.add(inv2.getProductQuantity(i));
    }
    return InventoryManager(matrix, names, quantities);
}

void InventoryManager::split(InventoryManager &section1,
                             InventoryManager &section2,
                             double ratio) const
{
    // TODO
    int size1 = this->size() * ratio;
    int size2 = this->size() - size1;

    // List2D<InventoryAttribute> matrix1;
    // List1D<string> names1;
    // List1D<int> quantities1;
    // List2D<InventoryAttribute> matrix2;
    // List1D<string> names2;
    // List1D<int> quantities2;
    // for(int i = 0; i < size1; i++)
    // {
    //     matrix1.setRow(matrix1.rows(), this->getProductAttributes(i));
    //     names1.add(this->getProductName(i));
    //     quantities1.add(this->getProductQuantity(i));
    // }
    // for(int i = size1; i < this->size(); i++)
    // {
    //     matrix2.setRow(matrix2.rows(), this->getProductAttributes(i));
    //     names2.add(this->getProductName(i));
    //     quantities2.add(this->getProductQuantity(i));
    // }
    // section1 = InventoryManager(matrix1, names1, quantities1);
    // section2 = InventoryManager(matrix2, names2, quantities2);

        for(int i = 0; i < size1; i++)
    {
        section1.attributesMatrix.setRow(section1.attributesMatrix.rows(), this->getProductAttributes(i));
        section1.productNames.add(this->getProductName(i));
        section1.quantities.add(this->getProductQuantity(i));
    }
    
    for(int i = size1; i < this->size(); i++)
    {
        section2.attributesMatrix.setRow(section2.attributesMatrix.rows(), this->getProductAttributes(i));
        section2.productNames.add(this->getProductName(i));
        section2.quantities.add(this->getProductQuantity(i));
    }
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // TODO
    return attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
    return productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
    return quantities;
}

string InventoryManager::toString() const
{
    // TODO
    stringstream ss;
    ss << "InventoryManager[ " << endl;
    ss << "Attributes Matrix: " << attributesMatrix.toString() << "," << endl;
    ss << "Product Names: " << productNames.toString() << "," << endl;
    ss << "Quantities: " << quantities.toString() << endl;
    ss << "]";
    return ss.str();
}

#endif /* INVENTORY_MANAGER_H */
