class Dvector
{
    private:
        int size;
        double *pCor;

    public:
        Dvector();
        int getSize();
};

Dvector::Dvector()
{
    size = 0;
    pCor = new double[size];
};

int Dvector::getSize() {
    return size;
};
