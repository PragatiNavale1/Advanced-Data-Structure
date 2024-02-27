#include<iostream>
#include<string>
using namespace std;

class lms{

public:
  int bid,price,copies;
  string title,author;
  lms *next,*temp;
  
  void accept();
  void beg();
  void display();
  void update();
  void search();
  
  void insertNode();
  void insertAtBeg();
  void insertAtEnd();
  void insertAtany();
  
  void deleteNode();
  void deleteAtBeginning();
  void deleteAtEnd();
  void deleteByBookID(int bookID);
  
  void searchByBookID(int bookID);
 
}*start;

void lms::accept(){

 temp=new lms;
 cout<<"---------------------------------------------\n";
 cout<<"Enter BOOK ID: \n";
 cin>>temp->bid;
 cout<<"TITLE: ";
 cin>>temp->title;
 cout<<"AUTHOR: ";
 cin>>temp->author;
 cout<<"PRICE: ";
 cin>>temp->price;
 cout<<"COPIES: ";
 cin>>temp->copies;
 cout<<"---------------------------------------------\n";
 
 temp->next=NULL;
 temp->next=start;
 start=temp;
}

void lms::beg()
{
    lms *newptr,*temp;
    temp=start;
    newptr=new lms;
    cout<<"---------------------------------------------\n";
    cout<<"Enter BOOK ID: \n";
    cin>>temp->bid;
    cout<<"TITLE: ";
    cin>>temp->title;
    cout<<"AUTHOR: ";
    cin>>temp->author;
    cout<<"PRICE: ";
    cin>>temp->price;
    cout<<"COPIES: ";
    cin>>temp->copies;
    cout<<"---------------------------------------------\n";
    if(temp==NULL)
    {
        temp=newptr;
    }else{
        temp=start;
        start=newptr;
        newptr->next=temp;
    }
}

void lms::insertNode() {
    int insertChoice;
    cout << "Where would you like to insert the new node?\n";
    cout << "1. At the Beginning\n";
    cout << "2. At the End\n";
    cout << "3. In the Middle\n";
    cin >> insertChoice;

    switch (insertChoice) {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtany();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}


void lms::insertAtBeg() {
    beg();
}

void lms::insertAtEnd() {
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    beg();
    temp->next = start;
}

void lms::insertAtany() {
    int pos, i;
    cout << "Enter the position where you want to insert: ";
    cin >> pos;
    if (pos == 1)
        insertAtBeg();
    else {
        temp = start;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL)
            cout << "Position out of range\n";
        else {
            beg();
            temp->next = start;
        }
    }
}


void lms :: search()
{
    int bookid ,f=0;
    lms *temp = start;
    cout<<"Enter the book id you want to search:";
    cin>>bookid;
    while(temp!=NULL)
    {
        if(temp->bid == bookid)
        {
            f =1;
            cout<<"Book Found!!!\n";
            cout<< "BID\tNAME\tAUTHOR\tPRICE\\n";
            cout <<temp->bid << "\t" <<temp->title << "\t" <<temp->author << "\t" << temp->price<< "\t" << endl;
            COUT<<"---------------------------------------------------";
        }
        temp =temp->next;
    }
    if(f ==0)
    {
        cout<<"Book record not found";
    }    

}

void lms::deleteNode() {
    int deleteChoice;
    cout << "Where would you like to delete the node from?\n";
    cout << "1. At the Beginning\n";
    cout << "2. At the End\n";
    cout << "3. By Book ID\n";
    cin >> deleteChoice;

    switch (deleteChoice) {
        case 1:
            deleteAtBeginning();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            int bookID;
            cout << "Enter the Book ID to DELETE: ";
            cin >> bookID;
            deleteByBookID(bookID);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void lms::deleteAtBeginning() {
    if (start == NULL) {
        cout << "List is EMPTY\n";
        return;
    }
    temp = start;
    start = start->next;
    delete temp;
}

void lms::deleteAtEnd() {
    if (start == NULL) {
        cout << "List is EMPTY\n";
        return;
    }
    temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void lms::deleteByBookID(int bookID) {
    if (start == NULL) {
        cout << "List is EMPTY\n";
        return;
    }
    temp = start;
    lms *prev = NULL;
    while (temp != NULL && temp->bid != bookID) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Book ID not found\n";
        return;
    }
    if (prev == NULL)
        start = start->next;
    else
        prev->next = temp->next;
    delete temp;
}


void lms::display(){
 temp=start;

 while(temp!=NULL){
  cout<<"---------------------------------------------\n";
  cout<<temp->bid<<"\t|"<<temp->title<<" |"<<temp->author<<" |"<<temp->price<<" |"<<temp->copies<<" |\n";
  
  temp=temp->next;
 }
}
void lms::update()
{
    int bookid, f = 0;
    lms *temp = start;
    cout << "Enter the book id you want to UPDATE:";
    cin >> bookid;
    while (temp != NULL)
    {
        if (temp->bid == bookid)
        {
            f = 1;
            cout << "Enter new details of book : " << endl;
            cout << "\nBook Id :";
            cin >> temp->bid;
            cout << "Book Name :";
            cin >> temp->title;
            cout << "Book Author :";
            cin >> temp->author;
            cout << "Price :";
            cin >> temp->price;
            cout << "Copies :";
            cin >> temp->copies;
        }
        temp = temp->next;
    }
    if (f == 1)
    {
        cout << "Book record is UPDATED\n";
        display();
    }
    else if (f == 0)
    {
        cout << "Book Record Not Found!!!!";
    }
}

/*
void lms::searchByBookID(int bookID) {
    temp = start;
    while (temp != NULL) {
        //if (temp->bid == bookID) {
            cout << "Book found:\n";
            cout << "Book ID: " << temp->bid << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "Price: " << temp->price << endl;
            
            return;
       // }
        temp = temp->next;
    }
    cout << "Book with ID " << bookID << " not found\n";
}
*/

int main(){
int ch;
lms b;
    do {
        cout << "Enter your choice: \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT NEW NODE\n";
        cout << "4. DELETE A NODE\n";
        cout << "5. UPDATE\n";
        cout << "6. SEARCH\n";
        cout << "5. EXIT\n";
       
        cout << "Enter your choice: \n";
        cin >> ch;
        switch (ch) {
            case 1:
                b.accept();
                break;
            case 2:
                 cout<<"Book ID | Title   | Author | Price| Copies|\n"; 
                b.display();
                break;
            case 3:
                b.insertNode();
                break;
            case 4:
                b.deleteNode();
                break;
            case 5:
                b.update();
                break;
            case 6:
                b.search();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (ch != 8);

    return 0;
}