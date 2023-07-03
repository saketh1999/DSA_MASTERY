#include <iostream>
using namespace std;
// struct Node
// {
//     int data;
//     Node* next;
// };
class Node
{ 
    private:
    
    public:
    int data;
    Node* next;
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~Node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
    void insertAtHead(Node * &head, int data)//Insert at the head of the LL , pass by reference so we dont create another copy
    {
        Node * element =new Node(data);
        element->next= head;
        head=element;

    }
        void insertAtEnd(Node * &tail, int data)//Insert at the tail of the LL , pass by reference so we dont create another copy
    {
        Node * element =new Node(data);
        tail->next= element;
        tail=element;

    }
    void insetAtPosition(Node* &head,Node * &tail,int data,int position)
    {
        //Insetion at a positing
        if(position==1)
        {
            insertAtHead(head,data);
            return;
        }
        
        Node *element = new Node(data);
        int i=1;//position
        Node *travers_add =head;
        while(i<position)
        {
            travers_add=travers_add->next;
            i++;
        }
        //Insertion at the last node
        if(travers_add->next==NULL)
        {
            insertAtEnd(tail,data);
            return;
        }

        if(i==position )
        {
            element->next=travers_add->next;
            travers_add->next=element;
        }
    }

    void deleteNode(Node* &head, Node* &tail,int pos)
    {
        //deleting first node
        if(pos==1)
        {
            Node* temp=head;
            head=head->next;
            //delete temp;
            temp->next=NULL;
            delete temp; //destructor will be called

        }
        //deleting any element from middle to end
        else{
            Node*curr=head;
            Node*prev =NULL;
            int cnt=1;
            while(cnt<pos)
            {
                prev=curr;

                curr=curr->next;
                cnt++;
            }

          
            if(curr->next==NULL)
            {
                tail=prev;
            }
              prev->next=curr->next;
            curr->next=NULL;
            delete curr;


        }
    }
    void printLL_fromTail(Node * LL)
    {
        cout<<"Printing for TAIL Insersion: ";
        Node* traverse=LL->next;
        while(traverse!=NULL)
        {
            cout<<traverse->data<<" ";
            traverse=traverse->next;
        }
        cout<<endl;

    }

    void printLL_fromHead(Node * LL)
    {
        cout<<"Printing for HEAD Insersion: ";
        Node* traverse=LL;
        while(traverse!=NULL)
        {
            cout<<traverse->data<<" ";
            traverse=traverse->next;
        }
        cout<<endl;

    }
};

int main()
{
    
    Node*tail=new Node;
    Node*track_tail=tail;//this is important, else it will only print the last element
    Node* head=new Node;

    Node* LL=new Node;//one LL which does tail and head insertion
    Node* head_of_LL=LL;
    Node* tail_of_LL= LL;

    int n; cin>>n;

    for(int i=1;i<=n;i++)
    {
        head->insertAtHead(head,i);
    }

    for(int i=1;i<=n;i++)
    {
        tail->insertAtEnd(track_tail,i);
    }
//////////////////////////////////////////////////////////
        for(int i=1;i<=n;i++)
    {
        LL->insertAtHead(head_of_LL,i);
    }

    for(int i=1;i<=n;i++)
    {
        LL->insertAtEnd(tail_of_LL,i);
    }
    
    head->printLL_fromHead(head);
    tail->printLL_fromTail(tail);
//////////////////////////////////////////////////////////
    
    LL->printLL_fromHead(head_of_LL);
    LL->printLL_fromTail(LL);//passing tail_of_LL wont work since it is point to null and is used only to add elements at tail
    
    LL->insetAtPosition(head_of_LL,tail_of_LL,964,13);
    LL->printLL_fromHead(head_of_LL);
//////////////////////////////////////////////////////////
  
    cout<<"Tail "<<tail_of_LL->data<<endl;
    LL->deleteNode(head_of_LL,tail_of_LL,16);
     LL->printLL_fromHead(head_of_LL);
     cout<<"HEAD "<<head_of_LL->data<<endl;
    cout<<"Tail "<<tail_of_LL->data;


}
/*


for input =6 
expected out put is as follows

Printing for HEAD Insersion: 6 5 4 3 2 1 
Printing for TAIL Insersion: 1 2 3 4 5 6 
Printing for HEAD Insersion: 6 5 4 3 2 1 0 1 2 3 4 5 6(since we will print the whole linked list from head to end of linked list)
Printing for TAIL Insersion: 1 2 3 4 5 6 (It will only print values from the start of the tail)
*/

/*
Expected output for the Insert at any position
with this =>  LL->insetAtPosition(head_of_LL,964,13);
7
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 
Printing for TAIL Insersion: 1 2 3 4 5 6 7 
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 
Printing for TAIL Insersion: 1 2 3 4 5 6 7 
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 1 2 3 4 5 964 6 7 
*/

/*
deteletion output
7
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 
Printing for TAIL Insersion: 1 2 3 4 5 6 7 
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 
Printing for TAIL Insersion: 1 2 3 4 5 6 7 
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 1 2 3 4 5 964 6 7 
Tail 7
Memory is free for the node with data 7
Printing for HEAD Insersion: 7 6 5 4 3 2 1 0 1 2 3 4 5 964 6 
HEAD 7
Tail 6% //we are also taking care of the tail when deletion is at the last index   
*/