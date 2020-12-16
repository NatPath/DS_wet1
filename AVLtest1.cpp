/*
 * testAVLTree.cpp
 *
 *  Created on: 19 ���� 2013
 *      Author: shirel
 */

#include "Avl.h"
#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>

int main(){
AVL_Tree <int,int> tree;
	//Specific Cases

/*correct output for the four next cases
1 BF: 0 Height: 0
2 BF: 0 Height: 1
3 BF: 0 Height: 0 */

//basic LL root change case1
std::cout<<"case1"<<std::endl;
	tree.insertNode(3,3);
	tree.insertNode(2,2);
	tree.insertNode(1,1);
	tree.printTree();
	tree.treeClear();

	//basic LR root change case2
	std::cout<<"case2"<<std::endl;
	tree.insertNode(3,3);
	tree.insertNode(1,1);
	tree.insertNode(2,2);
	tree.printTree();
	tree.treeClear();

	//basic RR root change case3
	std::cout<<"case3"<<std::endl;
	tree.insertNode(1,1);
	tree.insertNode(2,2);
	tree.insertNode(3,3);
	tree.printTree();
	tree.treeClear();

	//basic RL root change case4
	std::cout<<"case4"<<std::endl;
	tree.insertNode(1,1);
	tree.insertNode(3,3);
	tree.insertNode(2,2);
	tree.printTree();
	tree.treeClear();
//basic LR not root change case5
//correct output
/*1 BF: 0 Height: 0
2 BF: 0 Height: 1
3 BF: 0 Height: 0
4 BF: 1 Height: 2
5 BF: 0 Height: 0
6 BF: 1 Height: 3
7 BF: 0 Height: 0
8 BF: 1 Height: 1 */
std::cout<<"case5"<<std::endl;
	tree.insertNode(6,6);
	tree.insertNode(4,4);
	tree.insertNode(8,8);
	tree.insertNode(3,3);
	tree.insertNode(5,5);
	tree.insertNode(7,7);
	tree.insertNode(1,1);
	tree.insertNode(2,2);
	tree.printTree();
	tree.treeClear();

	//basic LL not root change case6
	/*correct output
1 BF: 0 Height: 0
2 BF: 0 Height: 1
3 BF: 0 Height: 0
4 BF: 1 Height: 2
5 BF: 0 Height: 0
6 BF: 1 Height: 3
7 BF: 0 Height: 0
8 BF: 1 Height: 1 */
std::cout<<"case6"<<std::endl;
	tree.insertNode(6,6);
	tree.insertNode(4,4);
	tree.insertNode(8,8);
	tree.insertNode(3,3);
	tree.insertNode(5,5);
	tree.insertNode(7,7);
	tree.insertNode(2,2);
	tree.insertNode(1,1);
	tree.printTree();
	tree.treeClear();

	//basic RR not root change case7
	/*correct output
1 BF: 0 Height: 0
2 BF: 0 Height: 1
3 BF: 0 Height: 0
5 BF: 1 Height: 2
7 BF: 0 Height: 0*/
std::cout<<"case7"<<std::endl;
	tree.insertNode(5,5);
	tree.insertNode(7,7);
	tree.insertNode(1,1);
	tree.insertNode(2,2);
	tree.insertNode(3,3);
	tree.printTree();
	tree.treeClear();




	//basic RL not root change case8
	/*correct output
1 BF: 0 Height: 0
2 BF: 0 Height: 1
3 BF: 0 Height: 0
5 BF: 1 Height: 2
7 BF: 0 Height: 0*/
std::cout<<"case8"<<std::endl;
	tree.insertNode(5,5);
	tree.insertNode(7,7);
	tree.insertNode(1,1);
	tree.insertNode(3,3);
	tree.insertNode(2,2);
	tree.printTree();
	tree.treeClear();

	//root deletion no roll successor is a neighbour case9
	/*correct output
2 BF: 0 Height: 0
3 BF: 1 Height: 1
5 BF: 1 Height: 2
6 BF: 0 Height: 0*/
std::cout<<"case9"<<std::endl;
	tree.insertNode(4,4);
	tree.insertNode(5,5);
	tree.insertNode(3,3);
	tree.insertNode(2,2);
	tree.insertNode(6,6);
	tree.deleteNode(4);
	tree.printTree();
	tree.treeClear();

		//root deletion no roll successor is not a neighbour case10
	/*correct output
2 BF: 0 Height: 0
3 BF: 1 Height: 1
5 BF: 0 Height: 2
6 BF: 0 Height: 0
7 BF: 0 Height: 1
8 BF: 0 Height: 0 */
std::cout<<"case10"<<std::endl;
	tree.insertNode(4,4);
	tree.insertNode(3,3);
	tree.insertNode(7,7);
	tree.insertNode(2,2);
	tree.insertNode(5,5);
	tree.insertNode(8,8);
	tree.insertNode(6,6);
	tree.deleteNode(4);
	tree.printTree();
	tree.treeClear();


    //node deletion no roll successor is a neighbour case11
	/*correct output
1 BF: 0 Height: 0
2 BF: 1 Height: 1
4 BF: 1 Height: 2
5 BF: 0 Height: 0
7 BF: 1 Height: 3
8 BF: -1 Height: 1
9 BF: 0 Height: 0*/
std::cout<<"case11"<<std::endl;
	tree.insertNode(7,7);
	tree.insertNode(3,3);
	tree.insertNode(8,8);
	tree.insertNode(2,2);
	tree.insertNode(4,4);
	tree.insertNode(9,9);
	tree.insertNode(5,5);
	tree.insertNode(1,1);
	tree.deleteNode(3);
	tree.printTree();
	tree.treeClear();

	//node deletion no roll successor is not a neighbour case12
	/*correct output
1 BF: 0 Height: 0
2 BF: 1 Height: 1
5 BF: 0 Height: 2
6 BF: 0 Height: 0
7 BF: 0 Height: 1
8 BF: 0 Height: 0
9 BF: 0 Height: 3
10 BF: 0 Height: 0
12 BF: -1 Height: 2
13 BF: -1 Height: 1
14 BF: 0 Height: 0*/
std::cout<<"case12"<<std::endl;
	tree.insertNode(9,9);
	tree.insertNode(3,3);
	tree.insertNode(12,12);
	tree.insertNode(2,2);
	tree.insertNode(7,7);
	tree.insertNode(10,10);
	tree.insertNode(13,13);
	tree.insertNode(1,1);
	tree.insertNode(5,5);
	tree.insertNode(8,8);
	tree.insertNode(14,14);
	tree.insertNode(6,6);
	tree.deleteNode(3);
	tree.printTree();
	tree.treeClear();

	//node deletion causing LR case13
	/*correct output
1 BF: 0 Height: 0
2 BF: 0 Height: 1
3 BF: 0 Height: 0
4 BF: 0 Height: 2
7 BF: -1 Height: 1
8 BF: 0 Height: 0*/
std::cout<<"case13"<<std::endl;
	tree.insertNode(7,7);
	tree.insertNode(2,2);
	tree.insertNode(8,8);
	tree.insertNode(1,1);
	tree.insertNode(4,4);
	tree.insertNode(9,9);
	tree.insertNode(3,3);
	tree.deleteNode(9);
	tree.printTree();
	tree.treeClear();

	//node deletion causing LL case14
	/*correct output
1 BF: 0 Height: 0
2 BF: 1 Height: 1
3 BF: 0 Height: 2
4 BF: 0 Height: 0
7 BF: 0 Height: 1
8 BF: 0 Height: 0*/
std::cout<<"case14"<<std::endl;
	tree.insertNode(7,7);
	tree.insertNode(3,3);
	tree.insertNode(8,8);
	tree.insertNode(2,2);
	tree.insertNode(4,4);
	tree.insertNode(9,9);
	tree.insertNode(1,1);
	tree.deleteNode(9);
	tree.printTree();
	tree.treeClear();

	//node deletion causing RR case15
	/*correct output
2 BF: 0 Height: 0
3 BF: 0 Height: 1
7 BF: 0 Height: 0
8 BF: 0 Height: 2
9 BF: -1 Height: 1
10 BF: 0 Height: 0*/
std::cout<<"case15"<<std::endl;
	tree.insertNode(3,3);
	tree.insertNode(2,2);
	tree.insertNode(8,8);
	tree.insertNode(7,7);
	tree.insertNode(1,1);
	tree.insertNode(9,9);
	tree.insertNode(10,10);
	tree.deleteNode(1);
	tree.printTree();
	tree.treeClear();

	//node deletion causing RL case16
	/*correct output
2 BF: 0 Height: 0
3 BF: 1 Height: 1
7 BF: 0 Height: 2
10 BF: 0 Height: 0
13 BF: 0 Height: 1
14 BF: 0 Height: 0*/
std::cout<<"case16"<<std::endl;
	tree.insertNode(3,3);
	tree.insertNode(2,2);
	tree.insertNode(13,13);
	tree.insertNode(7,7);
	tree.insertNode(1,1);
	tree.insertNode(14,14);
	tree.insertNode(10,10);
	tree.deleteNode(1);
	tree.printTree();
	tree.treeClear();

	//double rotations RL and RR case 17
	/*correct output
3 BF: 0 Height: 0
5 BF: 0 Height: 1
7 BF: 0 Height: 0
9 BF: 0 Height: 2
11 BF: 0 Height: 0
13 BF: 1 Height: 1
15 BF: 0 Height: 3
17 BF: 0 Height: 0
19 BF: -1 Height: 2
21 BF: -1 Height: 1
23 BF: 0 Height: 0*/
std::cout<<"case17"<<std::endl;
	tree.insertNode(9,9);
	tree.insertNode(3,3);
	tree.insertNode(15,15);
	tree.insertNode(1,1);
	tree.insertNode(7,7);
	tree.insertNode(13,13);
	tree.insertNode(19,19);
	tree.insertNode(5,5);
	tree.insertNode(11,11);
	tree.insertNode(17,17);
	tree.insertNode(21,21);
	tree.insertNode(23,23);
	tree.deleteNode(1);
	tree.printTree();
	tree.treeClear();

	//double rotations RR and RR case 18
	/*correct output
3 BF: 0 Height: 0
7 BF: 0 Height: 1
8 BF: 0 Height: 0
9 BF: 0 Height: 2
11 BF: 0 Height: 0
13 BF: 1 Height: 1
15 BF: 0 Height: 3
17 BF: 0 Height: 0
19 BF: -1 Height: 2
21 BF: -1 Height: 1
23 BF: 0 Height: 0*/
std::cout<<"case18"<<std::endl;
	tree.insertNode(9,9);
	tree.insertNode(3,3);
	tree.insertNode(15,15);
	tree.insertNode(1,1);
	tree.insertNode(7,7);
	tree.insertNode(13,13);
	tree.insertNode(19,19);
	tree.insertNode(8,8);
	tree.insertNode(11,11);
	tree.insertNode(17,17);
	tree.insertNode(21,21);
	tree.insertNode(23,23);
	tree.deleteNode(1);
	tree.printTree();
	tree.treeClear();

	//double rotations RL and LL case 19
	/*correct output
6 BF: 0 Height: 0
7 BF: 1 Height: 1
8 BF: 1 Height: 2
9 BF: 0 Height: 0
10 BF: 0 Height: 3
11 BF: -1 Height: 1
12 BF: 0 Height: 0
15 BF: 0 Height: 2
17 BF: 0 Height: 0
18 BF: 0 Height: 1
20 BF: 0 Height: 0
	 */
	std::cout<<"case19"<<std::endl;
	tree.insertNode(15,15);
	tree.insertNode(10,10);
	tree.insertNode(20,20);
	tree.insertNode(8,8);
	tree.insertNode(11,11);
	tree.insertNode(17,17);
	tree.insertNode(21,21);
	tree.insertNode(7,7);
	tree.insertNode(9,9);
	tree.insertNode(12,12);
	tree.insertNode(18,18);
	tree.insertNode(6,6);
	tree.deleteNode(21);
	tree.printTree();
	tree.treeClear();

	//double rotations LR and LL case 20
	/*correct output
6 BF: 0 Height: 0
7 BF: 1 Height: 1
8 BF: 1 Height: 2
9 BF: 0 Height: 0
10 BF: 0 Height: 3
11 BF: -1 Height: 1
12 BF: 0 Height: 0
15 BF: 0 Height: 2
20 BF: 0 Height: 0
21 BF: 0 Height: 1
22 BF: 0 Height: 0 */
std::cout<<"case20"<<std::endl;
	tree.insertNode(15,15);
	tree.insertNode(10,10);
	tree.insertNode(20,20);
	tree.insertNode(8,8);
	tree.insertNode(11,11);
	tree.insertNode(17,17);
	tree.insertNode(22,22);
	tree.insertNode(7,7);
	tree.insertNode(9,9);
	tree.insertNode(12,12);
	tree.insertNode(21,21);
	tree.insertNode(6,6);
	tree.deleteNode(17);
	tree.printTree();
	tree.treeClear();

	//delete node cause LR case21
	/*correct output
2 BF: 0 Height: 0
3 BF: -1 Height: 2
4 BF: 0 Height: 0
6 BF: 1 Height: 1*/
std::cout<<"case21"<<std::endl;
	tree.insertNode(5,5);
	tree.insertNode(3,3);
	tree.insertNode(6,6);
	tree.insertNode(2,2);
	tree.insertNode(4,4);
	tree.deleteNode(5);
	tree.printTree();
	tree.treeClear();

	//delete node cause LR case22
	/*correct output
2 BF: 0 Height: 0
3 BF: 0 Height: 1
6 BF: 0 Height: 0*/
std::cout<<"case22"<<std::endl;
	tree.insertNode(5,5);
	tree.insertNode(3,3);
	tree.insertNode(6,6);
	tree.insertNode(2,2);
	tree.deleteNode(5);
	tree.printTree();
	tree.treeClear();

	std::vector<int> vector;
	 for (int i=1; i<=100; i++) vector.push_back(i);

	 //Randomly insert and removes nodes
	 for (int k = 0; k < 20; ++k) {
		 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		 shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
		 for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
				tree.insertNode(*it,*it);

		 }
		 tree.printTree();
		 shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
		 for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
				tree.deleteNode(*it);
				tree.printTree();

		 }
		 tree.treeClear();
		 tree.printTree();
		 std::cout << '\n';
	}

	return 0;
}

