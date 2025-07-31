class Node {

public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node() {

        key = -1;
        val = -1;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {

    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = nullptr;
        node->prev = nullptr;

        return;
    }

    void insertAtHead(Node* node) {

        Node* nextNode =  head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;

        return;
    }

    void removeNodeFromTail() {

        Node* node = tail->prev;
        Node* prevNode = node->prev;
        
        prevNode->next = tail;
        tail->prev = prevNode;

        mp.erase(node->key);
        node->next = nullptr;
        node->prev = nullptr;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        int val = node->val;

        deleteNode(node);
        insertAtHead(node);

        return val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];
            
            deleteNode(node);
            insertAtHead(node);

            node->val = value;

            return;
        }

        if(mp.size() == capacity) {
            removeNodeFromTail();
        }

        Node* newNode = new Node();
        newNode->key = key;
        newNode->val = value;
        mp[key] = newNode;

        insertAtHead(newNode);

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */