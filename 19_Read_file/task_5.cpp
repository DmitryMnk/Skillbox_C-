#include <iostream>
#include <fstream>
#include <limits>
#include <numeric>
#include <string>

bool isValidInput() {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void getQuestion(std::string* question, int sektor)
{
    std::fstream file;
    std::string path = "data//sektor_" + std::to_string(sektor) + ".txt";
    file.open(path);
    getline(file, *question);
    file.close();
}

void getAnswer(std::string* answer, int sektor)
{
    std::fstream file;
    std::string path = "data//sektor_" + std::to_string(sektor) + "_answer.txt";
    file.open(path);
    file >> *answer;
    file.close();
}

int main()
{
    int push,
        activeSektor = 1,
        playersScores = 0,
        viwersScores = 0;

    bool states[13];
    std::string question,
                playerAnswer,
                answer;

    for (int i = 0; i < 13; i++)
    {
        states[i] = false;
    }

    while(playersScores < 6 && viwersScores < 6)
    {

        std::cout << "Enter push: ";
        std::cin >> push;

        while (!isValidInput())
        {
            std::cout << "Error! Try again: ";
            std::cin >> push;
        }

        int sektor = (activeSektor + push) % 13;
        sektor == 0 ? activeSektor = 13 : activeSektor = sektor;

        while (states[activeSektor - 1])
        {
            activeSektor = (activeSektor + 1) % 13;
            if (activeSektor == 0)
            {
                activeSektor = 13;
            }
        }

        states[activeSektor - 1] = true;
        getQuestion(&question, activeSektor);
        std::cout << question << std::endl;

        std::cout << "Enter answer: ";
        std::cin >> playerAnswer;

        getAnswer(&answer, activeSektor);

        std::cout << "True answer is: " << answer << std::endl;

        if (answer == playerAnswer)
        {
            playersScores += 1;
            std::cout << "Correct! Players get 1 score" << std::endl;
        } else
        {
            viwersScores += 1;
            std::cout << "Incorrect! Viewers get 1 score" << std::endl;    
        }

        std::cout << "Players scores: " << playersScores << std::endl;
        std::cout << "Viewers scores: " << viwersScores << std::endl;
    }

    if (viwersScores == 6)
    {
        std::cout << "Viewrs win!" << std::endl;
    } else
    {
        std::cout << "Players win!" << std::endl;
    }

    return 0;

}