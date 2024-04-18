#include <iostream>
#include <vector>

using namespace std;

enum Type { // Look up why we're doing this
    ANT = 1,
    DOODLEBUG = 2
};


class Organism {
public:

    Type orgType;
    int breed;
    bool recently_moved;

    Organism(Type type) {

        orgType = type;
        breed = 0;
        recently_moved = false;

    }

    virtual  ~Organism() = default;
    virtual void move() = 0;
    virtual Type getType() const = 0;
    virtual bool getMoved() const = 0;
    virtual void resetMoveState() = 0;
    virtual void resetBreed() = 0;
    virtual int getBreed() const = 0;
    virtual int getStarve() const { return 0; };
    virtual void resetStarve() {};

    virtual char getSymbol() = 0;


private:

};

class Ant : public Organism {

public:

    Ant() : Organism(Type::ANT) {}

    void move();
    bool get

    char getSymbol() {
        return 'O';
    }


};

class Doodlebug : public Organism {

public:

    Doodlebug(int x, int y) {

        rowLoc = x;
        colLoc = y;
        age = 0;

    }

    Doodlebug() {

        int xLocation = (rand() % 20);
        int yLocation = (rand() % 20);
        rowLoc = xLocation;
        colLoc = yLocation;

        age = 0;

    }

    void move() {

    }

    char getSymbol() {
        return 'X';
    }

};

void fillAnts(int &numAnts, vector<Ant *> &ants) {
    for (int x = 0; x < numAnts; x++) {
        Ant *tempAnt = new Ant();
        ants.push_back(tempAnt);
    }
}

void fillBugs(int &numBugs, vector<Doodlebug *> &bugs) {
    for (int x = 0; x < numBugs; x++) {
        Doodlebug *tempBug = new Doodlebug();
        bugs.push_back(tempBug);
    }
}

void printBoard(vector<vector<Organism *> > world) {
    for (size_t rowI = 0; rowI < world.size(); ++rowI) {
        for (size_t colI = 0; colI < world[0].size(); ++colI) {
            if (world[rowI][colI] == nullptr) {
                cout << " - ";
            } else {
                cout << " " << world[rowI][colI]->getSymbol() << " ";
            }

        }
        cout << endl;
    }
}

bool legal(vector<vector<Organism *> > world,int row, int col) {
    if(world[row][col] == nullptr) {
        return true;
    }
    else{
        return false;
    }
}



int main() {

    srand(time(0));

    vector<Ant *> ants;
    int numAnts = 100;
    fillAnts(numAnts, ants);

    vector<Doodlebug *> bugs;
    int numBugs = 5;
    fillBugs(numBugs, bugs);

    int step = 0;


    int rows = 20;
    int cols = 20;

    vector<Organism *> aRow;

    for (int c = 0; c < cols; ++c) {
        aRow.push_back(NULL);
    }

    vector<vector<Organism *> > world;

    for (int r = 0; r < rows; ++r) {
        world.push_back(aRow);
    }

    for (Ant *ant: ants) {
        world[ant->rowLoc][ant->colLoc] = ant;
    }

    for (Doodlebug *bug: bugs) {
        world[bug->rowLoc][bug->colLoc] = bug;
    }

    cout << "Step: " << step << endl;
    printBoard(world);

    cout << endl;

    while (true) {
        step++;

        string temp;

        getline(cin, temp);

        if (temp != "") {
            break;
        }

        cout << "Step: " << step << endl;
        printBoard(world);

    }

}
