# cs-303--Assignment-3  

Name: Muhammad Chaudhry
Date: 4/21/2025

This project demonstrates the implementation of key data structure concepts in C++.

Q1: A templated queue with a circular array and the operations push(), pop(), front(), size(), empty(), and a custom method move_to_rear().

     - Uses a dynamic circular array with automatic resizing

     - Efficient O(1) operations for push() and pop()

      - move_to_rear() shifts the front element to the rear using pop() and push()

Q2: A recursive linear search function that finds the last occurrence of a target value in a vector.
     
    - Recursively traverses the vector

    - Stores result of deeper recursion call first, ensuring last match wins

     - Time complexity: O(n)

Q3: An insertion sort function for sorting a singly linked list in ascending order.
    - Uses dummy head for easier insertion

    - Each node is repositioned based on value

    -  Sorts the list in-place (no new node allocation)

    -  Time complexity: O(n²) (best for small lists)
