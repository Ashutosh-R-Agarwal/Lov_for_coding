#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#include<stdio.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;


class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

std::queue <Node *> q;

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  Node *root;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    else
        root = &(nodes[child_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  /*int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }*/

  // nodes[left_index] ya phir &nodes[leaf_index] , EQUAL ??

  int maxHeight = 0 ;

  //std::cout << "NODES  " << nodes[0] << "Address of node" << &nodes[0];
    //std::cout << nodes[0].<< "Address of node" << &nodes[0];

  /*for(int child_index = 0; child_index < n; child_index++) {
    int height;
    Node *v = &nodes[child_index];
   // Node * temp = v->parent;
   // if (temp)
    //{
        height = v->children.size();
       // if(height)
        printf("\nLeaf index number : %d and no. of children ; %d", child_index, height);
        height ++;
        maxHeight = std::max(maxHeight, height);
    //}

  }*/

//int maxHeight = 0 ;
  maxHeight = 0;
  int nodecount;
  q.push(root);
  while(1)
  {
      nodecount = q.size();

      if (nodecount == 0)
        break;
      maxHeight++;
      while(nodecount)
      {
          Node *v = q.front();
          printf("\n Nodes are : %d", v->key);
          q.pop();
         int i = v->children.begin();
          Node *temp = v->children.begin();
         // v->children[i];

          //q.push(temp);
          v->children.pop_back();
          nodecount--;
      }
  }
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
