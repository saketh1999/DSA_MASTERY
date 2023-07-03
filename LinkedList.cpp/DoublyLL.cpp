#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node * next;

    //constructor
    
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    //destructor for deleting an element
    ~Node()
    {
        int val = this->data;
        if(this->next!=NULL)
        {
            delete this->next;
            this->next=NULL;
        }
        cout<<"Node with value "<<val<<" has been deleted" <<endl;

    }

 

};
   void printDLL(Node * head)
    {
        cout<<"Printing from the Head: ";
        Node* trav=head;
        while (trav!=NULL)
        {
            /* code */
            cout<<trav->data<<" ";
            trav=trav->next;

        }
        cout<<endl;
        
    }
       void printDLL_fromTail(Node * head)
    {
        cout<<"Printing from the Tail: ";
        Node* trav=head;
        while (trav!=NULL)
        {
            /* code */
            cout<<trav->data<<" ";
            trav=trav->prev;

        }
        cout<<endl;
        
    }
int getLength(Node *head)
{
    Node* trav=head;
    int count =0;
        while (trav!=NULL)
        {
            /* code */
            count++;
            trav=trav->next;

        }
        
        cout<<"Length of DLL = "<<count<<endl;
        return count;

}
void insertAtHead(Node * &head,int val)
{
    Node * element = new Node(val);

    element->next=head;
    head->prev=element;
    head=element; 

}
void insertAtTail(Node * &tail,int val)
{
    Node * element = new Node(val);

    element->prev=tail;
    tail->next=element;
    tail=element; 

}
void insertAtPosition(Node * &head,Node* &tail, int pos,int val)
{
    Node* element=new Node(val);

    Node*temp=head;
    int i=1;
    //inset at the begining
    if(pos==1)
    {
        insertAtHead(head,val);
        return;
    }
    //inset at the end
    if(getLength(head)<pos)
    {
        insertAtTail(tail,val);
                return;
    }
    //insert at a position given
    while(i<pos-1)
    {
        i++;
        temp=temp->next;

    }
    element->next=temp->next;
    element->prev= temp->next->prev;
    temp->next->prev=element;
    temp->next=element;
    
    
}
void deleteNode(Node* &head , Node * &tail, int pos)
{
    if(pos==1)
    {
        Node*temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*prev =NULL;
        Node*curr=head;

        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL)//deleting at the tail
        {
         curr->prev=NULL;
         prev->next=curr->next;
         curr->next=NULL;  
         tail=prev;//only if deleting at the tail
        }
        
        curr->prev=NULL;
        prev->next=curr->next;
        if(curr->next!=NULL)
        curr->next->prev=prev;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head=node1;
    Node* tail=node1;
  
    getLength(head);
    insertAtHead(head,8);
    printDLL(head);
    insertAtHead(head,13);
    printDLL(head);
    insertAtHead(head,15);
    printDLL(head);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    printDLL(head);
    insertAtPosition(head,tail,2,4567);
    printDLL(head);
    insertAtPosition(head,tail,9,9567);
    printDLL(head);
    printDLL_fromTail(tail);
    deleteNode(head,tail,2);
    printDLL(head);
    deleteNode(head,tail,8);
    printDLL(head);
    printDLL_fromTail(tail);
}