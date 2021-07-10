///////////////////////////////////////////////////////////////////////////////////////
//          Generic Singly Linear linklist application.
//Date: 26th May 2021.
//////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

template <class T>//structure for Singly Linear linklist
struct clnode
{
   T data;
   struct clnode* next;
};
/////////////////////////////////////////////////////////////////


template <class T>//structure for Doubly Linear linklist
struct dlnode
{
   T data;
   struct dlnode* next;
   struct dlnode* prev;
};

/////////////////////////////////////////
template <class T>
class SinglyLll
{
private:
    struct clnode<T> * Head;
    int iSize;

public:
    SinglyLll();
    ~SinglyLll();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPosition(T,int);
    void DeleteAtPosition(int);
};
///////////////////////////////////////////////////
template <class T>
class DoublyLll
{
private:
    struct dlnode<T> * Head;
    int iSize;

public:
    DoublyLll();
    ~DoublyLll();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPosition(T,int);
    void DeleteAtPosition(int);
};
//////////////////////////////////////////////////////
//             Constructor
////////////////////////////////////////////////////////
template<class T>
SinglyLll<T>:: SinglyLll()
{
    Head = NULL;
    iSize = 0;
}
template<class T>
SinglyLll<T>:: ~SinglyLll()
{
    delete Head;
}
/////////////////////////////////////////////////////////////////////
//Function name : InsertFirst
//prototype     : void
//author        : prajwal kadam
//////////////////////////////////////////////////////////////////
template<class T>
void SinglyLll<T> :: InsertFirst(T no)
{
    struct clnode<T> *newn= new struct clnode<T>;
    newn->data=no;
    newn->next=NULL;

    newn->next=Head;
    Head=newn;
    iSize++;
}
template <class T>
void SinglyLll<T> :: InsertLast(T no)
{
    struct clnode<T> *newn=new struct clnode<T>;
    newn->data = no;
    newn->next = NULL;
    struct clnode<T>*temp = Head;

    if(Head==NULL)
    {
        Head=newn;
    }
    else{
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

/////////////////////////////////////////////////////////////
//Function Name:  InsertAtPosition
//Date         :  26/05\2021   
//prototype    :  void
////////////////////////////////////////////////////////////
template <class T>
void SinglyLll<T> :: InsertAtPosition(T iNo,int iPos)
{
    struct clnode<T> * temp = Head;
    iSize = Count();
    if((iPos<1)||(iPos>iSize))
    {
        return;
    }
    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iSize+1)
    {
        InsertLast(iNo);
    }
    else{
         struct clnode<T> * newn = NULL;
         newn= new struct clnode<T>;
         newn->data=iNo;
         newn->next=NULL;

         for(int i=1;i<iPos-1;i++)
         {
             temp = temp->next;
         }
         newn ->next = temp-> next;
         temp->next = newn;
         iSize++;
    }
}

template <class T>
void SinglyLll<T> :: DeleteFirst()
{
    struct clnode<T> * temp=Head;
    if(Head==NULL)
    {
       return;
    }    
    else{
         Head=Head->next;
        delete temp;
        iSize--;
    }
}

template <class T>
void SinglyLll<T> :: DeleteLast()
{
    if(iSize==0)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        delete Head;
        Head=NULL;
        iSize--;
    }
    else{
        struct clnode<T> * temp = Head;              //create temp pointer
        while(temp ->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete (temp->next);
        temp->next=NULL;
        iSize--;
    }
}
template<class T>
void SinglyLll<T> :: DeleteAtPosition(int iPos)
{
 
    struct clnode <T>*temp=Head;
    struct clnode <T>* target=NULL;
    iSize=Count();
    if((iSize==1)||(iPos>iSize))
    {
       return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }    
    else if(iPos == iSize)
    {
        DeleteLast();
    }
    else{
        for(int i=1;i<iPos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target -> next;
        delete target;
        iSize--;
    }
}


template <class T>
int SinglyLll<T> :: Count()
{
    return iSize;
}

template <class T>
void SinglyLll<T> :: Display()
{
    struct clnode<T> *temp = Head;
    while(temp!= NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//             Constructor
////////////////////////////////////////////////////////
template<class T>
DoublyLll<T>:: DoublyLll()
{
    Head = NULL;
    iSize = 0;
}
template<class T>
DoublyLll<T>:: ~DoublyLll()
{
    delete Head;
}
/////////////////////////////////////////////////////////////////////
//Function name : InsertFirst
//prototype     : void
//author        : prajwal kadam
//////////////////////////////////////////////////////////////////
template<class T>
void DoublyLll<T> :: InsertFirst(T no)
{
    struct dlnode<T> *newn= new struct dlnode<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

 newn->next = Head;
 newn->prev = Head;
 Head = newn;
 iSize++;
}
template <class T>
void DoublyLll<T> :: InsertLast(T no)
{
    struct dlnode<T> *newn = new struct dlnode<T>;
    newn -> data = no;
    newn->next = NULL;
    newn->prev = NULL;
    struct dlnode<T>* temp = Head;

    if(Head==NULL)
    {
        Head = newn;
    }
    else{
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}

/////////////////////////////////////////////////////////////
//Function Name:  InsertAtPosition
//Date         :  26/05\2021   
//prototype    :  void
////////////////////////////////////////////////////////////
template <class T>
void DoublyLll<T> :: InsertAtPosition(T iNo,int iPos)
{

    iSize = Count();    
    if((iPos < 1)||(iPos > iSize+1))
    {
        return;
    } 
    if(iPos == 1)
    {   
        InsertFirst(iNo);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else{
          struct dlnode<T> *newn = NULL;
          newn = new struct dlnode<T>;
          newn -> data = iNo;
          newn->next = NULL;
          newn->prev = NULL;
          struct dlnode <T> *temp= Head;

        for(int i=1;i < iPos-1 ;i++) 
        {
            temp = temp->next;
        }
        newn -> next = temp->next;
        temp -> next -> prev =newn;
        temp -> next = newn;
        newn -> prev = temp;       
        iSize++;                                                                        
    }
}

template <class T>
void DoublyLll<T> :: DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
    }
    else{
        Head = Head -> next;
        delete (Head->prev);
        Head->prev = NULL;
    }
    iSize--;
}

template <class T>
void DoublyLll<T> :: DeleteLast()
{
    iSize = Count(); 
    struct dlnode<T>*temp = Head;
    if(Head == NULL)
    {
        return;
    }
    else if(iSize == 1)
    {
        DeleteFirst();
    }
    else{
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
     iSize--;
}
template<class T>
void DoublyLll<T> :: DeleteAtPosition(int iPos)
{
    iSize = Count();
    if((iPos<1)||(iPos>iSize+1))
    {
        return ;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos == iSize)
    {
        DeleteLast();
    }
    else{
            struct dlnode<T>*temp = Head;
            for(int i=1;i < iPos-1 ; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete(temp->next->prev);
            temp->next->prev=temp;
            iSize--;
    }

}

template <class T>
int DoublyLll<T> :: Count()
{
   return iSize;
}

template <class T>
void DoublyLll<T> :: Display()
{
    struct dlnode<T> *temp = Head;
    while(temp!= NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}



int main()
{
int iRet=0,iPos=0,iList=1,iOption1 = 1;
int iNo=0;

                     while(iList != 0)//while1
                     {
                          //case for select link list
                          cout<<"------------------------------------------------------------------------\n";
                          cout<<"Enter your choice\n";
                          cout<<"---------------------------------------------------------------------------\n";
                          cout<<"1 : Singly Linear LinkList\n";
                          cout<<"2 : Doubly Linear LinkList\n";
                          cout<<"0 : Exit\n";
                          cout<<"----------------------------------------------------------------------------\n";
                          cin>>iList;



                          switch(iList)
                          {

                               case 1:  { 
                                            
                                            while (iOption1!=0)//while 
                                            {
                                                int iOption2=1;
                                                  
                                                  //case for primitive data type
                                                  cout<<"-------------------------------------------\n";
							                      cout<<"Enter your choice\n";
							                      cout<<"-------------------------------------------\n";
							                      cout<<"1.Linked list of integers\n2.Linked list of floating point\n3.Linked list of double\n4.Linked list of characters\n5.Linked list of String\n0.Exit\n";
							                      cout<<"-------------------------------------------\n";
							                      cin>>iOption1; 

                                                 switch(iOption1)
                                                 {
                                                      //case for operations  on perticuler data type   

                                                      case 1:
                                                      {
                                                          SinglyLll <int> *slobj = new SinglyLll <int>;
                                                          cout<<"-------------------------------------------\n";
										                  cout<<"Linked List of Integer is created\n";
							                              cout<<"-------------------------------------------\n"; 

                                                          while(iOption2 != 0)
                                                          {
                                                              cout<<"-------------------------------------\n";
                                                              cout<<"Enter your choice\n";
                                                              cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n6:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                              //cout<<"-------------------------------------\n";
                                                              //cout<<"Enter your choice\n";
                                                              cin>>iOption2;

                                                              switch(iOption2)
                                                              {
                                                                  case 1:
                                                                         cout<<"Enter data:\n";
                                                                         cin>>iNo;
                                                                         slobj->InsertFirst(iNo);
                                                                         break;

                                                                   case 2:
                                                                         cout<<"Enter data\n";
                                                                         cin>>iNo;
                                                                         slobj->InsertLast(iNo);
                                                                         break;

                                                                   case 3:
                                                                         cout<<"Enter Data:\n";  
                                                                         cin>>iNo;
                                                                         cout<<"Enter Enter Position:";
                                                                         cin>>iPos;
                                                                         slobj->InsertAtPosition(iNo,iPos);
                                                                         break; 


                                                                   case 4:
                                                                         slobj->DeleteFirst();
                                                                         break;

                                                                   case 5:
                                                                         slobj->DeleteLast();
                                                                         break;

                                                                   case 6:
                                                                         cout<<"Enter Position\n";
                                                                         cin>>iPos;
                                                                         slobj->DeleteAtPosition(iPos);
                                                                         break;

                                                                   case 7:
                                                                         slobj->Display();
                                                                         break;

                                                                   case 8:
                                                                        iRet = slobj->Count();
                                                                        cout<<"Count of Data is:"<<iRet<<"\n";
                                                                        break;

                                                                    case 0:
                                                                        cout<<"Thank You for Using our application\n";
                                                                        break;
       
                                                                    default:
                                                                        cout<<"Please enter valid Option\n";
                                                                        break;
                                                              }
                                                              
                                                          }
                                                          //break;
                                                      }
                                                      break;
                                                      case 2:
                                                      {
                                                           float iFno = 0;
                                                           SinglyLll <float> *slobj = new SinglyLll <float>;
                                                           cout<<"-------------------------------------------\n";
										                   cout<<"Linked List of floating point is created\n";
										                   cout<<"-------------------------------------------\n";

                                                           while(iOption2 != 0)
                                                           {
                                                                cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                cout<<"-------------------------------------\n";
                                                                cout<<"Enter your choice\n";
                                                                cin>>iOption2;

                                                                switch(iOption2)

                                                                {
                                                                    case 1:
                                                                         cout<<"Enter data:\n";
                                                                         cin>>iNo;
                                                                         slobj->InsertFirst(iFno);
                                                                         break;

                                                                   case 2:
                                                                         cout<<"Enter data\n";
                                                                         cin>>iNo;
                                                                         slobj->InsertLast(iFno);
                                                                         break;

                                                                   case 3:
                                                                         cout<<"Enter Data:\n";  
                                                                         cin>>iFno;
                                                                         cout<<"Enter Enter Position:";
                                                                         cin>>iPos;
                                                                         slobj->InsertAtPosition(iFno,iPos);
                                                                         break; 


                                                                   case 4:
                                                                         slobj->DeleteFirst();
                                                                         break;

                                                                   case 5:
                                                                         slobj->DeleteLast();
                                                                         break;

                                                                   case 6:
                                                                         cout<<"Enter Position\n";
                                                                         cin>>iPos;
                                                                         slobj->DeleteAtPosition(iPos);
                                                                         break;

                                                                   case 7:
                                                                         slobj->Display();
                                                                         break;

                                                                   case 8:
                                                                        iRet = slobj->Count();
                                                                        cout<<"Count of Data is:"<<iRet<<"\n";
                                                                        break;

                                                                    case 0:
                                                                        cout<<"Thank You for Using our application\n";
                                                                        break;
       
                                                                    default:
                                                                        cout<<"Please enter valid Option\n";
                                                                        break;

                                                                }

                                                           }
                                                         
                                                      }
                                                 
                                                 
                                                     break;

                                                      case 3:
                                                      {
                                                               double iDno = 0.0;
                                                               SinglyLll <double> *slobj = new SinglyLll <double>;
                                                               cout<<"-------------------------------------------\n";
    										                   cout<<"Linked List of Double is created\n";
    										                   cout<<"-------------------------------------------\n";

                                                               while(iOption2 != 0)
                                                               {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                      switch(iOption2)
                                                                      {
                                                                              case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>iNo;
                                                                              slobj->InsertFirst(iDno);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>iNo;
                                                                              slobj->InsertLast(iDno);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>iDno;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              slobj->InsertAtPosition(iDno,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              slobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              slobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              slobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              slobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = slobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;
  
  
                                                                        }
  
                                                               } 

                                                      }
                                                    break;


                                                      case 4:
                                                      {
                                                           char iIno = '\0';
                                                           SinglyLll <char> *slobj = new SinglyLll <char>;
                                                           cout<<"-------------------------------------------\n";
										                   cout<<"Linked List of Character  is created\n";
										                   cout<<"-------------------------------------------\n"; 

                                                           while(iOption2 != 0)
                                                           {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                    switch(iOption2)
                                                                    {
                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>iIno;
                                                                              slobj->InsertFirst(iIno);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>iIno;
                                                                              slobj->InsertLast(iIno);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>iIno;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              slobj->InsertAtPosition(iIno,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              slobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              slobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              slobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              slobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = slobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;

                                                                    }
                                                                        
                                                                
                                                           }
                                                        
                                                      }

                                                      break;

                                                      case 5:
                                                      {
                                                           char ch = '\0';
                                                           string str;
                                                           SinglyLll <string> *slobj = new SinglyLll <string>;
     
                                                           cout<<"-------------------------------------------\n";
										                   cout<<"Linked List of String is created\n";
										                   cout<<"-------------------------------------------\n"; 

                                                             while(iOption2 != 0)
                                                           {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                    switch(iOption2)
                                                                    {
                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>str;
                                                                              slobj->InsertFirst(str);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>str;
                                                                              slobj->InsertLast(str);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>str;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              slobj->InsertAtPosition(str,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              slobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              slobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              slobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              slobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = slobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;

                                                                    }


                                                           }
                                                      }

                                                      
                                                       break;
                                                 

                                                      case 0:cout<<"-------------------------------------------\n";
										                     cout<<"Thank you for using our application\nTry another application\n";
										                     cout<<"-------------------------------------------\n";
										                     break;
                                                                                                            

                                                      default:cout<<"-------------------------------------------\n";
										                      cout<<"Error:Invalid choice...\n";
										                      cout<<"-------------------------------------------\n";
                                                              break;

                                                      

                                                  
                                                 }//end of switch
                                                  
                                            }//end of while 
                                       }
                          
                               break;
                          

                               case 2 :
                               {
                                        while(iOption1!=0)
                                        {
                                            int iOption2=1;
                                                  
                                             //for select primitive datatype
                                                  cout<<"-------------------------------------------\n";
							                      cout<<"Enter your choice\n";
							                      cout<<"-------------------------------------------\n";
							                      cout<<"1.Linked list of Character\n2.Linked list of floating point\n3.Linked list of double\n4.Linked list of Integer\n5.Linked list of String\n0.Exit\n";
							                      cout<<"-------------------------------------------\n";
							                      cin>>iOption1;


                                             switch(iOption1)
                                             {

                                                  case 1: {  
                                                               char iNo ='\0';
                                                               DoublyLll <char> *dlobj = new DoublyLll <char>;
                                                               cout<<"-------------------------------------------\n";
									                           cout<<"Linked List of char is created\n";
							                                   cout<<"-------------------------------------------\n"; 

                                                               while(iOption2 !=0)
                                                               {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                    switch (iOption2)
                                                                    {
                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>iNo;
                                                                              dlobj->InsertFirst(iNo);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>iNo;
                                                                              dlobj->InsertLast(iNo);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>iNo;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              dlobj->InsertAtPosition(iNo,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              dlobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              dlobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              dlobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              dlobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = dlobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;
                                                                    
                                                                    }

                                                               }

                                                  }
                                             break;
                                         
                                         
                                                  case 2:{
                                                              float iFno = 0.0;
                                                              DoublyLll <float> *dlobj = new DoublyLll <float>;
                                                              cout<<"-------------------------------------------\n";
                           	                                  cout<<"Linked List of floating point is created\n";							
                                                              cout<<"-------------------------------------------\n"; 

                                                              while(iOption2 != 0)
                                                              {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                     switch (iOption2)
                                                                    {
                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>iFno;
                                                                              dlobj->InsertFirst(iFno);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>iFno;
                                                                              dlobj->InsertLast(iFno);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>iFno;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              dlobj->InsertAtPosition(iFno,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              dlobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              dlobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              dlobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              dlobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = dlobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"P   lease enter valid Option\n";
                                                                             break;
                                                                    
                                                                    }

                                                              }

                                                  }                                               
                                                       break;
                                                  
                                                  case 3:{
                                                               double iDno = 0.0;
                                                               DoublyLll <double> *dlobj = new DoublyLll <double>;
                                                               cout<<"-------------------------------------------\n";
										                       cout<<"Linked List of floating point is created\n";
										                       cout<<"-------------------------------------------\n"; 

                                                               while(iOption2 != 0)
                                                               {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                    switch(iOption2)
                                                                    {
                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>iDno;
                                                                              dlobj->InsertFirst(iDno);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>iDno;
                                                                              dlobj->InsertLast(iDno);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>iDno;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              dlobj->InsertAtPosition(iDno,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              dlobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              dlobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              dlobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              dlobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = dlobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;
                                                                    }

                                                               }
                                                  }

                                                       break;
                                                  
                                                  case 4:{
                                                              int iIno = 0.0;
                                                              DoublyLll <int> *dlobj = new DoublyLll <int>;
                                                              cout<<"-------------------------------------------\n";
										                      cout<<"Linked List of floating point is created\n";
										                      cout<<"-------------------------------------------\n"; 

                                                              while(iOption2 != 0)
                                                              {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                    switch(iOption2)
                                                                    {
                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>iIno;
                                                                              dlobj->InsertFirst(iIno);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>iIno;
                                                                              dlobj->InsertLast(iIno);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>iIno;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              dlobj->InsertAtPosition(iIno,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              dlobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              dlobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              dlobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              dlobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = dlobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;
                                                                    }
                                                              }
 
                                                  }                                              
                                                       break;
                                                  
                                                  case 5:{
                                                              char ch = '\0';
                                                              string str;
                                                              DoublyLll <string> *dlobj = new DoublyLll <string>;
                                                              cout<<"-------------------------------------------\n";
									                          cout<<"Linked List of floating point is created\n";
									                          cout<<"-------------------------------------------\n"; 

                                                              while(iOption2 != 0)
                                                              {
                                                                    cout<<"1:Insert first\n2:Insert last\n3:Insert At position\n4:Delete First\n5:Delete Last\n5:Delete At position\n7:Display Data\n8:Count data\n0:EXIT \n";
                                                                    cout<<"-------------------------------------\n";
                                                                    cout<<"Enter your choice\n";
                                                                    cin>>iOption2;

                                                                    switch (iOption2)
                                                                    {

                                                                        case 1:
                                                                              cout<<"Enter data:\n";
                                                                              cin>>str;
                                                                              dlobj->InsertFirst(str);
                                                                              break;
     
                                                                        case 2:
                                                                              cout<<"Enter data\n";
                                                                              cin>>str;
                                                                              dlobj->InsertLast(str);
                                                                              break;
     
                                                                        case 3:
                                                                              cout<<"Enter Data:\n";  
                                                                              cin>>str;
                                                                              cout<<"Enter Enter Position:";
                                                                              cin>>iPos;
                                                                              dlobj->InsertAtPosition(str,iPos);
                                                                              break; 
     
     
                                                                        case 4:
                                                                              dlobj->DeleteFirst();
                                                                              break;
     
                                                                        case 5:
                                                                              dlobj->DeleteLast();
                                                                              break;
     
                                                                        case 6:
                                                                              cout<<"Enter Position\n";
                                                                              cin>>iPos;
                                                                              dlobj->DeleteAtPosition(iPos);
                                                                              break;
     
                                                                        case 7:
                                                                              dlobj->Display();
                                                                              break;
     
                                                                        case 8:
                                                                             iRet = dlobj->Count();
                                                                             cout<<"Count of Data is:"<<iRet<<"\n";
                                                                             break;
     
                                                                         case 0:
                                                                             cout<<"Thank You for Using our application\n";
                                                                             break;
            
                                                                         default:
                                                                             cout<<"Please enter valid Option\n";
                                                                             break;

                                                                    }
                                                                  
                                                              }
                                                  }
                                                  
                                                       break;
                                                  
                                                  
                                                  
                                                  case 0:
                                                        cout<<"-------------------------------------------\n";
									                	   cout<<"Thank you for using our application\nTry another application\n";
									                	   cout<<"-------------------------------------------\n";
                                                  
                                                       break;
                                                  
                                                  default:
                                                        cout<<"-------------------------------------------\n";
										                   cout<<"Error:Invalid choice...\n";
										                   cout<<"-------------------------------------------\n";
                                                  
                                                       break;
                                                  
                                                  

                                             }//end of switch 

                                        }//end of while


                               
                               break;

                               case 0:
                               cout<<"Thank you for using application"<<"\n";
                               break;

                               default:
                                       cout<<"-------------------------------------------\n";
					                   cout<<"Error:Invalid choice...\n";
					                   cout<<"-------------------------------------------\n";
					                   break;


                               }
                               }
                          }
           return 0;          
}