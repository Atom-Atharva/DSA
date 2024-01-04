// https://leetcode.com/problems/lru-cache/?envType=study-plan-v2&envId=top-interview-150

//*************************** DESIGN QUESTION ***********************************//

#include <iostream>
using namespace std;
#include <unordered_map>

struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int val)
    {
        this->key = key;
        this->value = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache
{
    Node *head;
    Node *tail;
    unordered_map<int, Node *> umap;
    int capacity;
    int size;

public:
    LRUCache(int capacity)
    {
        head = NULL;
        tail = NULL;
        this->capacity = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (umap.count(key) > 0)
        {
            Node *node = umap[key];
            if (node == head)
            {
                return node->value;
            }

            Node *prev = node->prev;
            Node *next = node->next;

            if (prev != NULL)
            {
                prev->next = next;
            }
            if (next != NULL)
            {
                next->prev = prev;
            }
            else
            {
                tail = prev;
            }

            node->next = head;
            head->prev = node;
            head = node;

            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (umap.count(key) > 0)
        {
            umap[key]->value = value;

            Node *node = umap[key];
            if (node == head)
            {
                return;
            }

            Node *prev = node->prev;
            Node *next = node->next;

            if (prev != NULL)
            {
                prev->next = next;
            }
            if (next != NULL)
            {
                next->prev = prev;
            }
            else
            {
                tail = prev;
            }

            node->next = head;
            head->prev = node;
            head = node;
            return;
        }

        Node *node = new Node(key, value);
        if (size < capacity)
        {
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                node->next = head;
                head->prev = node;
                head = node;
            }
            size++;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;

            umap.erase(tail->key);

            tail = tail->prev;
            tail->next = NULL;
        }
        umap[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */