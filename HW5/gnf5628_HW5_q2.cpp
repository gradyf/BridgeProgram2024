
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {

    //Creating the random answer variable
    int rand_ans;

    //creating and initializing the bounds
    int lower_bound = 1, upper_bound = 100;

    //variable for the user to guess the random variable.
    int guess;

    //tracker variable for how many guesses there has been
    int count = 5;

    //setting the seed for the random quess variable
    srand(time(0));

    // initializing the random guess variable
    rand_ans = (rand() % 100) + 1;

    cout << rand_ans << endl;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;


    while (count > 0) {
        cout << "Range: [" << lower_bound << ", " << upper_bound << "], "
             << "Number of guesses left: " << count << endl;

        cout << "Your guess: ";
        cin >> guess;
        count--;

        if (guess == rand_ans) {
            cout << "Correct! You guessed my number in " << (5 - count) << " guesses";
            count = -1;
            break;
        }
        else if (guess > rand_ans) {
            cout << "Wrong! My number is smaller." << endl;
            upper_bound = guess;
        }
        else if (guess < rand_ans) {
            cout << "Wrong! My number is bigger." << endl;
            lower_bound = guess;
        }


    }


    if (count == 0) {
        cout << "Out of guesses! My number is " << rand_ans;
    }
}