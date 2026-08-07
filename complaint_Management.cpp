#include <iostream>
#include <string>

using namespace std;

// Complaint structure
struct Complaint
{
    int id;
    string name;
    string type;
    string description;
    string status;
};

Complaint complaints[100];
int count = 0;

// Function declarations
bool login();
void menu();
void registerComplaint();
void viewComplaints();
void searchComplaint();
void updateComplaint();
void deleteComplaint();

int main()
{
    if(login())
    {
        menu();
    }
    else
    {
        cout << "\nToo many incorrect attempts. Exiting...\n";
    }

    return 0;
}


// Login Function
bool login()
{
    string username, password;

    for(int i = 1; i <= 3; i++)
    {
        cout << "\n===== Complaint Management System =====\n";

        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if(username == "admin" && password == "1234")
        {
            cout << "\nLogin Successful!\n";
            return true;
        }
        else
        {
            cout << "\nInvalid Username or Password.\n";
        }
    }

    return false;
}


// Menu Function
void menu()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n Complaint Management System";
        cout << "\n==============================";

        cout << "\n1. Register Complaint";
        cout << "\n2. View Complaints";
        cout << "\n3. Search Complaint";
        cout << "\n4. Update Complaint";
        cout << "\n5. Delete Complaint";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerComplaint();
                break;

            case 2:
                viewComplaints();
                break;

            case 3:
                searchComplaint();
                break;

            case 4:
                updateComplaint();
                break;

            case 5:
                deleteComplaint();
                break;

            case 6:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 6);
}


// Register Complaint
void registerComplaint()
{
    cout << "\n===== Register Complaint =====\n";

    cout << "Enter Complaint ID: ";
    cin >> complaints[count].id;

    cout << "Enter Name: ";
    cin >> complaints[count].name;

    cout << "Enter Complaint Type: ";
    cin >> complaints[count].type;

    cout << "Enter Description: ";
    cin.ignore();
    getline(cin, complaints[count].description);

    complaints[count].status = "Pending";

    count++;

    cout << "\nComplaint Registered Successfully!\n";
}


// View Complaints
void viewComplaints()
{
    cout << "\n===== All Complaints =====\n";

    if(count == 0)
    {
        cout << "No Complaints Available.\n";
        return;
    }

    for(int i = 0; i < count; i++)
    {
        cout << "\nComplaint ID: " << complaints[i].id;
        cout << "\nName: " << complaints[i].name;
        cout << "\nType: " << complaints[i].type;
        cout << "\nDescription: " << complaints[i].description;
        cout << "\nStatus: " << complaints[i].status;
        cout << "\n-------------------------";
    }
}


// Search Complaint
void searchComplaint()
{
    int id;
    bool found = false;

    cout << "\nEnter Complaint ID to Search: ";
    cin >> id;

    for(int i = 0; i < count; i++)
    {
        if(complaints[i].id == id)
        {
            cout << "\nComplaint Found";
            cout << "\nName: " << complaints[i].name;
            cout << "\nType: " << complaints[i].type;
            cout << "\nDescription: " << complaints[i].description;
            cout << "\nStatus: " << complaints[i].status;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nComplaint Not Found!";
    }
}


// Update Complaint
void updateComplaint()
{
    int id;
    bool found = false;

    cout << "\nEnter Complaint ID to Update: ";
    cin >> id;

    for(int i = 0; i < count; i++)
    {
        if(complaints[i].id == id)
        {
            cout << "Enter New Status: ";
            cin >> complaints[i].status;

            cout << "\nComplaint Updated Successfully!";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nComplaint Not Found!";
    }
}


// Delete Complaint
void deleteComplaint()
{
    int id;
    bool found = false;

    cout << "\nEnter Complaint ID to Delete: ";
    cin >> id;

    for(int i = 0; i < count; i++)
    {
        if(complaints[i].id == id)
        {
            for(int j = i; j < count - 1; j++)
            {
                complaints[j] = complaints[j + 1];
            }

            count--;

            cout << "\nComplaint Deleted Successfully!";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nComplaint Not Found!";
    }
}
