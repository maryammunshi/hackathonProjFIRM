//
//  main.cpp
//  hackthenestProjFIRM
//
//  Created by mimi munshi on 4/5/25.
//

#include <iostream>
#include <string>

using namespace std;

int lifePts = 100;

struct Miner
{
    int age;
    char gender;
    string name;
    
};

void displayHome();
void displayStart(Miner);
int day1(int, char, string, int&);
int day2(int, char, string, int&);
int day3(int, char, string,int&);
int day4(int, char, string, int&);
int day5(int, char, string, int&);


int main() {
    
    displayHome();
    
    
    return 0;
}

void displayHome()
{
    char key;
    Miner person;
    cout << "  5 Days of Life in the Mines\n";
    cout << "------------------------------------\n";
    cout << "PRESS S TO START, ANY OTHER KEY TO QUIT: ";
    cin.get(key);
    if (key == 's' || key == 'S')
    {
        displayStart(person);
    }
    else
    {
        cout << "\nYou chose to quit.\n";
        return;
    }
  
    
    
    
}
void displayStart(Miner p1)
{
    
    cout << "\nEnter name: ";
    cin.ignore();
    getline(cin, p1.name);
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "Enter gender (m/f): ";
    cin.ignore();
    cin.get(p1.gender);
 
}

int day1(int age, char gender, string name, int &points)
{
    return 0;
}

int day2(int age, char gender, string name, int &points)
{
    return 0;
}

int day3(int age, char gender, string name, int &points)
{
    return 0;
}

int day4(int age, char gender, string name, int &points)
{
    return 0;
}

int day5(int age, char gender, string name, int &points)
{
    return 0;
}
