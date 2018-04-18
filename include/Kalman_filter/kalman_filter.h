// Based on slides from Cyrill Stachniss

#include<boost/numeric/ublas/matrix.hpp>
#include<vector>

using namespace boost::numeric::ublas;
class Kalmanfilter{
    matrix<double> state_;
    matrix<double> covariance_;
    matrix<double> a_matrix_;   // describes how state evolves from t-1 to t without control input or noise (n x n)
    matrix<double> b_matrix;    // describes how control changes from t-1 to t (n x l)
    matrix<double> c_matrix_;   // map state x(t) to an observation z(t) (k x n)
    matrix<double> r_matrix_;
    matrix<double> q_matrix_;
    matrix<double> control_input_;
public:
    Kalmanfilter(const matrix<double>&, const matrix<double>&);
    Kalmanfilter(size_t);
    void predict(unsigned int);
    void measure();
    void correct();
    void update();

    ~Kalmanfilter();

    matrix<double> state() const;
    void setState(const matrix<double>& state);
    matrix<double> covariance() const;
    void setCovariance(const matrix<double>& covariance);
    matrix<double> a_matrix() const;
    void setA_matrix(const matrix<double>& a_matrix);
    matrix<double> getB_matrix() const;
    void setB_matrix(const matrix<double>& value);
    matrix<double> c_matrix() const;
    void setC_matrix(const matrix<double>& c_matrix);
    matrix<double> r_matrix() const;
    void setR_matrix(const matrix<double>& r_matrix);
    matrix<double> q_matrix() const;
    void setQ_matrix(const matrix<double>& q_matrix);
    matrix<double> control_input() const;
    void setControl_input(const matrix<double>& control_input);
};
