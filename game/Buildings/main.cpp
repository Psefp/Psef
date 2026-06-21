#include <SFML/Graphics.hpp>
#include <iostream>

// GLOBAL AYARLAR 
const int HARITA_GENISLIK = 50;
const int HARITA_YUKSEKLIK = 40;
const float KARE_BOYUTU = 16.0f; 

// Harita matrisi
int harita[HARITA_GENISLIK][HARITA_YUKSEKLIK] = {0};

// 1. FONKSİYON
void haritayiUret()
{
    for (int x = 0; x < HARITA_GENISLIK; x++)
    {
        for (int y = 0; y < HARITA_YUKSEKLIK; y++)
        {
            // Rastgele dağlık araziler 
            if (rand() % 100 < 15)
                harita[x][y] = 2; // 2 = Dağ
            else
                harita[x][y] = 0; // 0 = Düzlük
        }
    }
}

// 2. FONKSİYON: Haritayı Ekrana Çizme Mekanizması
void haritayiCiz(sf::RenderWindow &window, sf::RectangleShape &kutu)
{
    for (int y = 0; y < HARITA_YUKSEKLIK; y++)
    {
        for (int x = 0; x < HARITA_GENISLIK; x++)
        {
            // Hafızadaki rakama göre renk seçiyoruz
            if (harita[x][y] == 1)
                kutu.setFillColor(sf::Color::Red); // Fethedilen Yer
            else if (harita[x][y] == 2)
                kutu.setFillColor(sf::Color(128, 128, 128)); // Dağ (Gri)
            else
                kutu.setFillColor(sf::Color::White); // Düzlük (Beyaz)

            kutu.setPosition(x * KARE_BOYUTU, y * KARE_BOYUTU);
            window.draw(kutu);
        }
    }
}

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 640), "Fiyodal Strateji Prototip");

    srand(time(0));
    haritayiUret(); 

    sf::RectangleShape kutu(sf::Vector2f(KARE_BOYUTU, KARE_BOYUTU));
    kutu.setOutlineThickness(-1.0f);
    kutu.setOutlineColor(sf::Color(200, 200, 200)); // Çizgileri yumuşak gri yaptık

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // TIKLAMA VE GERİ ÇEKME (TOGGLE) MEKANİZMASI
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                int MouseX = event.mouseButton.x / KARE_BOYUTU;
                int MouseY = event.mouseButton.y / KARE_BOYUTU;

                if (MouseX >= 0 && MouseX < HARITA_GENISLIK && MouseY >= 0 && MouseY < HARITA_YUKSEKLIK)
                {
                    // GERİ ÇEKME KOMUTU
                    if (harita[MouseX][MouseY] == 1)
                    {
                        harita[MouseX][MouseY] = 0;
                    }
                  
                    else if (harita[MouseX][MouseY] == 0)
                    {
                        harita[MouseX][MouseY] = 1;
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        haritayiCiz(window, kutu);

        window.display();
    }

    return 0;
}
