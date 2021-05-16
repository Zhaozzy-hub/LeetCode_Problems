#include <iostream>
using namespace std;


int numWaterBottles(int numBottles, int numExchange) {
    int drinked = numBottles;
    while (numBottles >= numExchange) {
        drinked += numBottles / numExchange;
        numBottles = numBottles % numExchange + numBottles / numExchange;
    }
    return drinked;
}