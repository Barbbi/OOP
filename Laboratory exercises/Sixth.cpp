#include <iostream>
#include <cstring>

using namespace std;

class DisciplinaryAction {
private: 
char* name;
char* reason;
int index;
int sessions;
public:
DisciplinaryAction (){
    name = new char [1];
    name [0] = '\0';
    reason = new char [1];
    reason [0] = '\0';
    index = 0;
    sessions = 0;
}
DisciplinaryAction (const DisciplinaryAction& diact) {
    name = new char [strlen (diact.name) + 1];
    strcpy(name, diact.name);
    reason = new char [strlen (diact.reason) +1];
    strcpy(reason, diact.reason);
    index = diact.index; 
    sessions = diact.sessions;
}
DisciplinaryAction (const char* naMe, int inDex, const char* reaSon, int sesSions) {
    name = new char [strlen (naMe) + 1];
    strcpy(name, naMe);
    reason = new char [strlen (reaSon) +1];
    strcpy(reason, reaSon);
    index = inDex; 
    sessions = sesSions;
}

~DisciplinaryAction(){
    delete[]name;
    delete[]reason; 
}

void setIndex (int inDex){
    index=inDex;
}
int getIndex() const {
    return index;
}

DisciplinaryAction& operator = (const DisciplinaryAction& diact){
        delete [] name; 
        name = new char [strlen (diact.name) + 1];
        strcpy(name, diact.name);
        delete [] reason;
        reason = new char [strlen (diact.reason) +1];
        strcpy(reason, diact.reason);
        index = diact.index; 
        sessions = diact.sessions;
    return *this;
    }

friend ostream &operator<< (ostream &op, const DisciplinaryAction &diac){
    op << "Student: " << diac.name << endl;
    op << "Student's index: " << diac.index << endl;
    op << "Reason: " << diac.reason << endl;
    op << "Sessions: " << diac.sessions << endl;
}

DisciplinaryAction &operator ++ () {
    ++sessions;
    return *this;
}

bool operator >= (const DisciplinaryAction &diact) const {
    return sessions >= diact.sessions;
}

};


/// Do NOT edit the main() function

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        cout << (++arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}