class Node {
public:
    Node() {
        prev = nullptr;
        next = nullptr;
        val = 0;
    }

    Node(int v) {
        val = v;
        prev = nullptr;
        next = nullptr;
    }

    Node(int v, Node* n) {
        val = v;
        next = n;
        prev = nullptr;
    }

    Node(Node* p, int v) {
        val = v;
        prev = p;
        next = nullptr;
    }
    int getVal() {
        return val;
    }

    Node* getPrev() {
        return prev;
    }

    Node* getNext() {
        return next;
    }

    void setPrev(Node* p) {
        prev = p;
    }

    void setNext(Node* n) {
        next = n;
    }
private:
    Node* prev;
    Node* next;
    int val;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    int get(int index) {
        if(index < 0 || index >= len) return -1;
        Node* curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->getNext();
        }
        return curr->getVal();
    }

    void insertHead(int val) {
        len++;
        Node* newNode = new Node(val);
        if(len == 1)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        if(len == 2)
        {
            head = newNode;
            head->setNext(tail);
            tail->setPrev(head);
            return;
        }
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
        return;
    }
    
    void insertTail(int val) {
        len++;
        Node* newNode = new Node(val);
        if(len == 1)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        if(len == 2)
        {
            tail = newNode;
            head->setNext(tail);
            tail->setPrev(head);
            return;
        }
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
        return;
    }

    bool remove(int index) {
        if(index < 0 || index >= len) return false;
        len--;
        Node* curr = head;
        if(len == 0)
        {
            head = nullptr;
            delete(tail);
            tail = nullptr;
            return true;
        }
        if(index == 0)
        {
            head = head->getNext();
            delete(head->getPrev());
            head->setPrev(nullptr);
            return true;
        }
        if(index == len)
        {
            tail = tail->getPrev();
            delete(tail->getNext());
            tail->setNext(nullptr);
            return true;
        }
        for(int i = 0; i < index-1; i++)
        {
            curr = curr->getNext();
        }
        curr->setNext(curr->getNext()->getNext());
        delete(curr->getNext()->getPrev());
        curr->getNext()->setPrev(curr);
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head;
        for(int i = 0; i < len; i++)
        {
            res.push_back(curr->getVal());
            curr = curr->getNext();
        }
        return res;
    }
private:
    Node* head;
    Node* tail;
    int len;
};
