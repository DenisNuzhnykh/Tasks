#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <cassert>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include "Node.h"

using namespace std;

void PrintMatrix3x3(Matrix3x3 matrix) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }
}

void PrintMatrixXnX(MatrixXnX& matrix) {
    int dim = matrix.getDim();
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            cout << matrix.element(i, j) << "\t";
        cout << endl;
    }
}

void WorkWithMatrix3x3() {
    Matrix3x3 matrix3x3 = Matrix3x3();
    matrix3x3.fillRandomElements(-10, 10);
    PrintMatrix3x3(matrix3x3);
    cout << "productPrincipalDiag = " << matrix3x3.productPrincipalDiag() << endl;
    cout << "productSecondaryDiag = " << matrix3x3.productSecondaryDiag() << endl;
    cout << "sumPrincipalDiag = " << matrix3x3.sumPrincipalDiag() << endl;
    cout << "sumSecondaryDiag = " << matrix3x3.sumSecondaryDiag() << endl;
    for (int i = 0; i < 3; ++i)
        cout << "sumofRow = " << matrix3x3.sumRow(i) << endl;
    for (int i = 0; i < 3; ++i) 
        cout << "ColumnMin = " << matrix3x3.minColumn(i) << endl;
    for (int i = 0; i < 3; ++i)
        cout << "ColumnMax = " << matrix3x3.maxColumn(i) << endl;
}

void WorkWithMatrixXnX() {
    int iDim = 5;
    MatrixXnX matrixXnX(iDim);
    matrixXnX.fillRandomElements(-10, 10);
    PrintMatrixXnX(matrixXnX);
    cout << "productPrincipalDiag = " << matrixXnX.productPrincipalDiag() << endl;
    cout << "productSecondaryDiag = " << matrixXnX.productSecondaryDiag() << endl;
    cout << "sumPrincipalDiag = " << matrixXnX.sumPrincipalDiag() << endl;
    cout << "sumSecondaryDiag = " << matrixXnX.sumSecondaryDiag() << endl;
    for (int i = 0; i < iDim; ++i)
        cout << "sumOfRow = " << matrixXnX.sumRow(i) << endl;
    for (int i = 0; i < iDim; ++i) 
        cout << "ColumnMin = " << matrixXnX.minColumn(i) << endl;
    for (int i = 0; i < iDim; ++i)
        cout << "ColumnMax = " << matrixXnX.maxColumn(i) << endl;
    
}



void PrintList(Node& list) {
    Node* head = &list;
    while (head != nullptr) {
        cout << head->getValue() << " ";
        head = head->getNext();
    }
    cout << endl;
}

bool VectorContains(vector<int> vector, int value) {
    for (int i = 0; i < vector.size(); i++)
        if (vector[i] == value)
            return true;
    return false;
}

void DistinctLinkedList(Node& root) {
    vector<int> a;
    Node* ptr = &root;
    a.push_back(ptr->getValue());
    while (ptr->getNext()) {
        if (VectorContains(a, ptr->getNext()->getValue())) {
            ptr->deleteNext();
            continue;
        }
        a.push_back(ptr->getNext()->getValue());
        ptr = ptr->getNext();
    }
}

void FindKElementFromEnd(Node& list, int k) {
    int count = 0;
    Node* head = &list;
    while (head != nullptr) {
        count++;
        head = head->getNext();
    }
    assert(k < count);
    head = &list;
    for (int i = 0; i < count - k; i++)
        head = head->getNext();
    cout << head->getValue() << endl;
}

int main()
{
    WorkWithMatrix3x3();
    WorkWithMatrixXnX();
    Node linkedList = Node(0);
    for (int i = 1; i < 10; i++) {
        linkedList.push(new Node(i));
        linkedList.push(new Node(100));
    }
    PrintList(linkedList);
    DistinctLinkedList(linkedList);
    PrintList(linkedList);
    FindKElementFromEnd(linkedList, 4);
}









