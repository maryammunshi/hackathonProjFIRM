//
//  main.cpp
//  hackthenestProjFIRM
//
//  Created by mimi munshi on 4/5/25.
//

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

struct Miner
{
    int age;
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
void disaster();

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
void disaster()
{
    srand(time(0));
    int choice = rand() % 10;
    
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }
}
