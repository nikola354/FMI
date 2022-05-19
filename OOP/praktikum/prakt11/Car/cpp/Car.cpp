#include "../h/Car.h"

Car::Car() {
    weight = -1;
    kmTraveled = -1;
    tiresCount = 0;
}

Car::Car(const FuelTank &tank, const Engine &engine, const Battery &battery, double kmTraveled,
         double weight) : tank(tank), engine(engine), accumulator(battery), kmTraveled(kmTraveled),
                          weight(weight), tiresCount(0) {}

void Car::addTire(const Tire &tire, int count) {
    for (int i = 0; i < count; ++i) {
        if (tiresCount >= TIRES_NUMBER)
            throw std::logic_error("No more space for tires!");

        tires[tiresCount++] = tire;
    }
}

void Car::drive(double km) {
    if (tiresCount < 4)
        throw std::logic_error("The car does not have 4 tires!");

    //double fuelForKm = (log(engine.getHp()) / log(3.6) + log(weight) / log (8)) / 100;
    int fuelForKm = 1; //litre

    double fuelNeeded = km * fuelForKm;

    tank.use(fuelNeeded); //throws exception if not enough fuel
    kmTraveled += km; //stays unchanged if exception is thrown
}

double Car::getFuel() const {
    return tank.getFuel();
}

const FuelTank &Car::getFuelTank() const {
    return tank;
}

double Car::getWeight() const {
    return weight;
}

const Engine &Car::getEngine() const {
    return engine;
}

Car *dragRace(Car *car1, Car *car2) {
    bool canDrive1 = true;
    bool canDrive2 = true;

    try {
        car1->drive(DRAG_DISTANCE);
    } catch (std::logic_error &e) {
        canDrive1 = false; // car1 cannot travel this distance
    }

    try {
        car2->drive(DRAG_DISTANCE);
    } catch (std::logic_error &e) {
        canDrive2 = false;
    }

    if (canDrive1 && canDrive2) {
        double ratio1 = car1->getWeight() / car1->getEngine().getHp();
        double ratio2 = car2->getWeight() / car2->getEngine().getHp();

        if (ratio1 < ratio2)
            return car1;

        if (ratio2 < ratio1)
            return car2;

        return nullptr;
    }

    if (canDrive1)
        return car1;

    if (canDrive2)
        return car2;

    return nullptr;

}