//
// Created by yarnall on 1/24/23.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdexcept>

/**
 * This is class template -- it is NOT a class. Rather, it is a template that tells the compiler
 * how to write a class. The parameter is a type, T. If we write list<string> lst; in a program, the
 * compiler will stop and use this template to generate a class with string plugged in for T.
 *
 * That means that ALL of the code must be available to the compiler, so we cannot do what we usually
 * do and write our function implementations in a separate file. Later in the semester we will look at
 * how we can still separate the interface and implementation in a template.
 *
 * @tparam T the type of value stored in our list.
 */

template <typename T>
class List {
private:
    /**
     * Our doubly-linked list node.
     */
    struct node {
        explicit node(const T& val = T(), node* p = nullptr, node* n = nullptr)
                : value{val}, next{n}, prev{p}
        {}

        T value;
        node* next;
        node* prev;
    };

    struct iterator {
        /**
         * construct a new iterator
         * @param n the node the iterator points to
         * @param lst the list we're pointing into
         */
        iterator(node* n, List* lst)
                : cur{n}, list{lst}
        {}

        /**
         * This constructor makes an end iterator
         * @param lst the list we point into.
         */
        explicit iterator(List* lst)
                : cur{lst->head}, list{lst}
        {}

        /**
         * prefix increment operator. Advance to the next list entry.
         * @return the iterator after advance
         */
        iterator& operator++() {
            // have we already walked off the end of the list?
            if (cur != list->head)
                cur = cur->next;
            return *this;
        }

        /**
         * postfix increment.
         * @return a copy of the iterator before advance.
         */
        iterator operator++(int) {
            iterator old(cur, list);
            // have we already walked off the end of the list?
            if (cur != list->head)
                cur = cur->next;
            return old;
        }

        iterator& operator--() {
            if (cur != list->head)
                cur = cur->prev;
            return *this;
        }

        iterator operator--(int) {
            iterator old(cur, list);
            if (cur != list->head)
                cur = cur->prev;
            return old;
        }

        /**
         * check whether two iterators point at the same list element
         * @param other an iterator to compare to this
         * @return true if the iterators point at the same list elements.
         */
        bool operator==(const iterator& other) const {
            return cur == other.cur && list == other.list;
        }


        /**
         * dereference operator -- access the VALUE that the iterator points to
         * @return the value in the node this iterator points to. Throw if end().
         */
        T& operator*() {
            if (cur == list->head)
                throw std::invalid_argument("dereference end() iterator");
            else
                return cur->value;
        }

        /**
         * A version of the deref operator that's callable on a const iterator.
         * @return the value stored in the node.
         */
        const T& operator*() const {
            if (cur == list->head)
                throw std::invalid_argument("dereference end() iterator");
            else
                return cur->value;
        }

        /**
         * the node this iterator points to
         */
        node* cur;

        /**
         * the list we're iterating over. We need this to get at the list head.
         */
        List* list;
    };

public:

    /**
     * Construct an empty list.
     */
    List()
            : head{new node()}, size{0}
    {
        head->next = head;
        head->prev = head;
    }

    /**
     * Add a value to the end of the list
     * @param val the value to add
     */
    void push_back(const T& val) {
        node* n = new node(val, head->prev, head);
        head->prev->next = n;
        head->prev = n;
        ++size;
    }

    /**
     * Add a value to the beginning of the list
     * @param val the value to add
     */
    void push_front(const T& val) {
        node* n = new node(val, head, head->next);
        head->next->prev = n;
        head->next = n;
        ++size;
    }

    /**
     * insert a value at a position in the list. pos must be
     * between 0 and the size of the list; if not, the call throws
     * a std::out_of_range error
     * @param val the value to insert
     * @param pos the position.
     */
    void insert(const T& val, int pos) {
        if (pos < 0 || pos > size)
            throw std::out_of_range("bad list position");

        // find the node at location pos
        auto cur = head;
        for (auto i = 0; i < pos; ++i)
            cur = cur->next;

        // insert val AFTER cur
        auto n = new node(val, cur, cur->next);
        (cur->next)->prev = n;
        cur->next = n;

        ++size;
    }

    void splice( iterator pos, List<T>& l) {
        if (pos < 0 || pos > size)
            throw std::out_of_range("bad list position");

        if (l == *this) throw std::logic_error("This is the same list!");

        // find the node at location pos
        auto cur = head;
        for (auto i = 0; i < pos; ++i)
            cur = cur->next;

        //add list after cur
        for (auto it = l.begin(); it != l.end(); ++it) {
            //new node with l[it]'s value
            auto n = new node(it.cur->value, cur, cur->next);
            (cur->next)->prev = n;
            cur = cur->next = n;
            ++size;
        }
    }

    /**
     * Does this list contain an entry that compares equal to val?
     * @param val the value to search for
     * @return true if val is present, false otherwise.
     */
    bool contains(const T& val) const {
        for (auto cur = head->next; cur != head ; cur = cur->next) {
            if (val == cur->value)
                return true;
        }
        return false;
    }

    /**
     * create an iterator that points at the first element in the list
     * @return the begin() iterator
     */
    iterator begin() {
        return iterator{head->next, this};
    }

    /**
     *
     * @return an iterator that logically points "one off the end" of the list
     */
    iterator end() {
        return iterator(this);
    }

private:
    /**
     * Our head node -- the next pointer points at our first node, and the prev pointer
     * points at the last node.
     */
    node* head;

    /**
     * the size of the list.
     */
    int size;
};

#endif //LIST_LIST_H
