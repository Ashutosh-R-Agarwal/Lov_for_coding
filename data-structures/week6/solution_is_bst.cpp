#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>


using std::cin;
using std::cout;
using std::endl;
using std::vector;


struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}

  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

bool IsBinarySearchTreeUtil(size_t index)
{
	if (index != tree.size())
	{
		static int prev = INT_MIN;
		if (tree[index].left != -1)
		{
			if (!IsBinarySearchTreeUtil(tree[index].left))
				return false;
		}
		if (tree[index].left != -1 && tree[tree[index].left].key == tree[index].key)
		{
			return false;
		}

		//tree_inorder.push_back(tree[index].key);
		if (prev != INT_MIN && prev > tree[index].key)
			return false;

		prev = tree[index].key;
		if (tree[index].right != -1)
		{
			if(!IsBinarySearchTreeUtil(tree[index].right))
					return false;
		}
	}
	return true;

}


bool IsBinarySearchTree() {
  // Implement correct algorithm here
	//vector<struct Node>::iterator it;// = tree.begin();
	bool isBst = IsBinarySearchTreeUtil(0);
/*	bool isBst= true;
	if (tree_inorder.size()) {
		for (size_t t = 1; t != tree_inorder.size(); t++)
		{
			if (tree_inorder[t - 1] > tree_inorder[t])
			{
				isBst = false;
				break;
			}
		}
	}*/

	return isBst;

//  return true;
}

int main() {
  int nodes;
  cin >> nodes;


  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  if (IsBinarySearchTree()) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
