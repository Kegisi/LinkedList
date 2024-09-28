/**
 * @file List.h
 * @author Dennis Kerry
 * @date September 27, 2024
 */

#ifndef LIST_H
#define LIST_H

class List
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* _head;
public:
    List();
    explicit List(Node* node);
    ~List();
    void insert(int data, int position);
    int read(int position) const;
    void change(int data, int position) const;
    int remove(int position);
};

#endif //LIST_H
