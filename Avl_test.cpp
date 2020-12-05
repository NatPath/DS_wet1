#include "Avl.h"
#include <iostream>

void testAvlNode(){
    Node_ptr<int,int> n=nullptr;
    bool res= n==nullptr;
    n->setRight(n);
    print(res);

    
}
void testInOrder(){
    AVL_Tree<int,int> a;
    //int num1=4;
    //int num2=5;
    int arr[10];
    for (int i=0 ;i<10;i++){
        arr[i]=10-i;
        a.insertNode(arr[i],arr[i]);
    }
    /*
    for (int i=0 ;i<1000;i++){
        arr[i]=1000-i;
        a.insertNode(arr[i]);
    }
    */
    itterateOrder(a.getRoot(),IN,printValue<int>);
    print(a.getRoot()->getParent()==nullptr);
    print(a.getHeight());
    return;
}
template <typename KEY,typename VAL>
void usecount(Node_ptr<KEY,VAL>& n){
    print(n.use_count());
}
void testSmallTree(){
    AVL_Tree<int,int> tree;
    int n=1000;
    int* arr=new int[n];
    for (int i=0 ;i<n;i++){
        arr[i]=n-i;
        tree.insertNode(arr[i],arr[i]);
    }

    print("Printing usecount:");
    itterateOrder(tree.getRoot(),IN,usecount);
    print("Printing tree");
    itterateOrder(tree.getRoot(),IN,printValue);
    delete[] arr;

    //print(tree.getRoot().use_count());
}
void testDeleteNode(){
    int n=10;
    int* arr=new int[n];
    AVL_Tree<int,int> tree;
    for (int i=0 ;i<n;i++){
        arr[i]=n-i;
        tree.insertNode(arr[i],arr[i]);
    }
    print("printing tree before deletion");
    itterateOrder(tree.getRoot(),IN,printValue);
    for (int i=0 ;i<n;i++){
        tree.deleteNode(arr[n-i-1]);
        print("printing meanwhile tree");
        itterateOrder(tree.getRoot(),IN,printValue);
    }
    itterateOrder(tree.getRoot(),IN,printValue);
    delete[] arr;
    
}
int main(){
    //testInOrder();
    //testSmallTree();
    testDeleteNode();
    //testAvlNode();
}