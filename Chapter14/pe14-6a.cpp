#include "vehicle.h"

int main() {

    Vehicle * v = new LandVechicle(new GasEngine());
    v->drive();

    Vehicle * v1 = new LandVechicle(new NuclearEngine());
    v1->drive();

    Vehicle * v2 = new AirVechicle(new NuclearEngine());
    v2->drive();

    delete v;
    delete v1;
    delete v2;
}
