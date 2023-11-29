#include <bits/stdc++.h>
#ifndef __node__cpp__
#define __node__cpp__
using namespace std;
template <class T>
class node {
public:
    T elem; //element
    node* prev; //prev: con tro quan ly node phia truoc 
    node* next; //next: con tro quan li node phia sau 


	node(){
	}
    node(T e,node<T> *p = NULL, node<T> *n = NULL) //Ham tao
	{
		elem = e;
		prev = p;
		next = n;
	}

    T getElem(){
        return elem;
    }

    void setElem(T& value) {
        elem = value;
    }

    node* getPrev(){
        return prev;
    }

    void setPrev(node<T>* p) {
        prev = p;
    }

    node* getNext(){
        return next;
    }

    void setNext(node<T>* n) {
        next = n;
    }
};
#endif
//int main() {
//    // Tao 1 node kieu  int
//    node<int>* myNode = new node<int>(5);
//
//    // Lay gt cua ptu trong node
//    int value = myNode->getElem();
//    cout << "Value: " << value << endl;
//
//    // Thay doi gt cua ptu trong node
//    myNode->setElem(10);
//    value = myNode->getElem();
//    cout << "New Value: " << value << endl;
//
//    // Tao 1 node khac va thiet lap con tro prev và next
//    node<int>* newNode = new node<int>(15);
//    myNode->setNext(newNode);
//    newNode->setPrev(myNode);
//
//    // Truy cap vao node tiep theo va in gt ptu
//    node<int>* nextNode = myNode->getNext();
//    cout << "Next Node Value: " << nextNode->getElem() << endl;
//
//    // Truy cap vao node truoc do va in gt ptu
//    node<int>* prevNode = newNode->getPrev();
//    cout << "Previous Node Value: " << prevNode->getElem() << endl;
//
//	// In bo bo du lieu trong node ra
//	cout << "Node Data: ";
//    for (node<int>* it = myNode; it != NULL; it = it->getNext()) {
//        cout << it->getElem() << " ";
//    }
//    cout << endl;
//    
//    node<int> A,B(1),C(2,&B);
//    
//    
//    // Giai phong bo nho
//    delete myNode;
//    delete newNode;
//
//    return 0;
//}



