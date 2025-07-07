/*
 * @file
 *
 * @brief Implementation of Singly Linked List
 */

#include <iostream>
#include <cstddef>
#include <stdexcept>


/* 
 * @namespace
 *
 * @brief Parent namespace for namespaces of various data structures
 */
namespace data_structures {

/*
 * @namespace linked_list
 *
 * @brief Implementations of Singly Linked Lists
 */
namespace linked_list {

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    private:
        Node *head;

        void _sort(std::size_t size) {
            if (size <= 1) return;

            Node *temp = this->head;
            while (temp->next) {
                if (temp->data > temp->next->data) std::swap(temp->data, temp->next->data);
                temp = temp->next;
            }

            _sort(size - 1);
        }

    public:
        LinkedList() {
            head = nullptr;
        }

        /* 
         * @brief Inserts @param value at the beginning
         * 
         * @param value value to be inserted
         */
        void insert(int value) {
            Node *newNode = new Node(value);
            newNode->next = this->head;
            this->head = newNode;
        }
        
        /* 
         * @brief Inserts @param value at the @param index
         * 
         * @param value value to be inserted
         * @param index index at which @param value is to be inserted
         * 
         * @throws std::out_of_range if index is greater than list size
         */
        void insertAt(int value, std::size_t index) {
            if (index == 0) {
                insert(value);
                return;
            }

            std::size_t count = 0;
            Node *temp = this->head;

            bool outOfBounds = true;

            while (temp && count < index - 1) {
                temp = temp->next;
                count++;
            }

            if (!temp) throw std::out_of_range("Insert requested at out of bounds index.");

            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        /* 
         * @brief Inserts @param value at the end
         * 
         * @param value value to be inserted
         */
        void insertAtEnd(int value) {
            Node *newNode = new Node(value);

            if (this->head == nullptr) {
                this->head = newNode;
                return;
            }
            
            Node *temp = this->head;

            while(temp->next) temp = temp->next;
            
            temp->next = newNode;
        }

        /* 
         * @brief Deletss the value from the beginning
         * 
         * @throws std::underflow_error if Linked List is empty
         */
        void deleteFromBeginning() {
            if (!this->head) throw std::underflow_error("List is empty. Cannot delete from beginning.");
            Node *first = this->head;
            this->head = first->next;

            delete first;
        }

        /* 
         * @brief Deletes the value at @param index
         * 
         * @param index Index at which the value is to be deleted
         * 
         * @throws std::out_of_range if index is greater than list size
         */
        void deleteAt(std::size_t index) {
            if (index == 0) {
                deleteFromBeginning();
            }

            Node *temp = this->head;
            std::size_t count = 0;

            while (temp && count < index - 1) {
                temp = temp->next;
                count++;
            }

            if (!temp || !temp->next) throw std::out_of_range("delete requested at out of bounds index.");

            Node* nextNode = temp->next;
            temp->next = nextNode->next;

            delete nextNode;
        }

        /* 
         * @brief Deletes the value from the end
         * 
         * @throws std::underflow_error if Linked List is empty
         */
        void deleteFromEnd() {
            if (!this->head) throw std::underflow_error("List is empty. Cannot delete from end.");

            if (!this->head->next) {
                delete this->head;
                this->head = nullptr;
                return;
            }
            
            Node *previous = nullptr;
            Node *current = this->head;

            while (current->next) {
                previous = current;
                current = current->next;
            }

            previous->next = nullptr;
            delete current;
        }

        /* 
         * @brief Deletes @param value from Linked List if it exists
         * 
         * @throws std::invalid_argument if @param value is not in Linked List
         */
        void deleteByValue(int value) {
            if (!this->head) throw std::underflow_error("List is empty. Cannot delete value.");

            Node *previous = nullptr;
            Node *current = this->head;

            while (current) {
                if (current->data == value) {
                    break;
                }

                previous = current;
                current = current->next;
            }

            if (!current) throw std::invalid_argument("Value not found in the list.");

            if (previous) {
                previous->next = current->next;
            } else {
                this->head = current->next;
            }

            delete current;
        }

        /* 
         * @brief Displays the entire Linked List
         */
        void display() {
            Node *temp = this->head;

            while (temp) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }

            std::cout << std::endl;
        }

        /* 
         * @brief Length of the Linked List
         */
        std::size_t length() {
            std::size_t len = 0;
            
            Node *temp = head;

            while (temp) {
                len++;

                temp = temp->next;
            }

            return len;
        }

        /* 
         * @brief Searches if @param value is in the list
         */
        bool search(int value) {
            Node *temp = this->head;

            while (temp) {
                if (value == temp->data) {
                    return true;
                }
                temp = temp->next;
            }

            return false;
        }

        /* 
         * @brief Gets the value stored at @param index
         * 
         * @throws std::out_of_range if @param index is greater than list size
         */
        int getValueAt(std::size_t index) {
            Node *temp = this->head;
            std::size_t count = 0;

            while (temp) {
                if (count == index) {
                    return temp->data;
                }
                temp = temp->next;
                count++;
            }
        throw std::out_of_range("delete requested at out of bounds index.");
        }

        /*
         * @brief Reverses the list in-place
         */
        void reverse() {
            Node *previous = nullptr;
            Node *current = this->head;
            Node *after;

            while (current) {
                after = current->next;
                current->next = previous;
                
                previous = current;
                current = after;
            }
            
            this->head = previous;
        }

        /* 
         * @brief Sorts the list in-place using recursive Bubble Sort
         */
        void sort() {
            if (!this->head) return;
            
            _sort(this->length());
        }

        /* 
         * @brief Returns if the list is empty or not
         */
        bool isEmpty() {
            return !this->head;
        }

        /* 
         * @brief Returns the first element of the list
         * 
         * @throws std::underflow_error if the list is empty.
         */
        int front() {
            if (this->head) return this->head->data;
            throw std::underflow_error("List is empty.");
        }

        /* 
         * @brief Returns the last element of the list
         * 
         * @throws std::underflow_error if the list is empty.
         */
        int back() {
            if (!this->head) throw std::underflow_error("List is empty.");

            Node *temp = this->head;
            while (temp->next) {
                temp = temp->next;
            }

            return temp->data;
        }


        ~LinkedList() {
            Node *temp = head;

            while (temp) {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
        }
};

} // namespace linked_list

} // namespace data_structures
