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
    int foodneed;
    int homeday;

public:
    
    Home(int playerx , int playery);

    // Evin yapacağı işler (Fonksiyonlar)
    void profiligeration(); // Nüfus dağıtma/çoğaltma işi
    int getpopulation();    // Dışarıya nüfus bilgisini güvenle gönderme kapısı
    void time();
    void need();
};

#endif
