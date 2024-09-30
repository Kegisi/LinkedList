/**
 * @file list_test.cpp
 * @author Dennis Kerry
 * @date September 27, 2024
 * @brief This file contains the main function for testing the List class.
 *
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
        list.insert(i);
    }
    for (int i = 0; i < 6; i++)
    {
        std::cout << list.read(i) << ' ';
    }
    std::cout << std::endl;
    list.insert(9283749, 3);  // add a random number to the mix
    list.remove(6);  // get rid of the last node
    list.modify(8, 0); // change the head to hold 8

    for (int i = 0; i < 6; i++)
    {
        std::cout << list.read(i) << ' ';
    }
    return 0;
}
