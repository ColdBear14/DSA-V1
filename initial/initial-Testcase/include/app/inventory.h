#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "../list/XArrayList.h"
#include "../list/DLinkedList.h"
#include "../list/IList.h"
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
    List1D<T>& operator=(const List1D<T> &other);
    virtual ~List1D();

    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    string toString() const;

    T removeAt(int index); // add function to remove element at specific index
    int indexOf(const T &value) const;
    void add(int index, const T &value);

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
    List2D<T>& operator=(const List2D<T> &other);
    virtual ~List2D();

    int rows() const;
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;

    IList<T>* removeAt(int index);

    friend ostream &operator<<(ostream &os, const List2D<T> &matrix);
};

struct InventoryAttribute
{
    string name;
    double value;
    InventoryAttribute() : name(""), value(0.0) {}
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    bool operator==(const InventoryAttribute &other) const
    {
        return name == other.name && value == other.value;
    }
    string toString() const {        
        ostringstream oss;
        oss << name << ": " << fixed << setprecision(6) << value;
        return oss.str();
    }
    friend std::ostream &operator<<(std::ostream &os, const InventoryAttribute &attr) {
        os << attr.name << ": " << fixed << setprecision(6) << attr.value;
        return os;
    }
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
    List1D<string> sortAndRetrieveProductNames(const List1D<int>& listPosition, const List1D<double>& listValue, bool ascending) const;

};

// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    this->pList = new XArrayList<T>();
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
    this->pList = new XArrayList<T>();
    for(int i = 0; i < num_elements; i++)
    {
        pList->add(T());
    }
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    this->pList = new XArrayList<T>();
    for(int i = 0; i < num_elements; i++)
    {
        pList->add(array[i]);
    }
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
    this->pList = new XArrayList<T>();
    for (int i = 0; i < other.size(); ++i) {
        pList->add(other.get(i));
    }
    
}

template <typename T>
List1D<T>& List1D<T>::operator=(const List1D<T>& other) {
    if (this != &other) {
        delete pList;
        pList = new XArrayList<T>();
        for (int i = 0; i < other.size(); ++i) {
            pList->add(other.get(i));
        }
    }
    return *this;
}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
    if (pList != nullptr) {
        delete pList;
        pList = nullptr;
    }
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
    pList->get(index) = value;
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
    if(!pList) return "[]";
    return pList->toString();
}

template <typename T> // Remember to change back to T
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
int List1D<T>::indexOf(const T &value) const
{
    return pList->indexOf(value);
}

template <typename T>
void List1D<T>::add(int index, const T &value)
{
    pList->add(index, value);
}

// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // TODO
    this->pMatrix = new DLinkedList<IList<T>*>();
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    // TODO
    this->pMatrix = new DLinkedList<IList<T>*>();
    for(int i = 0; i < num_rows; i++){
        IList<T>* newRow = new XArrayList<T>();
        for(int j = 0; j < array[i].size(); j++){
            newRow->add(array[i].get(j));
        }
        pMatrix->add(newRow);
    }

}


template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO
    this->pMatrix = new DLinkedList<IList<T>*>();
    for (int i = 0; i < other.pMatrix->size(); ++i) {
        IList<T>* originalRow = other.pMatrix->get(i);
        IList<T>* newRow = new XArrayList<T>();
        for (int j = 0; j < originalRow->size(); ++j) {
            newRow->add(originalRow->get(j));
        }
        pMatrix->add(newRow);
    }
}

template <typename T>
List2D<T>& List2D<T>::operator=(const List2D<T> &other) {
    if (this == &other) return *this;
    
    // First, free existing resources
    for (int i = 0; i < pMatrix->size(); ++i) {
        delete pMatrix->get(i);
    }
    delete pMatrix;
    
    // Now, create a deep copy of the other object's pMatrix
    pMatrix = new DLinkedList<IList<T>*>();
    for (int i = 0; i < other.pMatrix->size(); ++i) {
        IList<T>* originalRow = other.pMatrix->get(i);
        IList<T>* newRow = new XArrayList<T>();
        for (int j = 0; j < originalRow->size(); ++j) {
            newRow->add(originalRow->get(j));
        }
        pMatrix->add(newRow);
    }
    return *this;
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    for (int i = 0; i < pMatrix->size(); ++i) {
        delete pMatrix->get(i);
    }
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
    IList<T>* newRow = new XArrayList<T>();
    for (int i = 0; i < row.size(); ++i) {
        newRow->add(row.get(i));
    }
    pMatrix->add(rowIndex, newRow);
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    return pMatrix->get(rowIndex)->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    IList<T>* row = pMatrix->get(rowIndex);
    List1D<T> result;
    for (int i = 0; i < row->size(); ++i) {
        result.add(row->get(i));
    }
    return result;
}

template <typename T>
string List2D<T>::toString() const
{
    // TODO
    std::ostringstream oss;
    oss << "[";
    for (int i = 0; i < pMatrix->size(); ++i) {
        if (i > 0) oss << ", ";
        oss << "[";
        IList<T>* row = pMatrix->get(i);
        for (int j = 0; j < row->size(); ++j) {
            if (j > 0) oss << ", ";
            oss << row->get(j);
        }
        oss << "]";
    }
    oss << "]";
    return oss.str();
}

template <class T>
ostream &operator<<(ostream &os, const List2D<T> &matrix)
{
    // TODO
    os << matrix.toString();
    return os;
}

// -------------------- List2D Method Definitions --------------------
template <typename T>
IList<T>* List2D<T>::removeAt(int index) {
    return pMatrix->removeAt(index); // Return the removed row (IList<T>*)
}

// -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
    attributesMatrix = List2D<InventoryAttribute>();
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
    return this->productNames.size();
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
    List1D<int> listPosition;
    List1D<double> listValue;
    for (int i = 0; i < productNames.size(); i++)
    {
        if (quantities.get(i) >= minQuantity)
        {
            List1D<InventoryAttribute> attributeList = attributesMatrix.getRow(i);
            for (int j = 0; j < attributeList.size(); j++)
                if (attributeList.get(j).name == attributeName && attributeList.get(j).value >= minValue && attributeList.get(j).value <= maxValue)
                {
                    listPosition.add(i);
                    listValue.add(attributeList.get(j).value);
                    break;
                }
        }
    }
    return sortAndRetrieveProductNames(listPosition, listValue, ascending);
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
    for(int i = 0; i < size1; i++)
    {
        section1.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));

    }
    for(int i = size1; i < this->size(); i++)
    {
        section2.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));
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
    ss << "InventoryManager[" << endl;
    ss << "AttributesMatrix: " << attributesMatrix.toString() << "," << endl;
    ss << "ProductNames: " << productNames.toString() << "," << endl;
    ss << "Quantities: " << quantities.toString() << endl;
    ss << "]";
    return ss.str();
}

List1D<string> InventoryManager::sortAndRetrieveProductNames(const List1D<int>& listPosition, const List1D<double>& listValue, bool ascending) const {
    List1D<int> sortPosition;
    List1D<double> sortValue = listValue;
    List1D<string> result;

    if(ascending = true){
        for(int i = 1; i<listPosition.size(); i++){
            int key = sortValue.get(i);
            int j = i - 1;
            while(j >=0 && sortValue.get(j) > key){
                sortValue.set(j+1,sortValue.get(j));
                j = j - 1;
            }
            sortValue.set(j+1, key);
        }
    }
    else{
        for(int i = 1; i<listPosition.size(); i++){
            int key = sortValue.get(i);
            int j = i - 1;
            while(j >=0 && sortValue.get(j) < key){
                sortValue.set(j+1,sortValue.get(j));
                j = j - 1;
            }
            sortValue.set(j+1, key);
        }
    }
    for(int i = 0; i < listPosition.size(); i++){
        for(int j = 0; j < listPosition.size(); j++ ){
            if(sortValue.get(i) == listValue.get(j)){
                sortPosition.add(listPosition.get(j));
            }
        }
    }
    for(int i = 0; i < listPosition.size(); i++){
        result.add(getProductName(sortPosition.get(i)));
    }
    return result;
}

#endif /* INVENTORY_MANAGER_H */
