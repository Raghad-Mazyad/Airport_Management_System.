#include <iostream>
using namespace std;
//int group; --> I made it a local variable inside main()
struct person{
    int gnum;
    //person *prev = NULL;
    person *next = NULL;
    
};

struct LinkedList {
person* head = NULL;
person* tail = NULL;

bool isFound(int key)
    {
    	
        person* temp = head;
		
        while(temp != NULL)
        {
            if(temp->gnum == key)
                return true;

            temp = temp->next;
        }
        return false;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }


void InsertRear(int group) {
    person* newPerson = new person;
    newPerson->gnum = group;
    
    //temp->next=NULL;
    //temp->prev=NULL;    
    if (isEmpty()) //or head == NULL
    {
        head=newPerson;
        tail=newPerson;
    }
    else
    {
        tail->next=newPerson;
        //temp->prev=tail;
        tail=newPerson; 
    }
 }
void insertafter(int group){
    
    //temp->prev=NULL;
    //temp->next=NULL;
	 if(isFound(group))//if (head==NULL) This will be in insertRear()
    {/*
        head=temp;
        tail=temp;
        cur=temp;

        These lines will be in InsertRear()
      */  
        

        person* newPerson = new person;
        newPerson->gnum = group;
        
        person* temp = head; // for traversing
        

      while(temp != NULL && temp->gnum != group) // temp will be at the beginning of the group
            temp = temp->next;
        
        newPerson->next = temp->next;
        temp->next = newPerson;

        if(newPerson->next == NULL)
            tail = newPerson;
    }
   
	
 }

void PrintForward()
{
    person* cur = head;

    if(isEmpty()) //or head == NULL
    {
        cout<<"List is Empty !! please enter new person\n";
    }
    else
    {
        cout<<"List display: \n";
        while(cur!=NULL)
        {
            cout <<" " <<cur->gnum <<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
}

	
void Delete()
{
	if(isEmpty())
        cout << "The list is empty.\n";
    else
    {
        int complete, key;
        cout << "is your group complete? yes[1], no[0]: ";
        cin >> complete;
        if(complete == 0){
            cout <<"you can not end the group procedure"<< endl;
            return;
        }
        else
        {
            cout << "insert the number of group: " ;
            cin >> key;
            if(isFound(key))
            {
                person* delPerson = head;
                if(head->gnum == key)
                {
                    while(head->gnum == key)
                    {
                        delPerson = head;
                        head = head->next;
                        delete delPerson;
                    }
                }
                else
                {
                    person* prev = NULL;
                    while(delPerson->gnum != key)
                    {
                        prev = delPerson;
                        delPerson = delPerson->next;
                    }

                    person* temp = delPerson; // in case the group was in the middle.
                    while((delPerson->gnum == key) && (delPerson->next != NULL))
                    {
                        temp = delPerson;
                        prev->next = delPerson->next;
                        delPerson = delPerson->next;
                        delete temp;
                    }

                    // The previous loop doesn't delete the tail even if it was included in the group.
                    if(tail->gnum == key)
                    {
                        temp = tail;
                        tail = prev;
                        tail->next = NULL;
                        delete temp;
                        temp = NULL;
                    }
                }
                cout << "group ended their procedure" << endl;
            }
            else
                cout << "Group was not found.\n";
                
            
        }
    }
}

};
	
int main(){
    int choice;
    int group;
    LinkedList list;

    do{
        cout << "1: Enter the new person\n";
        cout << "2: Display persons\n";
        cout << "3: End Procedure\n";
        cout << "4: Exit\n";
        cout << "Enter your desired choice: ";
        
        cin>>choice;
        
        switch (choice){
        case 1:
               cout<<"Enter group number\n";	
			   cin>> group;
			  if(!list.isFound(group)){
                cout << "New person stands at the end.\n";
			  	list.InsertRear(group);
			  }
			  else // In case the group NO was found in the list.
			  {
                cout << "New person stands right behind their group.\n";
			  	list.insertafter(group);
			  }
			  /*else{
			  	InsertFront();
			  }  */
               break;
        case 2:
               list.PrintForward();
               break;
        case 3:
        		list.Delete();
        		break;
        case 4:
               cout<<"Exiting Program\n";
               break;
        default:
            cout<<"Error! wrong choice\n";
       }
    }while (choice!=4);

    return 0;
}
