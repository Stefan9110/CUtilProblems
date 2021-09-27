#ifndef PROBLBAC_LIST_H
#define PROBLBAC_LIST_H

/**
 * Linked List implementation C++
 * @tparam E - data type used in list
 */
template<class E>
class List {
private:
    E value_;
    List *next_ptr_ = nullptr;
    List *last_value_ = this;

public:
    /**
     * Constructor of List class
     * Initializes a new linked list node
     * Requires value found in the node with data type E
     * @param value - initialized value in node
     */
    explicit List(E value) {
        this->value_ = value;
    }

    /**
     * @return value found in node with E data type
     */
    E value() {
        return value_;
    }

    /**
     * @return List pointer to next node
     */
    List *next_ptr() {
        return next_ptr_;
    }

    /**
     * Method used to set next node pointer to current node
     * @param next List pointer to next node
     * @return given List pointer
     */
    List *setNext(List *next) {
        this->next_ptr_ = next;
        return next;
    }

    /**
     * @return initialized pointer address to last value in List (found in first node of the list)
     */
    List *last_value() {
        return this->last_value_;
    }

private:
    /**
     * Obtain and reinitialize next pointer with the last value pointer of the list
     * @param last_value Pointer to last node in the list
     * @return updated with last_value pointer node of the next pointer
     */
    List *next_ptr(List *last_value) {
        next_ptr_->last_value_ = last_value;
        return next_ptr_;
    }

public:
    /**
     * Adds new element to the end of the list
     * @param element Value to be added
     * @return Node added to the list
     */
    List *add(E element) {
        this->last_value_ = this->last_value_->setNext(new List<E>(element));
        return this->last_value_;
    }

    void modifyValue(E element) {
        this->value_ = element;
    }

    /**
     * Remove node containing element E from the list
     * @param element value of the node to be removed
     * @return If the element is found in the head of the list we return the updated head, otherwise return same head (this)
     */
    List *remove(E element) {
        if (this->value() == element) return next_ptr(this->last_value());

        for (auto it = this; it->next_ptr() != nullptr; it = it->next_ptr()) {
            if (it->next_ptr()->value() != element) continue;

            it->setNext(it->next_ptr()->next_ptr());
            return this;
        }

        return this;
    }

    /**
     * Linear search for node containing given element
     * @param element value of the node to be returned
     * @return pointer to node containing the given element. If not found, returns nullptr
     */
    List *find(E element) {
        for (auto it = this; it != nullptr; it = it->next_ptr()) if (it->value() == element) return it;
        return nullptr;
    }

    /**
     * @return length of the list
     */
    size_t length() {
        size_t count = 0;
        for (auto it = this; it != nullptr; it = it->next_ptr(), count++);
        return count;
    }

    /**
     * @param position Position of the node in the list that shall be returned
     * @return Node at the given position
     */
    List *nodeAt(unsigned int position) {
        int count = 0;
        for (auto it = this; it != nullptr; it = it->next_ptr(), count++) if (count == position) return it;
        return nullptr;
    }

    /**
     * Adds new node after node with value given
     * @param element Value of the node after which a new node shall be added
     * @param toAdd Value contained by the new node
     */
    List *addAfter(E element, E toAdd) {
        List *foundNode = find(element);
        if (foundNode == nullptr) return;

        List *newlyAdded = new List<E>(toAdd);
        newlyAdded->setNext(foundNode->next_ptr());
        foundNode->setNext(newlyAdded);

        return newlyAdded;
    }
};

#endif
