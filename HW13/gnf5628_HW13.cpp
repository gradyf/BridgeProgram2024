
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Organism {
public:

    int xLoc, yLoc, age;

    int number;

    virtual void move(vector<int> spaces) = 0;

    virtual void ageUp() = 0;


private:

};

class Ant : public Organism {
public:

    Ant() {

        age = 0;

        // initializing the random guess variable
        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        xLoc = xLocation;
        yLoc = yLocation;
    }


    void move(vector<int> spaces) {


        int direction = (rand() % spaces.size());

        //move right
        if (spaces[direction] == 1) {
            if (xLoc < 19) {
                xLoc++;
            }
        }
            //Move Left
        else if (spaces[direction] == 2) {
            if (xLoc > 0) {
                xLoc--;
            }
        }
            //Move Up
        else if (spaces[direction] == 3) {
            if (yLoc > 0) {
                yLoc--;
            }
        }
            //Move down
        else if (spaces[direction] == 4) {
            if (yLoc < 19) {
                yLoc++;
            }
        }

    }


    void breed() {

    }

    void ageUp() {
        age++;
    }


private:

};

class Doodlebug : public Organism {
public:
    Doodlebug() {
        age = 0;

        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        xLoc = xLocation;
        yLoc = yLocation;

    }

    void move(vector<int> spaces) {

    }

    void breed() {

    }

    void starve() {

    }

    void ageUp() {
        age++;
    }

private:
};

class Board {
public:

    void drawBoard(vector<Ant> ants, int numAnts, vector<Doodlebug> bugs, int numBugs) {

        bool printed;

        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 20; x++) {
                printed = false;
                for (int a = 0; a < numAnts; a++) {
                    if (ants[a].xLoc == x && ants[a].yLoc == y) {
                        cout << " O ";
                        printed = true;
                    }
                }
                for (int b = 0; b < numBugs; b++) {
                    if (bugs[b].xLoc == x && bugs[b].yLoc == y) {
                        cout << " X ";
                        printed = true;
                    }
                }
                if (!printed) {
                    cout << " - ";
                }
            }
            cout << endl;

        }
    }

    vector<int> legalSpaces(vector<Ant> ants, int numAnts, vector<Doodlebug> bugs, int numBugs, int x, int y) {
        vector<int> legalSpaces;
        bool right = true; // 1
        bool left = true; // 2
        bool up = true; // 3
        bool down = true; // 4

        vector<Organism> combined;

        for (int a = 0; a < numAnts; a++) {
            //check right
            if (ants[a].xLoc == (x + 1) && ants[a].yLoc == y) {
                right = false;
            }
            //check left
            if (ants[a].xLoc == (x - 1) && ants[a].yLoc == y) {
                left = false;
            }
            //check up
            if (ants[a].xLoc == (x) && ants[a].yLoc == (y - 1)) {
                up = false;
            }
            //check down
            if (ants[a].xLoc == (x) && ants[a].yLoc == (y + 1)) {
                down = false;
            }

        }

        for (int b = 0; b < numBugs; b++) {
            //check right
            if (bugs[b].xLoc == (x + 1) && bugs[b].yLoc == y) {
                right = false;
            }
            //check left
            if (bugs[b].xLoc == (x - 1) && bugs[b].yLoc == y) {
                left = false;
            }
            //check up
            if (bugs[b].xLoc == (x) && bugs[b].yLoc == (y - 1)) {
                up = false;
            }
            //check down
            if (bugs[b].xLoc == (x) && bugs[b].yLoc == (y + 1)) {
                down = false;
            }

        }

        if (right) {
            legalSpaces.push_back(1);
        }
        if (left) {
            legalSpaces.push_back(2);
        }
        if (up) {
            legalSpaces.push_back(3);
        }
        if (down) {
            legalSpaces.push_back(4);
        }


        return legalSpaces;


    }

    void cleanAnts(vector<Ant> ants, int numAnts) {
        bool cont = true;

        while (cont) {
            bool swapped = true;

            if (swapped) {
                swapped = false;
                for (int x = 0; x < numAnts; x++) {
                    for (int y = 0; y < numAnts; y++) {
                        if (x != y) {
                            if (ants[x].xLoc == ants[y].xLoc && ants[x].yLoc == ants[y].yLoc) {
                                ants[x].xLoc++;
                                ants[x].yLoc++;
                                swapped = true;
                            }
                        }
                    }
                }

            }
            if (!swapped) {
                cont = false;
            }

        }

    }


    void cleanBugs(vector<Doodlebug> bugs, int numBugs) {
        bool cont = true;

        while (cont) {
            bool swapped = true;

            if (swapped) {
                swapped = false;
                for (int x = 0; x < numAnts; x++) {
                    for (int y = 0; y < numAnts; y++) {
                        if (x != y) {
                            if (ants[x].xLoc == ants[y].xLoc && ants[x].yLoc == ants[y].yLoc) {
                                ants[x].xLoc++;
                                ants[x].yLoc++;
                                swapped = true;
                            }
                        }
                    }
                }

            }
            if (!swapped) {
                cont = false;
            }

        }

    }


};


int main() {

    Board playingBoard;
    int step = 0, numAnts = 100, numBugs = 0;

    vector<Ant> ants;
    for (int a = 0; a < numAnts; a++) {
        ants.push_back(Ant());
    }

    vector<Doodlebug> bugs;
    for (int a = 0; a < numBugs; a++) {
        bugs.push_back(Doodlebug());
    }

    for (int a = 0; a < numAnts; a++) {
        cout << "Ant: " << a + 1 << ", (" << ants[a].xLoc << ", " << ants[a].yLoc << ")" << endl;
    }

//    string input;
//
//    cout << "Step: " << step << endl;
//
//    playingBoard.drawBoard(ants, numAnts, bugs, numBugs);
//
//    while (true) {
//
//        getline(cin, input);
//
//        if (!input.empty()) {
//            break;
//        }
//        step++;
//
//        for (int x = 0; x < 21; x++) {
//            cout << endl;
//        }
//
//        cout << "Step: " << step << endl;
//
//        playingBoard.drawBoard(ants, numAnts, bugs, numBugs);
//
//        for (int a = 0; a < numAnts; a++) {
//
//            ants[a].move(playingBoard.legalSpaces(ants, numAnts, bugs, numBugs, ants[a].xLoc, ants[a].yLoc));
//            ants[a].ageUp();
//        }
//
//
//
//    }


    return 0;

}