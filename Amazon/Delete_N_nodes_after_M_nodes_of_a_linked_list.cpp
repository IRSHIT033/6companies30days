// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}


class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {  
        struct Node *temp=head;
        struct Node *temp2;
        int NewM,NewN;
        while(temp!=NULL){
         NewM=M-1;
        
        while(NewM-- and temp!=NULL){
            temp=temp->next;
        }
        if(temp==NULL){
            return;
        }
         temp2=temp->next;
         NewN=N;
        while(NewN-- and temp2!=NULL){
            struct Node* t=temp2;
            temp2=temp2->next;
            delete t;
        }
        temp->next=temp2;
        temp=temp2;
        
        
        }
    }
};

=
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
