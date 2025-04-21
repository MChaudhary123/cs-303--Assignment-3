#include "functions.h"
#include <iostream>

// Question 1 

// Constructor for Queue
template<typename T>
Queue<T>::Queue(size_t capacity)
    : data_(new T[capacity]), head_(0), tail_(0), count_(0), capacity_(capacity) {
}

// Destructor to free allocated memory
template<typename T>
Queue<T>::~Queue() {
    delete[] data_;
}

// Push a new element to the rear of the queue
template<typename T>
void Queue<T>::push(const T& value) {
    if (count_ == capacity_) { // If full, double the capacity
        size_t newcap = capacity_ * 2;
        T* newdata = new T[newcap];
        // Copy elements in circular order
        for (size_t i = 0; i < count_; ++i)
            newdata[i] = data_[(head_ + i) % capacity_];
        delete[] data_;
        data_ = newdata;
        head_ = 0;
        tail_ = count_;
        capacity_ = newcap;
    }
    data_[tail_] = value;               // Insert new value
    tail_ = (tail_ + 1) % capacity_;    // Move tail pointer circularly
    ++count_;                           // Increment element count
}

// Remove the front element of the queue
template<typename T>
void Queue<T>::pop() {
    if (empty()) return;               // Do nothing if queue is empty
    head_ = (head_ + 1) % capacity_;   // Move head pointer circularly
    --count_;                          // Decrement element count
}

// Access the front element
template<typename T>
T& Queue<T>::front() {
    return data_[head_];
}

// Return the number of elements in the queue
template<typename T>
size_t Queue<T>::size() const {
    return count_;
}

// Check if the queue is empty
template<typename T>
bool Queue<T>::empty() const {
    return count_ == 0;
}

// Move front element to the rear
template<typename T>
void Queue<T>::move_to_rear() {
    if (empty()) return;              // Do nothing if empty
    T tmp = front();                  // Store front value
    pop();                            // Remove it
    push(tmp);                        // Re-insert at rear
}

// Force template instantiation for int type
template class Queue<int>;


// Question 2 

// Recursive function to find last occurrence of `target` in `vec`
// Starts searching from index `idx`
template<typename T>
int last_linear_search(const std::vector<T>& vec, const T& target, int idx) {
    if (idx >= static_cast<int>(vec.size())) return -1; // Base case: end of vector
    int res = last_linear_search(vec, target, idx + 1); // Recursive search
    if (res != -1) return res;                          // If found later, return it
    return (vec[idx] == target ? idx : -1);             // If current is match, return idx
}

// Force template instantiation for int type
template int last_linear_search<int>(const std::vector<int>&, const int&, int);


// Question 3

// Perform insertion sort on a singly linked list
Node* insertion_sort(Node* head) {
    Node dummy(0);                      // Dummy head for sorted list
    Node* sorted_tail = &dummy;        // Keeps track of end of sorted list

    while (head) {
        Node* cur = head;              // Extract current node
        head = head->next;             // Advance input list pointer

        // Find where to insert cur in the sorted list
        Node* prev = &dummy;
        while (prev->next && prev->next->value < cur->value)
            prev = prev->next;

        // Insert cur into sorted list
        cur->next = prev->next;
        prev->next = cur;
    }
    return dummy.next;                 // Return head of sorted list
}

// Print all elements in a linked list
void print_list(Node* head) {
    for (Node* p = head; p; p = p->next)
        std::cout << p->value << " ";
    std::cout << "\n";
}
