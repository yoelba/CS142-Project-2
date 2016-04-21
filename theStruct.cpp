//This isn't the project
//This is some code and some testing stuff
//Nobody but us three sghould ever see this!

#include <iostream>
#include <map>
#include <string>

unsigned now = 2016;

struct player{
    std::string name; //player name
    unsigned birthYear; //BirthYear is an unsigned integer
    unsigned category;//integer value equals the number after the U
    bool regStatus; //true is paid, false is unpaid
    
};


std::map<std::string, player> playerMap;


void addPlayer(){
    player newGuy; //New player
    std::string nameIn;
    std::cout<<"Please input the player's name"<<std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, nameIn);
    newGuy.name = nameIn;

    std::cout<<"What year was this player born in?"<<std::endl;
    unsigned yearIn;
    std::cin>>yearIn;
    //Error checking here
    newGuy.birthYear = yearIn;

    std::cout<<"Has this player payed their dues? (Y/N)"<<std::endl;
    char yn = 'Q';
    std::cin>>yn;
    //More error checking here
    if(yn=='Y' || yn == 'y'){
	newGuy.regStatus = true;
    }else if(yn == 'N' || yn == 'n'){
	newGuy.regStatus = false;
    };

    int age = (now-newGuy.birthYear);
    int category;
    //Error handling for age
    if(age<6){
	category = 6;
    }else if(age<8){
	category = 8;
    }else if(age<10){
	category = 10;
    }else if(age<12){
	category = 12;
    }else if(age<14){
	category = 14;
    }else if(age<17){
	category = 17;
    }
    //Error handling for age again
    newGuy.category = category;

    playerMap.insert(std::pair<std::string, player>(nameIn, newGuy));
    
    
    
};

int main(){
    char end = 'n';
    
    while(end=='n'){
	addPlayer();
	std::cout<<"Added enough players for your satisfaction?"<<std::endl;
	std::cin>>end;
    }
    return 0;
}
