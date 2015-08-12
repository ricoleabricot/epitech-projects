#ifndef CORE_HPP_
# define CORE_HPP_

# include <iostream>
# include <iomanip>
# include <sstream>
# include <fstream>

# include <vector>
# include <cmath>

# include "gmpxx.h"
# include "Exception.hpp"
using namespace std;

class Core {
    vector<int> _effectifs;
    vector<double> _ajust;

    vector<int> _pourcents;
    vector<vector<double> > _datas;

    vector<string> _x;
    vector<double> _ox;
    vector<double> _tx;

    double _p;
    double _s;
    double _d;

    int _min;
    int _max;

 public:
    Core() {};
    ~Core() {};

    void init(int argc, char **argv) {
        this->_effectifs.resize(9);
        this->_effectifs.assign(9, 0);

        this->_ajust.resize(9);
        this->_ajust.assign(9, 0);

        this->_pourcents.resize(13);
        this->_pourcents.assign(13, 0);

        vector<double> data;
        data.resize(14);
        data.assign(14, 0);

        this->_datas.resize(10);
        this->_datas.assign(10, data);

        this->_x.resize(9);
        this->_x.assign(9, "");

        this->_ox.resize(9);
        this->_ox.assign(9, 0);

        this->_tx.resize(9);
        this->_tx.assign(9, 0);

        for (int i = 1; i < argc; i++) {
            int number(this->stringToNumber(argv[i]));

            if (number < 0) {
                throw Exception("You must enter only positive numbers"); 
            } else {
                this->_effectifs[i - 1] = number;
            }
        }

        cout << "\033[01mUtilisation des effectifs entier:\033[0m ";
        for (vector<int>::iterator it = this->_effectifs.begin(); it != this->_effectifs.end(); it++) {
            cout << *it << " ";
        }
        cout << endl << endl;

        this->fill();
    }

    void run(void) {
        this->law();
        this->binomial();
        this->calculate();
        this->sum();
        this->degre();
        this->pourcent();

        cout << "\033[4mx  |";
        for (int i = 0; i < 9; i++) {
            if (!this->_x[i].empty()) {
                if (this->_x[i] == "7+") {
                    cout << "  " << this->_x[i] << "  |";
                } else {
                    cout << "  " << this->_x[i] << "   |";
                }
            }
        }
        cout << " total\033[0m" << endl;

        cout << "Ox |";
        for (int i = 0; i < 9; i++) {
            if (!this->_x[i].empty()) {
                if (this->_x[i].length() > 2) {
                    cout << "  " << this->_ox[i] << "    |";
                } else {
                    cout << " " << this->_ox[i] << "   |";
                }

            }
        }
        cout << " 100" << endl;

        cout << setprecision(1) << fixed;
        cout << "Tx |";
        for (int i = 0; i < 9; i++) {
            if (!this->_x[i].empty()) {
                if (this->_x[i].length() > 2) {
                    cout << "  " << (this->_tx[i] * 100) << "  ";
                } else {
                    cout << " " << (this->_tx[i] * 100) << " ";
                }

                if (this->_tx[i] * 100 < 10) {
                    cout << " |";
                } else {
                    cout << "|";
                }
            }
        }
        cout << " 100" << endl;
        cout << endl << endl;

        cout << setprecision(4) << fixed;
        cout << "\033[01mLoi choisie:\033[0m\t\t\tB(100, " << this->_p << ")" << endl;
        cout << setprecision(3) << fixed;
        cout << "\033[01mSomme des carrés des écarts:\033[0m\tX2 = " << this->_s << endl;
        cout << setprecision(0) << fixed;
        cout << "\033[01mDegrés de liberté:\033[0m\t\tv = " << this->_d << endl;
        cout << "\033[01mValidité de l’ajustement:\033[0m\t" << this->_min << "% < P < " << this->_max << "%" << endl;
    }

    void end(void) {
        this->_effectifs.clear();
    }

    void law(void) {
        for (int i = 0; i < 9; i++) {
            this->_p += i * this->_effectifs[i];
        }

        this->_p /= 10000;
    }

    void binomial(void) {
        int n(100);

        for (int k = 0; k < 51; k++) {
            double coef(coefficient(n, k));
            coef = (coef * (pow(this->_p, k)) * (pow((1 - this->_p), (n - k))));

            if (k < 8) {
                this->_ajust[k] += coef;
            } else {
                this->_ajust[8] += coef;
            }
        }
    }

    void calculate(void) {
        stringstream stream;

        for (int i = 0; i < 7; i++) {
            double ox(this->_effectifs[i]);
            double tx(this->_ajust[i]);

            stream.str("");
            stream.clear();

            if (this->_effectifs[i] < 10) {
                if (this->_effectifs[i] + this->_effectifs[i + 1] < 10) {
                    this->_ox[i] = this->_effectifs[i] + this->_effectifs[i + 1] + this->_effectifs[i + 2];
                    this->_tx[i] = this->_ajust[i] + this->_ajust[i + 1] + this->_ajust[i + 2];

                    stream << i << "-" << i + 2;
                    this->_x[i] = stream.str();
                } else {
                    this->_ox[i] = this->_effectifs[i] + this->_effectifs[i + 1];
                    this->_tx[i] = this->_ajust[i] + this->_ajust[i + 1];

                    stream << i << "-" << i + 1;
                    this->_x[i] = stream.str();
                }
                i++;
            } else {
                this->_ox[i] = ox;
                this->_tx[i] = tx;

                stream << i;
                this->_x[i] = stream.str();
            }
        }

        if (this->_effectifs[7] < 10 or this->_effectifs[8] < 10) {
            this->_ox[7] = this->_effectifs[7] + this->_effectifs[8];
            this->_tx[7] = this->_ajust[7] + this->_ajust[8];
            this->_x[7] = "7+";    
        } else {
            this->_ox[7] = this->_effectifs[7];
            this->_tx[7] = this->_ajust[7];
            this->_x[7] = "7";

            this->_ox[8] = this->_effectifs[8];
            this->_tx[8] = this->_ajust[8];
            this->_x[8] = "8";
        }
    }

    void sum(void) {
        for (int i = 0; i < 9; i++) {
            if (!this->_x[i].empty() and this->_tx[i] != 0) {
                this->_s += pow(this->_ox[i] - (this->_tx[i] * 100), 2) / (this->_tx[i] * 100);
            }
        }
    }

    void degre(void) {
        for (int i = 0; i < 9; i++) {
            if (!this->_x[i].empty()) {
                this->_d += 1;
            }
        }

        this->_d -= 2;
    }

    void pourcent(void) {
        for (int i = 1; i < 14; i++) {
            if (this->_s < this->_datas[this->_d - 1][i]) {
                this->_min = this->_pourcents[i - 1];
                this->_max = this->_pourcents[i - 2];

                break;
            }
        }
    }

    double coefficient(double firstValue, double secondValue) {
        mpz_t b, tmp, tmp2, tmp3, i, k, n;
        double k2, j = 0;

        mpz_init_set_d(b, 1);
        mpz_init_set_d(i, 1);
        mpz_init_set_d(n, firstValue);
        mpz_init_set_d(tmp, 1);
        mpz_init_set_d(tmp2, 1);
        mpz_init_set_d(tmp3, 1);

        if (secondValue < 0 or secondValue > firstValue) {
            mpz_set_d(b, 0);
        } else {
            k2 = min(secondValue, (firstValue - secondValue));
            mpz_init_set_d(k, k2);
            j = 1;
            while (j <= k2) {
                mpz_sub(tmp, n, i);
                mpz_add_ui(tmp2, tmp, 1);
                mpz_mul(tmp3, b, tmp2);
                mpz_div(b, tmp3, i);
                mpz_add_ui(i, i, 1);
                j++;
            }
        }

        mpz_class res(b);
        return res.get_d();
    }

    void fill(void) {
        fstream file;
        file.open("data.xml");
        int i(0);

        if (file) {
            string line;

            while (getline(file, line)) {

                if (line.find("line") != line.npos and line.find("pourcent") != line.npos) {
                    int j(0);
                    while (getline(file, line) and line.find("cell") != line.npos) {
                        istringstream cell(line);
                        string value;

                        cell >> value;
                        cell >> value;
                        this->_pourcents[j] = stringToNumber(value);
                        j++;
                    }
                }

                else if (line.find("line") != line.npos) {
                    int j(0);
                    while (getline(file, line) and line.find("cell") != line.npos) {
                        istringstream cell(line);
                        string value;

                        cell >> value;
                        cell >> value;
                        this->_datas[i][j] = stringToNumber(value);
                        j++;
                    }
                    i++;
                }
            }
        } else {
            throw Exception("Can't open data.xml file");
        }
    }

    double stringToNumber(const std::string &value) {
        stringstream stream;
        double number(0);

        stream << value;
        stream >> number;

        return number;
    }
};

#endif /* CORE_HPP_ */
