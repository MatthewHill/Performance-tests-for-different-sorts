/* 
 * File:   LinkedList.h
 * Author: jerry
 *
 * Created on March 1, 2018, 1:59 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    long data;
    node* next;
};

class LinkedList {
public:
    LinkedList();
    virtual ~LinkedList();
    
    void push(long data);
    long readHead();
    void deleteHead();
    void print();
    int getSize();
    void insertionSort();
private:
    node *head, *tail, *temp;
    int size;
};

#endif /* LINKEDLIST_H */