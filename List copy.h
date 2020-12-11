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
    Node_ptr next;
    Node_ptr prev;

    public:
    ListNode()=default;
    ListNode(const Value_ptr value):value(value),next(nullptr),prev(nullptr){}
     
    Value_ptr getValue() {
        return value;
    }

    Node_ptr getNext(){
        return next;
    }

    
    Node_ptr getPrev(){
        return next;
    }

    void setValue(Value_ptr new_value) {
        value = new_value;
    }

    void connectNext(Node_ptr after){
        next = after;
        if(after){
            after->prev = std::shared_ptr<ListNode<T>>(this);
        }
    }

    void connectPrev(Node_ptr before){
        prev = before;
        if(before){
            before->next = std::shared_ptr<ListNode<T>>(this);
        }
    }

};

template<class T>
class List{

    typedef struct std::shared_ptr<ListNode<T>> Node_ptr;
    Node_ptr root;
 

    Node_ptr find(const T& value){
        Node_ptr i=root;
        while(i){
            if(i->getValue() == value){
                return i;
            }
        }
        return nullptr;
    }

    void addNode(Node_ptr to_add){
        to_add->connectNext(root);
        root = to_add;
    }

    public:

    List()=default;
    List(Node_ptr root):root(root){}

    Node_ptr getRoot(){
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
        Node_ptr new_node = std::make_shared<ListNode<T>>(to_add);
        addNode(new_node);
    }

    void add(ListNode<T> to_add){
        //check unique?
        addNode(Node_ptr(&to_add));
    }

    void remove(T& to_remove){
        Node_ptr i=root;

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


};

#endif