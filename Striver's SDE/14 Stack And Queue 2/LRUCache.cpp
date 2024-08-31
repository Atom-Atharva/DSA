// https://www.geeksforgeeks.org/problems/lru-cache/1

#include <iostream>
using namespace std;
#include <unordered_map>

// Doubly Linked List
class Node
{
public:
    Node *prev;
    Node *next;
    pair<int, int> val;

    Node(pair<int, int> val)
    {
        this->prev = NULL;
        this->next = NULL;
        this->val = val;
    }
};

class LRUCache
{
    unordered_map<int, Node *> umap;
    int capacity;
    Node *head, *tail;

    void deleteNode(Node *curr)
    {
        Node *prev = curr->prev;
        Node *next = curr->next;
        prev->next = next;
        next->prev = prev;
    }
    void insertNode(Node *curr)
    {
        Node *temp = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->capacity = cap;
        head = new Node({0, 0});
        tail = new Node({0, 0});
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // Check in Map
        // If Not Present return -1
        if (umap.count(key) == 0)
        {
            return -1;
        }
        // Else Store Value and mark as least recently used
        Node *curr = umap[key];

        // Delete curr from DLL
        deleteNode(curr);

        // Insert After Head in DLL
        insertNode(curr);

        return curr->val.second;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        // Check in umap
        if (umap.count(key) > 0)
        {
            Node *curr = umap[key];
            curr->val.second = value;

            deleteNode(curr);
            insertNode(curr);

            return;
        }

        // If Not then
        Node *curr = new Node({key, value});

        // Check capacity of umap
        // If space available then store in DLL and MAP
        if (umap.size() < capacity)
        {
            umap[key] = curr;
            insertNode(curr);
            return;
        }

        // Else remove LRU Node from map and DLL.
        Node *lru = tail->prev;
        deleteNode(lru);
        umap.erase(lru->val.first);

        // Then Store NEW NODE in DLL and map.
        insertNode(curr);
        umap[key] = curr;
        return;
    }
};