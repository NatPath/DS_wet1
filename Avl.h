#ifndef _AVL_H_
#define _AVL_H_
#include <memory>
#include <exception>

template<class T>


class AVL{
    typedef struct std::shared_ptr Node;
    T& value;
    Node left;
    Node right;
    Node parent;
    int bf;

    
    void roll_ll();
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
    public:
    AVL()=default;
    AVL(T& value,Node left,Node right ,Node parent):left(left),right(right),parent(parent){};
    bool isLeaf(Node node){
        return node->left==nullptr&&node->right==nullptr;

    }
    inorder(void* func);
    postorder(void* func);
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