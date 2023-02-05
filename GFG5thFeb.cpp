
#include <bits/stdc++.h>
using namespace std;

/* Linked List Node*/
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
          Node* temp =head1;

//connect both linked list

        while(temp->next !=NULL){

            temp=temp->next;

        }

        temp->next = head2;

        //find the node where loop starts

        Node* slow =head1;

        Node* fast =head1;

        slow=slow->next;

        fast=slow->next;

        while(slow!=fast){

            slow=slow->next;

            fast=fast->next->next;

        }

        fast = head1;

        while(fast!=slow){

            slow=slow->next;

            fast=fast->next;

        }

        return slow->data;
    }
};

int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}