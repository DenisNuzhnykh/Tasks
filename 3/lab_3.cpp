#include <iostream>
#include <string>

using namespace std;

struct Person {
    int age;
    string name;
    char value;
};

Person createPerson(string name, int age, char value){
    Person newPerson;
    newPerson.age = age;
    newPerson.name = name;
    newPerson.value = value;
    return newPerson;
}

int main()
{
    Person newPerson = createPerson("Denis",20,'c');
    cout  << newPerson.age << endl;
    cout  << newPerson.name << endl;
    cout  << newPerson.value << endl;
    
}