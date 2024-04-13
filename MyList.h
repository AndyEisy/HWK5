using namespace std;

template <class T>
class MyList {
private:
    Node<T>* head; // Pointer to the head of the list

public:
    MyList() : head(nullptr) {} // Constructor to initialize head as nullptr

    void insertHead(T theData) {
        head = new Node<T>(theData, head); // Create a new node and update head
    }

    T deleteHead() {
        if (head == nullptr) {
            // List is empty, handle this case based on your requirements
            return T(); // Return a default-constructed T object
        }

        Node<T>* temp = head; // Save the current head
        T data = temp->getData(); // Get the data from the current head
        head = head->getLink(); // Move the head to the next node
        delete temp; // Delete the old head node
        return data; // Return the data from the old head
    }

    bool search(T& target) {
        Node<T>* curr = head;
        while (curr != nullptr) {
            if (curr->getData() == target) {
                return true; // Found the target
            }
            curr = curr->getLink();
        }
        return false; // Target not found
    }

    void display() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->getData() << " "; // Print the data
            curr = curr->getLink();
        }
        cout << std::endl;
    }
};

