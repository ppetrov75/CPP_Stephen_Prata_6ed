#include "vehicle.h"


int main() {

    Vehicle * v = new NuclearLandVechicle();
    v->drive();

    Vehicle * v1 = new GasLandVechicle();
    v1->drive();

    delete v;
    delete v1;
}
