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
    Node* _head;
    int _size;
public:
    // Constructors
    List();
    explicit List(int data);
    ~List();  // Destructor

    int getSize() const;  // getter

    // Member functions
    void insert(int data, int position = -1);
    [[nodiscard]] int read(int position) const;
    void modify(int position, int data) const;
    int remove(int position);
};

#endif //LIST_H
