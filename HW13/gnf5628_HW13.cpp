
#include <iostream>
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





int main() {

    Ant ant1;



}