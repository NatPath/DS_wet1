#ifndef _AVL_H_
#define _AVL_H_
#include <memory>
#include <exception>
#include "Auxiliaries.h"

enum Side {R,L,N};
enum Order {PRE,POST,IN};


template<class KEY,class VAL>
class AVL_NODE{
    typedef struct std::shared_ptr<AVL_NODE<KEY,VAL>> Node_ptr;
    KEY key;
    VAL value;
    Node_ptr left;
    Node_ptr right;
    Node_ptr parent;
    int height;

    public:
    AVL_NODE(const KEY& key,const VAL& value):key(key),value(value),left(nullptr),right(nullptr),parent(nullptr),height(0){}
    ~AVL_NODE();

    //getters
    const VAL& getValue() const{
        return value;
    }
    const KEY& getKey() const{
        return key;
    }
    Node_ptr getRight() {
        return right;
    }
    Node_ptr getLeft() {
        return left;
    }
    Node_ptr getParent() {
        return parent;
    }
    int getHeight(){
        return height;
    }
    //setters
    void setValue(const VAL& new_value){
        value=new_value;
    }
    void setKey(const KEY& new_key){
        key=new_key;
    }
    void setRight(Node_ptr new_right){
        right=new_right;
    }
    void setLeft(Node_ptr new_left){
        left=new_left;
    }
    void setParent(Node_ptr new_parent){
        parent=new_parent;
    }

    /*
    *connects two nodes , parent to child with the side specified
    */

    void setHeight(int new_height){
        height=new_height;
    }
    int calcHeight(Node_ptr parent_node){

        int left_height=-1;
        int right_height=-1;
        Node_ptr left= parent_node->getLeft();
        if (left!=nullptr){
            left_height=left->height;
        }
        Node_ptr right= parent_node->getRight();
        if (right!=nullptr){
            right_height=right->height;
        }
        return max(left_height,right_height)+1;
    }
    int calcHeight(){
        int left_height=-1;
        int right_height=-1;
        if (left!=nullptr){
            left_height=left->height;
        }
        if (right!=nullptr){
            right_height=right->height;
        }
        return max(left_height,right_height)+1;

    }
    void updateHeight(){
        height=this->calcHeight();
    }

};

template<class KEY,class VAL>
class AVL_Tree{
    //fields if splitting
    typedef struct std::shared_ptr<AVL_NODE<KEY,VAL>> Node_ptr;
    Node_ptr root;

    
    //given correct height of childrens, calculates the height of the parent
    public:
    AVL_Tree():root(nullptr){}
    ~AVL_Tree();
    Node_ptr getRoot(){return root;}

    VAL getRootValue(){
        if(root==nullptr){
            return VAL();
        }
        return root->getValue();
    }
    KEY getRootKey(){
        if(root==nullptr){
            return KEY();
        }
        return root->getKey();
    }

    //void inorder(void* func);
    //void postorder(void* func);
    //Given children with correct heights, returns balance factor
    int balance_factor(Node_ptr parent_node){
        if (parent_node==nullptr){
            return 0;
        }
        int left_height=-1;
        int right_height=-1;
        Node_ptr left= parent_node->getLeft();
        Node_ptr right= parent_node->getRight();
        if (left!=nullptr){
            left_height=left->getHeight();
        }
        if (right!=nullptr){
            right_height=right->getHeight();
        }
        return left_height-right_height;
    }

    
    //
    Node_ptr findLastOfSearchPath(KEY& to_find){
        Node_ptr i=root;
        if(i==nullptr){
            return nullptr;
        }
        do{
            
            if (i->getKey()==to_find){
                return i;
            }
            if (i->getKey()>to_find){
                
                if (i->getLeft()!=nullptr){
                    i=i->getLeft();
                }
                else {
                    return i;
                }
            }
            else{
                if (i->getRight()!=nullptr){
                    i=i->getRight();
                }
                else {
                    return i;
                }
            }

        } while (true);
        
    }
    void insertNode(KEY& key_insert,VAL& val_insert){
        Node_ptr found_spot=findLastOfSearchPath(key_insert);
        if (found_spot==nullptr){
            //first node in the tree
            root=std::make_shared<AVL_NODE<KEY,VAL>>(key_insert,val_insert);

            //root= std::shared_ptr<AVL_NODE<KEY,VAL>>(key_insert,val_insert);
            return;
        }
        if (found_spot->getKey()==key_insert){
            //value is already in the tree
            return;
        }
        Node_ptr i=std::make_shared<AVL_NODE<KEY,VAL>>(key_insert,val_insert);
        
        //Node_ptr i=std::shared_ptr<AVL_NODE<KEY,VAL>>(key_insert,val_insert); 
        if(found_spot->getKey() < key_insert){
            connectNodes(found_spot,i,R);               
        }
        else{
            connectNodes(found_spot,i,L);
        }

        i->setHeight(0);
        Node_ptr parent = i->getParent();
        int bf;
        //int height;
        while(i!=root){ 
            bf=balance_factor(parent);
            parent->setHeight(i->getHeight()+1);
            if(bf>1){
                //left
                if(balance_factor(i)>0){
                    //left left
                    roll_ll(parent);

                }
                else{
                    // left right
                    roll_lr(parent);
                }
                root=getRootClimb(parent);


                return;

            }
            else if(bf<-1){
                //right
                if(balance_factor(i)<0){
                    //right right
                    roll_rr(parent);
                }
                else{
                    // right left
                    roll_rl(parent);
                }
                root=getRootClimb(parent);


                return;
            }
            i=parent;
            parent=i->getParent();
        }
        

        
    }
    
    void deleteNode(KEY& key_to_delete){
        Node_ptr found_spot=findLastOfSearchPath(key_to_delete);
        if (found_spot->getKey()!=key_to_delete){
            //value searched was not found
            return;
        }
        Node_ptr i=found_spot;// define an iterator and assign it the found spot

        //find a subsitute to the node removed, we're looking for the minimum node to its right
        //O(log(n))
        /*
        while(i->getRight()!=nullptr){
            Node_ptr temp_min= findMinNode(i->getRight());
            i.swap(temp_min);
            i=temp_min;
        }
        */
        Node_ptr parent_of_found=found_spot->getParent();
        Node_ptr substitute(nullptr);
        Node_ptr parent_of_subsitute(nullptr);
        if (isLeaf(found_spot)){
            if (found_spot==root){
                root.reset();
                return;
            }
            freeNode(found_spot);
            i=parent_of_found;
        }
        else if (found_spot->getRight()!=nullptr){
            substitute= findMinNode(i->getRight());
            i=substitute->getParent();
            found_spot->setKey(substitute->getKey());
            found_spot->setValue(substitute->getValue());
            //swapValues(found_spot,substitute);
            connectNodes(i,substitute->getRight(),L);
            freeNode(substitute);
        }
        else{
            substitute= findMaxNode(i->getLeft());
            i=substitute->getParent();
            found_spot->setKey(substitute->getKey());
            found_spot->setValue(substitute->getValue());
            //swapValues(found_spot,substitute);
            connectNodes(i,substitute->getLeft(),R);
            freeNode(substitute);
        }


        //trace up and update heights of nodes in the search path
        //O(log(n))
        Node_ptr j=i;//temporary iterator
        while (j!=nullptr){
            j->updateHeight();
            j=j->getParent();
        }
        j.reset();

        //handles corner case of i being the root
        //do rolls
        Node_ptr parent =i->getParent();
        int bf;
        while(i!=nullptr){ 
            bf=balance_factor(i);
            if(bf>1){
                //left
                if(balance_factor(i->getLeft())>0){
                    //left left
                    roll_ll(i);

                }
                else{
                    // left right
                    roll_lr(i);
                }
            }
            else if(bf<-1){
                //right
                if(balance_factor(i->getRight())<0){
                    //right right
                    roll_rr(i);
                }
                else{
                    // right left
                    roll_rl(i);
                }
            }
            if (i->getParent()==nullptr){
                root=i;
            }
            i=i->getParent();
        }
    }
    //void destroy();
    int getHeight(){
        return root->getHeight();
    }

    
    
};

template <typename KEY,typename VAL>
using Node_ptr=std::shared_ptr<AVL_NODE<KEY,VAL>>;


template <typename KEY,typename VAL>
void freeNode(Node_ptr<KEY,VAL>& to_delete){
    Side side=childSide(to_delete->getParent(),to_delete);
    connectNodes(to_delete->getParent(),Node_ptr<KEY,VAL>(nullptr),side);
    to_delete.reset();
}


template<typename KEY,typename VAL>
AVL_Tree<KEY,VAL>::~AVL_Tree(){
    if (root!=nullptr){
        itterateOrder(root->getRight(),POST,freeNode);
        itterateOrder(root->getLeft(),POST,freeNode);
        root.reset();
    }
}
template<typename KEY,typename VAL>
AVL_NODE<KEY,VAL>::~AVL_NODE(){
    
}

template <typename KEY,typename VAL>
void printValue(Node_ptr<KEY,VAL>& node){
    print(node->getValue());
}


template <typename KEY,typename VAL>
Node_ptr<KEY,VAL> getRootClimb(Node_ptr<KEY,VAL> node){
    while(node->getParent()!=nullptr){
        node=node->getParent();
    }
    return node;
}

template <typename KEY,typename VAL>
void inOrder(Node_ptr<KEY,VAL> root, void(*f)(Node_ptr<KEY,VAL>&)){
    if (root==nullptr){
        return;
    }
    if (isLeaf(root)){
        (*f)(root);
        return;
    }
    inOrder(root->getLeft(),f);
    (*f)(root);
    inOrder(root->getRight(),f);
}


template <typename KEY,typename VAL>
void itterateOrder(Node_ptr<KEY,VAL> root,Order order, void(*f)(Node_ptr<KEY,VAL>&),bool reverse = false){
    if (root==nullptr){
        return;
    }
    if (isLeaf(root)){
        (*f)(root);
        return;
    }
    if (!reverse){
        if (order==IN){
            itterateOrder(root->getLeft(),IN,f);
            (*f)(root);
            itterateOrder(root->getRight(),IN,f);
        }
        if (order==POST){
            itterateOrder(root->getLeft(),POST,f);
            itterateOrder(root->getRight(),POST,f);
            (*f)(root);
        }
        if (order==PRE){
            (*f)(root);
            itterateOrder(root->getLeft(),PRE,f);
            itterateOrder(root->getRight(),PRE,f);
        }
    }
    else{
        if (order==IN){
            itterateOrder(root->getLeft(),IN,f,true);
            (*f)(root);
            itterateOrder(root->getRight(),IN,f,true);
        }
        if (order==POST){
            itterateOrder(root->getLeft(),POST,f,true);
            itterateOrder(root->getRight(),POST,f,true);
            (*f)(root);
        }
        if (order==PRE){
            (*f)(root);
            itterateOrder(root->getLeft(),PRE,f,true);
            itterateOrder(root->getRight(),PRE,f,true);
        }
    }
}

template <typename KEY,typename VAL>
void swapValues(Node_ptr<KEY,VAL> a,Node_ptr<KEY,VAL> b){
    VAL temp = a->getValue();
    a->setValue(b->getValue());
    b->setValue(temp);
}
template <typename KEY,typename VAL>
Node_ptr<KEY,VAL> findMaxNode(Node_ptr<KEY,VAL> root){
    Node_ptr<KEY,VAL> i=root;
    while (i->getRight()!=nullptr){
        i=i->getRight();
    }
    return i;
}
template <typename KEY,typename VAL>
Node_ptr<KEY,VAL> findMinNode(Node_ptr<KEY,VAL> root){
    Node_ptr<KEY,VAL> i=root;
    while (i->getLeft()!=nullptr){
        i=i->getLeft();
    }
    return i;
}

template <typename KEY,typename VAL>
bool isLeaf(Node_ptr<KEY,VAL> node){
    if (node==nullptr){
        return false;
    }
    return node->getLeft()==nullptr&&node->getRight()==nullptr;
}

template <typename KEY,typename VAL>
void connectNodes(Node_ptr<KEY,VAL> parent,Node_ptr<KEY,VAL> child, Side side){
    /*
    print("-----------------------------------------------------");
    print("parent use count before:");
    print(parent.use_count());
    print("child use count before:");
    print(child.use_count());
    */
    if (parent!=nullptr){
        if (side==R){
            parent->setRight(child);
        }
        else if (side==L){
            parent->setLeft(child);
        }
        else{
            throw std::runtime_error("Excpected side to be left or right, but is either");
        }
    }
    if (child!=nullptr){
        child->setParent(parent);
    }
    /*
    print("parent use count after:");
    print(parent.use_count());
    print("child use count after:");
    print(child.use_count());
    */
}
/**
 * Given a parent and a child, returns which side the child is
 * */
template <typename KEY,typename VAL>
Side childSide(Node_ptr<KEY,VAL> parent,Node_ptr<KEY,VAL> child){
    if (child==nullptr){
        //no child , no side
        return N;
    }
    if (parent==nullptr){
        //no parent , no side
        return N;
    }
    if (parent->getLeft()==child){
        return L;
    }
    if (parent->getRight()==child){
        return R;
    }
    // the child is not connected to the parent
    return N;
} 

template <typename KEY,typename VAL>
void roll_ll(Node_ptr<KEY,VAL>& old_root){
    Node_ptr<KEY,VAL> parent=old_root->getParent();
    Node_ptr<KEY,VAL> new_root=old_root->getLeft();
    Node_ptr<KEY,VAL> LR_Tree=new_root->getRight();

    Side root_side =childSide(parent,old_root);
    
    //handle new_root pointers 
    connectNodes(parent,new_root,root_side);//connect to its parent
    connectNodes(new_root,old_root,R);//connect old root to its right
    
    //handle old_root pointers
    connectNodes(old_root,LR_Tree,L);


/*
    print(parent.use_count());
    print(new_root.use_count());
    print(LR_Tree.use_count());
    print(old_root.use_count());
*/

    //handles new heights
    old_root->setHeight(old_root->getHeight()-2);

    old_root=new_root;


}

template <typename KEY,typename VAL>
void roll_rr(Node_ptr<KEY,VAL>& old_root){
    Node_ptr<KEY,VAL> parent=old_root->getParent();
    Node_ptr<KEY,VAL> new_root=old_root->getRight();
    Node_ptr<KEY,VAL> RL_Tree=new_root->getLeft();

    Side root_side =childSide(parent,old_root);
    
    //handle new_root pointers 
    connectNodes(parent,new_root,root_side);//connect to its parent
    connectNodes(new_root,old_root,L);//connect old root to its left
    
    //handle old_root pointers
    connectNodes(old_root,RL_Tree,R);
    
    //handles new heights
    old_root->setHeight(old_root->getHeight()-2);

    old_root=new_root;
}


template <typename KEY,typename VAL>
void roll_lr(Node_ptr<KEY,VAL>& old_root){
    Node_ptr<KEY,VAL> parent=old_root->getParent();
    Node_ptr<KEY,VAL> left=old_root->getLeft();
    Node_ptr<KEY,VAL> new_root=left->getRight();
    Node_ptr<KEY,VAL> LRR_Tree=new_root->getRight();
    Node_ptr<KEY,VAL> LRL_Tree=new_root->getLeft();

    Side root_side =childSide(parent,old_root);
    
    //handle new_root pointers 
    connectNodes(parent,new_root,root_side);//connect to its parent
    connectNodes(new_root,old_root,R);//connect old root to its right
    connectNodes(new_root,left,L);//connect left to its left
    
    //handle old_root pointers
    connectNodes(old_root,LRR_Tree,L);

    //handle left pointers
    connectNodes(left,LRL_Tree,R);

    //handles new heights
    old_root->setHeight(old_root->getHeight()-2);
    new_root->setHeight(new_root->getHeight()+1);
    left->setHeight(left->getHeight()-1);
    
    old_root=new_root;
}

template <typename KEY,typename VAL>
void roll_rl(Node_ptr<KEY,VAL>& old_root){
    Node_ptr<KEY,VAL> parent=old_root->getParent();
    Node_ptr<KEY,VAL> right=old_root->getRight();
    Node_ptr<KEY,VAL> new_root=right->getLeft();
    Node_ptr<KEY,VAL> RLL_Tree=new_root->getLeft();
    Node_ptr<KEY,VAL> RLR_Tree=new_root->getRight();

    Side root_side =childSide(parent,old_root);
    
    //handle new_root pointers 
    connectNodes(parent,new_root,root_side);//connect to its parent
    connectNodes(new_root,old_root,L);//connect old root to its left 
    connectNodes(new_root,right,R);//connect right to its right 
    
    //handle old_root pointers
    connectNodes(old_root,RLL_Tree,R);

    //handle right pointers
    connectNodes(right,RLR_Tree,L);

    //handles new heights
    old_root->setHeight(old_root->getHeight()-2);
    new_root->setHeight(new_root->getHeight()+1);
    right->setHeight(right->getHeight()-1);

    old_root=new_root;
}


#endif 