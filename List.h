#ifndef _LIST_H_
#define _LIST_H_
#include <memory>
#include <exception>
#include "Auxiliaries.h"


template<class T>
class ListNode{
    typedef struct std::shared_ptr<T> Value_ptr;
    Value_ptr value;
    ListNode<T>* next;
    ListNode<T>* prev;

    public:
    ListNode():value(nullptr),next(nullptr),prev(nullptr){};
    ListNode(const Value_ptr value):value(value),next(nullptr),prev(nullptr){}
    ListNode(const ListNode<T>& to_copy){
        if(to_copy){
            T actual_value;
            if (to_copy.value){
                actual_value=*(to_copy.value);
            }
            value=std::make_shared<T>(actual_value);
            next=to_copy.next;
            prev=to_copy.prev;
        }
        else{
            value=nullptr;
            next=nullptr;
            prev=nullptr;
        }
    }
    ListNode<T>& operator=(const ListNode<T>& to_copy){
        value=to_copy.value;
        next=to_copy.next;
        prev=to_copy.prev;
        return *this;
    }
     
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
    void printValue(){
        if (value){
            print(*value);
        }
    }
    ~ListNode(){
        value.reset();
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

    List():root(nullptr){};
    List(ListNode<T>*  root):root(root){}
    List(const List<T>& another_list){
        ListNode<T>* itt=another_list.root;
        T new_val;
        root=new ListNode<T>();
        ListNode<T>* new_itt=root;
        while(itt){
            new_val=*(itt->getValue());
            ListNode<T>* next=new ListNode<T>(std::make_shared<T>(new_val));
            new_itt->connectNext(next);
            itt=itt->getNext();
            new_itt=new_itt->getNext();
        }

    }

    ListNode<T>* getRoot() const{
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
        ListNode<T>* new_node = new ListNode<T>(std::make_shared<T>(to_add));
        add(new_node);
    }
    

    void add(ListNode<T>* to_add){
        //check unique?
        if (!root){
            root=to_add;
            return;
        }
        to_add->connectNext(root);
        root = to_add;
    }

    void setRoot(ListNode<T>* new_root){
        delete root;
        root = new_root;
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
           if(*(i->getValue())==to_remove){
               if (i->getPrev()){
                   i->getPrev()->connectNext(i->getNext());
                   delete i;
               }
               else{
                   //deleting root
                   root=i->getNext();
                   delete i;
               }
               
               return;
           }
           i=i->getNext();
       }


    }

    ~List(){
        ListNode<T>* i = root;

        while (i)
        {
            ListNode<T>* next = i->getNext();
            delete i;
            i = next;
        }
    }
    void printList(){
        ListNode<T>* itt=root;        
        while (itt!=nullptr){
            itt->printValue();
            itt=itt->getNext();
        }
    }
    /*
    class iterator;
    iterator begin(){
        return iterator(this,0);
    }
    */



};
/*
template<class T>
class List<T>::iterator{
    friend class List<T>;
    List<T>* list;
    int index;

    public:
    iterator(List<T>* list,int index):list(list),index(index){};
    iterator operator++(int){
        iterator result=*this;
        ++*this;
        return result;
    }
    iterator& operator++(){
        ++index;
        return *this;
    }
    T& operator*() const{
        if (index>=list->size()){
            throw std::runtime_error("trying to access out of range index");
        }
        return *list.value;

    }
};
*/

#endif