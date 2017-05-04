
class ParkMiller
{

protected:

  int seed;

public:

  ParkMiller();

  ParkMiller(const ParkMiller& P);

  ~ParkMiller();

  ParkMiller operator =(const ParkMiller& P);

  int getSeed() {return this->seed;}

  void setSeed(int seed) {this->seed = seed;}

  double genRandom();

};
