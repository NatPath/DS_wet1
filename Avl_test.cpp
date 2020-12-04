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
    int arr[100];
    for (int i=0 ;i<1000;i++){
        arr[i]=1000-i;
        a.insertNode(arr[i]);
    }
    inOrder(a.getRoot(),printValue<int>);
    print(a.getHeight());
    return;
}
int main(){
    testInOrder();
    //testAvlNode();
}