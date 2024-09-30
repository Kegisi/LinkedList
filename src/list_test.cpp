/**
 * @file list_test.cpp
 * @author Dennis Kerry
 * @date September 27, 2024
 * @brief This file contains the main function for testing the List class.
 * @details
 * This project is my attempt at creating a linked list by myself after
 * Professor Allen introduced them the other day.
 */

#include <iostream>
#include "List.h"


int main()
{
    // test that the list class works
    List list;
    for (int i = 0; i < 6; i++)
    {
        list.insert(i);  // each node will contain its index
    }
    for (int i = 0; i < 6; i++)
    {
        std::cout << list.read(i) << ' ';
    }
    std::cout << std::endl;
    list.insert(9283749, 3);  // add a random number to the mix
    list.insert(23);  // insert 23 at end of list
    list.remove(6);  // get rid of the last node
    list.modify(0, 56); // change the head to hold 56

    for (int i = 0; i < 7; i++)
    {
        // should look like 56 1 2 9283749 3 4 23
        std::cout << list.read(i) << ' ';
    }
    return 0;
}
