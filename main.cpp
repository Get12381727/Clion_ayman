
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class SLL {     // SLL single linked list
private:
    Node<T> * head;
    Node<T> * tail;
    size_t size;

public:
    // Constructor and Destructor
    SLL() : head(nullptr), tail(nullptr), size(0) {}

    ~SLL() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        delete tail;
    }

    // Get Size Function
    size_t getSize() const {
        return size;
    }

    // Insertion Function (Update pushBack function)   إضافة عناصر في نهاية Linked List)،
    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Reverse Function  عكس
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Swap head and tail pointers
        Node<T>* temp = head;
        head = tail;
        tail = temp;
    }

    // Delete at Function  حذف عنصر معين
    void deleteAt(size_t index) {
        if (index >= size || index < 0) {
            cerr << "Index out of bounds." << endl;
            return;
        }
        if (index == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node<T>* current = head;
            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    // Pop Back Function حذف اخر عنصر
    void popBack() {
        if (size == 0) {
            cerr << "List is empty." << endl;
            return;
        }
        deleteAt(size - 1);
    }

    // Find Function      بحث عن عنصر معين باستخدام قيمته
    int find(const T& value) {
        Node<T>* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;  // Element not found
    }

    // Traversal Function  عرض المصفوفه كامله
    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    SLL<int>List;
    int num ;

    cout<<"Enter a number to insert it:"<<endl ;
    cin>>num ;
    List.pushBack(num);

    cout<<"Enter a number to insert it:"<<endl ;
    cin>>num ;
    List.pushBack(num);

    cout<<"Enter a number to insert it:"<<endl ;
    cin>>num ;
    List.pushBack(num);

    cout << "Original List: ";
    List.print();

    List.popBack();
    cout<<"The last element delete successful"<<endl;

    cout<<"Enter a number to verify its existence:"<<endl ;
    cin>>num ;
    if (List.find(num) != -1)
    {
        cout<<"Found "<< num <<" at index:Yes "<<endl;
    } else{
        cout<< num <<" not found in the list."<<endl;
    }


    cout<<"Enter Index of element to delete it"<<endl;
    cin>>num;
    List.deleteAt(num);


    cout<<"After changes the List element is: "<<endl;
    List.print();

    cout<<"After revers the List element is: "<<endl;
    List.reverse();

    cout << "Final size of the list: " << List.getSize() << endl;

}


