#ifndef _functions_h_
#define _functions_h_

#include <iostream>
#include <fstream>
#include <map>
using std::iterator;
#include <string>

unsigned int now;

struct player{
    std::string name; //player name
    unsigned int birthYear; //BirthYear is an unsigned integer
    unsigned int category;//integer value equals the number after the U
    bool regStatus = false; //true is paid, false is unpaid
};
void addPlayer();

std::map<std::string, player> playerMap;

void inputData()
{
    std::string currentYear_;

    bool validFile = true;

    std::ifstream fin;
    fin.open( "data.txt" );

    if ( fin.fail() )
    {
        std::cout << "No previous data, creating new data file\n";

        trycurrentyear:
        std::cout << "What is the current year? ... ";

        std::cin >> currentYear_;
        for(int i = 0; i < currentYear_.length(); i++)
        {
            if(isdigit(currentYear_[i])==false)
            {
                std::cout<<"Your year contained non-integer characters. Have another try!"<<std::endl;
                goto trycurrentyear;
            }
        }
        now = stoi(currentYear_);
    }
    else
    {
        fin >> now;
        fin.get();  // remove endline character

        // temporary values
        std::string temp_name;
        unsigned int temp_yob;
        unsigned int temp_category;
        bool temp_regstat;

        // grabbing each 4 lines and storing data in our map
        while ( !fin.eof() )
        {
            // get values
            getline(fin, temp_name);
            fin >> temp_yob;
            fin.get(); //endline removal
            fin >> temp_category;
            fin.get();
            fin >> temp_regstat;
            fin.get();

            playerMap[ temp_name ].name = temp_name;
            playerMap[ temp_name ].birthYear = temp_yob;
            playerMap[ temp_name ].category = temp_category;
            playerMap[ temp_name ].regStatus = temp_regstat;
        }
    }
    fin.close();
}

void outputData()
{
    std::ofstream fout;

    fout.open("data.txt");

    // write to file
    fout << now << '\n';

    for ( std::map<std::string, player>::iterator i = playerMap.begin(); i != playerMap.end(); i++ )
    {
        fout << i->second.name << '\n';
        fout << i->second.birthYear << '\n';
        fout << i->second.category << '\n';
        fout << i->second.regStatus << '\n';
    }

    fout.close();
}

int NewSeason(){
    /*Makes file, deletes data in file if
    user wants it deleted*/
    std::ofstream outfile;
    char choice;
    std::string string_year;

    std::cout << "Do you wish to delete previous season's file? (Y/N) ";
    std::cin >> choice;

    if ((choice == 'N') || (choice == 'n')){
        return 0;
    } else if ((choice == 'Y') || (choice == 'y')){

        playerMap.empty();
        if (playerMap.empty() != true){
            playerMap.clear();
        }

        std::remove("Season.txt");
        std::cout << "Year: " << std::endl;
        std::cin >> string_year;

        for(int i = 0; i < string_year.length(); i++){
            while (!isdigit(string_year.at(i))){
                std::cout << "Year: " << std::endl;
                std::cin >> string_year;
                i=0;
            }
        }
        now = atoi(string_year.c_str());


        outfile.open ("Season.txt");

        if (!outfile.is_open()){
            std::cout << "File could not open." << std::endl;
        }

        return 1;
        }
}

void addPlayer(){
    std::string nameIn;
    std::cout<<"Please input the player's name"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nameIn);


    tryname:
    std::cout<<"What year was this player born in?"<<std::endl;
    std::string yearIn;
    std::cin>>yearIn;
    for(int i = 0; i < yearIn.length(); i++){
	if(isdigit(yearIn[i])==false){
	    std::cout<<"Your year contained non-integer characters. Have another try!"<<std::endl;
	    goto tryname;
	}
    };

    YNcheck:
    std::cout<<"Has this player payed their dues? (Y/N)"<<std::endl;
    char yn = 'Q';
    bool registered;
    std::cin>>yn;
    if(yn=='Y' || yn == 'y'){
	registered = true;
    }else if(yn == 'N' || yn == 'n'){
	registered = false;
    }else{
	std::cout<<"That was not a good character. Input Y or N!"<<std::endl;
	goto YNcheck;
    };

    int age = (now-stoi(yearIn));

    if(age<4){
	std::cout<<"This person is much too young to play soccer. Can't add them, sorry."<<std::endl;
	return;
    }else if(age>16){
	std::cout<<"This person is far too ancient to play soccer. Cant add them, sorry."<<std::endl;
	return;
    };
    int _category;
    if((age > 4) && (age <6)){
	_category = 6;
    }else if(age<8){
	_category = 8;
    }else if(age<10){
	_category = 10;
    }else if(age<12){
	_category = 12;
    }else if(age<14){
	_category = 14;
    }else if(age<17){
	_category = 17;
    }


    playerMap[nameIn].name = nameIn;
    playerMap[nameIn].birthYear = stoi(yearIn);
    playerMap[nameIn].category = _category;
    playerMap[nameIn].regStatus = registered;

};

void lookUp(){
    player temp;
    std::string lookName;
    std::cout<<"Enter the name of the player you're looking up!"<<std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, lookName);
    if(playerMap.find(lookName)==playerMap.end()){
	std::cout<<"This player doesn't exist, man!"<<std::endl;
	return;
    };
    std::cout<<"Player's Name: "<<playerMap[lookName].name<<std::endl;
    std::cout<<"Player Birth Year: "<<playerMap[lookName].birthYear<<std::endl;
    std::cout<<"Player's Category: U"<<playerMap[lookName].category<<std::endl;
    std::cout<<"Player's Registration Status: ";
    if(playerMap[lookName].regStatus == true){
	std::cout<<"Registered!"<<std::endl;
    }else{
	std::cout<<"Not Registered." <<std::endl;
    }
};

void EditPlayer(){
    /*Allows the player data to be edited*/
    std::string answer;

    player p;

    std::cout << "Edit player? (YES or NO)\n";
    std::cin >> answer;
    if ((answer == "YES")||(answer == "yes")||("Yes")){
        std::cout << "Player name?;";
        std::cin.ignore();
        std::getline(std::cin, p.name);
        std::map<std::string, player>::iterator itr = playerMap.find(p.name);
        playerMap.erase (itr);
        std::cout << "Please enter new information.\n";
        addPlayer();
        std::cout << "Player Information Changed.\n";

    } else {
        std::cout << "No Changes Made.\n";
    }
}

int generateList()
{

    int temp_categ;
    std::string cat_input;

    // Get a proper category
    trycategory:
    std::cout << "What category would you like to draw from (ie. U6, U8, U10) ... ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> cat_input;

    //input check
    char ucheck = cat_input[0];
    if ( ucheck != 'U' && ucheck != 'u' )
    {
        std::cout << "Invalid input format, try again.\n";
        goto trycategory;
    }
    temp_categ = stoi(cat_input.substr(1, 2));
    if ( temp_categ == 6 || temp_categ == 8 || temp_categ == 10 || temp_categ == 12 || temp_categ == 14 || temp_categ == 17 )
    {
        //donothing
    }
    else
    {
        std::cout << "Invalid category, enter again\n";
        goto trycategory;
    }


    std::string filename;
    // Get proper output file
    tryfilename:
    std::cout << "Enter an output file in the form of \"filename.txt\" ... ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> filename;
    std::ofstream fout;
    std::ifstream fin;
    fin.open(filename);
    if ( fout.fail() )
    {
        std::cout << "Bad filename, try again...\n";
        goto tryfilename;
    }
    else if ( fin.peek() != EOF )
    {
        fin.close();
        char overwrite;
        std::cout << "This filename is already in use. Do you want to overwrite it? (y/n) ...";
        std::cin >> overwrite;
        if ( overwrite == 'Y' || overwrite == 'y')
        {
            std::cout << "Overwriting file " << filename << " for output.\n";
            goto writefile;
        }
        else if ( overwrite == 'N' || overwrite == 'n')
        {
            std::cout << "Aborting overwrite of " << filename << ", and exiting filewrite process.\n";
            return -1;
        }
        else
        {
            std:: cout << "Invalid input, assumed 'n'. Overwrite of " << filename << " aborted.\n";
            return -1;
        }
    }
    else
    {
        writefile:
        fout.open(filename);
        fout << 'U' << temp_categ << " players\n";
        for ( std::map<std::string, player>::iterator i = playerMap.begin(); i != playerMap.end(); i++ )
        {
            if ( i->second.category == temp_categ )
            {
                fout << i->second.name << '\n';
                fout << i->second.birthYear << '\n';
                fout << i->second.category << '\n';
                fout << i->second.regStatus << '\n';
            }
        }
        fout.close();
        return 0;
    }
}
#endif
