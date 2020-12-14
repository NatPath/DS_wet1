#include "List.h"

int main(){
   List<int> a;
   int n=10;
   for (int i=0 ; i<n;i++){
       a.add(i);
   }
   a.printList();
   


}