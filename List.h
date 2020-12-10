#ifndef _LIST_H_
#define _LIST_H_
#include <memory>
#include <exception>
#include "Auxiliaries.h"


template<class T>
class ListNode{
    typedef struct std::shared_ptr<ListNode<T>> Node_ptr;
    typedef struct std::shared_ptr<T> Value_ptr;
    Value_ptr value;
    ListNode<T>* next;
    ListNode<T>* prev;

    public:
    ListNode()=default;
    ListNode(const Value_ptr value):value(value),next(nullptr),prev(nullptr){}
     
    Value_ptr getValue() {
        return value;
    }

    ListNode<T>* getNext(){
        return next;
    }

    
    ListNode<T>* getPrev(){
        return prev;
    }

    void setValue(Value_ptr new_value) {
        value = new_value;
    }

    void connectNext(ListNode<T>* after){
        next = after;
        if(after){
            after->prev = this;
        }
    }

    void connectPrev(ListNode<T>* before){
        prev = before;
        if(before){
            before->next =this;
        }
    }

};

template<class T>
class List{

    typedef struct std::shared_ptr<ListNode<T>> Node_ptr;
    ListNode<T>* root;
 

    ListNode<T>*  find(const T& value){
        ListNode<T>*  i=root;
        while(i){
            if(i->getValue() == value){
                return i;
            }
        }
        return nullptr;
    }

    void addNode(ListNode<T>*  to_add){
        to_add->connectNext(root);
        root = to_add;
    }



    public:

    List()=default;
    List(ListNode<T>*  root):root(root){}

    ListNode<T>* getRoot(){
        return root;
    }

    bool isEmpty(){
        return root==nullptr;
    }

    bool isInList(const T& value){
        return find(value)!=nullptr;
    }

    
    void add(T& to_add){
        //check unique?
        ListNode<T>* new_node = new ListNode<T>(to_add);
        add(new_node);
    }
    

    void add(ListNode<T>* to_add){
        //check unique?
        to_add->connectNext(root);
        root = to_add;
    }
    

    void remove(T& to_remove){
        ListNode<T>* i=root;

        /* single link version
        if(!i->getNext()){
            if(i->getValue()==to_remove){
                root = nullptr;
            }
        }
        while(i->getNext()){
            if(i->getNext()->getValue() == to_remove){
                i->connectNext(i->getNext()->getNext());
                return;
            }
        }
        */

       while(i){
           if(i->getValue()==to_remove){
               i->getPrev()->connectNext(i->getNext());
               
               return;
           }
       }


    }

    ~List(){
        ListNode<T>* i = root;

        while (i)
        {
            ListNode<T>* next = i->next;
            delete i;
            i = next;
        }
    }


};

#endif