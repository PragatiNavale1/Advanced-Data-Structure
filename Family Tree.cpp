#include<iostream>
#include<string>

using namespace std;
#define max 20
int cnt=0;
class tree
{
	public:
	int age,cnt,cnt1,cnt2;
	string name,gen,dob;
	tree *lc,*rc;
	
	void create();
	void insert(tree *root,tree *next);
	void display(tree *root);
	void height();
	void leaf(tree *root);
		
}*root,*next,*stack[max],*temp;

void tree::create()
{
	int ch;
	
	root=new tree;
	cout<<"\nENTER the your FAMILY INFORMATION: ";
	cout<<"\nEnter NAME: ";
	cin>>root->name;
	cout<<"Enter DOB: ";
	cin>>root->dob;
	cout<<"Enter GENDER: ";
	cin>>root->gen;
	cout<<"Enter AGE: ";
	cin>>root->age;
	
	cnt=cnt1=cnt2=1;
	root->lc=root->rc=NULL;
	cnt++;
	do{
		cout<<"Do you want to add new Member (0/1)no/yes?: ";
		cin>>ch;
		if(ch==1)
		{
			next=new tree;
			cout<<"\nEnter the data for new Member: ";
			
			cout<<"\nEnter NAME: ";
			cin>>next->name;
			cout<<"Enter DOB: ";
			cin>>next->dob;
			cout<<"Enter GENDER: ";
			cin>>next->gen;
			cout<<"Enter AGE: ";
			cin>>next->age;
			
			next->lc=next->rc=NULL;
			insert(root,next);
		}
		
	}while(ch==1);
	
}
void tree::insert(tree *root,tree *next)
{
	 char chr;
	 tree *temp;
	 cout<<"\nEnter data has to be insert either Left(l) OR Right(r)?: ";
	 cin>>chr;
	 if(chr=='l'||chr=='L')
	 {
	 	if(root->lc==NULL)
	 	{
	 		root->lc=next;
	 		cnt1++;
	 	}
	 	else
	 	{
	 		insert(root->lc,next);
	 	}
	 	
	 }
	 if(chr=='r'||chr=='R')
	 {
	 	if(root->rc==NULL)
	 	{
	 		root->rc=next;
	 		cnt2++;
	 	}
	 	else
	 	{
	 		insert(root->rc,next);
	 	}
	 }
}	 

void tree::height()
{
	if(cnt1>=cnt2)
	{
		cout<<"Total Generations in the Family: "<<cnt1;
		
	}
	else
	{
		cout<<"Total Generations in the Family: "<<cnt2;
	}
}
void tree::leaf(tree *root)
{
	
	int top=-1;
	temp = root;
	if(root!=NULL)
	{
		do
		{
			while(temp!=NULL)
			{
				top++;
				stack[top]=temp;
				temp=temp->lc;
			}
			if(top!=-1)
			{
				temp=stack[top];
				if(temp->lc==NULL && temp->rc==NULL)
				{				
					
					cout<<temp->name<<"\t\t"<<temp->dob<<"\t"<<temp->gen<<"\t"<<temp->age<<endl;
				}
				temp=temp->rc;
				top--;
			}
		}while(top!=-1 || temp !=NULL);
	}
}

void tree::display(tree *root)
{

	if(root==NULL)
	{
		return;
	}
	else
	{
		
		cout<<root->name<<"\t\t"<<root->dob<<"\t"<<root->gen<<"\t"<<root->age<<endl;
		
		display(root->lc);
		display(root->rc);
	}
}

int main()
{
	int ch;
	tree t;
	
	do{
		cout<<"\n\nEnter your Choice: ";
		cout<<"\n1. ADD Members";
		cout<<"\n2. DISPLAY the Family";
		cout<<"\n3. Total Generations in the Family";
		cout<<"\n4. Current Generation of Family";
		cout<<"\n5. EXIT\n";
		
		cin>>ch;
		
		switch (ch) 
		{
			case 1:
				t.create();
				break;
				
			case 2:
				cout<<"NAME\t\t DOB \t\t GENDER \t AGE\n";
				t.display(root);
				break;
				
			case 3:
				t.height();
				break;
			
			case 4:
				cout<<"NAME\t\t DOB \t\t GENDER \t AGE\n";
				t.leaf(root);
				break;
					
			case 5:
				exit(0);
				
			default:
				cout<<"Invalid Choice!!";
				break;
		}
	}while(ch!=6);
		
	return 0;
}			
