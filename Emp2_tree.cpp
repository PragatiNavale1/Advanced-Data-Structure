#include<iostream>
#include<stack>
#define max 20
using namespace std;
int cnt = 0;
class emp
{
public:
	string name, dob;
	int age, salary,sum=0;
	emp* lc, * rc;

	int cnt, cnt1, cnt2;
	void display1(emp* root);
	void display2(emp* root);
	void create();
	void insert(emp* root, emp* next);
	void display(emp* root);
    void display_left(emp* root);
    void display_right(emp* root);
	void height();
	void leaf(emp* root);
	void totalsal();
    void top_three(emp *root);

}*root, * st[max];
void emp::create()
{
	int ch;
	emp* next;
	root = new emp;
	cout << "ENTER the Company employee INFORMATION \n";
	cout << "Enter NAME: ";
	cin >> root->name;
	cout << "Enter DOB: ";
	cin >> root->dob;
	cout << "Enter SALARY: ";
	cin >> root->salary;
	sum=sum+root->salary;
	cout << "Enter AGE: ";
	cin >> root->age;

	cnt = cnt1 = cnt2 = 1;
	
	root->lc = root->rc = NULL;

	do {
		cout << "Do you want to add new Node:(0/1)no/yes";
		cin >> ch;
		if (ch == 1)
		{
			next = new emp;
			cout << "ENTER the Employee INFORMATION \n";

			cout << "Enter NAME of Employee : ";
			cin >> next->name;
			cout << "Enter DOB of Employee : ";
			cin >> next->dob;
			cout << "Enter SALARY: ";
			cin >> next->salary;
			cout << "Enter AGE: ";
			cin >> next->age;
			sum=sum+next->salary;
			next->lc = next->rc = NULL;
			insert(root, next);
		}

	} while (ch == 1);

}
void emp::insert(emp* root, emp* next)
{
	char chr;
	emp* temp;

	if (root->salary > next->salary)
	{
		if (root->lc == NULL)
		{
			root->lc = next;
			cnt1++;
		}
		else
		{
			insert(root->lc, next);
		}

	}
	if (root->salary < next->salary)
	{
		if (root->rc == NULL)
		{
			root->rc = next;
			cnt2++;
		}
		else
		{
			insert(root->rc, next);
		}
	}
}
void emp::display1(emp* root) {
	int top = -1;

	emp* temp;
	temp = root;

	if (root != NULL) {
		while (temp != NULL) {
			top++;
			st[top] = temp;
			temp = temp->lc;
		}
		if (top != -1) {
			temp = st[top];


			cout << "Employee with Minimum salary Record is \n ";
			cout << "Name of Employee  : " << temp->name << endl;
			cout << "DOB of Employee    : " << temp->dob << endl;
			cout << "Salary of Employee : " << temp->salary << endl;
			cout << "Age of Employee    : " << temp->age << endl;
			temp = temp->lc;


		}

	}
}

void emp::display2(emp* root) {
	int top = -1;

	emp* temp;
	temp = root;

	if (root != NULL) {


		while (temp != NULL) {
			top++;
			st[top] = temp;
			temp = temp->rc;
		}
		if (top != -1) {
			temp = st[top];


			cout << "Employee with Maximum salary Record is \n";
			cout << "Name of Employee  : " << temp->name << endl;
			cout << "DOB of Employee    : " << temp->dob << endl;
			cout << "Salary of Employee : " << temp->salary << endl;
			cout << "Age of Employee    : " << temp->age << endl;
			temp = temp->rc;


		}

	}
}

void emp::display(emp* root)
{

	int top = -1;
	emp* temp;
	temp = root;
    
	if (root != NULL) {
		do{

		while (temp != NULL) {
			top++;
			st[top] = temp;
			temp = temp->lc;
		}
		if (top != -1) {
			temp = st[top];
			cout << "Name of Employee  : " << temp->name << endl;
			cout << "DOB of Employee    : " << temp->dob << endl;
			cout << "Salary of Employee : " << temp->salary << endl;
			cout << "Age of Employee    : " << temp->age << endl;
			temp = temp->rc;
			top--;


		}
		}while (top != -1 || temp != NULL);
	}
	

}
void emp::display_left(emp* root)
{
	int top = -1;
	emp* temp;
	temp = root;
    
	if (root != NULL) {
		do{

		while (temp != NULL) {
			top++;
			st[top] = temp;
			temp = temp->lc;
		}
		if (top != -1) {
            if(st[top]==root)
            {
                return;
            }
			temp = st[top];
			cout << "Name of Employee  : " << temp->name << endl;
			cout << "DOB of Employee    : " << temp->dob << endl;
			cout << "Salary of Employee : " << temp->salary << endl;
			cout << "Age of Employee    : " << temp->age << endl;
			temp = temp->rc;
			top--;
		}
		}while (top != -1 || temp != NULL);
	}
	

}
void emp::display_right(emp* root)
{
	int top = -1;
	emp* temp;
	temp = root;
    
	if (root != NULL) {
		do{

		while (temp != NULL) {
			top++;
			st[top] = temp;
			temp = temp->rc;
		}
		if (top != -1) {
            if(st[top]==root)
            {
                return;
            }
			temp = st[top];
			cout << "Name of Employee  : " << temp->name << endl;
			cout << "DOB of Employee    : " << temp->dob << endl;
			cout << "Salary of Employee : " << temp->salary << endl;
			cout << "Age of Employee    : " << temp->age << endl;
			temp = temp->lc;
			top--;
		}
		}while (top != -1 || temp != NULL);
	}
	

}
void emp::top_three(emp* root)
{
    int top = -1;
    emp* temp;
    temp = root;
    int count = 0; // Counter variable to track the number of nodes printed
    
    if (root != NULL) {
        do {
            while (temp != NULL) {
                top++;
                st[top] = temp;
                temp = temp->rc;
            }
            if (top != -1) {
                if (st[top] == root) {
                    return;
                }
                temp = st[top];
                cout << "Name of Employee  : " << temp->name << endl;
                cout << "DOB of Employee    : " << temp->dob << endl;
                cout << "Salary of Employee : " << temp->salary << endl;
                cout << "Age of Employee    : " << temp->age << endl;
                temp = temp->lc;
                top--;
                count++; // Increment the counter after printing a node
                if (count == 3) // Check if 3 nodes have been printed
                    break; // Exit the loop if 3 nodes have been printed
            }
        } while (top != -1 || temp != NULL);
    }
}

void emp::height()
{
	if (cnt1 >= cnt2)
	{
		cout << "height of tree is : " << cnt1;
	}
	else
	{
		cout << "height of tree is : " << cnt2;
	}
}

void emp::leaf(emp* root)
{
	emp* stack[max];
	emp* temp;
	int top = -1;
	temp = root;
	if (root != NULL)
	{
		do {
			while (temp != NULL)
			{
				top++;
				stack[top] = temp;
				temp = temp->lc;
			}
			if (top != -1)
			{
				temp = stack[top];
				if (temp->lc == NULL && temp->rc == NULL)
				{
					cout << temp->name << endl;
				}
				temp = temp->rc;
				top--;

			}
		} while (top != -1 || temp != NULL);
	}
}
void emp::totalsal()
{
	cout<<"Total Salary of Organisation is "<<sum;
}
int main()
{
	int ch;
	emp t;

	do {
		cout << "\nEnter your Choice: ";
		cout << "\n1. CREATE";
		cout << "\n2. DISPLAY";
		cout << "\n3. HEIGHT of tree ";
		cout << "\n4. LEAF nodes of tree ";
		cout << "\n5. minmum salary \n6. Maximum salary\n7. Display total salary\n8.Display Left Subtree\n9.Display Right Subtree\n10.Display top three\n 11.Exit";

		cin >> ch;

		switch (ch)
		{
		case 1:
			t.create();
			break;
		case 2:
			t.display(root);
			break;
		case 3:
			t.height();
			break;
		case 4:
			cout << "Leaf nodes are :\n";
			t.leaf(root);
			break;
		case 5:
			t.display1(root);
			break;
		case 6:
			t.display2(root);
			break;
		case 7:
			t.totalsal();
			break;
        case 8:
            t.display_left(root);
            break;
        case 9:
            t.display_right(root);
            break;
        case 10:
            t.top_three(root);
            break;
		case 11:
			exit(0);
			break;
		default:
			cout << "Invalid Choice!!";
			break;
		}
	} while (ch != 11);

	return 0;
}