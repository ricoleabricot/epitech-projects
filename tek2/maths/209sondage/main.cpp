/* 
* @Author: gicque_p
* @Date:   2015-05-25 11:11:01
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-05-25 11:59:52
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

void usage(char **argv) {
    cout << argv[0] << ": <population_size> <sample_size> <poll_result>" << endl;
}

double stringToNumber(string value) {
    stringstream stream;
    double number(0);

    stream << value;
    stream >> number;

    return number;
}

double check_min(double sample) {
    if (sample < 0) {
        return 0;
    } else {
        return sample;
    }
}

double check_max(double sample) {
    if (sample > 100) {
        return 100;
    } else {
        return sample;
    }
}

int main(int argc, char **argv) {

    if (argc != 4) {
        usage(argv);
        return -1;
    } else {
        double population(stringToNumber(argv[1]));
        double sample(stringToNumber(argv[2]));
        double poll(stringToNumber(argv[3]));

        double variance(0);
        double p1(0);
        double p2(0);

        population = round(population);
        sample = round(sample);
        if (population <= 0) {
            cerr << "Population size must be higher than zero" << endl;
            return -1;
        } else if (sample >= population or sample <= 0) {
            cerr << "Sample size must be lower than population size and higher than zero" << endl;
            return -1;
        } else if (poll < 0 or poll > 100) {
            cerr << "Poll result cannot be under 0% or upper 100%" << endl;
            return -1;
        } else if (population - 1 < 0) {
            cerr << "Division by zero" << endl;
            return -1;
        } else {
            double p(poll / 100);

            variance = ((p * (1 - p)) / sample) * ((population - sample) / (population - 1));
            p1 = (2 * 1.96 * sqrt(variance)) / 2 * 100;
            p2 = (2 * 2.58 * sqrt(variance)) / 2 * 100;

            cout << "\033[01mTaille de la population:\033[0m\t" << population << endl;
            cout << "\033[01mTaille de l'échantillon:\033[0m\t" << sample << endl;
            cout << "\033[01mRésultat du sondage:\033[0m\t\t" << poll << "%" << endl;

            cout << setprecision(6) << fixed;
            cout << "\033[01mVariance estimée:\033[0m\t\t" << variance << endl;

            double s1(check_min(poll - p1));
            double s2(check_max(poll + p1));
            double s3(check_min(poll - p2));
            double s4(check_max(poll + p2));

            cout << setprecision(2) << fixed;
            cout << "\033[01mIntervalle de confiance à 95%:\033[0m\t" << "[" << s1 << "% ; " << s2 << "%]" << endl;
            cout << "\033[01mIntervalle de confiance à 99%:\033[0m\t" << "[" << s3 << "% ; " << s4 << "%]" << endl;

            return 0;
        }
    }
}
