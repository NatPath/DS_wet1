#include "Avl.h"
#include "Auxiliaries.h"
#include <random>

template <typename KEY,typename VAL>
void printNode(Node_ptr<KEY,VAL>& a){
    print(a->getValue());   
}
void TestRandomInserts(){
    int n=10000;
    int *arr=new int[n];
    AVL_Tree<int,int> tree;
    for (int i=0;i<n;i++){
        arr[i]=rand()%10000;
        tree.insertNode(arr[i],arr[i]);
    }
    itterateOrder(tree.getRoot(),IN,printNode);
    delete []arr;
    
}

int main(){
    TestRandomInserts();

}