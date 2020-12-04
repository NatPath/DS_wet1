#include "Avl.h"
#include <iostream>

int main(){
    AVL_Tree<int> a;
    //int num1=4;
    //int num2=5;
    int arr[100];
    for (int i=0 ;i<100;i++){
        arr[i]=100-i;
        a.insertNode(arr[i]);
    }
    inOrder(a.getRoot(),printValue<int>);
}