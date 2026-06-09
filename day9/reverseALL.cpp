#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse a linked list using stack
    ListNode* reverseList(ListNode* head) {
        // Stack to store values of nodes
        stack<int> st;

        // Temporary pointer to traverse the list
        ListNode* temp = head;

        // Traverse and push all node values to stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Reset temp back to head
        temp = head;

        // Reassign values from stack in reverse order
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        // Return the modified head
        return head;
    }

    // Function to reverse a linked list iteratively
    ListNode* reverseList(ListNode* head) {
        // Initialize previous pointer to NULL
        ListNode* prev = NULL;

        // Start from the head of the list
        ListNode* temp = head;

        // Traverse the list
        while (temp != NULL) {
            // Save the next node
            ListNode* front = temp->next;

            // Reverse the current node's pointer
            temp->next = prev;

            // Move prev to current node
            prev = temp;

            // Move to the next node
            temp = front;
        }

        // Return new head (last node becomes first)
        return prev;
    }

    
};

// Driver code
int main() {
    // Creating linked list 1 -> 2 -> 3 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    head = sol.reverseList(head);

    // Printing reversed list
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
