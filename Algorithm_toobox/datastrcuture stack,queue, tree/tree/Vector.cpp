#include <iostream>
#include <vector>
#include <iostream>

class Node {
    public:
    int key;

    Node * parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }
    void setParent(Node *thisparent)
    {
        parent = thisparent;
        parent->children.push_back(this);
    }
};

int main()
{
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  std::cout << "Printing out the original order along with child \n";
  for(int child_index = 0; child_index < n; child_index++) {
    Node n = nodes[child_index];
    std::cout << "\n " << n.key << "\n";
    int j = 0;
    for(Node *temp = nodes[child_index]->children[j++]; temp != NULL; temp = nodes[child_index].children[j++])
    {
        std::cout << " " << temp->key;
    }
  }
    return 0;
}
