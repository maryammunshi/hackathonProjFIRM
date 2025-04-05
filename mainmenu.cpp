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
void day1();

//MAIN FUNCTION
int main() {
    day1();
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
    cout << "\nEnter character name: ";
    getline(cin, tempStruct.name);
    cout << "Enter character age: ";
    cin >> tempStruct.age;
    cout << "Enter character gender (m/f): ";
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
    printLifeBar(lifePts);
    cout << "Choose a number between 0-5";
    cout << "\n Hello " << tempStruct.name << "...\n";
    cout << "Choose a number between 0-5: ";
    cin.ignore();
    cin >> tempStruct.familySize;
    return tempStruct;
}

void day1()
{
    char response1, response2, response3;

    cout << "It's raining this morning." << R"( 
                           (   )
                         (      )
                        (______)__)
                          ' ' ' '
                           ' ' ' ' )" << endl << "Will you go to work? (y / n) \n";
    cin >> response1;

    //they go to the mines
    if(response1 == 'y' || response1 == 'Y') 
    {
        cout << "You arrive at the mine and decend.\n" << "You are the first one in and find a new pickaxe. You gain 5 LP.\n\n";
        lifePts += 5;
        printLifeBar(lifePts);
        //insert pickaxe here

        cout << "\nYou are busy working, and don't notice the ceiling above you." << R"(
        _______________________________
        \                             /
         \   _____       _____       /
          \_/     \_____/     \_____/ 
              ---
             /   \
              ---  )" << endl 
        <<"The mine's weak cieling couldn't handle the pressure from the rain. A portion collpses while you are inside. You lose 5 LP.\n\n";
        lifePts -= 5;
        printLifeBar(lifePts);

        cout << "\nYou rip off some of your shirt to use as a bandage and get back to work.\nAfter an hour you're really feeling fatigued. Should you go home for the day? (y/n) ";
        cin >> response2;

        //they leave
        if (response2 == 'y' || response2 == 'Y')
        {
            //idk yet maybe more money
        }
        //they stay
        else if (response2 == 'n' || response2 == 'n')
        {
            cout << "\n\nYou earn more money for working longer. You gain 5 LP.\n\n";
            lifePts -= 5;
            printLifeBar(lifePts);

            cout << "\nThe rain outside gets heavier. Rainwater floods one of the main shafts."
                << R"( 
                           ___________
                          /           \
                         | ~ FLOODED ~ |
                         |__~__~__~__~_|)" 
                << "\nDo you try to escape? (y/n) ";
            cin >> response3;
            //escape
            if (response3 == 'y' || response3 == 'Y')
            {
                cout << "You barely escape before it fills completely. You're soaked and exhausted. You lose 5 LP.\n\n";
                lifePts -= 5;
                printLifeBar(lifePts);
            }
            //give up
            else if (response3 == 'n' || response3 == 'n')
            {
                cout << "You were too exhausted to escape. Luckily, a fellow miner rescued you. Unfortunatley, the damage was extensive." 
                    << R"(
                        (-_-)
                         /|\ 
                         / \   )"
                    << "\nYou lose 20 LP.\n\n";
                lifePts -= 20;
                printLifeBar(lifePts);
            }
        }
    }

    //they dont go to the mines
    else if (response1 == 'n' || response1 == 'N')
    {
        cout << "You don't get paid so you can't make rent. The landlord locks the door and throws your belongings into the street.\n";
        cout << R"( 
                          /\    
                         /  \   
                        /____\  
                        | [] |  
                        |____| )" << endl;

        cout << "You lose 5 LP.\n" << endl;
        lifePts -= 5;
        printLifeBar(lifePts);
    }
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
    case 5:
    {
        cout << R"(
                         |\
                         |==>
                         |/  )" << endl;
        cout << "You were starving. With no other food available, you tracked and killed an ape. It gave you meat, but the guilt remains. You lose 3 LP." << endl;
        lifePts -= 5;
        break;
    }
    
    }
}
