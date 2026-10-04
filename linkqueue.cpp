   // LINKED QUEUE IMPLEMENTATION
  
  #include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class queue {
private:
    Node* front;
    Node* back;
    int currsize;

public:
    // Constructor
    queue() {
        front = nullptr;
        back = nullptr;
        currsize = 0;
    }

    // Destructor
    ~queue() {
       Node*curr=front;
       Node*temp;
       while(curr!=nullptr){
        temp=curr;
        curr=curr->next;
        delete temp;
        temp=nullptr;

       }
       front =nullptr;

    }

    bool isempty() {
        return currsize == 0;
    }

    // Insert at back → O(1)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isempty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        currsize++;
    }

    // Delete from front → O(1)
    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {  // list became empty
            back = nullptr;
        }
        delete temp;
        currsize--;
    }

    // See front element
    int peek() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void makeempty() {
        while (!isempty()) {
            dequeue();
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue: ";
    q.display();              // 10 20 30 40

    cout << "Front: " << q.peek() << endl;   // 10

    q.dequeue();
    cout << "After dequeue: ";
    q.display();              // 20 30 40

    q.dequeue();
    cout << "After dequeue: ";
    q.display();              // 30 40

    q.makeempty();
    cout << "After makeempty: ";
    q.display();              // empty
}