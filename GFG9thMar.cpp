#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}
class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
         vector<int> arr(26,0),arr2(26,0);
        int c=0,c1=0;
        for(auto x:s){
            arr[x-'a']++;
            if(arr[x-'a']==1)c++;
        }
        Node* temp=head;
        vector<Node*> ans;
        while(temp){
            arr2[temp->data-'a']++;
            if(arr2[temp->data-'a']==arr[temp->data-'a'])c1++;
            while(arr2[temp->data-'a']>arr[temp->data-'a']){
                if(arr2[head->data-'a']==arr[head->data-'a'])c1--;
                arr2[head->data-'a']--;
                head=head->next;
            }
            if(c==c1){
                ans.push_back(head);
                Node* t = temp->next;
                temp->next=NULL;
                temp=t;
                head=t;
                c1=0;
                fill(arr2.begin(),arr2.end(),0);
            }
            else temp=temp->next;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}