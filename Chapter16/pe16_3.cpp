// hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>

int main()
{
    std::ifstream file_txt("../pe16_3.txt");

    if(!file_txt) {
        std::cout << "Can't open file!\n";
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> wordlist;
    std::string word;
    while(file_txt >> word) {
        wordlist.push_back(word);
    }
    file_txt.close();

    auto len = wordlist.size();

    std::srand(std::time(nullptr));
    char play;
    std::cout << "Will you play a word game? <y/n> ";
    std::cin >> play;
    while (tolower(play) == 'y')
    {
        std::string target = wordlist[std::rand() % len];
        int length = target.length();
        std::string attempt(length, '-');
        std::string badchars;
        int guesses = 6;
        std::cout << "Guess my secret word. It has " << length
             << " letters, and you guess\n"
             << "one letter at a time. You get " << guesses
             << " wrong guesses.\n";
        std::cout << "Your word: " << attempt << std::endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            if (badchars.find(letter) != std::string::npos
                || attempt.find(letter) != std::string::npos) {
                std::cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == std::string::npos) {
                std::cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            } else {
                std::cout << "Good guess!\n";
                attempt[loc] = letter;
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != std::string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            std::cout << "Your word: " << attempt << std::endl;
            if (attempt != target) {
                if (badchars.length() > 0)
                    std::cout << "Bad choices: " << badchars << std::endl;
                std::cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            std::cout << "That's right!\n";
        else
            std::cout << "Sorry, the word is '" << target << "'.\n";

        std::cout << "Will you play another? <y/n> ";
        std::cin >> play;
    }

    std::cout << "Bye\n";

    return 0;
}
