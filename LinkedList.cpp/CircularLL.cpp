#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~Node()
    {
        int value = this->data;

        if(this->next!=NULL)
        {
            delete this->next;
            this->next= NULL;
        }
        cout<<"We have deleted the node with value "<<value<<endl;

    }
};
void printCLL(Node* tail)
{
    Node*temp = tail;
    if(tail==NULL)
    {
        cout<<"CLL is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
    
}
void insetNode(Node * &tail, int val, int after_val)
{
    //if the list is empty
    if(tail==NULL)
    {
        Node* element =new Node(val);
        tail=element;
        element->next=tail;

    }
    else{
        Node* temp = tail;
        //assuming that the after_val is present in the LL
        while(temp->data!=after_val)
        {
            temp=temp->next;

        }
        //now the temp found after_val
        Node * element =new Node(val);
        element->next=temp->next;
        temp->next=element;
    
        
    }
    cout<<"Tail = "<<tail->data<<endl;
}
void deleteNode(Node* &tail, int val)
{
    //if list is empty
    if(tail==NULL)
    {
        cout<<"LL is empty"<<endl;return;
    }
    else{
        //non empty
        //assuming that value is present
        Node *prev=tail;
        Node * curr= prev->next;

        while (curr->data!=val)
        {
            prev=curr;
            curr=curr->next;
        }
      
        prev->next=curr->next;
        if(prev==curr)//only 1 node LL
        {
            
            tail=NULL;

        }
        if(curr==tail)//deleting the tail element
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
        
    }
}

int main()
{
    Node* tail =NULL;

    insetNode(tail, 5, 3);
    printCLL(tail);

    insetNode(tail,7,5);
    printCLL(tail);

    insetNode(tail,3,7);
    printCLL(tail);

    insetNode(tail,6,7);
    printCLL(tail);
    
    deleteNode(tail,5);
    printCLL(tail);
 }


 /*
 
 the CLL is like this 
7 6 3 5
but since we are priniting the tail first , i.e 5, we are seeing the print as 5 7 6 3
by analysing the deleteNode code we can see that prev= tail =5 
and curr = prev->next = 7 (which is also the head informally)

after deleting 5 we will get 
7 6 3 (3 is the tail)
3 7 6 (hence tail is printed first)
 */