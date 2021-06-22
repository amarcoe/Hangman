//  Began June 3 2021
//  Worked on June 4 2021
//  Worked on June 8 2021
//  Hangman

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>

using namespace std;


int wordChoice();
void hangman(int fail);

int main() {
    ifstream fin;
    fin.open("/Users/amarcoe/Desktop/OneDrive/Hangman/Hangman/words.txt");
    
    if (!fin){
        cout << "ERROR: The file did not open" << endl;
    }
    
    char word[10], blank[10], wrong_guesses[6];
    int line = wordChoice();
    int fail = -1, correct = 0, fail_check = 0, length = 0;
    char guess;
        
    for (int i = 0; i < line; i++){
        fin.getline(word, 10);
    }
    
    hangman(fail);
    
    fail = fail + 1;
    
    for (int i = 0; i < 10; i++){
    /*
     This loop sets the array blank to have an _ if the character in the array word is alphabetic and outputs an _ for each character.
     */
        if (isalpha(word[i])){
            blank[i] = '_';
            length++;
        }
        else{
            break;
        }
    }
    cout << setw(22) << "Your word is " << length << " letters long" << endl;
    cout << setw(30) << blank << endl;
        
    while((correct < length) && (fail != 6)){
    /*
    Loop begins by taking in player's guess.  It then sets fail_check equal to correct so that if correct doesn't go up then they are equal and there was a wrong guess.  The second loop checks if the guess is the same as any letter in the array word, if it is the _ in blank is set to the letter and correct goes up.  After that it outputs blank so the player knows what the word looks like now and checks the copies.
    */
        cout << "Guess a single letter: ";
        cin >> guess;
        guess = tolower(guess);
        
        fail_check = correct;
        
        for (int j = 0; j < 10; j++){
            if (isalpha(word[j]) && word[j] == guess){
                blank[j] = guess;
                correct++;
                }
        }
        
        if (fail_check >= correct){
            wrong_guesses[fail] = guess;
            fail++;
            hangman(fail);
        }
        else {
            hangman(fail);
        }
        
        cout << "Your wrong guesses are: ";
        for (int j = 0; j < fail; j++){
            cout << wrong_guesses[j] << " ";
        }
        
        cout << endl;
        cout << setw(30) << blank << endl;
        cout << endl;
        
    }
    if (fail == 6){
    cout << "Your word was ";
    for (int i = 0; i < 10; i++){
        cout << word[i];
        }
        cout << endl;
    }
    
    
    return 0;
}

int wordChoice(){
    ifstream fin;
    fin.open("/Users/amarcoe/Desktop/OneDrive/Hangman/Hangman/words.txt");
    
    if (!fin){
        cout << "ERROR: The file did not open" << endl;
    }
    
    int num_list[20];
    
    char word[10];
    int num_lines = 0;
    int line = 0;
    
    while (fin.getline(word, 10)){
        num_lines++;
        if (fin.eof()){
            break;
        }
    }
    
    srand(time(0));
    for (int i = 0; i < 20; i++){
        num_list[i] =  ((rand() % num_lines) + 1);
    }
    
    for (int i = 0; i < (rand() % 10) + 1; i++){
        line = num_list[i];
    }
    
    fin.close();
    
    return line;
}

void hangman(int fail){
    switch (fail) {
        case 0:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|    \n";
            cout << setw(29) << "|     " << endl;
            cout << setw(29) << "|     " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        case 1:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   O\n";
            cout << setw(29) << "|     " << endl;
            cout << setw(29) << "|     " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        case 2:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   O\n";
            cout << setw(29) << "|   | " << endl;
            cout << setw(29) << "|     " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        case 3:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   O\n";
            cout << setw(30) << "|   |\\ " << endl;
            cout << setw(29) << "|     " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        case 4:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   O\n";
            cout << setw(30) << "|  /|\\ " << endl;
            cout << setw(29) << "|     " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        case 5:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   O\n";
            cout << setw(30) << "|  /|\\ " << endl;
            cout << setw(30) << "|    \\ " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        case 6:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   O\n";
            cout << setw(30) << "|  /|\\ " << endl;
            cout << setw(30) << "|  / \\ " << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            break;
        default:
            cout << setw(39) << "————-- \n";
            cout << setw(30) << "|   | \n";
            cout << setw(29) << "|   o\n";
            cout << setw(29) << "|  /|\\" << endl;
            cout << setw(29) << "|  / \\" << endl;
            cout << setw(30) << "|     \n";
            cout << setw(44) << "--——————\n";
            cout << "To win hangman you must guess all the letters in the word before all the limbs can be attatched to the man." << endl;
            cout << endl;
            break;
    }
}
