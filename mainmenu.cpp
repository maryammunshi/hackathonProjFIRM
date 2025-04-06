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
    char boolStayHome, stayAtMine, boolEscape;
    cout << "It's raining this morning." << R"( 
                           (   )
                         (      )
                        (______)__)
                          ' ' ' '
                           ' ' ' ' )" << endl << "Will you go to work? (y / n) \n";
    cin >> boolStayHome;

    //they go to the mines
    if (boolStayHome == 'y' || boolStayHome == 'Y')
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
            << "The mine's weak cieling couldn't handle the pressure from the rain. A portion collpses while you are inside. You lose 5 LP.\n\n";
        lifePts -= 5;
        printLifeBar(lifePts);
        //insert pickaxe here

        cout << "You rip off some of your shirt to use as a bandage and get back to work.\n After an hour you're really feeling fatigued. Should you go home for the day? (y/n) ";
        cin >> stayAtMine;
        
        //they leave
        if (stayAtMine == 'y' || stayAtMine == 'Y')
        {
            //idk yet maybe more money
        }

        //they stay
        else if (stayAtMine == 'n' || stayAtMine == 'N')
        {
            cout << "You earn more money for working longer. You gain 5 LP.";
            lifePts -= 5;
            printLifeBar(lifePts);

            cout << "The rain outside gets heavier. Rainwater floods one of the main shafts. Do you try to escape? (y/n) ";
            cin >> boolEscape;
            if (boolEscape == 'y' || boolEscape == 'Y')
            {
                cout << "You barely escape before it fills completely. You're soaked and exhausted. You lose 5 LP.\n\n";
                lifePts -= 5;
                printLifeBar(lifePts);
            }

            //give up
            else if (boolEscape == 'n' || boolEscape == 'N')
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
    else if (boolStayHome == 'n' || boolStayHome == 'N')
    {
        string foodSearch;
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

        // Consequence: Hunger or survival choices
        cout << "With no shelter and no money, you go without food for the day. Your stomach growls in hunger.\n";
        cout << "You realize you need to find food to survive. What will you do next?\n";

        cout << "You can try to hunt for an ape in the jungle or search for some wild fruits nearby.\n";
        cout << "What will you do? (hunt / search)\n";
        cin >> foodSearch;
        // Hunting for food:
        if (foodSearch == "hunt")
        {
            cout << "You venture into the jungle and after a few hours, you successfully track and kill an ape.\n";
            cout << "While the meat will feed you, the guilt weighs heavy on your conscience.\n";
            cout << "You lose 3 LP from the stress of killing an animal for food.\n";
            lifePts -= 3;
            printLifeBar(lifePts);
        }
        // Searching for fruits:
        else if (foodSearch == "search")
        {
            cout << "You spend the day searching for edible fruits but find little to satisfy your hunger.\n";
            cout << "You lose 2 LP from hunger and fatigue.\n";
            lifePts -= 2;
            printLifeBar(lifePts);
        }
    }

    // Consequence of staying home longer:
    cout << "\nAs the night falls, you realize you can't avoid your situation any longer. You are exhausted, hungry, and homeless.\n";
    cout << "The future looks bleak. Your family depends on you, but without work, survival grows increasingly difficult.\n";

    cout << "\nWill you go back to work tomorrow? Or will you risk it all staying home and hope for a better outcome?\n";

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
    case 6:
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
        lifePts += 5;


    }
    case 7:
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
