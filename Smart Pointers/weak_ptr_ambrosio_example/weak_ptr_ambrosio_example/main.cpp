//example code to show circular link problem among shared pointers:
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Student 
{
private:
    string name; //stores student name.
    shared_ptr<Student>myFriend;
    //every object/student has a shared_ptr called myFriend
    //which points to a friend of theirs.
    
public:
    //default constructor:
    Student()
    {
        name = "Nameless";
        cout << "Nameless Student created" << endl;
    }
    //parametarized constructor:
    Student(string n) //creates a student
    //what about the shared_ptr?
    {
        name = n;
        cout << "Student " << n << endl;
    }
    //destructor:
    ~Student()
    {
        cout << "Student is destroyed" << endl;
    }
    void makeFriend(shared_ptr<Student> f)
    //takes in a shared pointer.
    {
        myFriend = f;
        return;
    }
    void speak() 
    {
        cout << "Student " << name << " speaks!" << endl;
        return;
    }
}; //close Student class.

int main() 
{
    //create a friend object via shared_ptr:
    shared_ptr<Student>morisStudent = make_shared<Student>("Moris");
    
    //create a friend object via shared_ptr:
    shared_ptr<Student>ashStudent = make_shared<Student>("Ash");
    
    //make Ash's new friend be Moris:
    ashStudent->makeFriend(morisStudent); //ash method is pointing to moris
    
    //make Moris' new friend be Ash:
    morisStudent->makeFriend(ashStudent); //moris method is pointing to ash. we in a circle lol.
    
    //this is problem bc neither ashStudent or morisStudent will delete.
    //methods pointing at each other lol.
    //notice how a destructor is never called lol.
    //how does weak_ptr solve this?
    //it allows us to create a non-own ref to an object managed by
    //a shared_ptr w/o affecting the ref count or preventing the
    //object from being deleted.
    
    weak_ptr<Student>weakPtr = morisStudent;
    cout << "weak ptr ref #" << weakPtr.use_count() << endl;
    
    
    
    
/*
    shared_ptr<Student> pS(new Student("Steven"));
    shared_ptr<Student> pS2(new Student("Angel"));

    pS->makeFriend(pS2); //Cyclic reference
    pS2->makeFriend(pS);

    weak_ptr<Student> wpS = pS; 
    //Weak pointer has no ownership of the pointed object

    cout << "weak ptr ref #" << wpS.use_count() << endl;
    
    { //opening new scope.
        shared_ptr<Student> temp = wpS.lock();
        // lock returns a shared pointer
        temp->speak();
        cout << "weak_ptr ref #" << wpS.use_count() << endl;
    } //closing new scope.
    cout << "weak_ptr ref #" << wpS.use_count() << endl;
*/
    return 0;
}

