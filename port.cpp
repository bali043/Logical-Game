#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char generateRandomChoice()
{
    char choices[] = {'S', 'W', 'G'};
    int randomIndex = rand() % 3;
    return choices[randomIndex];
}

char determineWinner(char cpu, char user)
{
    if (cpu == user)
        return 'T';
    else if ((cpu == 'S' && user == 'G') || (cpu == 'W' && user == 'S') || (cpu == 'G' && user == 'W'))
        return 'U';
    else
        return 'C';
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    char playAgain; // Variable to store user's choice to play again or exit

    do
    {
        cout << "Enter S, W, or G: ";
        char userChoice;
        cin >> userChoice;

        char cpuChoice = generateRandomChoice();
        char winner = determineWinner(cpuChoice, userChoice);

        cout << "CPU: " << cpuChoice << "\nUser: " << userChoice << "\nThe winner is: ";
        if (winner == 'T')
            cout << "Tied" << endl;
        else if (winner == 'U')
            cout << "User" << endl;
        else
            cout << "CPU" << endl;

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y'); // Continue if 'Y' or 'y'

    return 0;
}
