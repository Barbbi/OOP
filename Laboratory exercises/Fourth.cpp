#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char* name;
    char* major;
    int age;
    
public:
    Student(char* name = " ", int age = 0, char* major = " ") {
        this->name = new char[strlen(name) +1];
        strcpy(this->name, name);
        this->major = new char[strlen(major) +1];
        strcpy(this->major, major);
        this->age = age;
    }
    Student(const Student &stnt) {
        this->name = new char[strlen(stnt.name) + 1];
        strcpy(name, stnt.name);
        this->major = new char[strlen(stnt.major) + 1];
        strcpy(major, stnt.major);
        this->age = stnt.age;
    }
    Student& operator = (const Student &stnt) {
        this->name = new char[strlen(stnt.name) + 1];
        strcpy(name, stnt.name);
        this->major = new char[strlen(stnt.major) + 1];
        strcpy(major, stnt.major);
        this->age = stnt.age;
        return * this;
    }
    char *getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    char *getMajor() const {
        return major;
    }
};

class Classroom {
private:
    Student* students;
    int numStudents;
    int capacity;
public:
    Classroom() {
        this->numStudents = 0;
        this->capacity = 0;
        students = NULL;
    }

    Classroom(Student* students, int numStudents, int capacity) {
        this->numStudents = numStudents;
        this->capacity = capacity;
        this->students = new Student[numStudents];
        for (int i = 0; i < numStudents; i++) {
            this->students[i] = Student(students[i]);
        }
    }

    Student *getStudents() const {
        return students;
    }
    int getNumStudents() const {
        return numStudents;
    }

    void add (Student s) {
        Student *tmp = new Student[numStudents+1];
        for (int i = 0; i < numStudents; i++) {
            tmp[i] = students[i];
        }
        tmp[numStudents] = s;
        delete [] students;
        students = tmp;
        numStudents++;
    }

    void remove (char* name) {
        int indexSv = -1;
        int counterr = 0;
        for(int i = 0; i < numStudents; i++) {
            if ( strcmp(name, students[i].getName()) == 0 ) {
                indexSv = i;
                break;
            }
        }
        for (int i = 0; i < numStudents; i++) {
            if (i != indexSv) {
                counterr++;
            }
        }
    
        Student *tmp = new Student[counterr];
        int j = 0;
        for (int i = 0; i < numStudents; i++) {
            if (i != indexSv) {
                tmp[j] = students[i];
                j++;
            }
        }
        delete [] students;
        students = tmp;
        numStudents = counterr;
    }

    void printStudents() {
        for (int i = 0; i < numStudents; i++) {
            cout << students[i].getName() << " (" << students[i].getAge() << ", " << students[i].getMajor() << ")" << endl;
        }
        cout<<endl;
    }
};
double findMedianAge(Classroom classroom) {
    Student* students = classroom.getStudents();
    int n = classroom.getNumStudents() / 2;
    double medianN = students[n].getAge();

    if(classroom.getNumStudents() % 2 == 0) {
        medianN = (students[n].getAge() + students[n - 1].getAge()) / 2.0;
    }
    return medianN;
}

//DO NOT CHANGE
int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i*numStudents + j] = student;
        }
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout<<"After removing the elements:"<<endl; /// Added 
    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }

    return 0;
}