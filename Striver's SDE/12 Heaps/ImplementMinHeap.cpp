// https://www.naukri.com/code360/problems/min-heap_4691801?topList=striver-sde-sheet-problems

#include <iostream>
using namespace std;
#include <vector>

void upHeapify(vector<int> &heap)
{
    int curr = heap.size() - 1;

    while (curr > 0)
    {
        // Compare Child with Parent
        int parent = (curr - 1) / 2;

        // Swap if Needed till it reach topmost level or desired level
        if (heap[curr] < heap[parent])
        {
            int temp = heap[curr];
            heap[curr] = heap[parent];
            heap[parent] = temp;

            curr = parent;
        }
        else
        {
            break;
        }
    }
    return;
}

void downHeapify(vector<int> &heap)
{
    int curr = 0;

    while (curr < heap.size())
    {
        // Compare Parent with child
        int leftChild = (2 * curr) + 1;
        int rightChild = (2 * curr) + 2;

        // Swap with Min Element Till Reaches Leaf Node
        int minChild = curr;
        if (leftChild < heap.size() && heap[leftChild] < heap[minChild])
        {
            minChild = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[minChild])
        {
            minChild = rightChild;
        }
        if (minChild == curr)
        {
            break;
        }

        int temp = heap[minChild];
        heap[minChild] = heap[curr];
        heap[curr] = temp;

        curr = minChild;
    }

    return;
}

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    // Make Vector
    vector<int> heap;

    // Store Result
    vector<int> result;

    // For Each Query
    for (int i = 0; i < q.size(); i++)
    {
        // For Inserting
        if (q[i][0] == 0)
        {
            // - Insert in Last
            heap.push_back(q[i][1]);
            // - Up Heapify
            upHeapify(heap);
        }

        // For Removing
        else
        {
            // - Swap with last element
            int temp = heap[heap.size() - 1];
            heap[heap.size() - 1] = heap[0];
            heap[0] = temp;

            // Print Min Element
            result.push_back(heap[heap.size() - 1]);
            heap.pop_back();

            // - Down Heapify the first element
            downHeapify(heap);
        }
    }

    return result;
}
