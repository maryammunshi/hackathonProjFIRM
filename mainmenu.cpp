// disasters: evicted, house burned down,
// it rains --> collaspses + flooding,
// collaspes, lack of protective gear, drowning, 
// malaria, birth defects, asked to leave buying 
// house when asking for decent money, child died in the mines,
// no food you have no choice but to hunt for an ape, 
// you found a piece of colbalt, sharpened tool, tetanus, 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int lifePts = 100;

//structs
struct Miner
{
    int age, familySize;
    char gender;
    string name;

};
Miner person;

//function prototypes
void displayHome();
void printLifeBar(int current);
Miner displayStart(Miner);

//global variables
int day1(int, char, string, int&);
int day2(int, char, string, int&);
int day3(int, char, string, int&);
int day4(int, char, string, int&);
int day5(int, char, string, int&);

//MAIN FUNCTION
int main() {

    displayHome();

    return 0;
}


void displayHome()
{
    char key;
    cout << "  5 Days of Life in the Mines\n";
    cout << "------------------------------------\n";
    cout << "PRESS S TO START, ANY OTHER KEY TO QUIT: ";
    cin.get(key);
    if (key == 's' || key == 'S')
    {
        cout << "You are a cobalt miner in the Democratic Republic of Congo (DRC).\n";
        cout << "The morning is cold and damp as you, along with the other miners, gather at the entrance"
            << "\nto the cobalt mine. The ground is slippery, the air thick with dust, "
            << "and the smell of wet rock. You’ve started the week with 100 points, \nwhich represents "
            << "your life bar. But this will not last forever, "
            << "and every decision today will impact the rest of the week.\n"
            << "Your goal is to not die – that is, reach 0 in the health bar – by the end of the week.\n"
            << "Although the Democratic Republic of Congo (DRC) is abundant in natural resources, it remains the second "
            << "poorest country globally. The life expectancy in DRC is only 47 years for men and 51 years for women. "
            << "This is significantly lower than the average of 81.2 years in the UK.\n";
        cout << "Will *you* be able to survive the DRC?" << endl;
        person = displayStart(person);
    }
    else
    {
        cout << "\nYou chose to quit.\n";
        return;
    }
}

void printLifeBar(int current) {
    int max = 100;
    int barWidth = 10; // show only 10 characters total
    int filledBars = (current * barWidth) / max;

    cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < filledBars)
            cout << "#";
        else
            cout << "-";
    }
    cout << "] " << current << "/" << max << " LP" << endl;
}

Miner displayStart(Miner p1)
{
    Miner tempStruct;
    cin.ignore();
    cout << "\nEnter your character's name: ";
    getline(cin, tempStruct.name);
    cout << "Enter your character's age: ";
    cin >> tempStruct.age;
    cout << "Enter your character's gender (m/f): ";
    cin.ignore();
    cin.get(tempStruct.gender);
    if (tempStruct.gender == 'm')
    {
        cout << R"(    
                  O
                 /|\   <-YOU
                 / \ )" << endl;
    }
    else if (tempStruct.gender == 'f')
    {
        cout << R"(    
                  O
                 /|\   <-YOU
                 /_\ )" << endl;
    }
    cout << "You start with 100 life points.\n";
    printLifeBar(100);
    cout << "Choose a number between 0-5";
    cout << "\n Hello " << tempStruct.name << "...\n";
    cout << "Choose a number between 0-5: ";
    cin.ignore();
    cin >> tempStruct.familySize;
    return tempStruct;
}

int day1(int age, char gender, string name, int& points)
{
    return 0;
}

int day2(int age, char gender, string name, int& points)
{
    return 0;
}

int day3(int age, char gender, string name, int& points)
{
    return 0;
}

int day4(int age, char gender, string name, int& points)
{
    return 0;
}

int day5(int age, char gender, string name, int& points)
{
    return 0;
}

void events()
{
    srand(time(0));
    int choice = rand() % 10;
    switch (choice)
    {
    case 0:
    {
        cout << R"( 
                           (   )
                         (      )
                        (______)__)
                          ' ' ' '
                           ' ' ' ' )" << endl;
        cout << "It rained heavily last night. The mine's weak walls couldn't handle the pressure. A portion collapsed while you were inside. You lose 5 LP.";
        lifePts -= 5;
        break;
    }
    case 1:
    {
        cout << R"( 
                          /\    
                         /  \   
                        /____\  
                        | [] |  
                        |____| )" << endl;
        cout << "Your family couldn't make rent. The landlord locked the door and threw your belongings into the street. You spent the night exposed and hungry. You lose 5 LP." << endl;
        lifePts -= 5;
        break;
    }
    case 2:
    {
        cout << R"( 
                           ___________
                          /           \
                         | ~ FLOODED ~ |
                         |__~__~__~__~_|)" << endl;
        cout << "Rainwater flooded one of the main shafts. You barely escaped before it filled completely. You're soaked and exhausted. You lose 5 LP." << endl;
        lifePts -= 5;
        break;
    }
    case 3:
    {
        cout << R"(
                        (-_-)
                         /|\ 
                         / \   )" << endl;
        cout << "A mosquito bite turned deadly. Fever, chills, and pain hit you all at once. You have malaria. You lose 5 LP." << endl;
        lifePts -= 5;
        break;
    }
    case 4:
    {
        cout << R"(
                              ______
                             | |    |
                             | |    |
                        _____|_|    |
                       (  (         |
                        \__\________|
                         
                         )" << endl;
            cout << "You found some shoes! You get 5 LP" << endl;
            lifePts+=5;

        
    }
    case 5:
    {
            cout << R"(
                             
              _
       $$    / \       _______
             \_/     / \
                    /   \
                   /     \
                          \
                           \
)" << endl;
            cout << "You found some cobalt! You get 5 LP." << endl;    
    }
    }
}
