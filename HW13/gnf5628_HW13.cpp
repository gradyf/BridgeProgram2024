
#include <iostream>
#include <string>

using namespace std;

class Organism {
public:
    Organism();

    virtual void move() = 0;

private:

};

class Ant : public Organism {
public:
    Ant();

    void move() {

    }

    void breed() {

    }

private:
};

class Doodlebug : public Organism {
public:
    Doodlebug();

    void move() {

    }

    void breed() {

    }

    void starve() {

    }

private:
};

void drawBoard() {

    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            cout << " - ";
        }
        cout << endl;
    }
}

int main() {
    int step = 0;

    string input;

    cout << "Step: " << step << endl;

    drawBoard();

    while (true) {

        getline(cin, input);

        if (!input.empty()) {
            break;
        }
        step++;

        for (int x = 0; x < 21; x++){
            cout << endl;
        }

        cout << "Step: " << step << endl;

        drawBoard();



    }


    return 0;

}