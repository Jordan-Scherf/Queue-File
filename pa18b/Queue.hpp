/// @file Queue.hpp
/// @author Jordan Scherf <5005736913@student.csn.edu>
/// @date 07/29/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This lab demonstates [The Use of the Template Class.]
/// @note Time Taken to Develop Program is about 0 hours
/// between days 07/20 and 07/29 with Assitance of
/// [TA William]
/// Astyle was Used for Correct Indentation (if it not correct, I give up lol).

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <cassert>

template <class T>
class Queue {
public:
    // member types
    using value_type = T;
    using reference  = T&;
    using size_type  = std::size_t;

    // Default Constructor
    Queue() {
        head = nullptr;  // Giving Purporse by setting to Nullptr
        count = 0;  // Initializing to zero to ensure a clear Queue
        tail = nullptr;  // Giving Purporse by setting to Nullptr
    }

    // Copy Constructor
    Queue(const Queue& other) {
        clear();
        head = nullptr;

        *this = other;
    }

    // Deconstructor
    ~Queue() {
        clear();
    }

    // Copy Assignment Operator
    Queue& operator=(const Queue& rhs) {
        if (this != &rhs) {
            clear();
            Node *temp = rhs.head;  // Temp variable to hold the rhs head
            Node *behind = head = new Node(temp -> info);  // A tail to follow


            for (temp = temp -> link; temp != nullptr; temp = temp -> link) {
                behind -> link = new Node(temp -> info);
                behind = behind -> link;
                tail = behind;
                count++;
            }
        }

        return *this;
    }

    // Looks at the info at the first node in the Queue
    reference front() const {
        if (empty()) {
            throw std::logic_error("error: empty stack");
        }

        return (head -> info);
    }

    // Looks at the info at the last node in the Queue
    reference back() const {
        if (empty()) {
            throw std::logic_error("error: empty stack");
        }

        return (tail -> info);
    }

    // Checks to see if the function is empty or not
    bool empty() const {
        return (head == nullptr);
    }

    // Checks the size of the Queue by returning count
    size_type size() const {
        return count;
    }

    // Pus item in Question on the back of the Queue
    void push(const value_type& item) {
        Node *temp = new Node(item, nullptr);  // Temp Variable to place at end

        if (tail != nullptr) {
            tail -> link = temp;
        } else {
            head = temp;
        }

        tail = temp;
        count++;
    }

    // Deletes the item on the top of the Queue
    void pop() {
        if (head != nullptr) {
            Node *temp = head;
            head = head->link;

            delete temp;
            count--;
        }
    }

private:
    // Clears the Queue
    void clear() noexcept {
        while (head != nullptr) {
            pop();
        }

        tail = nullptr;
        count = 0;
    }

    // The Struct of a node (Still super Creative)
    struct Node {
        Node(const value_type& item = value_type{}, Node *node = nullptr)
            : info(item), link(node) {}
        value_type info;
        Node      *link;
    };

    Node     *head  = nullptr;  ///< Pointer to the first item.
    Node     *tail  = nullptr;  ///< Pointer to the last item.
    size_type count = 0;        ///< Count of items in the list.
};

#endif
