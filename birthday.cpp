// c/c++
//A. BIRTHDAY LIST
//In this project create, edit and display your loved Friend's/Family's birthday list.
//You can also provide a search option to find your friend's birthday by name. You can also view a list of monthly birthdays. Must display at least 5 birthdays.
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Birthday {
    string name;
    int day;
    int month;
};
bool compare_birthday(const Birthday& b1, const Birthday& b2) {
    if (b1.month == b2.month) {
        return b1.day < b2.day;
    }
    else {
        return b1.month < b2.month;
    }
}
int main() {
    vector<Birthday> birthdays;
    cout << "Birthday List\n";
    cout << "1. Add birthday\n";
    cout << "2. Edit birthday\n";
    cout << "3. Delete birthday\n";
    cout << "4. Search birthday\n";
    cout << "5. Display monthly birthdays\n";
    cout << "6. Exit\n";
    while (true) {
        cout << "Choose an option: ";
        int option;
        cin >> option;
        if (option == 1) {
            Birthday birthday;
            cout << "Enter name: ";
            cin >> birthday.name;
            cout << "Enter day (1-31): ";
            cin >> birthday.day;
            cout << "Enter month (1-12): ";
            cin >> birthday.month;
            birthdays.push_back(birthday);
        }
        else if (option == 2) {
            cout << "Enter name to edit: ";
             string name;
            //  bool temp;
            cin >> name;
            auto it = find_if(birthdays.begin(), birthdays.end(), [&](const Birthday& b) {
                return b.name == name;
                //  temp=strcmp(b.name.c_str(), name.c_str());
                //  return temp;
            });
            if (it != birthdays.end()) {
                cout << "Enter new day (1-31): ";
                cin >> it->day;
                cout << "Enter new month (1-12): ";
                cin >> it->month;
                cout << "Birthday updated.\n";
            }
            else {
                cout << "Birthday not found.\n";
            }
        }
        else if (option == 3) {
            Birthday birthday;
            cout << "Enter name to delete: ";
            cin >> birthday.name;
            // birthdays.erase (birthdays.end() - 1);
            // cout << "Birthday deleted from list."<<endl;
            auto it = find_if(birthdays.begin(), birthdays.end(), [&](const Birthday& b) {
                return b.name == birthday.name;
            });
            birthdays.erase(it);
            cout<<"Birthday Record deleted."<<endl;
        }
        /*
            Birthday birthday;
            cout << "Enter name to delete: ";
            cin >> birthday.name;
            for (auto it = birthdays.begin(); it != birthdays.end(); ++it){
                if(it==birthday.name){
                    birthdays.erase(it);
                    cout<<"Birthday Record deleted."<<endl;
                }
            }
        */

        // else if (option == 3) {
        //     cout << "Enter name to delete: ";
        //     string name;
        //     cin >> name;
            // auto it = remove_if(birthdays.begin(), birthdays.end(), [&](const Birthday& b) {
            //     return b.name;
            // });
        //}
        else if (option == 4){
            Birthday birthday;
            cout << "Enter name to search: ";
            cin >> birthday.name;
            vector<Birthday> name_birthdays;
            copy_if(birthdays.begin(), birthdays.end(), back_inserter(name_birthdays), [&](const
            Birthday& b) {
                return b.name == birthday.name;
            });
            cout << birthday.name << " " << birthday.day << "/" << birthday.month << endl;
            

            // cout << "Birthday not found.\n";
        }
        else if (option == 5) {
            int month;
            cout << "Enter month (1-12) to list: ";
            cin >> month;
            string name;
            vector<Birthday> month_birthdays;
            copy_if(birthdays.begin(), birthdays.end(), back_inserter(month_birthdays), [&](const
            Birthday& b) {
                return b.month == month;
            });
            sort(month_birthdays.begin(), month_birthdays.end(), compare_birthday);
            for (const auto& birthday : month_birthdays) {
                cout << birthday.name << " " << birthday.day << "/" << birthday.month << endl;
            }
            
        }
        else if (option == 6) {
            cout << "Exiting program.\n";
            exit(0); // exit the program with a successful status code
        }
        else {
            cout << "Invalid option.\n";
        }
    }
return 0;
}