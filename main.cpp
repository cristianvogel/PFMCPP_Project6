/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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

struct Comparator                                //4
{
    const T* compare(const T& a, const T& b) 
    {   
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float paramU1 { 0 }, paramU2 { 0 };
    float shiftAndProduct(float& valueIn)      //12
    {
        std::cout << "\tU's paramU1 value: " << this->paramU1 << std::endl;
        this->paramU1 = valueIn;
        std::cout << "\tU's paramU1 updated value: " << this->paramU1 << std::endl;
        while( std::abs(this->paramU2 - this->paramU1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            this->paramU2 += 1.f;
        }
        std::cout << "\n\tU's paramU2 updated value: " << this->paramU2 << std::endl;
        return (this->paramU2 * this->paramU1);
    }
};

struct Transform
{
    static float shiftAndProduct(U& that, float& valueIn )        //10
    {      
      	std::cout << "\tU's paramU1 value: " << that.paramU1 << std::endl;
        that.paramU1 = valueIn;
        std::cout << "\tU's paramU1 updated value: " << that.paramU1 << std::endl;
        while( std::abs(that.paramU2 - that.paramU1) > 0.001f )
        {
           /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
           	that.paramU2 += 1.f;
        }
        std::cout << "\n\tU's paramU2 updated value: " << that.paramU2 << std::endl;
        return that.paramU2 * that.paramU1;   
    }
};
        
int main()
{
    T varA( 100.0f, "A" );                                             //6
    T varB( 10.0f, "B" );                                             //6
            
    Comparator f;                                            //7
    const T* smaller = f.compare( varA, varB );
    
    if (smaller != nullptr) 
    {
        std::cout << "\n\nthe smaller one is << " << smaller->name << std::endl; //9
    }

    U varU3;
    float updatedValue = 3.0f;
    std::cout << "Transform::shiftAndProduct varU3's multiplied values: \n" << Transform::shiftAndProduct( varU3, updatedValue ) << std::endl;

    U varU4;
    std::cout << "U::shiftAndProduct varU4's multiplied values: \n" << varU4.shiftAndProduct( updatedValue ) << std::endl;
    return 0;
}
