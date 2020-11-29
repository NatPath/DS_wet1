#ifndef _AVL_H_
#define _AVL_H_
#include <memory>

template<class T>
class AVL_NODE{
    typedef struct std::shared_ptr<AVL_NODE> Node_ptr;
    T& value;
    Node_ptr left;
    Node_ptr right;
    Node_ptr parent;

    public:
    AVL_NODE(const T& value):value(value),left(nullptr),right(nullptr),parent(nullptr){}
    ~AVL_NODE();

    //getters
    const T& getValue() const{
        return value;
    }
    AVL_NODE getRight() {
        if (right==nullptr){
            return nullptr;
        }
        return *right;
    }
    AVL_NODE getLeft() {
        if (left==nullptr){
            return nullptr;
        }
        return *left;
    }
    AVL_NODE getParent() {
        if (parent==nullptr){
            return nullptr;
        }
        return *parent;
    }
    //setters
    void setValue(const T& new_value){
        value=new_value;
    }
    void setRight(AVL_NODE new_right){
        right=new_right;
        right.parent=this;
    }
    void setLeft(AVL_NODE new_left){
        left=new_left;
        left.parent=this;
    }

}
template<class T>
class AVL_Tree{
    typedef struct std::shared_ptr Node;
    typedef struct std::shared_ptr<AVL_NODE> Node_ptr;
    T& value;
    Node left;
    Node right;
    Node parent;
    Node_ptr root;
    int balance_factor;

    
    void roll_ll(){
        
    }
    void roll_lr();
    void roll_rr();
    void roll_rl();
    Node findNodeAux(Node root ,const T& value,Node parent, const bool return_parent){
        if(root==nullptr) {
            if(return_parent){
                return parent;
            }
            else{
                return nullptr;
            }
        }   
        if (value==root->*value){
            
            return root;
        }

        if(value<root->*value){
            return findNodeAux(root->left,value,root);
        }
        else{
            return findNodeAux(root->right,value,root);
        }
        
    };
    //These functions DO NOT preserve invariance
    void setLeft(Node new_left){
        new_left.parent=this;
        left=new_left;
    }
    void setRight(Node new_right){
        new_right.parent=this;
        left=new_right;
    }
    //
    public:
    AVL(const T& value):value(value),left(nullptr),right(nullptr),parent(nullptr){}
    AVL(T& value,Node left,Node right ,Node parent):left(left),right(right),parent(parent){};
    
    Node getRight(){
        return right;
    }
    Node getLeft(){
        return left;
    }
    Node getParent(){
        return parent;
    }

    //
    void climbTree(void* func){}

    Node getRoot(){
        Node climber;
        climber=this;
        while(climber.parent!=nullptr){
            climber==climber.parent;
        }
        return climber;
    }
    //returns the distance of the node from the root
    int getHeightOfNode(){
        Node climber=parent;
        int counter=0;
        while(climber!=nullptr){
            counter++;                        
            climber=climber.parent;
        }
        return counter;
    }

    bool isLeaf(Node node){
        return node->left==nullptr&&node->right==nullptr;

    }
    void inorder(void* func);
    void postorder(void* func);
    Node findNode(const T& value){
        Node root = std::make_shared<AVL>(this);
        return findNodeAux(root ,value,nullptr,false);
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

    }
    
    void destroy();
    
    
};

#endif 