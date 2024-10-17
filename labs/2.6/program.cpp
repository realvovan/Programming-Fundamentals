#include "iostream"

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head = nullptr;

    inline void AddToFront(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = this->head;
        this->head = newNode;
    }

    inline void RemoveFromFront() {
        if(this->head != nullptr) {
            Node *temp = this->head;
            this->head = this->head->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    inline void AddToEnd(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if(this->head == nullptr) {
            //if the list is empty make the new node its head
            this->head = newNode;
            return;
        }
        Node *last = this->head;
        while(last->next != nullptr) {
            //finds the last node
            last = last->next;
        }
        last->next = newNode;
    }

    inline void RemoveFromEnd() {
        if(this->head != nullptr) {
            Node *secondLast = this->head;
            if(secondLast->next == nullptr) {
                //if the list only has one node
                delete secondLast;
                this->head = nullptr;
                return;
            }
            while(secondLast->next->next != nullptr) {
                secondLast = secondLast->next;
            }
            delete (secondLast->next);
            secondLast->next = nullptr;
        }
    }

    inline Node* SearchForValue(int value) {
        Node *current = this->head;
        while(current != nullptr) {
            if(current->data == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    inline void Reverse() {
        Node *prev = nullptr;
        Node *current = this->head;
        Node *next = nullptr;

        while(current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
    }

    int Length() {
        int len = 0;
        Node *current = this->head;
        while(current != nullptr) {
            len++;
            current = current->next;
        }
        return len;
    }

    inline void SortList(bool ascending = true) {
        //check if the list empty or has only one value
        int length = this->Length();
        if(length == 0 || length == 1) return;

        for(int i = 0; i < length; i++) {
            Node *current = this->head;
            for(int j = 0; j < length - i - 1; j++) {
                if((ascending && current->data > current->next->data) || (!ascending && current->data < current->next->data)) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                }
                current = current->next;
            }
        }
    }

    inline void Clear() {
        while(this->head != nullptr) {
            this->RemoveFromFront();
        }
    }

    inline void PrintList() {
        Node *current = this->head;
        while(current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null\n";
    }
};

int main() {
    LinkedList myList;
    //try deleting from an empty list
    myList.RemoveFromFront();
    //populate it with values and print them
    std::cout << "Adding values to the front\n";
    myList.AddToFront(10);
    myList.AddToFront(20);
    myList.AddToFront(15);
    myList.AddToFront(15);
    myList.AddToFront(40);
    myList.PrintList();
    //remove the front value and print the list
    std::cout << "Removing one element from the front\n";
    myList.RemoveFromFront();
    myList.PrintList();
    //add values to the end of the list and print them
    std::cout << "Adding values to the end\n";
    myList.AddToEnd(-1);
    myList.AddToEnd(5);
    myList.PrintList();
    //now remove the last value in the list
    std::cout << "Removing one element from the end\n";
    myList.RemoveFromEnd();
    myList.PrintList();
    //search for elements
    if(myList.SearchForValue(15)) std::cout << "Number 15 is in the list\n";
    else std::cout << "Number 15 is NOT in the list";

    if(myList.SearchForValue(-1)) std::cout << "Number -1 is in the list\n";
    else std::cout << "Number -1 is NOT in the list\n";

    if(myList.SearchForValue(420)) std::cout << "Number 420 is in the list\n";
    else std::cout << "Number 420 is NOT in the list\n";
    //reverse the list and print it
    std::cout << "Reversing the list\n";
    myList.Reverse();
    myList.PrintList();
    //sort the list and print it
    std::cout << "Sorting he list\n";
    myList.SortList(true);
    myList.PrintList();

    myList.SortList(false);
    myList.PrintList();
    //clear the list
    std::cout << "Clearing the list\n";
    myList.Clear();
    myList.PrintList();
    std::cout << "The length of the list is now " << myList.Length() << "\n";
    return 0;
}