#pragma once

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <vector>
#include <iostream>

// Q1: Template Circular Queue

// Generic queue class implemented using a circular array
template<typename T>
class Queue {
public:
    Queue(size_t capacity = 16);      // Constructor with default capacity
    ~Queue();                         // Destructor to free memory

    void push(const T& value);        // Add element to rear
    void pop();                       // Remove element from front
    T& front();                       // Access the front element
    size_t size() const;             // Get number of elements
    bool empty() const;              // Check if queue is empty

    void move_to_rear();             // Move the front element to the rear

private:
    T* data_;                         // Dynamic array to store elements
    size_t head_, tail_;             // Head and tail indices for circular queue
    size_t count_;                   // Number of elements in the queue
    size_t capacity_;                // Current array capacity
};

// Q2: Recursive Linear Search

// Recursively search for the last occurrence of target in vec
// Returns index of last occurrence, or -1 if not found
template<typename T>
int last_linear_search(const std::vector<T>& vec, const T& target, int idx = 0);


// Q3: Singly Linked List Node

// Basic node structure for singly linked list
struct Node {
    int value;         // Integer value stored in the node
    Node* next;        // Pointer to the next node

    Node(int v) : value(v), next(nullptr) {}  // Constructor to initialize node
};

// Sorts a singly linked list in ascending order using insertion sort
Node* insertion_sort(Node* head);

// Utility function to print all values in the linked list
void print_list(Node* head);

#endif // ASSIGNMENT_H
