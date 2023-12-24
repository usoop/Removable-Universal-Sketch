#ifndef GENERIC_COUNTER_TURNSTILE_HPP_
#define GENERIC_COUNTER_TURNSTILE_HPP_

#pragma  pack (1)

# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>
#include <random>
#include "utils_active_counter.hpp"

using namespace std;
using std::ostream;
namespace datasketches {


    class GenericCounterTurnstile {
    private:


        bool n_counter_sign_positive_;


        uint8_t n_counter_exponent_;

        uint16_t n_counter_coefficient_;


        uint8_t n_len_exponent_;


        uint8_t n_len_coefficient_;

    public:


        explicit GenericCounterTurnstile(uint8_t n_len_exponent = 4, uint8_t n_len_coefficient = 11);


        GenericCounterTurnstile(const GenericCounterTurnstile &that);

        GenericCounterTurnstile(const int32_t &num);


        uint32_t get_counter_exponent() const;


        void set_counter_exponent(uint32_t n_counter_exponent);


        uint32_t get_counter_coefficient() const;


        uint32_t stochastic_rounding(uint32_t value, uint32_t exp);


        void set_counter_coefficient(uint32_t n_counter_coefficient);


        void set_counter_sign(bool n_counter_sign_positive);


        bool get_counter_sign() const;


        void adjust_generate_implicit(uint32_t &coeff_real_new, uint32_t exp_value,
                                      uint32_t &exp_value_new) const;


        int32_t compute_the_value_of_active_counter_stochastic() const;


        void get_homonymous_param(uint32_t increment, uint32_t &n_len_coeff, uint32_t &n_len_exp);


        int32_t cal_sign(int a);

        void update_active_counter_stochastic_by_increment(int32_t increment);


        void adjust_coeff_overflow(uint32_t &coeff_real_new, uint32_t exp_value,
                                   uint32_t &exp_value_new);

        GenericCounterTurnstile &operator=(const GenericCounterTurnstile &that);


        operator int() const {
            return this->compute_the_value_of_active_counter_stochastic();
        }


        GenericCounterTurnstile &operator=(const int32_t &num);


        GenericCounterTurnstile operator*(const int32_t &num);


        GenericCounterTurnstile &operator*=(const int32_t &num);

        bool operator>(const GenericCounterTurnstile &that) const;


        bool operator<(const GenericCounterTurnstile &that) const;


        bool operator<=(const GenericCounterTurnstile &that) const;

        bool operator>=(const GenericCounterTurnstile &that) const;


        bool operator>(const int32_t &num) const;


        bool operator>=(const int32_t &num) const;


        bool operator<=(const int32_t &num) const;


        bool operator<(const int32_t &num) const;


        bool operator==(const GenericCounterTurnstile &that) const;


        bool operator!=(const GenericCounterTurnstile &that) const;


        GenericCounterTurnstile operator+(const int32_t &increment);

        GenericCounterTurnstile operator-(const int32_t &increment);


        GenericCounterTurnstile &operator+=(const int32_t &increment);

        GenericCounterTurnstile operator+(const GenericCounterTurnstile &increment);

        GenericCounterTurnstile operator-(const GenericCounterTurnstile &increment);


        GenericCounterTurnstile &operator+=(const GenericCounterTurnstile &increment);


        friend ostream &operator<<(ostream &out, const GenericCounterTurnstile &that);


        friend int operator%(int i, const GenericCounterTurnstile &that);


        ~GenericCounterTurnstile();
    };


}


namespace datasketches {

    GenericCounterTurnstile::GenericCounterTurnstile(uint8_t n_len_exponent, uint8_t n_len_coefficient) :
            n_counter_sign_positive_(true),
            n_counter_exponent_(0),
            n_counter_coefficient_(0),
            n_len_exponent_(n_len_exponent),
            n_len_coefficient_(n_len_coefficient) {};

    GenericCounterTurnstile::GenericCounterTurnstile(const GenericCounterTurnstile &that)
            : n_counter_sign_positive_(that.n_counter_sign_positive_), n_counter_exponent_(that.n_counter_exponent_),
              n_counter_coefficient_(that.n_counter_coefficient_), n_len_exponent_(that.n_len_exponent_),
              n_len_coefficient_(that.n_len_coefficient_) {


    }

    GenericCounterTurnstile::GenericCounterTurnstile(const int32_t &num) : GenericCounterTurnstile() {
        *this = num;
    }


    bool GenericCounterTurnstile::get_counter_sign() const {
        return n_counter_sign_positive_;
    };

    void GenericCounterTurnstile::set_counter_sign(bool n_counter_sign_positive) {
        n_counter_sign_positive_ = n_counter_sign_positive;
    }

    uint32_t GenericCounterTurnstile::get_counter_exponent() const {
        return n_counter_exponent_;
    }

    void GenericCounterTurnstile::set_counter_exponent(uint32_t n_counter_exponent) {
        n_counter_exponent_ = n_counter_exponent;
    }


    uint32_t GenericCounterTurnstile::get_counter_coefficient() const {
        return n_counter_coefficient_;
    }

    void GenericCounterTurnstile::set_counter_coefficient(uint32_t n_counter_coefficient) {
        n_counter_coefficient_ = n_counter_coefficient;
    }


    int32_t GenericCounterTurnstile::compute_the_value_of_active_counter_stochastic() const {
        uint32_t active_counter_alpha = n_counter_coefficient_;
        uint32_t active_counter_beta = n_counter_exponent_;

        uint32_t pow_of_a = 1 << n_len_coefficient_;
        uint32_t abs_value_active_counter =
                (1 << (active_counter_beta + n_len_coefficient_)) + (active_counter_alpha << active_counter_beta) -
                pow_of_a;
        int32_t value_active_counter;
        if (n_counter_sign_positive_) {
            value_active_counter = (int32_t) abs_value_active_counter;
        } else {


            value_active_counter = ~(int32_t) abs_value_active_counter + 1;
        }
        return value_active_counter;
    }


    inline uint32_t GenericCounterTurnstile::stochastic_rounding(uint32_t value, uint32_t exp) {


        uint32_t integer_part = value >> exp;


        uint32_t remainder_part = (integer_part << exp) ^ value;
        if (remainder_part > 0) {
            uint32_t rand_denominator = 1 << exp;


            uint32_t rnd = (rand() & (rand_denominator - 1)) + 1;

            if (rnd <= remainder_part) {
                integer_part += 1;
            }
        }
        return integer_part;
    }

    void GenericCounterTurnstile::get_homonymous_param(uint32_t increment, uint32_t &aim_coeff, uint32_t &aim_exp) {


        uint32_t t_exponent_prob;
        uint32_t t_increment_integer_part;
        uint32_t t_increment_fraction_part;
        uint32_t rnd;

        uint32_t t_counter_coefficient_plus_one = 0;
        uint32_t t_addition_result = 0;
        uint32_t t_addition_result_integer_part = 0;
        uint32_t t_addition_result_fraction_part = 0;
        uint32_t t_len_addition_result = 0;
        uint32_t t_len_fraction_addition_result = 0;


        t_exponent_prob = std::pow(2, n_counter_exponent_);


        if (increment > t_exponent_prob) {
            t_increment_integer_part = increment >> n_counter_exponent_;
            uint32_t temp_increment_integer_part;
            temp_increment_integer_part = t_increment_integer_part << n_counter_exponent_;
            t_increment_fraction_part = increment ^ temp_increment_integer_part;
        } else if (increment == t_exponent_prob) {
            t_increment_integer_part = 1;
            t_increment_fraction_part = 0;
        } else if (increment < t_exponent_prob) {
            t_increment_integer_part = 0;
            t_increment_fraction_part = increment;
        }


        rnd = (rand() & (t_exponent_prob - 1)) + 1;
        if (rnd <= t_increment_fraction_part) {
            t_increment_integer_part = t_increment_integer_part + 1;
        }


        if (t_increment_integer_part + n_counter_coefficient_ < (1 << n_len_coefficient_)) {

            aim_coeff = n_counter_coefficient_ + t_increment_integer_part;
            aim_exp = n_counter_exponent_;
            return;
        }


        t_counter_coefficient_plus_one = n_counter_coefficient_ + std::pow(2, n_len_coefficient_);
        t_addition_result = t_counter_coefficient_plus_one + t_increment_integer_part;

#ifndef SIMPLE_IMPL

        t_len_addition_result = get_length_of_AVX(t_addition_result);
        uint32_t t_len_addition_result_2 = get_length_of_clz(t_addition_result);
        if (t_len_addition_result_2 != t_len_addition_result) {
            cout << "t_len_addition_result_2!=t_len_addition_result" << endl;
        }
#endif


        t_len_fraction_addition_result = t_len_addition_result - (n_len_coefficient_ + 1);
        t_addition_result_integer_part = t_addition_result >> t_len_fraction_addition_result;
        uint32_t temp_addition_result;
        temp_addition_result = t_addition_result_integer_part << t_len_fraction_addition_result;
        t_addition_result_fraction_part = t_addition_result ^ temp_addition_result;


        uint32_t temp_stochastic_prob;
        temp_stochastic_prob = (uint32_t) 1 << t_len_fraction_addition_result;
        rnd = (rand() % (temp_stochastic_prob - 1 + 1)) + 1;
        if (rnd <= t_addition_result_fraction_part) {
            t_addition_result_integer_part = t_addition_result_integer_part + 1;
        }


        aim_coeff = t_addition_result_integer_part - std::pow(2, n_len_coefficient_);
        aim_exp = n_counter_exponent_ + t_len_fraction_addition_result;
    }

    void GenericCounterTurnstile::adjust_generate_implicit(uint32_t &coeff_real_new, uint32_t exp_value,
                                                           uint32_t &exp_value_new) const {
        if (coeff_real_new) {
            uint32_t coeff_len = n_len_coefficient_;
            uint32_t exp_len = n_len_exponent_;

            uint32_t shift = coeff_len - get_length_of_clz(coeff_real_new) + 1;
            coeff_real_new = (coeff_real_new << shift);
            exp_value_new = exp_value - shift;
            if (exp_value_new >= (1 << exp_len)) {
                throw "exp_value_new ovefflow!";
            }
        } else {
            coeff_real_new = 1 << n_len_coefficient_;
            exp_value_new = 1;
        }
    }

    void GenericCounterTurnstile::adjust_coeff_overflow(uint32_t &coeff_real_new, uint32_t exp_value,
                                                        uint32_t &exp_value_new) {
        uint32_t coeff_len = n_len_coefficient_;
        uint32_t exp_len = n_len_exponent_;

        uint32_t tmp_exp = get_length_of_clz(coeff_real_new) - coeff_len - 1;

        coeff_real_new = stochastic_rounding(coeff_real_new, tmp_exp);
        if (coeff_real_new == (1 << (coeff_len + 1))) {
            coeff_real_new = 1 << coeff_len;

            exp_value_new = exp_value + tmp_exp + 1;
        } else {
            exp_value_new = exp_value + tmp_exp;
        }

        if (exp_value_new >= (1 << exp_len)) {
            throw "exp_value_new overflow!";
        }
    }

    inline int32_t GenericCounterTurnstile::cal_sign(int32_t a) {
        return (a >> 31) - (-a >> 31);
    }


    inline void GenericCounterTurnstile::update_active_counter_stochastic_by_increment(int32_t increment) {

        if (increment == 0) {
            return;
        }


        uint32_t coeff_len = n_len_coefficient_;
        uint32_t exp_len = n_len_exponent_;
        uint32_t exp_value = n_counter_exponent_;
        uint32_t coeff_value = n_counter_coefficient_;

        bool is_increment_postive;

        is_increment_postive = increment >= 0 ? true : false;

        bool homonymous;

        homonymous = n_counter_sign_positive_ == is_increment_postive ? true : false;
        bool change_sign = false;
        uint32_t abs_increment = abs(increment);
        uint32_t delta_coeff = stochastic_rounding(abs_increment, exp_value);

        uint32_t exp_value_new, coeff_value_new;
        exp_value_new = coeff_value_new = 0;
        uint32_t implicit_coeff = 1 << coeff_len;
        uint32_t coeff_real = implicit_coeff + coeff_value;
        uint32_t coeff_real_new = coeff_real;

        if (homonymous) {

            change_sign = false;


            coeff_real_new = coeff_real + delta_coeff;
            exp_value_new = exp_value;
        } else {

            uint32_t threshold = coeff_real - ((coeff_len >= exp_value) ? (1 << (coeff_len - exp_value)) : 0);
            if (delta_coeff < threshold) {
                change_sign = false;
                exp_value_new = exp_value;
                coeff_real_new = coeff_real - delta_coeff;
            } else {
                change_sign = true;
                coeff_real_new = delta_coeff - coeff_real +
                                 ((coeff_len + 1 >= exp_value) ? (1 << ((coeff_len - exp_value) + 1))
                                                               : stochastic_rounding(1 << (coeff_len + 1), exp_value));
                exp_value_new = exp_value;
            }


        }


        if (coeff_real_new < (1 << coeff_len)) {
            adjust_generate_implicit(coeff_real_new, exp_value, exp_value_new);
        } else if (coeff_real_new > ((1 << (coeff_len + 1)) - 1)) {
            adjust_coeff_overflow(coeff_real_new, exp_value, exp_value_new);
        } else {}

        n_counter_exponent_ = exp_value_new;
        n_counter_coefficient_ = coeff_real_new - implicit_coeff;
        if (change_sign) {
            n_counter_sign_positive_ = !n_counter_sign_positive_;
        }
        if (n_counter_exponent_ >= 1 << n_len_exponent_) {
            std::cout << "error" << std::endl;
            throw "n_counter_exponent_>1<<n_len_exponent_";
        }
        if (n_counter_coefficient_ >= 1 << n_len_coefficient_) {
            std::cout << "error" << std::endl;
            throw "n_counter_coefficient_>1<<n_len_coefficient_";
        }
    }

    inline GenericCounterTurnstile &GenericCounterTurnstile::operator=(const GenericCounterTurnstile &that) {
        if (this == &that)
            return *this;
        this->n_counter_sign_positive_ = that.n_counter_sign_positive_;
        this->n_counter_coefficient_ = that.n_counter_coefficient_;
        this->n_counter_exponent_ = that.n_counter_exponent_;
        this->n_len_exponent_ = that.n_len_exponent_;
        this->n_len_coefficient_ = that.n_len_coefficient_;
        return *this;
    }

    inline GenericCounterTurnstile &GenericCounterTurnstile::operator=(const int32_t &num) {


        if (num != 0) {
            n_counter_sign_positive_ = num >= 0 ? true : false;
            uint32_t abs_num = abs(num);
            uint32_t t_addition_result;
            uint32_t t_addition_result_integer_part;
            uint32_t t_addition_result_fraction_part;
            uint32_t t_len_addition_result;
            uint32_t t_len_fraction_addition_result;


            t_addition_result = abs_num + (1 << n_len_coefficient_);


            t_len_addition_result = get_length_of_clz(t_addition_result);


            t_len_fraction_addition_result = t_len_addition_result - (n_len_coefficient_ + 1);


            t_addition_result_integer_part = t_addition_result >> t_len_fraction_addition_result;


            uint32_t temp_addition_result;

            temp_addition_result = t_addition_result_integer_part << t_len_fraction_addition_result;


            t_addition_result_fraction_part = t_addition_result ^ temp_addition_result;


            uint32_t rnd;
            uint32_t temp_stochastic_prob;
            temp_stochastic_prob = (uint32_t) 1 << t_len_fraction_addition_result;


            rnd = (rand() % (temp_stochastic_prob)) + 1;

            if (rnd <= t_addition_result_fraction_part) {
                t_addition_result_integer_part = t_addition_result_integer_part + 1;
            }


            n_counter_coefficient_ = t_addition_result_integer_part - (1 << n_len_coefficient_);
            n_counter_exponent_ = t_len_fraction_addition_result;


            return *this;
        } else {
            n_counter_sign_positive_ = true;
            n_counter_coefficient_ = 0;
            n_counter_exponent_ = 0;
            return *this;
        }
    }

    inline GenericCounterTurnstile GenericCounterTurnstile::operator+(const int32_t &increment) {

        if (increment == 0)
            return *this;
        GenericCounterTurnstile new_obj(*this);
        new_obj.update_active_counter_stochastic_by_increment(increment);
        return new_obj;
    }


    inline GenericCounterTurnstile GenericCounterTurnstile::operator-(const int32_t &increment) {

        if (increment == 0)
            return *this;
        GenericCounterTurnstile new_obj(*this);
        new_obj.update_active_counter_stochastic_by_increment(-1 * increment);
        return new_obj;
    }

    inline GenericCounterTurnstile &GenericCounterTurnstile::operator+=(const int32_t &increment) {

        if (increment == 0)
            return *this;

        update_active_counter_stochastic_by_increment(increment);
        return *this;
    }

    inline GenericCounterTurnstile operator+(const int increment, GenericCounterTurnstile obj) {
        return obj + increment;
    }


    inline GenericCounterTurnstile GenericCounterTurnstile::operator+(const GenericCounterTurnstile &increment) {

        int32_t t_increment = increment.compute_the_value_of_active_counter_stochastic();
        GenericCounterTurnstile new_obj(*this);

        new_obj.update_active_counter_stochastic_by_increment(t_increment);
        return new_obj;
    }


    inline GenericCounterTurnstile GenericCounterTurnstile::operator-(const GenericCounterTurnstile &increment) {

        int32_t t_increment = increment.compute_the_value_of_active_counter_stochastic();
        GenericCounterTurnstile new_obj(*this);

        new_obj.update_active_counter_stochastic_by_increment(-1 * t_increment);
        return new_obj;
    }

    inline GenericCounterTurnstile &GenericCounterTurnstile::operator+=(const GenericCounterTurnstile &increment) {

        int32_t t_increment = increment.compute_the_value_of_active_counter_stochastic();
        update_active_counter_stochastic_by_increment(t_increment);
        return *this;
    }


    inline GenericCounterTurnstile &GenericCounterTurnstile::operator*=(const int32_t &num) {
        if (num != 1 && num != -1) {
            throw "can only handle to mul 1 or -1";
        }


        bool new_sign = !(this->n_counter_sign_positive_ ^ (num > 0));
        this->n_counter_sign_positive_ = new_sign;

        return *this;
    }


    inline GenericCounterTurnstile GenericCounterTurnstile::operator*(const int32_t &num) {
        if (num != 1 && num != -1) {
            throw "can only handle to mul 1 or -1";

        }


        bool new_sign = !(this->n_counter_sign_positive_ ^ (num > 0));


        GenericCounterTurnstile new_obj(*this);

        new_obj.n_counter_sign_positive_ = new_sign;
        return new_obj;
    }

    inline bool GenericCounterTurnstile::operator>(const GenericCounterTurnstile &that) const {


        if (this->n_counter_sign_positive_ && !that.n_counter_sign_positive_) {


            if ((n_counter_exponent_ == that.n_counter_exponent_) && n_counter_exponent_ == 0
                && (n_counter_coefficient_ == that.n_counter_coefficient_) && n_counter_coefficient_ == 0) {
                return false;
            } else {
                return true;
            }


        } else if (!this->n_counter_sign_positive_ && that.n_counter_sign_positive_) {
            return false;
        } else {
            if (this->n_counter_sign_positive_) {
                if (n_counter_exponent_ > that.n_counter_exponent_)
                    return true;
                else if ((n_counter_exponent_ == that.n_counter_exponent_)
                         && (n_counter_coefficient_ > that.n_counter_coefficient_))
                    return true;
                else
                    return false;
            } else {
                if (n_counter_exponent_ < that.n_counter_exponent_)
                    return true;
                else if ((n_counter_exponent_ == that.n_counter_exponent_)
                         && (n_counter_coefficient_ < that.n_counter_coefficient_))
                    return true;
                else
                    return false;
            }
        }
    }


    bool GenericCounterTurnstile::operator<(const GenericCounterTurnstile &that) const {

        if (this->n_counter_sign_positive_ && !that.n_counter_sign_positive_) {
            return false;
        } else if (!this->n_counter_sign_positive_ && that.n_counter_sign_positive_) {
            if ((n_counter_exponent_ == that.n_counter_exponent_) && n_counter_exponent_ == 0
                && (n_counter_coefficient_ == that.n_counter_coefficient_) && n_counter_coefficient_ == 0) {
                return false;
            } else {
                return true;
            }
        } else {
            if (this->n_counter_sign_positive_) {
                if (n_counter_exponent_ < that.n_counter_exponent_)
                    return true;
                else if ((n_counter_exponent_ == that.n_counter_exponent_)
                         && (n_counter_coefficient_ < that.n_counter_coefficient_))
                    return true;
                else
                    return false;
            } else {
                if (n_counter_exponent_ > that.n_counter_exponent_)
                    return true;
                else if ((n_counter_exponent_ == that.n_counter_exponent_)
                         && (n_counter_coefficient_ > that.n_counter_coefficient_))
                    return true;
                else
                    return false;
            }
        }
    }


    inline bool GenericCounterTurnstile::operator==(const GenericCounterTurnstile &that) const {
        if ((n_counter_exponent_ == that.n_counter_exponent_)
            && (n_counter_coefficient_ == that.n_counter_coefficient_)
            && (n_counter_sign_positive_ == that.n_counter_sign_positive_)) {
            return true;
        } else if ((n_counter_exponent_ == that.n_counter_exponent_) && n_counter_exponent_ == 0
                   && (n_counter_coefficient_ == that.n_counter_coefficient_) && n_counter_coefficient_ == 0) {
            return true;
        } else {
            return false;
        }
    }


    inline bool GenericCounterTurnstile::operator!=(const GenericCounterTurnstile &that) const {
        if ((n_counter_exponent_ == that.n_counter_exponent_)
            && (n_counter_coefficient_ == that.n_counter_coefficient_)
            && (n_counter_sign_positive_ == that.n_counter_sign_positive_)) {
            return false;
        } else if ((n_counter_exponent_ == that.n_counter_exponent_) && n_counter_exponent_ == 0
                   && (n_counter_coefficient_ == that.n_counter_coefficient_) && n_counter_coefficient_ == 0) {
            return false;
        } else {
            return true;
        }

    }


    ostream &operator<<(ostream &out, const GenericCounterTurnstile &that) {
        int32_t t_value = that.compute_the_value_of_active_counter_stochastic();
        out << t_value << " ";
        return out;
    }

    inline bool GenericCounterTurnstile::operator>(const int32_t &num) const {
        int32_t t_value;
        t_value = this->compute_the_value_of_active_counter_stochastic();
        return t_value > num;
    }


    inline bool GenericCounterTurnstile::operator<=(const GenericCounterTurnstile &that) const {
        if (!(*this > that)) {
            return true;
        } else {
            return false;
        }
    }

    inline bool GenericCounterTurnstile::operator>=(const GenericCounterTurnstile &that) const {
        if (!(*this < that)) {
            return true;
        } else {
            return false;
        }
    }


    inline bool GenericCounterTurnstile::operator>=(const int32_t &num) const {
        int32_t t_value;
        t_value = this->compute_the_value_of_active_counter_stochastic();
        return t_value >= num;
    }

    inline bool GenericCounterTurnstile::operator<(const int32_t &num) const {
        int32_t t_value;
        t_value = this->compute_the_value_of_active_counter_stochastic();
        return t_value < num;
    }

    inline bool GenericCounterTurnstile::operator<=(const int32_t &num) const {
        int32_t t_value;
        t_value = this->compute_the_value_of_active_counter_stochastic();
        return t_value <= num;
    }

    int operator%(int i, const GenericCounterTurnstile &that) {
        return i % that.compute_the_value_of_active_counter_stochastic();
    }

    GenericCounterTurnstile::~GenericCounterTurnstile() = default;
}


#endif
