#include <iostream>
#include <fstream>
#include <vector>

void findWord(std::vector<std::string> vec, std::string s_word, int* count)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == s_word)
        {
            *count += 1;
        }
    }
}

int main()
{
    std::string seeking_word = "sister";
    std::fstream words;
    int w_count = 0;
    words.open("words.txt");
    std::vector<std::string> words_vec; 
    while (!words.eof())
    {
        std::string word;
        words >> word;
        words_vec.push_back(word);
    }
    words.close();

    findWord(words_vec, seeking_word, &w_count);
    std::cout << "Word \"" << seeking_word << "\" appears " << w_count << " times." << std::endl;
    return 0;
}