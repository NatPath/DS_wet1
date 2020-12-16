#include "Avl.h"
#include "Auxiliaries.h"
#include <random>
#include <vector>

template <typename KEY,typename VAL>
void printNode(Node_ptr<KEY,VAL>& a){
    print(a->getKey());   
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
void TestComplexObjects(){
    int n=10000;
    std::vector<int> *vec_arr=new std::vector<int>[n];
    int *arr=new int[n];
    AVL_Tree<int,std::vector<int>> tree;
    for (int i=0;i<n;i++){
        arr[i]=rand()%100000;
        vec_arr[i]={arr[i],arr[i],arr[i],arr[i],arr[i]};
        tree.insertNode(arr[i],vec_arr[i]);
    }
    print("printing tree ");
    itterateOrder(tree.getRoot(),IN,printNode);
    for (int i=n-1;i>=5;i--){
        tree.deleteNode(arr[i]);
    }
    
    print("printing tree ");
    itterateOrder(tree.getRoot(),IN,printNode);
    delete []arr;
    delete[]vec_arr;


}
void makeRandomTree(AVL_Tree<int,std::vector<int>>* tree){
    int n=100;
    int num=0;
    for (int i=0;i<n;i++){
        num=rand()%1000;
        std::vector<int> vec={num,num,num,num,num};
        tree->insertNode(num,vec);
    }
    

    
}
void TestTreeOfTrees(){
    int n=100;
    AVL_Tree<int,AVL_Tree<int,std::vector<int>>> tree;
    AVL_Tree<int,std::vector<int>> *arr=new AVL_Tree<int,std::vector<int>>[n];
    for( int i=0;i<n;i++){
        makeRandomTree(&arr[i]);
        tree.insertNode(i,arr[i]);
    }

}

int main(){
    //TestRandomInserts();
    TestComplexObjects();

}