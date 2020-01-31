/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

 Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review...
 */

#include <iostream>
#include <string>
struct T
{
    float value;
    const std::string name; 
    
    T (float v, const char* aCharacter) :
        value (v),
        name (aCharacter)
    { }
};

struct Operation 
{
    T* compare(T* a, T* b)
    {   
        if (a != nullptr && b != nullptr) 
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr; 
    } 
};

struct U
{
    float var1 { 0 }, var2 { 0 };
    
    U(float a) : var1 (a) { }
    
    float product( float* inputValue ) 
    {
        std::cout << "U's var1 value: " << this->var1 << std::endl;
        if (inputValue != nullptr) 
        { 
            this->var1 = *inputValue;
            std::cout << "U's var1 updated value: " << this->var1 << std::endl;
            std::cout << "Reducing magnitude.. \n";
            while( std::abs (static_cast <long> (this->var2 - this->var1)) > 0.001f )
            {
                /*
                write something that makes the distance between that->name2 and that->name1 get smaller
                */
                this->var2 += 0.5f;
                std::cout << this->var2 << ", ";
            }
            std::cout << "U's var2 updated value: " << this->var2 << std::endl;
            return this->var2 * this->var1;
        }
    }
};

struct StaticTransform
{
    static float product(U* that, float* inputValue ) 
    {
        if ( inputValue != nullptr && that != nullptr)
        {
            std::cout << "\nU's var1 value: " << that->var1 << std::endl;
            that->var1 = *inputValue; 
            std::cout << "\nU's var1 updated value: " << that->var1 << std::endl;
            std::cout << "Reducing magnitude.. \n";
            while( std::abs (static_cast <long> (that->var2 - that->var1)) > 0.001f )
                {
                    /*
                    write something that makes the distance between that->name2 and that->name1 get smaller
                     */          
                    that->var2 += 0.5f;
                    std::cout << that->var2 << ", ";
                }
            std::cout << "\nU's var2 updated value: " << that->var2 << std::endl;
            return (that->var2 * that->var1);
        }
    }
};
        
int main()
{
    T var1( 0.1f , "a" );                                             
    T var2( 0.5f , "b");  
    
    Operation f;                                      
    T* smaller = f.compare( &var1, &var2 );  
    if (smaller != nullptr) std::cout << "\n\nthe smaller one is << " << smaller->name << std::endl; 
    
    U user3 ( -60.0f  );
    float updatedValue = 30.0f;

    std::cout << "StaticTransform function user3's multiplied values: " << StaticTransform::product( &user3 , &updatedValue ) << std::endl; 
    
    U user4 ( -60.0f  );
    std::cout << "Product function user4's multiplied values: " << user4.product( &updatedValue ) << std::endl;
}

 
