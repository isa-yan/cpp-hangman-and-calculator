#include <iostream>
#include <string>

/*
clang++ -g calculator.cpp -o calculator
./calculator
*/

int main(){
    /* set up */
    int x;
    int y;
    std::string oper;

    /*prep numbers :p*/
    std::cout<<"enter number one"<<"\n";
    std::cin>>x;
    std::cout<<"you entered "<<x<<"\n";
    std::cout<<"enter a new number "<<"\n";
    std::cin>>y;
    std::cout<<"you entered "<<y<< " as a second number"<<"\n";

    /*choose your pokemon :D*/
    std::cout<<"pick your operator"<<" no spaces, lowercase"<<"\n";
    std::cin>>oper;
    if (oper=="plus")
        std::cout<<x+y;
    else if (oper=="minus")
        std::cout<<x-y;
    else if (oper=="multiply")
        std::cout<<x*y;
    else if (oper=="divide")
        std::cout<<x/y;
    else   
        std::cout<<"that isn't a valid operator";



    return 0;
    
}
