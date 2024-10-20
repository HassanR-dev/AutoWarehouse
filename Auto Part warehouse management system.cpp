#include <iostream>
#include <map>
#include <string>

using namespace std;

class Employee {
protected:
    int employeeID;
    string name;
public:
    Employee(int id, string n) : employeeID(id), name(n) {}
    virtual void displayRole() = 0;
};

class WarehouseManager : public Employee {
public:
    WarehouseManager(int id, string n) : Employee(id, n) {}
    void displayRole() override {
        cout << "Employee ID: " << employeeID << ", Name: " << name << ", Role: Warehouse Manager\n";
    }
};

class Worker : public Employee {
public:
    Worker(int id, string n) : Employee(id, n) {}
    void displayRole() override {
        cout << "Employee ID: " << employeeID << ", Name: " << name << ", Role: Worker\n";
    }
};

class Part {
public:
    int partID;
    string partName;
    int quantity;
    Part(int id, string name, int qty) : partID(id), partName(name), quantity(qty) {}
    void displayPart() {
        cout << "Part ID: " << partID << ", Name: " << partName << ", Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    map<int, Part*> inventory;
public:
    void addPart(int partID, string partName, int quantity) {
        inventory[partID] = new Part(partID, partName, quantity);
        cout << "Part added successfully!\n";
    }

    void searchPart(int partID) {
        if (inventory.find(partID) != inventory.end()) {
            inventory[partID]->displayPart();
        } else {
            cout << "Part not found.\n";
        }
    }

    ~Warehouse() {
        for (auto& entry : inventory) {
            delete entry.second;
        }
    }
};

int main() {
    Warehouse warehouse;
    int choice;

    do {
        cout << "\n*** Warehouse Management System ***\n";
        cout << "1. Add a Part\n";
        cout << "2. Search for a Part\n";
        cout << "3. Display Employee Roles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int partID, quantity;
                string partName;
                cout << "Enter Part ID: ";
                cin >> partID;
                cin.ignore();
                cout << "Enter Part Name: ";
                getline(cin, partName);
                cout << "Enter Quantity: ";
                cin >> quantity;
                warehouse.addPart(partID, partName, quantity);
                break;
            }
            case 2: {
                int partID;
                cout << "Enter Part ID to search: ";
                cin >> partID;
                warehouse.searchPart(partID);
                break;
            }
            case 3: {
                WarehouseManager wm(1, "Hassan Rehan");
                Worker w(2, "M. Usman");
                wm.displayRole();
                w.displayRole();
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
