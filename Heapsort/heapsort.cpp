#include <iostream>
#include <vector>
using namespace std;

class Heap
{
  vector<int> arr;
  int N;

private:
  // does heapify logic
  void heapify(int currIndex, int boundLimit)
  {    
    int largest = currIndex;
    int leftChild = 2 * currIndex + 1;
    int rightChild = 2 * currIndex + 2;

    if (leftChild < boundLimit && arr[leftChild] > arr[largest])
      largest = leftChild;
    if (rightChild < boundLimit && arr[rightChild] > arr[largest])
      largest = rightChild;

    if (largest != currIndex)
    {
      swap(arr[currIndex], arr[largest]);
      heapify(largest, boundLimit);
    }
  }
  // constructs max heap
  void constructMaxHeap()
  {    
    for (int i = N - 1; i >= 0; i--)    
      heapify(i, N);    
  }

public:
  Heap() { this->N = 0; }

  // inserts element into the vector
  void insert(int n)
  {
    arr.push_back(n);
    this->N++;
  }

  // does heapsort
  void heapsort()
  {
    // first construct max heap and then do sorting
    constructMaxHeap();
    for (int i = N - 1; i >= 0; i--)
    {
      swap(arr[0], arr[i]);
      heapify(0, i);
    }
  }

  // printing the vector
  void print()
  {
    for (int i = 0; i < N; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
};

int main()
{
  Heap arr;
  for (int i = 0; i < 10; i++)  
    arr.insert(rand() % 25);  

  cout<<"Before sorting: ";
  arr.print();

  // sorting
  arr.heapsort();

  cout<<"After sorting: ";
  arr.print();
  return 0;
}