#include<iostream>
#include "Kalman_filter/kalman_filter.h"

int main()
{
    Kalmanfilter k(5);
    k.predict(0.1);
    std::cout << k.covariance() << '\n';
    return 0;
}
