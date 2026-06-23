#ifndef Home_h
#define Home_h

class Home
{
private:
    // Evin private  özellikleri (Sayılar/Değişkenler)
    int maxpopulation;
    int population;
    int price;
    int posx;
    int posy;
    int food;
    int foodNeed;
    int homeDay;

public:
    
    Home(int playerx , int playery);

    void profiligeration(); // Nüfus dağıtma/çoğaltma işi
    int getpopulation();    // Dısarıya nüfus bilgisini güvenle gönderme fonksiyonu
    void time();
    void calculateFoodConsumption();
};

#endif
