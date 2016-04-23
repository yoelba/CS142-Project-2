#include "functions.h"

#include <fstream>

int main()
{
    // Retrieve data
    inputData();

    // Start interface
    int choice; // value for user decision to be interpreted by a switch statement
    bool valid = true; // used in making sure user input is valid
    bool addmore = true;
    char addmore_c;
    bool lookmore = true;
    char lookmore_c;

    // Loop so the program can take multiple commands
    while ( choice != 6 )
    {
        // Request and check of valid input
        do
        {
            // Visual Formatting
            std::cout << '\n';
            std::cout << "==============================================\n";
            std::cout << '\n';
            std::cout << "Choose any of the following tasks by entering the respective number.\n";
            std::cout << '\n';
            std::cout << "   { 1 } Start a new season\n";
            std::cout << "   { 2 } Add a player\n";
            std::cout << "   { 3 } Look up a player\n";
            std::cout << "   { 4 } Edit a player's information\n";
            std::cout << "   { 5 } List players of a certain category (ie. U6, U8, U10)\n";
            std::cout << "   { 6 } End program\n";
            std::cout << '\n';
            // valid command check
            if ( !valid ) std::cout << "!!! Invalid command, enter any integer 1 through 5\n";
            // request input
            std::cin.clear();
            std::cout << "command: ";
            std::cin >> choice;
            std::cin.clear();
            std::cout << '\n';
            std::cout << "==============================================\n";
            // check input
            if ( choice >= 1 && choice <= 6 ) valid = true;
        }while( !valid );

        // Redirect to each command chosen by user
        switch ( choice )
        {
            // Start a new season
            case 1: NewSeason();
            break;

            // Add a player
            case 2: while ( addmore )
                    {
                        addPlayer();
                        std::cout << "Would you like to add more? (y/n)... ";
                        std::cin >> addmore_c;
                        if ( addmore_c == 'y' || addmore_c == 'Y' ) addmore = true;
                        else if ( addmore_c == 'n' || addmore_c == 'N' ) addmore = false;
                        else
                        {
                            std::cout << "Invalid choice, assumed 'n'\n";
                            addmore = false;
                        }
                    }
            break;
            // Look up a player
            case 3: while ( lookmore )
                    {
                        lookUp();
                        std::cout << "Would you like to look up another player? (y/n)... ";
                        std::cin >> lookmore_c;
                        if ( lookmore_c == 'y' || lookmore_c == 'Y' ) lookmore = true;
                        else if ( lookmore_c == 'n' || lookmore_c == 'N' ) lookmore = false;
                        else
                        {
                            std::cout << "Invalid choice, assumed 'n'\n";
                            lookmore == false;
                        }
                    }
            break;
            // Edit a player's information
            case 4: EditPlayer();
            break;

            // List players of a certain category
            case 5: generateList();
            break;

            // End program
            case 6: break;
        }
    }
}
