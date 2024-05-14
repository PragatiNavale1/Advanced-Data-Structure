#include<iostream>
#include<stack>

using namespace std;

class emp
{
public:
    string name, dob;
    int age, salary;
    emp *lc, *rc;

    void display1(emp* root);
    void display2(emp* root);
    void create();
    void insert(emp* root, emp* next);
    void display(emp* root);
    void display_lst(emp* root);
    void display_rst(emp* root);
    void display_top3(emp* root,int& count);
    int height(emp* root);
    void leaf(emp* root);

}*root, *st[20];

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
    cout << "Enter AGE: ";
    cin >> root->age;

    root->lc = root->rc = NULL;

    do {
        cout << "Do you want to add new Node:(0/1)no/yes";
        cin >> ch;
        if (ch == 1) {
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

            next->lc = next->rc = NULL;
            insert(root, next);
        }

    } while (ch == 1);

}

void emp::insert(emp* root, emp* next)
{
    if (root->salary > next->salary) {
        if (root->lc == NULL)
            root->lc = next;
        else
            insert(root->lc, next);
    }
    else {
        if (root->rc == NULL)
            root->rc = next;
        else
            insert(root->rc, next);
    }
}

void emp::display1(emp* root)
{
    if (root != NULL) {
        display1(root->lc);
        cout << endl;
        cout << "Name of Employee  : " << root->name << endl;
        cout << "DOB of Employee : " << root->dob << endl;
        cout << "Salary of Employee : " << root->salary << endl;
        cout << "Age of Employee : " << root->age << endl;

        display1(root->rc);
    }
}

void emp::display2(emp* root)
{
    if (root != NULL) {
        display2(root->rc);
        cout << endl;
        cout << "Name of Employee  : " << root->name << endl;
        cout << "DOB of Employee : " << root->dob << endl;
        cout << "Salary of Employee : " << root->salary << endl;
        cout << "Age of Employee : " << root->age << endl;

        display2(root->lc);
    }
}

void emp::display(emp* root)
{
    display1(root);
}

void emp::display_lst(emp* root)
{
    display1(root->lc);
}

void emp::display_rst(emp* root)
{
    display2(root->rc);
}

void emp::display_top3(emp *root, int &count)
{
    if (root == nullptr || count >= 3)
        return;

    // Traverse the right subtree first
    display_top3(root->rc, count);

    // Print the current employee information
    if (count < 3)
    {
        cout << "Name: " << root->name << ", Salary: " << root->salary << endl;
        count++;
    }

    // Traverse the left subtree
    display_top3(root->lc, count);
}

int emp::height(emp* root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->lc);
    int rightHeight = height(root->rc);

    return 1 + max(leftHeight, rightHeight);
}

void emp::leaf(emp* root)
{
    if (root != NULL) {
        if (root->lc == NULL && root->rc == NULL)
            cout << root->name << endl;
        leaf(root->lc);
        leaf(root->rc);
    }
}

int main()
{
    int ch;
    int count = 0;
    emp t;

    do {
        cout << "\nEnter your Choice: ";
        cout << "\n1. CREATE";
        cout << "\n2. DISPLAY";
        cout << "\n3. HEIGHT of tree ";
        cout << "\n4. LEAF nodes of tree ";
        cout << "\n5. Left subtree ";
        cout << "\n6. Right subtree ";
        cout << "\n7. Top 3";
        cout << "\n8. EXIT\n";

        cin >> ch;

        switch (ch) {
        case 1:
            t.create();
            break;
        case 2:
            t.display(root);
            break;
       case 3:
            cout << "Height of tree: " << t.height(root) << endl;
            break;

        case 4:
            cout << "Leaf nodes are :\n";
            t.leaf(root);
            break;
        case 5:
            cout << "Left Sub Tree :\n";
            t.display_lst(root);
            break;
        case 6:
            cout << "Right Sub Tree :\n";
            t.display_rst(root);
            break;
        case 7:
            
            cout << "Top three highly paid employees:" << endl;
            t.display_top3(root, count);
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << "Invalid Choice!!";
            break;
        }
    } while (ch != 8);

    return 0;
}