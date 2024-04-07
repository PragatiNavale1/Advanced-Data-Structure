#include<iostream>
#include<string>
using namespace std;
class CMS
{
	public:
	int did,amt;
	long int mno;
	string name,address;
	CMS *next,*prev;
	
	void accept();
	void insert();
	void display_next();
	void display_prev();
	void search();
	void modify();
	void deletE();
	
}*start,*end1;

void CMS::accept()
{
	CMS *nnode;
	nnode=new CMS;
	cout<<"************Enter Data Of Donor***********";
	cout<<"\nDonaor Id: ";
	cin>>nnode->did;
	cout<<"Name: ";
	cin>>nnode->name;
	cout<<"Address:";
	cin>>nnode->address;
	cout<<"Mobile No: ";
	cin>>nnode->mno;	
	cout<<"Donating Amount: ";
	cin>>nnode->amt;
	
	
	if(start==NULL)
	{
		start=end1=nnode;
	}
	else
	{
		end1->next=nnode;
		nnode->prev=end1;
		end1=nnode;
		
	}
}

void CMS::display_next()
{
	CMS *temp;
	temp=start;
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->did<<"\t"<<temp->name<<"\t"<<temp->address<<"\t"<<temp->mno<<"\t"<<temp->amt<<"\t";
		temp=temp->next;
		
	}
}


void CMS::display_prev()
{
	CMS *temp;
	temp=end1;
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->did<<"\t"<<temp->name<<"\t"<<temp->address<<"\t"<<temp->mno<<"\t"<<temp->amt<<"\t";
		temp=temp->prev;
		
	}
}

void CMS::search()
{
	    int donorid ,f=0;
	    CMS *temp = start;
	    cout<<"Enter the donor id you want to search:";
	    cin>>donorid;
	    while(temp!=NULL)
	    {
		if(temp->did == donorid)
		{
		    f =1;
		    cout<<"\nDonor Name : "<<temp->name;
		    cout<<"\nAddress : "<<temp->address;
		    cout<<"\nPhone NO : "<<temp->mno;
		    cout<<"\nDonating Amount : "<<temp->amt;
		     cout<<"---------------------------------------------\n";
		}
		temp =temp->next;
		
	    }
	    if(f==0)
	    {
		cout<<"\nDonor record not found";
	    }    
}

void CMS::modify()
{
	int donorid ,f=0;
	    CMS *temp = start;
	    cout<<"Enter the donor id you want to search:";
	    cin>>donorid;
	    while(temp!=NULL)
	    {
		if(temp->did == donorid)
		{
		    f =1;
		        cout<<"Name: ";
			cin>>temp->name;
			cout<<"Address:";
			cin>>temp->address;
			cout<<"Mobile No: ";
			cin>>temp->mno;	
			cout<<"Donating Amount: ";
			cin>>temp->amt;
			 cout<<"---------------------------------------------\n";
		}
		temp =temp->next;
		
	    }
	    if(f==0)
	    {
		cout<<"Donor record not found";
	    }    
}

void CMS::deletE()
{
	CMS *temp,*p;
	int doid;
	temp=start;
	cout<<"Enter the Donor ID to delete: ";
	cin>>doid;
	
	while(temp!=NULL)
	{
		if(temp->did==doid)
		{
		
			break;
			
		}
		p=temp;
		temp=temp->next;
		}
		p->next=temp->next;
		temp->next->prev=p->next;
		delete(temp);
		
	}


int main(){
int ch;
CMS b;
    do {
        cout << "\n Enter your choice: \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY in FORWARD WAY \n";
        cout << "3. DISPLAY in REVERSE\n";
        cout << "4. SEARCH BY ID\n";
        cout << "5. MODIFY\n";
        cout << "6. DELETE\n";
        
        
       
        cout << "Enter your choice: \n";
        cin >> ch;
        switch (ch) {
            case 1:
                b.accept();
                break;
                
            case 2:
            
                 cout<<"DONOR ID | NAME  | ADDRESS | PHONE NO   | AMOUNT|\n"; 
                 cout<<"---------------------------------------------\n";
                 b.display_next();
                break;
                
            case 3:
            
                 cout<<"DONOR ID | NAME  | ADDRESS | PHONE NO   | AMOUNT|\n"; 
                 cout<<"---------------------------------------------\n";
                 b.display_prev();
                break;
            
            case 4:
            	b.search();
            	break; 
            	
            case 5:
            	b.modify();
            	break;
            	
            case 6:
            	b.deletE();
            	break;		
            	
            	
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (ch != 7);

    return 0;
}
