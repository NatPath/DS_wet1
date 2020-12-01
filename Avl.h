#ifndef _AVL_H_
#define _AVL_H_
#include <memory>
#include <exception>
#include "Auxiliaries.h"

enum Side {R,L,N};
template<class T>
class AVL_NODE{
    typedef struct std::shared_ptr<AVL_NODE> Node_ptr;
    T& value;
    Node_ptr left;
    Node_ptr right;
    Node_ptr parent;
    int height;

    public:
    AVL_NODE(const T& value):value(value),left(nullptr),right(nullptr),parent(nullptr),height(0){}
    ~AVL_NODE();

    //getters
    const T& getValue() const{
        return value;
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
    void setValue(const T& new_value){
        value=new_value;
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
    // functions which can be elsewhere
    bool isLeaf(AVL_NODE node){
        return node->left==nullptr&&node->right==nullptr;
    }

    AVL_NODE getRoot(AVL_NODE node){
        AVL_NODE climber=node;
        while(climber.parent!=nullptr){
            climber==climber.parent;
        }
        return climber;
    }
    //returns the distance of the node from the root
    int distanceFromRoot(AVL_NODE node){ 
        Node climber=node;
        int counter=0;
        while(climber!=nullptr){
            counter++;                        
            climber=climber.parent;
        }
        return counter;
    }
    int calcHeight(AVL_NODE parent_node){

        int left_height=-1;
        int right_height=-1;
        Node_ptr left= parent_node->getLeft();
        if (left!=nullptr){
            left_height=left->height();
        }
        Node_ptr right= parent_node->getRight();
        if (right!=nullptr){
            right_height=right->height();
        }
        return max(left_height,right_height)+1;
    }

};

template<class T>
class AVL_Tree{
    //fields if splitting
    typedef struct std::shared_ptr<AVL_NODE> Node_ptr;
    Node_ptr root;

    
    //given correct height of childrens, calculates the height of the parent
    public:

    void inorder(void* func);
    void postorder(void* func);
    //Given children with correct heights, returns balance factor
    int balance_factor(Node_ptr parent_node){
        if (parent_node==nullptr){
            throw ;
        }
        int left_height=-1;
        int right_height=-1;
        AVL_NODE left= parent_node->getLeft();
        AVL_NODE right= parent_node->getRight();
        if (left!=nullptr){
            left_height=left->getHeight();
        }
        if (right!=nullptr){
            right_height=right->getHeight();
        }
        return left_height-right_height;
    }

    
    //
    Node_ptr findLastOfSearchPath(T& to_find){
        Node_ptr i=root;
        if(i==nullptr){
            return nullptr;
        }
        do{
            
            if (i->getValue()==to_find){
                return i;
            }
            if (i->getValue()>to_find){
                
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
    void insertNode(T& to_insert){
        Node_ptr found_spot=findLastOfSearchPath(to_insert);
        Node_ptr i;
        if (found_spot->getValue()==to_insert){
            //value is already in the tree
            return;
        }
        else {
            i=std::make_shared<AVL_NODE>(to_insert);
            if(found_spot->getValue() < to_insert){
                connectNodes(found_spot,i,R);               
            }
            else{
                connectNodes(found_spot,i,L);
            }
        }

        i->setHeight(0);
        Node_ptr parent = i->getParent();
        int bf;
        int height;
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
                return;
            }
            i=parent;
            parent=i->getParent();
            
            
        }
        

        
    }
    
    
    void destroy();

    
    
};
template <typename T>
using Node_ptr=std::shared_ptr<AVL_NODE<T>>;

template <typename T>
void connectNodes(Node_ptr<T> parent,Node_ptr<T> child, Side side){
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
}
/**
 * Given a parent and a child, returns which side the child is
 * */
template <typename T>
Side childSide(Node_ptr<T> parent,Node_ptr<T> child){
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

template <typename T>
void roll_ll(Node_ptr<T> old_root){
    Node_ptr<T> parent=old_root->getParent();
    Node_ptr<T> new_root=old_root->getLeft();
    Node_ptr<T> LR_Tree=new_root->getRight();

    Side root_side =childSide(parent,old_root);
    
    //handle new_root pointers 
    connectNodes(parent,new_root,root_side);//connect to its parent
    connectNodes(new_root,old_root,R);//connect old root to its right
    
    //handle old_root pointers
    connectNodes(old_root,LR_Tree,L);

    //handles new heights
    old_root->setHeight(old_root->getHeight()-2);


}

template <typename T>
void roll_rr(Node_ptr<T> old_root){
    Node_ptr<T> parent=old_root->getParent();
    Node_ptr<T> new_root=old_root->getRight();
    Node_ptr<T> RL_Tree=new_root->getLeft();

    Side root_side =childSide(parent,old_root);
    
    //handle new_root pointers 
    connectNodes(parent,new_root,root_side);//connect to its parent
    connectNodes(new_root,old_root,L);//connect old root to its left
    
    //handle old_root pointers
    connectNodes(old_root,RL_Tree,R);
    
    //handles new heights
    old_root->setHeight(old_root->getHeight()-2);
}

template <typename T>
void roll_lr(Node_ptr<T> old_root){
    Node_ptr<T> parent=old_root->getParent();
    Node_ptr<T> left=old_root->getLeft();
    Node_ptr<T> new_root=left->getRight();
    Node_ptr<T> LRR_Tree=new_root->getRight();
    Node_ptr<T> LRL_Tree=new_root->getleft();

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
    left->setHeight(left->getLeft()-1);
    

}

template <typename T>
void roll_rl(Node_ptr<T> old_root){
    Node_ptr<T> parent=old_root->getParent();
    Node_ptr<T> right=old_root->getRight();
    Node_ptr<T> new_root=right->getLeft();
    Node_ptr<T> RLL_Tree=new_root->getLeft();
    Node_ptr<T> RLR_Tree=new_root->getRight();

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
    right->setHeight(right->getLeft()-1);
}

#endif 