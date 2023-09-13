// Lab5_CGT215.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void cypherMessage(string& message) {
    vector<char> cypher = { 'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E' };

    //loop message
    for (int i = 0; i < message.length(); i++) {
        //get ascii number of current char
        int asciiVal(message[i]);

        if (asciiVal >= 65 && asciiVal <= 90) {
            //is a capital letter
            asciiVal -= 65;
            message[i] = cypher[asciiVal];
        }
        else if (asciiVal >= 97 && asciiVal <= 122) {
            //lowercase letter
            asciiVal -= 97;
            message[i] = tolower(cypher[asciiVal]);
        }
    }

}

int main()
{
    int running(1);
    string ShouldEnd;
    string message;

    while (running != 0) {
        cout << "Enter your message to be cyphered: ";
        getline(cin, message);
        //cypher text function & pass by value
        cypherMessage(message);
        cout << "Your cyphered message: " << message << endl;
        cout << "Would you like to continue (y/n)?: ";
        cin >> ShouldEnd;

        //checking if should end
        ShouldEnd == "n" ? running = 0 : running = 1;
        if (running) {
            message.clear();
            //clearing cin buffer
            cin.ignore();
        }
    }
}