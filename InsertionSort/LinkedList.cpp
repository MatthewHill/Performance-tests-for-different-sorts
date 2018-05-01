/* 
 * File:   LinkedList.cpp
 * Author: jerry
 * 
 * Created on March 1, 2018, 1:59 PM
 */

#include "LinkedList.h"
#include <iostream>

// #define NULL 0

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    temp = NULL;
    size = 0;
}

LinkedList::~LinkedList(){
    
}

void LinkedList::push(long data){
    // Creation of new node
    temp = new node;
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL){   // if list is empty, new node becomes head and tail
        head = tail = temp;
        head->next = NULL;
    }else{              // otherwise it becomes the tail
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
    size++;
}

long LinkedList::readHead(){
    return head->data;
}

void LinkedList::deleteHead(){
    if(head != NULL){
        temp = new node;
        temp = head;
        head = head->next;
        size--;
    }
}

void LinkedList::print(){
    temp = new node;
    temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

int LinkedList::getSize(){
    return size;
}

void LinkedList::insertionSort(){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* temp1 = head->next;
    while(temp1 != NULL){
        long sec_data = temp1->data;
        long found = 0;
        node* temp2 = head;
        while(temp2 != temp1){
            if(temp2->data > temp1->data && found == 0){
                sec_data = temp2->data;
                temp2->data = temp1->data;
                found = 1;
                temp2 = temp2->next;
            }else{
                if(found == 1){
                    int temp = sec_data;
                    sec_data = temp2->data;
                    temp2->data = temp;
                }
                temp2 = temp2->next;
            }
        }
        temp2->data = sec_data;
        temp1 = temp1->next;
    }
}