#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data 
    // (next set to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Class to hold the solution logic
class Solution {
public:
    // Function to print the linked list
    void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }

    // Function to delete the Nth node from the end
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // If list is empty, return NULL
        if (head == NULL) {
            return NULL;
        }

        int cnt = 0;
        Node* temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // If N equals the total number of nodes, delete the head
        if (cnt == N) {
            Node* newHead = head->next;
            // free memory
            delete head; 
            return newHead;
        }

        // Calculate the position from start to delete
        int res = cnt - N;
        temp = head;

        // Traverse to the node just before the one to delete
        while (temp != NULL) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }

        // Delete the target node
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode; // free memory

        return head;
    }


    // Function to delete the Nth node from the end 
    // using the optimized two-pointer method
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // Create a dummy node before head to handle edge cases
        Node* dummy = new Node(0, head);

        // Initialize slow and fast pointers at dummy
        Node* slow = dummy;
        Node* fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;

        // Return updated head
        return dummy->next;
    }

};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Creating linked list manually
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    Solution sol;
    head = sol.deleteNthNodeFromEnd(head, N);
    sol.printLL(head);
}
