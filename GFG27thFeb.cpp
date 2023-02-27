#include <bits/stdc++.h>
using namespace std;
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
       Node *curr=head,*prev=NULL,*agli;
        int node=0;
        while(curr){
            node++;
            agli = curr->next;
            curr->next = prev;
            prev = curr;
            curr=agli;
        }
        node=node-k-1;
        Node *temp = prev;
        while(node--){
            temp=temp->next;
        }
        head->next=prev;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}