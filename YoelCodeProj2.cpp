//This isn't the project
//This is some code and some testing stuff
//Nobody but us three should ever see this!

#include <iostream>
#include <map>
#include <string>

unsigned int now = 2016;

struct player{
    std::string name; //player name
    unsigned int birthYear; //BirthYear is an unsigned integer
    unsigned int category;//integer value equals the number after the U
    bool regStatus = false; //true is paid, false is unpaid
};


std::map<std::string, player> playerMap;



void addPlayer(){
    std::string nameIn;
    std::cout<<"Please input the player's name"<<std::endl;
//    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, nameIn);

    std::cout<<"What year was this player born in?"<<std::endl;
    unsigned int yearIn;
    std::cin>>yearIn;
    //Error checking here

    std::cout<<"Has this player payed their dues? (Y/N)"<<std::endl;
    char yn = 'Q';
    bool registered;
    std::cin>>yn;
    //More error checking here
    if(yn=='Y' || yn == 'y'){
	registered = true;
    }else if(yn == 'N' || yn == 'n'){
	registered = false;
    };

    int age = (now-yearIn);
    int _category;
    //Error handling for age
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
    //Error handling for age again


    playerMap[nameIn].name = nameIn;
    playerMap[nameIn].birthYear = yearIn;
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
    std::cout<<lookName<<std::endl;
    std::cout<<"Player's Name: "<<playerMap[lookName].name<<std::endl;
    std::cout<<"Player Birth Year: "<<playerMap[lookName].birthYear<<std::endl;
    std::cout<<"Player's Category: U"<<playerMap[lookName].category<<std::endl;
    std::cout<<"Player's Registration Status: ";
    if(playerMap[lookName].regStatus == true){
	std::cout<<"Registered!"<<std::endl;
    }else{
	std::cout<<"Not Registered. This player must pay their dues..." <<std::endl;
    }

}

int main(){//Test driver
    char end = 'n';

    while(end!='y'){//testing addPlayer()
	addPlayer();
	std::cout<<"enter y if we're done here"<<std::endl;
	std::cin>>end;
    }
    end = 'n';
    
    while(end!='y'){
	lookUp();
	std::cout<<"enter y if we're done here."<<std::endl;
	std::cin>>end;
    }
    end = 'n';
    
    return 0;
}
