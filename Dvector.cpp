class Dvector
{
    private:
        int size;
        double *pCor;

    public:
        Dvector();
        int getSize();
        Dvector(int, double*);
};

Dvector::Dvector()
{
    size = 0;
    pCor = new double[size];
};

int Dvector::getSize() {
    return size;
};

Dvector::Dvector(int size, double *pCor) {
  this-> size = size;
  this->pCor=pCor;
}
