#include<iostream>
#include<string>
using namespace std;

class AdjacencyMatrix
{
public:
    int vertex, edge, fuel, a[30][30];
    string city[30];
    void create();
    void display();
    int getFuel(string fromCity, string toCity);
};

void AdjacencyMatrix::create()
{
    cout << "Enter Number of Cities: ";
    cin >> vertex;
    for (int i = 0; i < vertex; i++)
    {
        cout << "Enter Name of City " << i + 1 << ": ";
        cin >> city[i];
    }
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++) 
        {
            if (i != j) 
            {
                if (i < j)
                {
                    cout << "Enter the fuel " << city[i] << " to " << city[j] << ": ";
                    cin >> fuel;
                    a[i][j] = fuel;
                    a[j][i] = fuel; // Assign the same value for symmetry
                }
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
}

void AdjacencyMatrix::display()
{
    cout << "***Adjacency Matrix***\n";
    cout << "\t";
    for (int i = 0; i < vertex; i++)
    {
        cout << city[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << city[i] << "\t";
        for (int j = 0; j < vertex; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

int AdjacencyMatrix::getFuel(string fromCity, string toCity)
{
    int fromIndex = -1, toIndex = -1;
    for (int i = 0; i < vertex; i++)
    {
        if (city[i]== fromCity)
            fromIndex = i;
        if (city[i]== toCity)
            toIndex = i;
    }
    if (fromIndex != -1 && toIndex != -1)
        return a[fromIndex][toIndex];
    else
        return -1; // Invalid city names
}


int main()
{
    AdjacencyMatrix AM;
    AM.create();
    AM.display();
    
    string fromCity, toCity;
    cout << "Enter the source city: ";
    cin >> fromCity;
    cout << "Enter the destination city: ";
    cin >> toCity;

    int fuelRequired = AM.getFuel(fromCity, toCity);
    if (fuelRequired != -1)
        cout << "Fuel required from " << fromCity << " to " << toCity << ": " << fuelRequired << endl;
    else
        cout << "Invalid city names!" << endl;

    return 0;
}
