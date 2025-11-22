#include <math.h>
#include <iostream>

int factorial(int start, int prod) {
    if (start == 1 or start == 0) {
        return prod;
    } else {
        return factorial(start - 1, prod * start);
    }
}

float exp_estimation(float exp) {
    float sum = 0;
    for(int i = 0; i < 30; i++) {
        std::cout << "Pow" << pow(exp,i) << std::endl;
        std::cout << "Fac" << factorial(i, 1) << std::endl;
        sum += (pow(exp,i)) / factorial(i, 1);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        std::cout << "Insufficient arguments. \nUsage: ./put_call_parity [mode flag] [mode value] [strike price] [time to maturity] [risk-free interest rate] [initial stock price]" << std::endl;
        exit(1);
    }
    std::string mode_flag = argv[1];
    float mode_value = std::stof(argv[2]);
    float strike_price = std::stof(argv[3]);
    float time_to_maturity = std::stof(argv[4]);
    float rfir = std::stof(argv[5]);
    float initial_price = std::stof(argv[6]);

    std::cout << mode_value << std::endl;
    std::cout << mode_flag << std::endl;
    std::cout << strike_price << std::endl;
    std::cout << time_to_maturity << std::endl;
    std::cout << rfir << std::endl;
    std::cout << initial_price << std::endl;


    if (mode_flag != "-p" and mode_flag != "-c") {
        std::cout << "Incorrect usage. Please indicate put or call mode, using -p or -c, respectively." << std::endl;
        exit(1);
    } else {
        if (mode_flag == "-p") {
            float call_price = mode_value + initial_price - (strike_price * exp_estimation(rfir * time_to_maturity));
            std::cout << "Call price: " << call_price << std::endl; 
        } else {
            float put_price = (strike_price * exp_estimation(-1 * rfir * time_to_maturity)) + mode_value - initial_price;
            std::cout << "Put price: " << put_price << std::endl; 
        }
    }
}