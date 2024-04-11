#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal {
public:
    string name;
    int age;

    virtual void feed() = 0;
    virtual void speak() = 0;
};

class Lion : public Animal {
public:
    void feed() override {
        cout << "Feeding the lion...\n";
    }

    void speak() override {
        cout << "Roar!\n";
    }
};

class Elephant : public Animal {
public:
    void feed() override {
        cout << "Feeding the elephant...\n";
    }

    void speak() override {
        cout << "Trumpet!\n";
    }
};

class Bird : public Animal {
public:
    void feed() override {
        cout << "Feeding the bird...\n";
    }

    void speak() override {
        cout << "Chirp!\n";
    }
};

class Employee {
public:
    virtual void doWork() = 0;
};

class Keeper : public Employee {
public:
    void doWork() override {
        cout << "Keeper is feeding animals.\n";
    }
};

class Veterinarian : public Employee {
public:
    void doWork() override {
        cout << "Veterinarian is treating animals.\n";
    }
};

class Guide : public Employee {
public:
    void doWork() override {
        cout << "Guide is conducting a tour.\n";
    }
};

class Visitor {
public:
    void interactWithAnimals(Animal* animal) {
        cout << "Visitor interacts with " << animal->name << ".\n";
    }
};

class Tour {
public:
    vector<string> route;

    void addLocation(string location) {
        route.push_back(location);
    }

    void startTour() {
        for (const auto& location : route) {
            cout << "Visiting: " << location << endl;
        }
    }
};

class VisitorManager {
private:
    int visitorCount;

public:
    VisitorManager() : visitorCount(0) {}

    void trackVisitor() {
        visitorCount++;
    }

    void displayVisitorCount() {
        cout << "Total visitors: " << visitorCount << endl;
    }
};

class FinanceManager {
private:
    double income;
    double expenses;

public:
    FinanceManager() : income(0), expenses(0) {}

    void addIncome(double amount) {
        income += amount;
    }

    void addExpense(double amount) {
        expenses += amount;
    }

    double calculateProfit() {
        return income - expenses;
    }

    double calculateExpense() { 
        return expenses;
    }
};

class Zoo {
private:
    vector<Animal*> animals;
    vector<Employee*> employees;
    vector<Visitor> visitors;
    vector<Tour> tours;
    VisitorManager visitorManager;
    FinanceManager financeManager;

public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void addVisitor(const Visitor& visitor) {
        visitors.push_back(visitor);
    }

    void addTour(const Tour& tour) {
        tours.push_back(tour);
    }

    void feedAllAnimals() {
        for (auto animal : animals) {
            animal->feed();
        }
    }

    void makeEmployeesWork() {
        for (auto employee : employees) {
            employee->doWork();
        }
    }

    void interactWithAnimals() {
        for (auto& visitor : visitors) {
            for (auto animal : animals) {
                visitor.interactWithAnimals(animal);
            }
        }
    }

    void conductTours() {
        for (auto& tour : tours) {
            tour.startTour();
        }
    }

    void trackVisitor() {
        visitorManager.trackVisitor();
    }

    void displayVisitorCount() {
        visitorManager.displayVisitorCount();
    }

    void addIncome(double amount) {
        financeManager.addIncome(amount);
    }

    void addExpense(double amount) {
        financeManager.addExpense(amount);
    }

    double calculateProfit() {
        return financeManager.calculateProfit();
    }

    void saveStateToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Income: " << financeManager.calculateProfit() + financeManager.calculateExpense() << endl;
            file << "Expense: " << financeManager.calculateExpense() << endl;
            file << "Profit: " << financeManager.calculateProfit() << endl;
            file.close();
            cout << "Zoo state saved to " << filename << endl;
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    void loadStateFromFile(string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
            cout << "Zoo state loaded from " << filename << endl;
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    void displayMenu() {
        cout << "Zoo Management System\n";
        cout << "1. Feed animals\n";
        cout << "2. Make employees work\n";
        cout << "3. Interact with animals\n";
        cout << "4. Conduct tours\n";
        cout << "5. Track visitor\n";
        cout << "6. Display visitor count\n";
        cout << "7. Add income\n";
        cout << "8. Add expense\n";
        cout << "9. Calculate profit\n";
        cout << "10. Save zoo state to file\n";
        cout << "11. Load zoo state from file\n";
        cout << "12. Exit\n";
    }

    void handleInput(int choice) {
        switch (choice) {
        case 1:
            feedAllAnimals();
            break;
        case 2:
            makeEmployeesWork();
            break;
        case 3:
            interactWithAnimals();
            break;
        case 4:
            conductTours();
            break;
        case 5:
            trackVisitor();
            break;
        case 6:
            displayVisitorCount();
            break;
        case 7: {
            double amount;
            cout << "Enter income amount: ";
            cin >> amount;
            addIncome(amount);
            break;
        }
        case 8: {
            double amount;
            cout << "Enter expense amount: ";
            cin >> amount;
            addExpense(amount);
            break;
        }
        case 9:
            cout << "Profit: $" << calculateProfit() << endl;
            break;
        case 10:
            saveStateToFile("zoo_state.txt");
            break;
        case 11:
            loadStateFromFile("zoo_state.txt");
            break;
        case 12:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
};

int main() {
    Zoo zoo;

    Lion lion;
    Elephant elephant;
    Bird bird;
    zoo.addAnimal(&lion);
    zoo.addAnimal(&elephant);
    zoo.addAnimal(&bird);

    Keeper keeper;
    Veterinarian vet;
    Guide guide;
    zoo.addEmployee(&keeper);
    zoo.addEmployee(&vet);
    zoo.addEmployee(&guide);

    Visitor visitor1, visitor2;
    zoo.addVisitor(visitor1);
    zoo.addVisitor(visitor2);

    Tour tour1, tour2;
    tour1.addLocation("Lion Enclosure");
    tour1.addLocation("Elephant Habitat");
    tour2.addLocation("Bird Aviary");
    tour2.addLocation("Reptile House");
    zoo.addTour(tour1);
    zoo.addTour(tour2);

    int choice;
    do {
        zoo.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        zoo.handleInput(choice);
    } while (choice != 12);

}
