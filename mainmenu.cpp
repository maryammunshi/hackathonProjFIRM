#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int lifePts = 100;


//structs
struct Miner
{
    int age;
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
void pointDecrease();
bool dead();
void flood();
void foodSearch();
void hunt();
void search();
void bedTime();
void kwanga();
//MAIN FUNCTION
int main() {
    displayHome();
    day1();

    cout << endl;
    system("pause");
    return 0;
}


void displayHome()
{
    char key;
    cout << "  5 Days of Life in the Mines\n";
    cout << "------------------------------------\n";
    cout << "\nYou are a cobalt miner in the Democratic Republic of Congo (DRC).\nHow long can you survive?" << endl;
    person = displayStart(person);
}


void printLifeBar(int current) {
    int max = 100;
    int barWidth = 10; // show only 10 characters total
    int filledBars = (current * barWidth) / max;

    cout << "\n	\033[32m[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < filledBars)
            cout << "#"; //or cout<<\u2665;
        else
            cout << "-";
    }
    cout << "] " << current << "/" << max << " LP\033[0m" << endl;
}

Miner displayStart(Miner p1)
{
    Miner tempStruct;
    cout << "\nEnter character name: ";
    getline(cin, tempStruct.name);
    cout << "Enter character age: ";
    cin >> tempStruct.age;
    cout << "Enter character gender (m/f): ";
    cin.ignore();
    cin.get(tempStruct.gender);
    if (tempStruct.gender == 'm')
    {
        cout << "\033[34m" << R"(   
          O
         /|\   <- YOU
         / \ 
)" << "\033[0m" << endl << endl;
    }
    else if (tempStruct.gender == 'f')
    {
        cout << "\033[35m" << R"(    
                  O
                 /|\   <-YOU
                 /_\ )" << "\033[0m" << endl << endl;
    }
    cout << "You start with 100 life points.\n";
    printLifeBar(lifePts);
    return tempStruct;
}

void day1()
{
    raining();

    //cout << "The future looks bleak. Your family depends on you," 
      //      << "but without work, survival grows invreasingly difficult.\n";
    cout << "\nWill you go back to work tomorrow? Or will you risk it all staying"
        << " home and hope for a better outcome?\n";
}

void raining()
{
    char goToWork;
    cout << "\n\nIt's raining this morning." << "\033[34m" << R"( 
                           (   )
                         (      )
                        (______)__)
                          ' ' ' '
                           ' ' ' ' )" << "\033[0m" << endl << "Will you go to work? (y / n) ";
    cin >> goToWork;
    if (goToWork == 'y' || goToWork == 'Y')
        goToMines();
    else if (goToWork == 'n' || goToWork == 'N')
        stayHome();
}
void goToMines()
{
    char stayAtMine;
    cout << "\nYou arrive at the mine and descend.\n" << "You quickly get to work. The enivorment is toxic. ";
    pointDecrease();
    printLifeBar(lifePts);
    //insert pickaxe here
    cout << "\033[33m" << "\n\nYou are busy working, and don't notice the ceiling above you." << R"(
        _______________________________
        \                             /
         \   _____       _____       /
          \_/     \_____/     \_____/ 
              ---
             /   \
              ---  )" << "\033[0m" << endl
        << "The mine's weak ceiling couldn't handle the pressure from the rain. A portion collpses while you are inside.\n";
    pointDecrease();
    printLifeBar(lifePts);

    cout << "\n\nYou rip off some of your shirt to use as a bandage and get back to work.\nAfter an hour you're feeling fatigued. Should you go home for the day? (y/n) ";
    cin >> stayAtMine;
    //they leave
    if (stayAtMine == 'y' || stayAtMine == 'Y')
        foodSearch();
    else if (stayAtMine == 'n' || stayAtMine == 'N')
        stayAtWork();


}
void stayAtWork()
{
    char leave;
    cout << "\n\nYou earn more money for working longer, but you're risking your life to do so.\n";

    cout << "\n\nThe rain outside gets heavier. Rainwater floods one of the main shafts. Do you try to escape? (y/n) ";
    cin >> leave;

    if (leave == 'y' || leave == 'Y')
        escape();
    else if (leave == 'n' || leave == 'N')
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

    pointDecrease();
    printLifeBar(lifePts);

    cout << "You and your family are hungry.";
    foodSearch();
}
void flood()
{
    cout << "\n\nYou were too exhausted to escape. Luckily, a fellow miner rescued you. Unfortunatley, the damage was extensive."
        << R"(
                         (-_-)
                          /|\ 
                          / \   )"
        << "\n";
    pointDecrease();
    printLifeBar(lifePts);
}
void escape()
{
    cout << "You barely escape before it fills completely. You're soaked and exhausted.\n\n";
    pointDecrease();
    printLifeBar(lifePts);
}
void foodSearch()
{
    string foodSearch;
    cout << "\n\nYour leaving early means you don't have enough money to buy food.\n";
    cout << "You can try to hunt for an ape in the jungle or search for some wild fruits nearby.\n";
    cout << "What will you do? (hunt / search) ";

    cin >> foodSearch;

    if (foodSearch == "hunt")
        hunt();
    else if (foodSearch == "search")
        search();
}
void hunt()
{
    {
        cout << "\n\nYou venture into the jungle and after a few hours, you successfully track and kill an ape.\n";
        cout << "While the meat will feed you, the risk was great. It is illegal to hunt "
            << "for apes and dangerous too, but what else was there to eat?\n\n";
        pointDecrease();
        printLifeBar(lifePts);
        bedTime();
    }
}
void search()
{
    cout << "You spend the rest of the day searching for edible fruits but find little to satisfy your hunger. You're exhausted and still hungry\n\n";
    pointDecrease();
    printLifeBar(lifePts);
    bedTime();
}
void kwanga()
{
    cout << "You have little money, but you scrape enough together to "
        << "buy cassava to make kwanga (fermented cassava bread).\n";
    bedTime();
    return;
}
void bedTime()
{
    cout << "\n\nYou're exhausted, every bone aches. You crawl into bed in the inky blackness of the deep night.\n";
    cout << "\033[36m" << R"( 
                          /\    
                         /  \   
                        /____\  
                        | [] |  
                        |____| )" << "\033[0m" << endl;

}
void pointDecrease()
{
    if (person.age > 0 && person.age < 18)
    {
        if (person.gender == 'f')
        {
            lifePts -= 20;
            cout << "\n\033[31mYou lose 20 LP. \n\033[0m ";
        }
        else {
            lifePts -= 15;
            cout << "\n\033[31mYou lose 15 LP. \n\033[0m ";
        }

    }
    else if (person.gender == 'm')
    {
        lifePts -= 10;
        cout << "\n\033[31mYou lose 10 LP. \n\033[0m ";
    }
    else
    {
        lifePts -= 15;
        cout << "\n\033[31mYou lose 15 LP. \n\033[0m ";
    }
}
bool dead()
{
    if (lifePts <= 0)
    {
        return true;
    }
    return false;
}
