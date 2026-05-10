#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>

/*
clang++ -g hangman.cpp -o hangman
./hangman
*/

int main(){
    /*setup*/
    int insert; //1 or 2
    std::string space = "_ ";
    std::string word; // the word that's inserted
    std::string prewords[5]={"rhythm","jazz","quartz","jockey","mystify"};
    int randomnum = rand() % 5;
    std::string hangedword; //the actual word chosen

    //word setting logic
    std::cout<<"would you like to have someone else enter a word, or generate a word"<<"\n";
    std::cout<<"1. insert a word"<<" 2. generate a word"<<"\n";
    std::cin>>insert;
    if (insert==1) {
        std::cin>>word;
        std::cout<<"word is decided now"<<"\n";
        hangedword=word;
    } else if (insert==2) {
        std::cout<<"word sucessfully generated"<<"\n";
        hangedword=prewords[randomnum];
        
    }

    int totalspace = (int)hangedword.length(); //how many spaces

    int guessamount=totalspace+6; //how many guesses player has

    std::cout<<"start guessing!"<<"You have "<<guessamount<<" guesses"<<"\n";

    /*guessing logic */
    std::vector<char> myguess; //tries to store an array of guessed characters
    char insertchar; //inserted character
    std::vector<char> currentguess(totalspace);
    std::vector<char> arrayletter(hangedword.begin(),hangedword.end()); //hangedword into an array of characters
    bool found;

    for (int i=0;i<totalspace;i++){
        std::cout<<space; //spaces
        currentguess[i] = '_';
    }
    std::cout<<"\n";

    for (int i=0;i<guessamount;i++){
        std::cout<<"you've used "<<i<<" guesses"<<"\n";
        std::cin>>insertchar; //taking in the inserted character
        if (std::find(myguess.begin(),myguess.end(),insertchar) !=myguess.end()){
            std::cout<<"you've already guessed "<<insertchar<<"\n";
        }
        myguess.push_back(insertchar); //adds the person's guess to the list of guesses


        for (int i=0;i<totalspace;i++)
            if (std::find(arrayletter.begin(), arrayletter.end(), insertchar) != arrayletter.end()){
                auto rightnum = std::find(arrayletter.begin(), arrayletter.end(), insertchar); //finds if in array
                int index = std::distance(arrayletter.begin(),rightnum);
                currentguess[index]=insertchar;
                found=true;
            }else
                found=false;
            
            std::string stringguess(currentguess.begin(),currentguess.end());

            if (found==true)
                std::cout<<stringguess<<"\n";
            else{
                std::cout<<insertchar<<" is not a character"<<"\n"; //prints if it's not a character
                std::cout<<stringguess<<"\n";

        }

    
        if (stringguess==hangedword)
            std::cout<<"you won"<<"\n";
            
        }
    
    return 0;
}
