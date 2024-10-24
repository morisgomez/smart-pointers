//notes on smart pointers:
//Description:
//- Smart pointers are like the responsible guardians
//of memory.They are a special type of pointer that
//automatically manages the memory they point to.
//This ensures that it is cleaned up properly when it
//is no longer needed.

//Memory leaks:
//- Without smart pointers, you have to manually
//delete the memory you allocate with "new." Forgetting
//to do this can lead to memory leaks, where your program keeps
//using up more and more memory, eventually crashing. Smart
//pointers handle this automatically, so yo dont have to worry
//about it.

//Dangling pointers:
//- If you delete memory pointed to by a raw pointer, but the pionter
//itself still exists, it becomes a dangling pointer. Trying to use it can
//lead to unpredictable behavior and crashes. Smart pointers preven this by
//automatically invalidating the pointer when the memory is deleted.

//Smart pointer analogy:
//- Imagine you are borrowing a boo, from a library. With a raw pointer, it
//is like you are given the book and told to return it when youre done. But
//if you forget, the library never gets it back, and the book is lost. With
//a smart pointer, it is like the librarian automatically takes the book
//back from you when you are done, ensuring it is returned to the shelf.

//Types of smart pointers:
//- unique_ptr:
//This is the most basic type of smart pointer. It represents exlusive
//ownership of the memory, meaning only one smart pointer can point to the
//same object at a time.
//- shared_ptr:
//This allows multiple pointers to share ownership of the memory. When the
//last shared_ptr goes out of scope, the memory is deleted. **What is meant
//by out of scope? {}
//- weak_ptr:
//This is used in conjuction with shared_ptr to stop circular references,
//which can lead to memory leaks. **What is meant by a circular reference?

//Summary:
//Smart pointers make memory management in C++ much easier and safer,
//saving you from potential headaches and crashes.

#include <iostream>
#include <memory>
using namespace std;

class Person
{
public:
    //default constructor.
    Person()
    {
        cout << "constructor called." << endl;
    }
    //destructor:
    ~Person()
    {
        cout << "destructor called." << endl;
    }
}; //close Person class.




int main()
{
/*
//1) UNIQUE_PTR:
    //1) make raw pointer with int data type (primitive):
    int x = 26; //we store an integer value of 26 into the container x.
    int *ptr1 = &x; //we point to the address of the container x, not x itself.
    
    //2) make a unique pointer with int data type (primitive):
    unique_ptr<int>unPtr1 = make_unique<int>(25);
    //unique_pointer of int data type.
    //the name of pointer is unPtr1.
    //it points to an int type of 25.
    //make_unique must be keyword im assuming?
    
    cout << unPtr1 << "->" << *unPtr1 << endl;
    
    //3) make another raw pointer point to the same object/data of 26:
    int *ptr2 = ptr1; //ptr2 and ptr1 pointing to the same object/data.
    cout << "ptr2 points to: " << ptr2 << " and value at the address is: " << *ptr2 <<endl; //ptr2 points to: 0x7ff7bfeff2c8 and value at the address is: 26
    cout << "ptr1 points to: " << ptr1 << " and value at the address is: " << *ptr1 <<endl; //ptr2 points to: 0x7ff7bfeff2c8 and value at the address is: 26
    
    //4) make another smart pointer point to same object/data of 25:
    //unique_ptr<int>unPtr2 = unPtr1; //error bc only 1 smart ptr can
    //point to a data/pbject at a time. 
    
    //5) We need give ownership to the other pointer:
    unique_ptr<int>unPtr2 = std::move(unPtr1);
    //unPtr2 now points to whatever unPtr 2 was pointing to (25).
    //unPtr1 automatically becomes NULL.
    
    //6) print value of new ownership.:
    cout << *unPtr2 << endl; //25
    //cout << *unPtr1 << endl; //no value/address. //exception thrown.

    cout << endl << "########BREAK #1#########" << endl << endl;
    
//2) REVIEW ON RAW POINTERS & STATIC/DYNAMIC MEMORY ALLOCATION:
    //1) create an object using a raw pointer:
    Person *rawPointer = new Person(); //via dynamic memory allocate.
    cout << rawPointer << endl;
    delete rawPointer; //have to deallocate b4 end of program.
    //w/o delete, the destructor is never called.
    
    //cout << "------" << endl; //via static memory allocate.
    //Person object1 = Person();
    //Person *rawPointer2 = &object1;
    //cout << rawPointer2 << endl;
    //program automatically deallocates memory at end of program.
    //we know this bc destructor is automatically called at end of main.
    
    cout << endl << "########BREAK #2#########" << endl << endl;
    
//3) UNIQUE_PTR WITH CLASS OBJECTS:
    unique_ptr<Person>unPersonPtr = make_unique<Person>();
    //unique ptr pointing to a data type(object) of Person.
    //the pointer name is unPersonPtr.
    //make_unique<Person>() creates the actual object to point to.
    //note: deconstructor is automatically called unlike dynamic memory allocation.
    //in other words: there is automatic memory deallocation once @end of main.
    
    //unique_ptr is destroyed/deallocated at end of a scope {}.
    //that is why it gets destroyed when reaching reaching the } of the main function.
    //lets build a new scope to test this out:
    {
        unique_ptr<Person>unPersonPtr7 = make_unique<Person>();
    } //unPersonPtr7 destroyed at end of this scope. } //calls deconstructor.
    
    cout << endl << "########BREAK #3#########" << endl << endl;
    
//3) SHARED_PTR WITH CLASS OBJECTS:
    //a shared pointer can be shared with multiple owners.
    //can assign 1 raw pointer to multiple owners.
    
    //1) create a shared pointer:
    shared_ptr<Person>sharedPointer1 = make_shared<Person>();
    //created a shared_ptr of class Person, make it point to an object.
    
    //2) display # of pointers/owners are pointing to that object:
    cout << "count: " <<  sharedPointer1.use_count() << endl; //1
    
    //3) create new shared_ptr and make it point to sharedPointer1:
    shared_ptr<Person>sharedPointer2 = sharedPointer1;
    
    //4) display # of pointers/owners are pointing to that object:
    cout << "count: " <<  sharedPointer1.use_count() << endl; //2
    //shared pointers automatically deallocated at end of scope (main
    //in this case0 ONLY when no more owners avaialble.
    //all owners destroyed at end of each scope.
    //memory free for other use.
    
    cout << endl << "########BREAK #4#########" << endl << endl;
    
//4) WEAK_PTR WITH CLASS OBJECTS:
    //weak_ptrs are used together with shared pointers. The difference
    //is that we can make a weak pointer point to an address
    //that a shared pointer is pointing to.
    //BUT that weak pointer will not count towards the total use_count().
    //weak_ptr will not keep an object alive if nothing else needs it.
    //used to observe objects in memory.
    //shared & unique OWN while weak observes.
*/
    //1) create a shared ptr & make a weak ptr point to it:
    shared_ptr<Person>sharedPointerTest = make_shared<Person>();
    shared_ptr<Person>sharedPointerTest2 = sharedPointerTest;
    cout << sharedPointerTest.use_count() << endl; //2
    weak_ptr<Person>weakPointerTest = sharedPointerTest;
    cout << sharedPointerTest.use_count() << endl; //2, no inc in ownership.
    
    //2) weak ptr is a solution to circular reference issue w/ shared ptrs.
    //for example, if ObjectA has a shared_ptr to ObjectB and ObjectB has a
    //shared_ptr to ObjectA, they form a circular reference. This can be
    //problematic because neither ObjectA nor ObjectB will ever be deleted,
    //leading to a memory leak.
    
    //Here, weak_ptr comes to the rescue by providing a way to break these
    //circular references. It allows you to create a non-own reference to
    //an object managed by shared_ptr without affecting the reference count
    //or preventing the object from being deleted.
    
    return 0;
} //unique, shared destroyed at end of this scope. } //calls deconstructor.
