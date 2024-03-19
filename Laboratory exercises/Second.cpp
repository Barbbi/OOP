#include <iostream>
#include <cstring>

using namespace std;

//YOUR CODE HERE
class MobilePhone {
private: 
char model[20];
int modelNumber;
int issueYear;
public:
MobilePhone(){
    strcpy(model, " ");
    modelNumber = 0;
    issueYear = 0;
}
MobilePhone (const char *model, int modelNumber, int issueYear){
strcpy(this->model, model);
this->modelNumber = modelNumber;
this->issueYear = issueYear;
}
MobilePhone (const MobilePhone& mobilePhone){
strcpy(model,mobilePhone.model);
modelNumber = mobilePhone.modelNumber;
issueYear = mobilePhone.issueYear;
}
~MobilePhone (){}

const char* getModel() const{
    return model;
}
int getModelNumber() const{
    return modelNumber;
}
int getIssueYear() const{
    return issueYear;
}

void print() const{
cout<<model<<" "<<modelNumber<<" release year: "<<issueYear<<endl;
}
};
class Owner {
private: 
char name[20];
char surname[20];
MobilePhone mobilePhone;
public:
Owner() {
    strcpy(name, " ");
    strcpy(surname, " ");
    mobilePhone = mobilePhone;
}
Owner(const char *firstName,const char *lastName,const MobilePhone& mobilePhone){
strcpy(name,firstName);
strcpy(surname, lastName);
this->mobilePhone = mobilePhone;
}

~Owner (){}

const char* getName() const{
    return name;
}
const char* getSurname() const{
    return surname;
}
const MobilePhone& getMobilePhone() const{
    return mobilePhone;
}

void print() const{
cout<<name<<" "<<surname<<" has a mobile phone: "<<endl;
mobilePhone.print();
}
};
//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

};
