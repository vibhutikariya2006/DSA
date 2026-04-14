#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Base {
public:
    int ver;
    vector<string> users;
    vector<vector<string>> followadj;

    Base(int x) {
        ver = x;
        followadj.resize(ver);
    }

    // Add user
    void addUser(string name) {
        users.push_back(name);
    }

    // Get index of user
    int getIndex(string name) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i] == name) {
                return i;
            }
        }
        return -1;
    }

    // Follow user
    void follower(string a, string b) {
        int i = getIndex(a);
        int j = getIndex(b);

        if (i == -1 || j == -1) {
            cout << "User not found" << endl;
            return;
        }

        followadj[i].push_back(b);
        cout << a << " started following " << b << endl;
    }

    // Show who a follows
    void getfollowers(string a) {
        int i = getIndex(a);

        if (i == -1) {
            cout << "User not found" << endl;
            return;
        }

        cout << a << " -> ";
        for (string nei : followadj[i]) {
            cout << nei << " ";
        }
        cout << endl;
    }

    // Check if a follows b
    void isfollowing(string a, string b) {
        int i = getIndex(a);

        if (i == -1) {
            cout << "User not found" << endl;
            return;
        }

        bool found = false;

        for (string nei : followadj[i]) {
            if (nei == b) {
                cout << a << " is following " << b << endl;
                found = true;
            }
        }

        if (!found) {
            cout << a << " is not following " << b << endl;
        }
    }

    // Display full network
    void displayNetwork() {
        for (int i = 0; i < users.size(); i++) {
            cout << users[i] << " -> ";
            for (string nei : followadj[i]) {
                cout << nei << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Base fd(10);

    // Add users FIRST
    fd.addUser("rahu");
    fd.addUser("Vibhuti");
    fd.addUser("mukesh");

    int choice;
    string a, b;

    do {
        cout << "\n<---------- SOCIAL MEDIA SYSTEM ---------->\n";
        cout << "1. Follow a user\n";
        cout << "2. View following list\n";
        cout << "3. Check following\n";
        cout << "4. Display network\n";
        cout << "5. Add user\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
    
    cout << "Enter follower: ";
    cin >> a;

    cout << "Enter followee: ";
    cin >> b;

    fd.follower(a, b);
    break;
        

        case 2:
            cout << "Enter user: ";
            cin >> a;
            fd.getfollowers(a);
            break;

        case 3:
            cout << "Enter two users: ";
            cin >> a >> b;
            fd.isfollowing(a, b);
            break;

        case 4:
            fd.displayNetwork();
            break;

        case 5:
            cout << "Enter new user: ";
            cin >> a;
            fd.addUser(a);
            cout << "User added\n";
            break;

        case 6:
            cout << "Exit successfully\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}