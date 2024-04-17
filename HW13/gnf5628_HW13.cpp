#include <iostream>
#include <vector>

using namespace std;


class Organism {
public:

    int xLoc, yLoc, age;


    virtual void move() = 0;



private:

};

class Ant : public Organism {

public:
    Ant(){
        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        xLoc = xLocation;
        yLoc = yLocation;

    }

    void move() {

    }

};

class Doodlebug : public Organism {

public:

    Doodlebug() {
        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        xLoc = xLocation;
        yLoc = yLocation;

    }

    void move() {

    }

};

class Board {

public:

    void drawboard(){
        int rows = 20;
        int cols = 20;
        vector<char> aRow;
        for (int c = 0; c < cols; ++c) {
            aRow.push_back('-');
        }

        vector<vector<char> > world;

        for (int r = 0; r < rows; ++r) {
            world.push_back(aRow);
        }


        for (size_t rowI = 0; rowI < world.size(); ++rowI) {
            for (size_t colI = 0; colI < world[0].size(); ++colI) {
                cout << world[rowI][colI] << ' ';
            }
            cout << endl;
        }


    }

    void fillAnts(int& numAnts, vector<Ant>& ants) {
        for (int x = 0; x < numAnts; x++) {
            Ant tempAnt;
            ants.push_back(tempAnt);
        }
    }

    void fillBugs(int& numBugs, vector<Doodlebug>& bugs) {
        for (int x = 0; x < numBugs; x++) {
            Doodlebug tempBug;
            bugs.push_back(tempBug);
        }
    }


};


int main() {

    srand(time(0));

    Board playingBoard;
    vector<Ant>ants;
    int numAnts = 10;

    vector<Doodlebug>bugs;
    int numBugs = 5;



    playingBoard.drawboard();

    //Create Vector of Ants
    playingBoard.fillAnts(numAnts,ants);

    for (int x = 0; x < numAnts; x++) {
        cout << "Ant " << x+1 << ": (" << ants[x].xLoc << ", " << ants[x].yLoc << ")" << endl;
    }

    //Create Vector of Bugs
    playingBoard.fillBugs(numBugs,bugs);

    for (int x = 0; x < numBugs; x++) {
        cout << "Bug " << x+1 << ": (" << bugs[x].xLoc << ", " << bugs[x].yLoc << ")" << endl;
    }





}

