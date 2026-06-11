#include<iostream>
#include <unordered_set>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};

// Utility function to insert node at the end of the linked list
void insertNode(node* &head, int val) {
    node* newNode = new node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

//brute force approach: O(n*m) time complexity, O(1) space complexity
// Utility function to check presence of intersection
node* intersectionPresent(node* head1, node* head2) {
    while (head2 != NULL) {
        node* temp = head1;
        while (temp != NULL) {
            // If both nodes are the same (intersection point)
            if (temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // Intersection is not present between the lists, return NULL
    return NULL;
}


//better
// Utility function to check presence of intersection
node* intersectionPresent(node* head1, node* head2) {
    unordered_set<node*> st;  // Set to store visited nodes from the first list
    while (head1 != NULL) {
        st.insert(head1);  // Insert nodes of the first list into the set
        head1 = head1->next;
    }
    while (head2 != NULL) {
        if (st.find(head2) != st.end()) return head2;  // If node is found in set, it's the intersection point
        head2 = head2->next;
    }
    return NULL;  // Return NULL if no intersection is found
}


//optimal 1
// Utility function to get the difference in lengths of two linked lists
int getDifference(node* head1, node* head2) {
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
}

// Utility function to check presence of intersection
node* intersectionPresent(node* head1, node* head2) {
    int diff = getDifference(head1, head2);
    
    if (diff < 0) 
        while (diff++ != 0) head2 = head2->next;
    else 
        while (diff-- != 0) head1 = head1->next;
    
    // Traverse both lists and compare node by node
    while (head1 != NULL) {
        if (head1 == head2) return head1;  // Intersection point found
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;  // Return NULL if no intersection
}

//optimal 2
// Utility function to check presence of intersection
node* intersectionPresent(node* head1, node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    // Traverse both lists, when one reaches the end, redirect it to the head of the other list
    while (d1 != d2) {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }
    
    return d1;  // If they meet, return the intersection node, otherwise NULL
}

// Utility function to print linked list
void printList(node* head) {
    while (head->next != NULL) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main() {
    // Creation of both lists
    node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    node* head1 = head;
    head = head->next->next->next;  // Intersection point
    node* headSec = NULL;
    insertNode(headSec, 3);
    node* head2 = headSec;
    headSec->next = head;  // Creating intersection
    
    // Printing of the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);
    
    // Checking if intersection is present
    node* answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL) 
        cout << "No intersection\n";
    else 
        cout << "The intersection point is " << answerNode->num << endl;
    
    return 0;
}
