#include "Kalman_filter/kalman_filter.h"


vector<double> Kalmanfilter::state() const
{
    return state_;
}

void Kalmanfilter::setState(const vector<double>& state)
{
    state_ = state;
}

matrix<double> Kalmanfilter::covariance() const
{
    return covariance_;
}

void Kalmanfilter::setCovariance(const matrix<double>& covariance)
{
    covariance_ = covariance;
}


matrix<double> Kalmanfilter::a_matrix() const
{
    return a_matrix_;
}

void Kalmanfilter::setA_matrix(const matrix<double>& a_matrix)
{
    a_matrix_ = a_matrix;
}

matrix<double> Kalmanfilter::getB_matrix() const
{
    return b_matrix;
}

void Kalmanfilter::setB_matrix(const matrix<double>& value)
{
    b_matrix = value;
}

matrix<double> Kalmanfilter::c_matrix() const
{
    return c_matrix_;
}

void Kalmanfilter::setC_matrix(const matrix<double>& c_matrix)
{
    c_matrix_ = c_matrix;
}

matrix<double> Kalmanfilter::r_matrix() const
{
    return r_matrix_;
}

void Kalmanfilter::setR_matrix(const matrix<double>& r_matrix)
{
    r_matrix_ = r_matrix;
}

matrix<double> Kalmanfilter::q_matrix() const
{
    return q_matrix_;
}

void Kalmanfilter::setQ_matrix(const matrix<double>& q_matrix)
{
    q_matrix_ = q_matrix;
}


vector<double> Kalmanfilter::control_input() const
{
    return control_input_;
}

void Kalmanfilter::setControl_input(const vector<double>& control_input)
{
    control_input_ = control_input;
}

Kalmanfilter::Kalmanfilter(const vector<double>& mean, const matrix<double>& covariance) : state_(mean), covariance_(covariance)
{

}

Kalmanfilter::Kalmanfilter(size_t size) : state_(size), covariance_(size, size)
{
    for(size_t i = 0; i < size; ++i)
                state_(i) = 0;

    for(size_t i = 0; i < size; ++i)
    {
            for(size_t j = 0; j < size; ++j)
            {
                if(i==j)
                    covariance_(i, j) = 1;
                else
                    covariance_(i, j) = 0;
            }
    }
}

void Kalmanfilter::correct()
{

}

void Kalmanfilter::measure()
{

}

void Kalmanfilter::predict(unsigned int del_t)
{
    //for(unsigned int t = 0; t < 5; t += del_t)
    //{
        state_ = prod(a_matrix_, state_) + prod(b_matrix, control_input_);
        covariance_ = prod(matrix<double>(prod(a_matrix_, covariance_)), matrix<double>(trans(a_matrix_))) + r_matrix_;
    //}
}

void Kalmanfilter::update()
{

}

Kalmanfilter::~Kalmanfilter()
{

}
