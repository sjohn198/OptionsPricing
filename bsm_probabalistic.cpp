#include <cmath>
#include <iostream>
#include <math.h>
#include "util.h"

float getNormalProb(float value) {
    return 0.5 * std::erfc((-1 * value) / std::sqrt(2));
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cout << "Insufficient arguments. \nUsage: ./bsm_probabalistic [strike price] [time to maturity] [risk-free interest rate] [initial stock price] [volatility]" << std::endl;
        exit(1);
    }
    float strike_price = std::stof(argv[1]);
    float time_to_maturity = std::stof(argv[2]);
    float rfir = std::stof(argv[3]);
    float initial_price = std::stof(argv[4]);
    float volatility = std::stof(argv[5]);

    float d_1 = (log(initial_price / strike_price) + (rfir + (pow(volatility, 2) / 2)) * time_to_maturity) / (volatility * sqrt(time_to_maturity));
    float d_2 = d_1 - volatility * sqrt(time_to_maturity);

    float call_price = initial_price * getNormalProb(d_1) - (strike_price * exp_estimation(-1 * rfir * time_to_maturity) * getNormalProb(d_2));
    float put_price = strike_price * exp_estimation(-1 * rfir * time_to_maturity) * getNormalProb(-1 * d_2) - initial_price * getNormalProb(-1 * d_1);

    std::cout << "Given your inputs:" << std::endl;
    std::cout << "Call price: " << call_price << std::endl;
    std::cout << "Put price: " << put_price << std::endl;

    return 0;
}