/**
 * @file List.h
 * @author Dennis Kerry
 * @date September 27, 2024
 * @brief Linked List class member function prototypes
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
    Node* _head;  // points to the first node in the list
    int _size;  // is equal to the amount of nodes in the list
public:
    // Constructors
    List();  // default constructor initializes empty list
    explicit List(int data);  // prop constructor initializes with one node

    ~List();  // deletes all nodes in the list

    [[nodiscard]] int getSize() const;  // returns _size

    // Member functions
    void insert(int data, int position = -1);
    [[nodiscard]] int read(int position) const;
    void modify(int data, int position) const;
    int remove(int position);
};

#endif //LIST_H
