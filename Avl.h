#ifndef _AVL_H_
#define _AVL_H_
#include <memory>
#include "Auxiliaries.h"

template<class T>
class AVL_NODE{
    typedef struct std::shared_ptr<AVL_NODE> Node_ptr;
    T& value;
    Node_ptr left;
    Node_ptr right;
    Node_ptr parent;
    int height;

    public:
    AVL_NODE(const T& value):value(value),left(nullptr),right(nullptr),parent(nullptr){}
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
        if (new_right!=nullptr){
            right.parent=this;
        }
    }
    void setLeft(Node_ptr new_left){
        left=new_left;
        if (new_left!=nullptr){
            left.parent=this;
        }
    }
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

        AVL_NODE left= parent_node->getLeft();
        AVL_NODE right= parent_node->getRight();
        return max(left->height(),right->height())+1;
    }

};


template<class T>
class AVL_Tree{
    //fields if splitting
    typedef struct std::shared_ptr<AVL_NODE> Node_ptr;
    Node_ptr root;
    //int balance_factor;

    
    void roll_ll(AVL_NODE ){
        
    }
    void roll_lr();
    void roll_rr();
    void roll_rl();

    
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
            left_height=left.getHeight();
        }
        if (right!=nullptr){
            right_height=right.getHeight();
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
    int height(Node_ptr root){
        if (root==nullptr){
            //shouldn't happen
            return -1;
        }
        int res=0;

        
    }
    void insertNode(T& to_insert){
        Node_ptr found_spot=findLastOfSearchPath(to_insert);
        if (found_spot->getValue()==to_insert){
            //value is already in the tree
            return;
        }
        else if(found_spot->getValue() < to_insert){
            found_spot->setRight(std::make_shared<AVL_NODE>(to_insert));
        }
        else{
            found_spot->setLeft(std::make_shared<AVL_NODE>(to_insert));
        }

        
    }
    void insertNode(T to_insert){
        Node found=findNodeAux(root,to_insert,nullptr,true);
        
        if(found==nullptr){
            // first node inserted, it has no parent, so it must be a root
            this->value=to_insert;
            return;
        }
        if (found->left==to_insert||found->right==to_insert){
            //The value we want to insert already exists
            return;            
        }
        if(to_insert < found->value){
            found.left=AVL(to_insert);
        }
        if(to_insert > found->value){
            found.right=new Node(to_insert);
        }

        Node_ptr i = found;
        i->setHeight(0);
        Node_ptr parent = i->getParent();
        int bf;
        while(i!=root){
            if(parent->getHeight() >= i->getHeight()+1){
                return;
            }
            parent->setHeight(i->getHeight()+1);
            bf=balance_factor(parent);
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
        }

    }
    
    void destroy();

    
    
};

#endif 