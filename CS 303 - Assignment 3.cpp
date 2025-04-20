#include "functions.h"
#include <vector>
#include <iostream>

int main() {
    using std::cout;
    using std::vector;

    // === Q1a: Instantiate Queue<int> and push 10 values ===
    Queue<int> q;
    for (int i = 1; i <= 10; ++i) {
        q.push(i * 10);  // Push 10, 20, ..., 100 into the queue
    }

    // === Q1b: Display all queue elements using only push/pop/front/size ===
    cout << "Queue contents: ";
    size_t n = q.size();  // Store the initial size to avoid infinite loop
    for (size_t i = 0; i < n; ++i) {
        cout << q.front() << " ";    // Print the front element
        q.push(q.front());           // Push it to the rear
        q.pop();                     // Remove the original front
    }
    cout << "\n";

    // === Q1c: Move front to rear and print new front ===
    q.move_to_rear();  // Move current front element to the rear
    cout << "After move_to_rear(), new front: " << q.front() << "\n\n";

    // === Q2: Recursive linear search for last occurrence ===
    vector<int> nums = { 1, 3, 5, 3, 9, 3, 7 };
    int target = 3;
    int index = last_linear_search(nums, target);  // Find last occurrence of 3
    if (index >= 0)
        cout << "Last occurrence of " << target << " is at index " << index << "\n\n";
    else
        cout << "Value " << target << " not found\n\n";

    // === Q3: Sort linked list using insertion sort ===

    // Manually create an unsorted linked list: 4 -> 2 -> 5 -> 1 -> 3
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);

    cout << "List before sort: ";
    print_list(head);  // Display original list

    Node* sorted = insertion_sort(head);  // Sort the list
    cout << "List after sort:  ";
    print_list(sorted);  // Display sorted list

    // === Clean up memory to avoid leaks ===
    while (sorted) {
        Node* temp = sorted;
        sorted = sorted->next;
        delete temp;
    }

    return 0;
}
