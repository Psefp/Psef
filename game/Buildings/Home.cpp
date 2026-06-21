#include "Home.h"
Home::Home(int playerx, int playery)
{
     maxpopulation= 100 ;
     population= 0;
    price = 200 ;
    posx=playerx;
     posy=playery;
    food=0;
     foodneed =0;
    homeday =0;
}
 void Home::time(){
homeday++;
food=food-foodneed; 
       if (food<0)
      population=population*85/100;
      profiligeration();
        }
 int Home::getpopulation(){

return population;}
 void Home::profiligeration()
 {
     // Eğer mevcut nüfus, maksimum kapasiteden küçükse:
     if (population < maxpopulation && food>foodneed )
     {
         population++; // Nüfusu 1 kişi artır!
     }
 }
 void Home::need(){
 foodneed=population+population;

 }