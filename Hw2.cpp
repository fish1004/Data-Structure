#include<iostream>
using namespace std;


class Node              // create a node
{
public:
    float data;
    Node* next;

};
Node *a;                  // set first node
Node *b;                  // set current node
void push(float);
float deletion();



int main()
{
    int choice,capacity;

    while(choice!=4)                                         // if choice=4, break the loop
    {
        cout<<"SELECT YOUR CHOICE\n\n";
	    cout<<"1.LINEAR QUEUE\n"<<"2.CIRCULAR QUEUE\n"<<"3.LINK LIST\n"<<"4.Exit\n";
	    cin>>choice;                                         //choose your kind of queue
        int Rear=0;
        int Front=0;
        int mode;
        float Element;
        if(choice==1)                                        // enter the Linear Queue
        {
            mode=0;
		    cout<<"\nLinear Queue\n"<<"Enter the size of Queue : ";
		    cin>>capacity;                                              // enter the capacity of the Queue
		    float* p= new float[capacity];                              // allocate space for array
		    cout<<"1.INSERTION\n"<<"2.DELETION\n"<<"3.EXIT\n";
		    while(mode!=3)                                              // if mode=3,exit loop
            {
                cout<<"\nEnter your choice :";
			    cin>>mode;                                              // choose the mode
                if( (mode!=1)&&(mode!=2)&&(mode!=3) )                   //check the input is correct or not
                {
                    cout<<"Error!!only 1,2,3 allowed to enter\n";
                }

			    if(mode==1)                                             // Insertion mode
			    {
				    if(Rear==capacity-1)                                //the condition queue if full
				    {
					    cout<<"Enter an element:";
				        cin>>Element;
					    cout<<"Queue is full!!\n";
				    }
				    else                                // insert a Element
				    {
					    cout<<"Enter an element:";
				        cin>>Element;
                        Rear++;
				        p[Rear]=Element;                // put the Element to the array
				    }

			    }
			    else if(mode==2)                        // deletion mode
			    {
			        if(Front==Rear)                     //the condition queue if empty
			        {
				        cout<<"Queue is empty!!\n";
			        }
			        else                                  // delete a Element
                    {
                        Front++;
				        cout<<"Deleted element is : "<<p[Front]<<endl;    //print the data in array
				        p[Front]=0;
                    }

			    }
			    if((mode==1)||(mode==2))                            // print the result
                {
                    for(int i=0;i<capacity;i++)
				        {
					        if(i<=Front)
					        {
						        cout<<"[] ";
					        }
					        else if(i<=Rear)
					        {
						        cout<<"["<<p[i]<<"] ";
					        }
					        else if(i>Rear)
					        {
					            cout<<"[] ";
					        }
				        }
                    cout<<"\nFront = "<<Front<<",Rear = "<<Rear<<endl;
                }

            }


        }
        else if(choice==2)                            // enter the Circular Queue
        {
            mode=0;
		    cout<<"\nCircular Queue\n"<<"Enter the size of Queue : ";
		    cin>>capacity;                            // enter the capacity of the Queue
         float* p= new float[capacity];               // allocate space for array
		    cout<<"1.INSERTION\n"<<"2.DELETION\n"<<"3.EXIT\n";
		    while(mode!=3)
            {
                cout<<"\nEnter your choice :";
			    cin>>mode;                           // enter the mode
                if( (mode!=1)&&(mode!=2)&&(mode!=3) )                   //check the input is correct or not
                {
                    cout<<"Error!!only 1,2,3 allowed to enter\n";
                }

			    if(mode==1)                          // Insertion mode
			    {
				    if(((Rear+1)%capacity)==Front) // condition the queue is full
				    {
					    cout<<"Enter an element:";
				        cin>>Element;
					    cout<<"Queue is full!!\n";
				    }
				    else                            // insert a Element
				    {
					    cout<<"Enter an element:";
				        cin>>Element;
                        Rear=(Rear+1)%5;
				        p[Rear]=Element;           // insert  Element to array
				    }

			    }
			    else if(mode==2)                      // deletion mode
			    {
			        if((Front%5)==Rear)               //condition the queue is empty
			        {
				        cout<<"Queue is empty!!\n";
			        }
			        else
                    {                                 // delete a Element from array
                        Front=(Front+1)%5;
				        cout<<"Deleted element is : "<<p[Front]<<endl; // print the data in array
				        p[Front]=0;
                    }

			    }
			    if((mode==1)||(mode==2))                        // print the result
                {
                    for(int i=0;i<capacity;i++)
				        {
				            if(Front<=Rear)
                            {
                                if(i<=Front)
					            {
						            cout<<"[] ";
                                }
					            else if(i<=Rear)
					            {
						            cout<<"["<<p[i]<<"] ";
					            }
					            else if(i>Rear)
					            {
					                cout<<"[] ";
					            }
                            }
                            if(Front>Rear)
                            {
                                if(i<=Rear)
					            {
						            cout<<"["<<p[i]<<"] ";
                                }
					            else if(i<=Front)
					            {
					                cout<<"[] ";
					            }
					            else if(i>Front)
					            {
						            cout<<"["<<p[i]<<"] ";
					            }
                            }

				        }
                    cout<<"\nFront = "<<Front<<",Rear = "<<Rear<<endl;
                }

            }



        }
        else if(choice==3)                                       //enter the Link list queue
        {
            mode=0;
		    cout<<"\nLink list\n"<<"Enter the size of Queue : ";
		    cin>>capacity;
		    cout<<"1.INSERTION\n"<<"2.DELETION\n"<<"3.EXIT\n";
		    a=new Node;                                         // allocate a place for Node
		    b=a;
		    while(mode!=3)                                     // if mode=3,exit the loop
            {
                cout<<"\nEnter your choice :";
			    cin>>mode;                                     //enter the mode
                if( (mode!=1)&&(mode!=2)&&(mode!=3) )                   //check the input is correct or not
                {
                    cout<<"Error!!only 1,2,3 allowed to enter\n";
                }
			    if(mode==1)                                   // enter insertion mode
			    {
				    if(((Rear+1)%capacity)==Front)           // condition queue is full
				    {
					    cout<<"Enter an element:";
				        cin>>Element;
					    cout<<"Queue is full!!\n";
                        b->next=a;                           // let node b pointer to b->next
				    }
				    else                                      //insert a Element
				    {
					    cout<<"Enter an element:";
				        cin>>Element;
                        Rear=(Rear+1)%5;
				        push(Element);
				    }

			    }
			    else if(mode==2)
			    {
			        if((Front%5)==Rear)                      // condition queue is empty
			        {
				        cout<<"Queue is empty!!\n";
			        }
			        else                                     // delete a Element
                    {
                        Front=(Front+1)%5;
				        cout<<"Deleted element is : "<<deletion()<<endl;
                    }

			    }
			    if((mode==1)||(mode==2))                                 // print the result
                {
                    Node* temp_a;                           // create a temporary node to represent a;
                    Node* temp_b;                       // create a temporary node to represent a;
                    temp_a = a;
                    temp_b = a;
                    int temp_Front=Front;
                    for(int i=0;i<capacity;i++)
				        {
				            if(Front<=Rear)
                            {
                                if(i<=Front)
					            {
						            cout<<"[] ";
                                }
					            else if(i<=Rear)
					            {
						            cout<<"["<<temp_a->next->data<<"] ";
						            temp_a=temp_a->next;

					            }
					            else if(i>Rear)
					            {
					                cout<<"[] ";
					            }
                            }
                            if(Front>Rear)
                            {
                                if(i<=Rear)
					            {
                                    while(temp_Front<capacity-1)
                                    {
                                        temp_b=temp_b->next;
                                        temp_Front++;
                                    }
						            cout<<"["<<temp_b->next->data<<"] ";
						            temp_b=temp_b->next;
                                }
					            else if(i<=Front)
					            {
					                cout<<"[] ";
					            }
					            else if(i>Front)
					            {
						            cout<<"["<<temp_a->next->data<<"] ";
						            temp_a=temp_a->next;
					            }
                            }

				        }
                    cout<<"\nFront = "<<Front<<",Rear = "<<Rear<<endl;
                }
            }
        }
    }
}


void push(float value)             // the push function
{
    Node *c = new Node;            // allocate place for new Node
    c->data = value;               // get the node's data
    c->next = NULL;
    b->next = c;                   // pointer to next node
    b=c;
}
float deletion()                   // the deletion function
{
    float x;
    x=a->next->data;               // pointer to next node
    a=a->next;
    return x;                      // return the data in node

}



















