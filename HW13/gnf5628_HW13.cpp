
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

    virtual void move() = 0;


private:

};

class Ant : public Organism {
public:

    Ant() {

        age = 0;

        // initializing the random guess variable
        int xLocation = (rand() % 20) ;
        int yLocation = (rand() % 20) ;
        xLoc = xLocation;
        yLoc = yLocation;
    }

    void move()  {
        // initializing the random guess variable
        int direction = (rand() % 4) + 1;

        //Move right
        if (direction == 1) {
            if(xLoc < 19) {
                xLoc++;
            }
        }
        //Move Left
        else if(direction == 2) {
            if(xLoc > 0) {
                xLoc--;
            }
        }
        //Move Up
        else if(direction == 3) {
            if(yLoc > 0){
                yLoc--;
            }
        }
        //Move down
        else if(direction == 4) {
            if(yLoc < 19) {
                yLoc++;
            }
        }

    }

    void breed() {

    }



private:
};

class Doodlebug : public Organism {
public:
    Doodlebug() {
        age = 0;

        int xLocation = (rand() % 20) ;
        int yLocation = (rand() % 20) ;
        xLoc = xLocation;
        yLoc = yLocation;

    }

    void move() {

    }

    void breed() {

    }

    void starve() {

    }

private:
};

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

bool isFull(vector<Ant> ants, int numAnts, vector<Doodlebug> bugs, int numBugs, int x, int y) {
    return false;
}

int main() {
    int step = 0, numAnts = 5, numBugs = 0;

    vector<Ant> ants;
    for (int a = 0; a < numAnts; a++) {
        ants.push_back(Ant());
    }

    vector<Doodlebug> bugs;
    for (int a = 0; a < numBugs; a++) {
        bugs.push_back(Doodlebug());
    }

    string input;

    cout << "Step: " << step << endl;

    drawBoard(ants, numAnts, bugs, numBugs);

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

        drawBoard(ants, numAnts, bugs, numBugs);

        for (int a = 0; a < numAnts; a++) {
            ants[a].move();
        }



    }


    return 0;

}