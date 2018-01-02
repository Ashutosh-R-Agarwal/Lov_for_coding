#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;



  void ReadData() {
    int n;
    cin >> n;
    cout << "VALUE ENTERED IS : " << n;
    data_.resize(n);
    for(int i = 1; i <= n; ++i)
      cin >> data_[i];
    //for(int i = 1; i <= n; ++i)
   //     cout << "\nValue entered are :" << data_[i];

  }

  int Parent(int i) {
	  return i / 2;
  }

  int LeftChild(int i) {
	  return 2 * i;
  }

  int RightChild(int i) {
	  return 2 * i + 1;
  }

  // MIN HEAP
  void shiftup(int i) {

	  //printf("\nVALUES of I is : %d" , i);
	 // printf("\n i / 2 is : %d   and data_ of i /2 : %d and data i : %d", i /2, data_[i/2], data_[i]);
	  while ((i /2 > 0) && (data_[i / 2]) > data_[i]) {
			//swap(data_[i] / 2 , i);
		  	  //printf("\n data to be swapped are : %d %d", data_[i / 2], data_[i]);
		      swap(data_[i /2], data_[i]);
		      swaps_.push_back(make_pair(i / 2 - 1 , i - 1));
	//	      printf("\n%d %d", i /2 - 1 , i - 1);
		      i = i / 2;
		}
  }

  void shiftdown(int i)
  {
	  int minIndex = i;
	  unsigned int left , right;
	  left = 2 * i;
	  right = 2 * i + 1;
	  if (left < data_.size() && data_[left] < data_[minIndex]) {
		  minIndex = left;
	  }
	  if (right < data_.size() && data_[right] < data_[minIndex]) {
		  minIndex = right;
	  }
	  if (i != minIndex) {
		  swap(data_[i], data_[minIndex]);
		  swaps_.push_back(make_pair(i , minIndex));
		  shiftdown(minIndex);
	  }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*for (unsigned int i = 0; i < data_.size(); ++i)
      for (unsigned int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }*/
    //swaps_.clear();
   /* for (unsigned int i = data_.size(); i > 0 ; i--) {
    	shiftup(i);
    }*/

	  //WriteResponse();
printf("\nFINISHED GENERATE SWAPS");
WriteResponse();
  }

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (unsigned int i = 1; i <= swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }
 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
 public:
  void printsol() {
	  WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
 // heap_builder.printsol();
  return 0;
}
