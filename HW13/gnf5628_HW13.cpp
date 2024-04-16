
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


class Organism {
public:

    int xLoc, yLoc, age;

    static int number;

    virtual void move(vector<int> spaces) = 0;

    virtual void ageUp() = 0;


private:

};

class Ant : public Organism {
public:


    Ant(int x, int y) {

        age = 0;

        // initializing the random guess variable

        xLoc = x;
        yLoc = y;
    }

    Ant() {

        age = 0;

        // initializing the random guess variable
        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        xLoc = xLocation;
        yLoc = yLocation;
    }


    void move(vector<int> spaces) {

        if (spaces.size() != 0) {

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


    }


    void breed(vector<int> spaces, vector<Ant> &ants, int &numAnts) {

        if (age >= 3) {

            if (spaces.size() != 0) {

                int direction = (rand() % spaces.size());
                //Breed right
                if (spaces[direction] == 1) {
                    if (xLoc < 19) {
                        ants.push_back(Ant(xLoc + 1, yLoc));
                        numAnts++;
                    }
                }
                    //Breed Left
                else if (spaces[direction] == 2) {
                    if (xLoc > 0) {
                        ants.push_back(Ant(xLoc - 1, yLoc));
                        numAnts++;

                    }
                }
                    //Breed Up
                else if (spaces[direction] == 3) {
                    if (yLoc > 0) {
                        ants.push_back(Ant(xLoc, yLoc - 1));
                        numAnts++;

                    }
                }
                    //Breed down
                else if (spaces[direction] == 4) {
                    if (yLoc < 19) {
                        ants.push_back(Ant(xLoc, yLoc + 1));
                        numAnts++;

                    }
                }

            }

            age = 0;
        }

    }

    void ageUp() {
        age++;
    }


private:

};

class Doodlebug : public Organism {
public:

    int ageEating;

    Doodlebug(int x, int y) {
        age = 0;
        ageEating = 0;

        xLoc = x;
        yLoc = y;

    }

    Doodlebug() {
        age = 0;
        ageEating = 0;

        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        xLoc = xLocation;
        yLoc = yLocation;

    }

    void move(vector<int> spaces) {

        if (spaces.size() != 0) {

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


    }

    void breed(vector<int> spaces, vector<Doodlebug> &bugs, int &numBugs) {

        if (age >= 8) {

            if (spaces.size() != 0) {

                int direction = (rand() % spaces.size());
                //Breed right
                if (spaces[direction] == 1) {
                    if (xLoc < 19) {
                        bugs.push_back(Doodlebug(xLoc + 1, yLoc));
                        numBugs++;
                    }
                }
                    //Breed Left
                else if (spaces[direction] == 2) {
                    if (xLoc > 0) {
                        bugs.push_back(Doodlebug(xLoc - 1, yLoc));
                        numBugs++;

                    }
                }
                    //Breed Up
                else if (spaces[direction] == 3) {
                    if (yLoc > 0) {
                        bugs.push_back(Doodlebug(xLoc, yLoc - 1));
                        numBugs++;


                    }
                }
                    //Breed down
                else if (spaces[direction] == 4) {
                    if (yLoc < 19) {
                        bugs.push_back(Doodlebug(xLoc, yLoc + 1));
                        numBugs++;

                    }
                }

            }

            age = 0;
        }

    }

    bool starve() {

        if (ageEating >= 8) {
            return true;
        } else {
            return false;
        }

    }

    void ageUp() {
        age++;
        ageEating++;
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

    void cleanAnts(vector<Ant> &ants, int numAnts) {
        bool cont = true;

        while (cont) {
            bool swapped = true;

            if (swapped) {
                swapped = false;
                for (int x = 0; x < numAnts; x++) {
                    for (int y = x + 1; y < numAnts; y++) {
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
                for (int x = 0; x < numBugs; x++) {
                    for (int y = 0; y < numBugs; y++) {
                        if (x != y) {
                            if (bugs[x].xLoc == bugs[y].xLoc && bugs[x].yLoc == bugs[y].yLoc) {
                                bugs[x].xLoc++;
                                bugs[x].yLoc++;
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

    srand(time(0));

    Board playingBoard;
    int step = 0, numAnts = 0, numBugs = 5;

    vector<Ant> ants(numAnts);

    vector<Doodlebug> bugs(numBugs);

    playingBoard.cleanAnts(ants, numAnts);
    playingBoard.cleanBugs(bugs, numBugs);

    string input;

    cout << "Step: " << step << endl;

    playingBoard.drawBoard(ants, numAnts, bugs, numBugs);


    while (true) {

        getline(cin, input);

        if (!input.empty()) {
            break;
        }
        step++;

        for (int x = 0; x < 21; x++) {
            cout << endl;
        }

        cout << "Step: " << step << endl;

        playingBoard.drawBoard(ants, numAnts, bugs, numBugs);

        for (int b = 0; b < numBugs; b++) {

            bugs[b].move(playingBoard.legalSpaces(ants, numAnts, bugs, numBugs, bugs[b].xLoc, bugs[b].yLoc));

            bugs[b].ageUp();

            if(bugs[b].starve()) {
                bugs.erase(b);
                numBugs--;

            }

            bugs[b].breed(playingBoard.legalSpaces(ants, numAnts, bugs, numBugs, bugs[b].xLoc, bugs[b].yLoc), bugs,
                          numBugs);

        }


        for (int a = 0; a < numAnts; a++) {

            ants[a].move(playingBoard.legalSpaces(ants, numAnts, bugs, numBugs, ants[a].xLoc, ants[a].yLoc));

            ants[a].ageUp();

            ants[a].breed(playingBoard.legalSpaces(ants, numAnts, bugs, numBugs, ants[a].xLoc, ants[a].yLoc), ants,
                          numAnts);


        }

//        for (int a = 0; a < numAnts; a++) {
//
//            cout << "Ant: " << a + 1 << " (" << ants[a].xLoc << ", " << ants[a].yLoc << "), age: " << ants[a].age
//                 << endl;
//
//        }


    }


    return 0;

}