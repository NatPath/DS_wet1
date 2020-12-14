#include "List.h"

void testBasicAddRemove(){
   List<int> a;
   int n=10;
   for (int i=0 ; i<n;i++){
       a.add(i);
   }
   a.printList();
   for (int i=0;i<n;i++){
       a.remove(i);
   }
   a.printList();
   for (int i=0 ; i<n;i++){
       a.add(i);
   }
   print("printing list");
   a.printList();
}
void testCopyConstructor(){
    List<int> a;
    int n=10;
    for (int i=0;i<n;i++){
        a.add(i);
    }
    print("printing first list");
    a.printList();
    List<int> b=a;
    print("printing second list");
    b.printList();
    print("deleting first list...");
    for (int i=0;i<n;i++){
        a.remove(i);
    }
    print("printing first list");
    a.printList();
    print("printing second list");
    b.printList();
    
}
int main(){
    testCopyConstructor();

}