/**
 * @file List.cpp
 * @author Dennis Kerry
 * @date September 27, 2024
 * @brief Linked list class member functions
 */

#include "List.h"
#include <iostream>

/**
 * Default constructor makes the list empty
 */
List::List()
{
    _head = nullptr;
    _size = 0;
}

/**
 * Property constructor initializes the list with one node of value: data
 * @param data
 */
List::List(const int data)
{
    _head = new Node(data, nullptr);
    _size = 1;
}

/**
 * Destructor that deletes all nodes to prevent memory leaks
 */
List::~List()
{
    // ReSharper disable once CppLocalVariableMayBeConst
    // ^ this tells CLion to stop trying to make pNode a const
    //   (we delete it so it shouldn't be)
    Node* pNode = _head;
    while (pNode)
    {
        Node* pNext = pNode->next;
        delete pNode;
        pNode = pNext;
    }
    _head = nullptr;  // just to be on the safe side
}

/**
 * Returns the list size
 * @return current size of the list
 */
int List::getSize() const
{
    return _size;
}

/**
 * Inserts a new node into the list
 * @param data value that new node should contain
 * @param position the index to insert the new node
 * - by default, appends to the end of the list
 * - negative numbers target head position
 */
void List::insert(const int data, int position)
{
    Node* pNew = new Node{data, nullptr};

    if (position < 0 || position > _size)  // if given position is out of scope
    {
        position = _size;  // make it the end of the list so we append
    }

    // insert at the start of the list
    if (position == 0)
    {
        pNew->next = _head;
        _head = pNew;
    }
    // insert anywhere else in the list, including the very end
    else
    {
        Node* pNode = _head;
        while (pNode->next && position > 1)
            // when position is 1, we've moved up to the node before the target
        {
            pNode = pNode->next;
            position--;
        }
        pNew->next = pNode->next;
        pNode->next = pNew;
    }
}

/**
 * Reads the value of a node in the list
 * @param position index of node to read
 * - default is last node
 * @return the value of targeted node
 */
int List::read(const int position) const
{
    Node* pNode = _head;
    int index = 0;
    while (pNode->next && index < position)
    {
        pNode = pNode->next;
        index++;
    }
    return pNode->data;
}

/**
 * Changes the value of a node in the list
 * @param data number to change the value of the node to
 * @param position index of node to modify
 * - default is last node
 */
void List::modify(const int data, const int position) const
{
    Node* pNode = _head;
    int index = 0;
    while (pNode->next && index < position)
    {
        pNode = pNode->next;
        index++;
    }
    pNode->data = data;
}

/**
 * Removes the node at a position
 * @param position the index for the node to remove
 * - negative values will target head
 * @return the value of the removed node
 */
int List::remove(const int position)
{
    int removedData;

    // if list is empty, there is nothing to remove
    if (!_head)
    {
        std::cerr << "List::remove() called with empty list" << std::endl;
        return -1;
    }

    // if the head is targeted, or if it's the only node, remove it
    if (position <= 0 || !_head->next)  // remove head
    {
        // ReSharper disable once CppLocalVariableMayBeConst
        Node* temp = _head;
        _head = _head->next;
        removedData = temp->data;
        delete temp;
        return removedData;
    }

    Node* pNode = _head->next;
    Node* temp = _head;
    int index = 1;  // index is 1 because we are starting on the second node
    while (pNode->next && index < position)
    {
        temp = pNode;
        pNode = pNode->next;
        index++;
    }  // we are now either at the end of the list or at the position index

    temp->next = pNode->next;
    removedData = pNode->data;
    delete pNode;
    _size--;
    return removedData;
}
