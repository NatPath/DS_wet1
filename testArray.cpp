#include "Array.h"

void testArrayBasicInsert(){
    int n=10;
    Array<int> arr(n);
    for (int i=0;i<n;i++){
        arr[i]=i;
    }
    arr.printArray();
}
void testCopyConstructor(){
    int n=10;
    Array<int> arr(n);
    for (int i=0;i<n;i++){
        arr[i]=i;
    }
    arr.printArray();
    Array<int> array_copy(arr);
    //delete first array
    for (int i=0;i<n;i++){
        arr[i]=0;
    }
    arr.printArray();
    print("printing second array");
    array_copy.printArray();

}
int main(){
    //testArrayBasicInsert();
    testCopyConstructor();

}