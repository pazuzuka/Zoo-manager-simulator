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


class Visitor {
public:
    void interactWithAnimals(Animal* animal) {
        cout << "Visitor interacts with " << animal->name << ".\n";
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

class Zoo {
private:
    vector<Animal*> animals;
    vector<Visitor> visitors;
    VisitorManager visitorManager;

public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }


    void addVisitor(const Visitor& visitor) {
        visitors.push_back(visitor);
    }



    void feedAllAnimals() {
        for (auto animal : animals) {
            animal->feed();
        }
    }

    void trackVisitor() {
        visitorManager.trackVisitor();
    }

    void displayVisitorCount() {
        visitorManager.displayVisitorCount();
    }


    void saveStateToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {

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


    int main() {
        Zoo zoo;

        Lion lion;
        Elephant elephant;
        Bird bird;
        zoo.addAnimal(&lion);
        zoo.addAnimal(&elephant);
        zoo.addAnimal(&bird);
    }
};