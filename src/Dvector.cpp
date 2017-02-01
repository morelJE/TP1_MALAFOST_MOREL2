#include "Dvector.h"


Dvector::Dvector()
{
    size = 0;
    pCor = new double[size];
};

int Dvector::getSize() {
    return this->size;
};

Dvector::Dvector(int size, double *pCor) {
    this->size = size;
    this->pCor = pCor;
};

Dvector::Dvector(int size) {
    this->size = size;
    this->pCor = new double[size];
};

void Dvector::display(std::ostream& str) {
    if (this-> size != 0) {
        for (int i = 0; i < this->size; i++) {
            str << this->pCor[i];
            str << "\n";
        }
    }
}
