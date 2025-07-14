/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // If linked list is empty
        if(head== nullptr){
            return nullptr;
        }

        // Map to store same corresponding keys address as node pointers
        unordered_map <Node*,Node*> m; 

        // Making a new head node(having diff address) with old head value
        Node* newhead= new Node(head->val);

        // head->next because we have already made head copy
        Node* oldtemp= head->next;
        Node* newtemp = newhead;

        // Bcoz this value is not stored in the while loop
        m[head]= newhead;

        // Copying simple linked list
        while(oldtemp != nullptr){
        // Make a copy node with val as old node.
        Node* copynode = new Node(oldtemp->val);
        m[oldtemp]= copynode;
        
        // Putting the corresponding new node value of old node in map
        m[oldtemp]= copynode;

        newtemp->next= copynode;

        // Traversing in both nodes simultaniously
        oldtemp = oldtemp->next;
        newtemp = newtemp->next;

        }

        // Copying random connections
        oldtemp= head;
        newtemp= newhead;
        while(oldtemp!= nullptr){
            // pointed to new temp random to old temp random's map value 
            newtemp->random= m[oldtemp->random];

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;
    }
};