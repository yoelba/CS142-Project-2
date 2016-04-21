// GRAPHICAL USER INTERFACE ====================================================
/* Allows user to choose the following
    1. Start a new season. The user provides the current year and the program
        deletes all the existing players from the file. Before deleting, the program
        asks for a confirmation.
    2. Add a player. The user provides the name, year of birth and registration
        status of a player and the program adds an entry to the file. The category
        is automatically computed.
    3. Look up a player. The user provides a name and the program displays the
        entry for that player or a message saying that the player was not found.
    4. Edit a player’s information. After searching for a player, the user is given
        the option of changing that player’s information (name, year of birth, reg-
        istration status). If needed, the category is recomputed automatically.
    5. Generate a list of all the players in a given category. The user provides the
        name of a category and a file name. The program then writes to that file
        a list of all the players in that category. Players are written to the file in
        alphabetical order and in the format described above.
*/
#include <string>

void gui()
{
    int choice; // value for user decision to be interpreted by a switch statement
    bool valid = true; // used in making sure user input is valid

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
            std::cout << "   { 5 } List players of a certain category (ie. U6, U8, U10)\n"
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
        }while( !valid )

        // Redirect to each command chosen by user
        switch ( choice )
        {
            // Start a new season
            case 1 :

            // Add a player
            case 2 :

            // Look up a player
            case 3 :

            // Edit a player's information
            case 4 :

            // List players of a certain category
            case 5 :

            // End program
            case 6 :
        }
    }
}
