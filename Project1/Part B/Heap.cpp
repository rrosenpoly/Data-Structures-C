// Rodolphe Eugene
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

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    void GenerateSwaps() {
        swaps_.clear();
        // Starting from the middle of the array, we iterate backwards 
        // and sift down each element to its correct position in the heap
        for (int i = data_.size() / 2; i >= 0; --i) {
            SiftDown(i);
        }
    }

    void SiftDown(int i) {
        int minIndex = i; // initialize with value of i and keep track of minimum elements 
        int leftChild = 2 * i + 1; // calculate the lefft index of current node 
        int rightChild = 2 * i + 2; // calculate the right index of current node

        // checks whether the left child of current node exist and if index is within bound
        if (leftChild < data_.size() && data_[leftChild] < data_[minIndex]) {
            minIndex = leftChild; // updates the index of the left child
        }

        // checks whether the right child of current node exists and if index is within bound
        if (rightChild < data_.size() && data_[rightChild] < data_[minIndex]) {
            minIndex = rightChild; // updates the index of the right child
        }

        // checks if current node is already the minimum element
        if (i != minIndex) {
            swap(data_[i], data_[minIndex]); // values in current node and minimum are swapped
            swaps_.push_back(make_pair(i, minIndex));  // add pair of indexes to  swap_ vector
            SiftDown(minIndex); // call recursively on minimum node until heap properties are satisfied
        }
    }


public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
