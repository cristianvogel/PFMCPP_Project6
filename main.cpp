//==============================================================================

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
 Wait for my code review.
 */

#include <iostream>
#include <string>

struct T
{
    float value;
    std::string name;
    
    T(float v, const char* label) : value(v), name (label) 
    { }
};

struct Compare                                //4
{
    T* compare(T* a, T* b) 
    {
        if ( (a != nullptr) && (b != nullptr) )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        } 
        return nullptr;
    }
};

struct U
{
    float paramU1 { 0 }, paramU2 { 0 };
    float shiftAndProduct(float* valueIn)      //12
    {
        if( valueIn != nullptr )
        {
            std::cout << "\tU's paramU1 value: " << this->paramU1 << std::endl;
            this->paramU1 = *valueIn;
            std::cout << "\tU's paramU1 updated value: " << this->paramU1 << std::endl;
            while( std::abs(this->paramU2 - this->paramU1) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                this->paramU2 += 1.f;
            }
            std::cout << "\n\tU's paramU2 updated value: " << this->paramU2 << std::endl;
            return this->paramU2 * this->paramU1;
        }
        return 0.0f;
    }
};

struct Transform
{
    static float shiftAndProduct(U* that, float* valueIn )        //10
    {
        if(that != nullptr && valueIn != nullptr)
        {
       		std::cout << "\tU's paramU1 value: " << that->paramU1 << std::endl;
        	that->paramU1 = *valueIn;
            std::cout << "\tU's paramU1 updated value: " << that->paramU1 << std::endl;
        	while( std::abs(that->paramU2 - that->paramU1) > 0.001f )
        	{
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            	that->paramU2 += 1.f;
        	}
            std::cout << "\n\tU's paramU2 updated value: " << that->paramU2 << std::endl;
            return that->paramU2 * that->paramU1;
        }
        return 0.0f;
    }
};
        
int main()
{
    T varA( 100.0f, "A" );                                             //6
    T varB( 50.0f, "B" );                                             //6
            
    Compare f;                                            //7
    auto* smaller = f.compare( &varA, &varB );
    if (smaller != nullptr)
    {                               //8
        std::cout << "\n\nthe smaller one is << " << smaller->name << std::endl; //9
    }
    
    U varU3;
    float updatedValue = 5.0f;
    std::cout << "Transform::shiftAndProduct varU3's multiplied values: \n" << Transform::shiftAndProduct( &varU3, &updatedValue ) << std::endl;

    U varU4;
    std::cout << "U::shiftAndProduct varU4's multiplied values: \n" << varU4.shiftAndProduct( &updatedValue ) << std::endl;
    return 0;
}
