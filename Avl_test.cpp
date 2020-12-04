#include "Avl.h"
#include <iostream>

void testAvlNode(){
    Node_ptr<int> n=nullptr;
    bool res= n==nullptr;
    n->setRight(n);
    print(res);

    
}
void testInOrder(){
    AVL_Tree<int> a;
    //int num1=4;
    //int num2=5;
    int arr[10];
    for (int i=0 ;i<10;i++){
        arr[i]=10-i;
        a.insertNode(arr[i]);
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
template <typename T>
void usecount(Node_ptr<T> n){
    print(n.use_count());
}
void testSmallTree(){
    /*
    int a=1;
    int b=2;
    int c=3;
    int d=4;
    */
    AVL_Tree<int> tree;
    int arr[300];
    for (int i=0 ;i<300;i++){
        arr[i]=300-i;
        tree.insertNode(arr[i]);
        itterateOrder(tree.getRoot(),IN,usecount);
    }

    print("Printing usecount:");
    itterateOrder(tree.getRoot(),IN,usecount);

    //print(tree.getRoot().use_count());
}
void testDeleteNode(){
    int n=10;
    int* arr=new int[n];
    AVL_Tree<int> tree;
    for (int i=0 ;i<n;i++){
        arr[i]=n-i;
        tree.insertNode(arr[i]);
    }
    for (int i=0 ;i<n;i++){
        tree.deleteNode(arr[i]);
        itterateOrder(tree.getRoot(),IN,printValue);
    }
    itterateOrder(tree.getRoot(),IN,printValue);
    
}
int main(){
    //testInOrder();
    //testSmallTree();
    testDeleteNode();
    //testAvlNode();
}