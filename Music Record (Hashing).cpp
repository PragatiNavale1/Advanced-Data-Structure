#include<iostream>
#include<string>
using namespace std;

//Musical Record System (Linear Probing)
int key[20],c[20],n;
int i;

class Album
{  
	public:
	int track_no;
	string composer,singer,title;
	void declare();
	void HTable();
	void accept();
	void search();
	void deletE();
	void modify();
	void displayRecord(int index); // Function to display the found record

}h[20];

void Album::declare()
{
	cout<<"\nEnter the Total No Of Music Albums: ";
	cin>>n;
	cout<<"\nEnter The Track_id: ";
	for(i=0;i<n;i++)
	{
	cin>>key[i];
	}
	for(i=0;i<20;i++)
	{
	
		h[i].track_no=-1;
		c[i]=0;
		
	}
}

void Album::accept()
{
	int no,pos;
	for(i=0;i<n;i++)
	{
		no=key[i]%10;
		pos=no;
		
		do
		{
			if(h[no].track_no==-1)
			{
			h[no].track_no=key[i];
			cout<<"\n********Enter Music Album Details********";
		
				cout<<"\nEnter Title: ";
				cin>>h[no].title;
				cout<<"\nEnter Singer: ";
				cin>>h[no].singer;
				cout<<"\nEnter Composer: ";
				cin>>h[no].composer;
				break;
				
			}
			else
			{
				no++;
				c[pos]=no;
				if(no>10)
				{
					no=0;
				}
			}
		}while(no<10);
	}
}

void Album::HTable()
{
	
	for(i=0;i<20;i++)
	{
		cout<<"\n";
		cout<<h[i].track_no<<"\t\t\t"<<h[i].title<<"\t\t\t"<<h[i].singer<<"\t\t\t"<<h[i].composer<<"\t\t\t"<<c[i];
	}
}

void Album::search()
{
    int tracKey;
    int no,f=0;
    cout<<"\nEnter Track No to SEARCH: ";
    cin>>tracKey;
    for(i=0;i<n;i++)
    {
        no=tracKey%10;
        if(h[no].track_no==tracKey)
        {
            f=1;
            cout<<"\nRecord is Found";
            displayRecord(no); // Display the found record
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

void Album::displayRecord(int index)
{
   cout<<"\n| Track NO |\t TITLE |\t SINGER |\t COMPOSER |\t CHAIN |\t";
    cout<<"\n";
	cout<<h[index].track_no<<"\t\t\t"<<h[index].title<<"\t\t\t"<<h[index].singer<<"\t\t\t"<<h[index].composer<<"\t\t\t"<<c[i];
}

void Album::deletE()
{
    int tracKey;
    int no,f=0;
    cout<<"\nEnter Track No to DELETE: ";
    cin>>tracKey;
    for(i=0;i<n;i++)
    {
        no=tracKey%10;
        if(h[no].track_no==tracKey)
        {
            f=1;
            h[no].track_no = -1;
            h[no].title = "";
            h[no].singer = "";
            h[no].composer = "";
            c[no] = 0;
            cout<<"\nRecord deleted successfully";
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

void Album::modify()
{
    int tracKey;
    int no,f=0;
    cout<<"\nEnter Track No to MODIFY: ";
    cin>>tracKey;
    for(i=0;i<n;i++)
    {
        no=tracKey%10;
        if(h[no].track_no==tracKey)
        {
            f=1;
            cout<<"\nEnter New Title: ";
            cin>>h[no].title;
            cout<<"\nEnter New Singer: ";
            cin>>h[no].singer;
            cout<<"\nEnter New Composer: ";
            cin>>h[no].composer;
            cout<<"\nRecord modified successfully";
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

int main()
{
	int ch;
	Album a;

	do {
		cout << "\nEnter your Choice: ";
		cout << "\n1. INSERT TRACK NO";
		cout << "\n2. Insert MUSIC DATA";
		cout << "\n3. DISPLAY";
		cout << "\n4. SEARCH MUSIC";
		cout << "\n5. DELETE MUSIC";
		cout << "\n6. MODIFY MUSIC \n7. EXIT\n";

		cin >> ch;

		switch (ch)
		{
		case 1:
			a.declare();
			cout<<"\n| Track NO |\t TITLE |\t SINGER |\t COMPOSER |\t CHAIN |\t";
			a.HTable();
			break;
		case 2:
			a.accept();
			break;
		case 3:
		    cout<<"\n| Track NO |\t TITLE |\t SINGER |\t COMPOSER |\t CHAIN |\t";
			a.HTable();
			break;
		case 4:
			a.search();
			break;
		case 5:
			a.deletE();
			break;
		case 6:
			a.modify();
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "Invalid Choice!!";
			break;
		}
	} while (ch != 8);

	return 0;
}
