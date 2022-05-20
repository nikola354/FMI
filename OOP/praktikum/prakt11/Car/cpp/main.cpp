#include <iostream>

#include "../h/Battery.h"
#include "../h/Tire.h"
#include "../h/Engine.h"
#include "../h/FuelTank.h"
#include "../h/Car.h"

int main() {
    try {
        Battery b(2, 15, 0, String("Sony"), String("Very good battery!"));

        Engine e(115, 0, String("China"), String("Desc desc"));

        Tire tire(180, 80, 15, 0, String("Michelin"), String("For snow"));

        FuelTank tank(50);

        Car peugeot(tank, &e, &b, 50000, 200);

        peugeot.addTire(&tire, 4);

        peugeot.drive(40);

        std::cout << peugeot.getFuel() << std::endl;

        Car golf(tank, &e, &b, 50000, 2000);

        golf.addTire(&tire, 4);

        Car *winner = dragRace(&peugeot, &golf);

        if (winner != nullptr)
            std::cout << winner->getFuel() << std::endl;
        else
            std::cout << "Equal" << std::endl;

    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
