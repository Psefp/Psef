#ifndef Factory_H
#define Factory_H
class Factory
{
private:
      int population;
      int maxpopulation;
      int time ;
      int proctionrate;
      int storage ;
      int  amount;
      int posy;
      int posx;
public:
      Factory(int FactoryX, int FactoryY , int FactoryPopulation);

      void calculateStorage();
      void calculateTime();
};

#endif 
