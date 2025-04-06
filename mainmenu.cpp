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
void raining();
void stayHome();
void goToMines();
void escape();
void stayAtWork();
void goBackToWork();
void goHome();
void flood();
//MAIN FUNCTION
int main() {
    displayHome();
    day1();

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
        cout << "\nYou are a cobalt miner in the Democratic Republic of Congo (DRC).\n" << endl;
        cout << "The morning is cold and damp. You, along with the other miners, \ngather at the entrance"
            << "to the cobalt mine. The ground is slippery, \nand the air is thick with dust "
            << "and the smell of wet rock." << endl;
        cout << "\nYou’ve started the week with 100 points, which represents "
            << "your life bar. \nBut this will not last forever, and every decision today will impact the \nrest of the week.\n"
            << "\nYour goal is to not die – that is, reach 0 in the health bar – by the end of the week.\n"
            << "Although the Democratic Republic of Congo (DRC) is abundant in natural resources, it \nremains the second "
            << "poorest country globally. The life expectancy in DRC is only 47 years \nfor men and 51 years for women. "
            << "This is significantly lower than the average of 81.2 \nyears in the UK.\n";
        cout << "\nWill *you* be able to survive the DRC?\n" << endl;
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
    raining();         
}

//void events()
//{
//    srand(time(0));
//    int choice = rand() % 10;
//    switch (choice)
//    {
//    case 0:
//    case 1:
//    case 2:
//    case 3:
//    case 5:
//    case 6:
//    case 7:
//    }
//}
void raining()
{
    char goToWork;
    cout << "It's raining this morning." << R"( 
                           (   )
                         (      )
                        (______)__)
                          ' ' ' '
                           ' ' ' ' )" << endl << "Will you go to work? (y / n) \n";
    cin >> goToWork;
    if (goToWork == 'y' || goToWork == 'Y')
        goToMines();
    else if (goToWork == 'n' || goToWork == 'N')
        stayHome();
}
void goToMines()
{
    char stayAtMine;
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
        << "The mine's weak ceiling couldn't handle the pressure from the rain. A portion collpses while you are inside. You lose 5 LP.\n\n";
    lifePts -= 5;
    printLifeBar(lifePts);
    //insert pickaxe here

    cout << "You rip off some of your shirt to use as a bandage and get back to work.\n After an hour you're really feeling fatigued. Should you go home for the day? (y/n) ";
    cin >> stayAtMine;
    //they leave
    if (stayAtMine == 'y' || stayAtMine == 'Y')
        goHome();
       // cout << "no $$$$";//idk yet maybe more money
    else if (stayAtMine == 'n' || stayAtMine == 'N')
        stayAtWork();


}
void stayAtWork()
{
    char leave;
    cout << "You earn more money for working longer. You gain 5 LP.";
    lifePts -= 5;
    printLifeBar(lifePts);

    cout << "The rain outside gets heavier. Rainwater floods one of the main shafts. Do you try to escape? (y/n) ";
    cin >> leave;

    if (leave == 'y' || leave == 'Y')
        escape();
    else if (leave == 'n' || leave == 'N')
        cout << "flood";
      flood();

}
void stayHome()
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
void flood()
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
void escape()
{
    cout << "You barely escape before it fills completely. You're soaked and exhausted. You lose 5 LP.\n\n";
    lifePts -= 5;
    printLifeBar(lifePts);
}
void goHome()
{
    cout << "You went home!";
}
