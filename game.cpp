#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int lifePts = 100;

//show life bar
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
    cout << "] " << current << "/" << max << " HP" << endl;
}

struct Miner
{
    int age, familySize;
    char gender;
    string name;

};
Miner person;

void displayHome();
Miner displayStart(Miner);
int day1(int, char, string, int&);
int day2(int, char, string, int&);
int day3(int, char, string, int&);
int day4(int, char, string, int&);
int day5(int, char, string, int&);

//MAIN FUNCTION
int main() {
    printLifeBar(62);
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
Miner displayStart(Miner p1)
{
    Miner tempStruct;
    cin.ignore();
    cout << "\nEnter name: ";
    getline(cin, tempStruct.name);
    cout << "Enter age: ";
    cin >> tempStruct.age;
    cout << "Enter gender (m/f): ";
    cin.ignore();
    cin.get(tempStruct.gender);
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