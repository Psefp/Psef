#include "Factory.h"
 Factory::Factory(int FactoryX ,int FactoryY,int FactoryPopulation){
 maxpopulation=100;
 time= 0;
 storage=0;
FactoryY=posy;
FactoryX=posx;
population=FactoryPopulation;
proctionrate=10;
 }
void Factory::calculateStorage()
    {
        storage = population / 10;
        if (population > 100)
        {
            storage = storage - (storage * 10);
        }
    }

void Factory::calculateTime(){
     time++ ;
 calculateStorage();



};




 
