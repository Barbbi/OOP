#include <iostream>
#include <cstring>

using namespace std;

class DisciplinaryAction {
private:
    char* name;
    char* reason;
    int index;

public:

    DisciplinaryAction() {
        name = new char[1];
        reason = new char[1];
        index = 0;
    }

    DisciplinaryAction(const char* newName, int newIndex, const char* newReason) {
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
        reason = new char[strlen(newReason) + 1];
        strcpy(reason, newReason);
        index = newIndex;
    }

    DisciplinaryAction(const DisciplinaryAction& discac) {
        name = new char[strlen(discac.name) + 1];
        strcpy(name, discac.name);
        reason = new char[strlen(discac.reason) + 1];
        strcpy(reason, discac.reason);
        index = discac.index;
    }

    ~DisciplinaryAction() {
        delete[] name;
        delete[] reason;
    }

    void setIndex(int newIndex) {
        index = newIndex;
    }

    int getIndex() const {
        return index;
    }

    DisciplinaryAction& operator=(const DisciplinaryAction& discac) {
        if (this != &discac) {
            delete[] name;
            delete[] reason;
            name = new char[strlen(discac.name) + 1];
            strcpy(name, discac.name);
            index = discac.index;
            reason = new char[strlen(discac.reason) + 1];
            strcpy(reason, discac.reason);
        }
        return *this;
    }

    void print() const {
        cout << "Student: " << name << endl;
        cout << "Student's index: " << index << endl;
        cout << "Reason: " << reason << endl;
    }
};
/// Do NOT edit the main() function

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for(int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;

        cin >> name >> index >> reason;

        arr[i] = DisciplinaryAction(name, index, reason);
    }

    cout << "-- Testing operator = & print() --\n";
    arr[0].print();

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    arr[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    merka.print();

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for(int i = 0; i < n; i++)
        arr[i].print();

    return 0;
}