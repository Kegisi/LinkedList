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
    // Constructors
    List();
    explicit List(int data);
    ~List();  // Destructor

    void insert(int data, int position);
    void insert(int data);  //overloaded so I don't have to provide a position

    [[nodiscard]] int read(int position) const;
    void modify(int data, int position) const;
    int remove(int position);
};

#endif //LIST_H
