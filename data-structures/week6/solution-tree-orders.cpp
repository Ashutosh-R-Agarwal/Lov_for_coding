#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

/*typedef struct tree{
	int key;
	struct tree * left;
	struct tree * right;

}tree;
*/
class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;

    key.resize(n);
    left.resize(n);
    right.resize(n);


    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  void in_order(int index) {
  //  vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if (left[index] != -1)
    	in_order(left[index]);
    printf("%d ", key[index]);
    if (right[index] != -1)
    	in_order(right[index]);

    //return result;
  }

  void pre_order(int index) {
   // vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
	 printf("%d ", key[index]);
	 if (left[index] != -1)
		pre_order(left[index]);
	 if(right[index] != -1)
		 pre_order(right[index]);
    //return result;
  }

  void post_order(int index) {
    //vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that

	  if (left[index] != -1)
		  post_order(left[index]);
	  if (right[index] != -1)
		  post_order(right[index]);
	 // if (index < n)
		printf("%d ", key[index]);

    //return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order(0);
  printf("\n");
  t.pre_order(0);
  printf("\n");
  t.post_order(0);
//  print(t.in_order());
//  print(t.pre_order());
  //print(t.post_order());
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

