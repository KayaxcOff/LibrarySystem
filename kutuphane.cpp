#include <iostream>
#include <string>
#include "kutuphaneIslemleri.hpp"

class KitapIslemi {
    public:
        Kitap* kitap;
        KitapIslemleri* kitapIslemleri;

        void kitapIslem(int kitapIslemiSecimi) {
            switch (kitapIslemiSecimi) {
                case 1: {
                    std::string kitapIsmi;
                    std::cout << "Odunc almak istediginiz kitabin ismini giriniz: " << std::endl;
                    std::cin >> kitapIsmi;
                    kitapIslemleri->oduncAl(kitapIsmi);
                    break;
                }

                case 2: {
                    std::string kitapIsmi;
                    std::cout << "Iade etmek istediginiz kitabin ismini giriniz: " << std::endl;
                    std::cin >> kitapIsmi;
                    kitapIslemleri->geriIade(kitapIsmi);
                    break;
                }

                case 3: {
                    std::string kitapIsmi;
                    std::cout << "Kutuphaneye eklemek istediginiz kitabin ismini giriniz: " << std::endl;
                    std::cin >> kitapIsmi;
                    kitapIslemleri->kitapEkle(kitapIsmi);
                    break;
                }

                case 4: {
                    std::string kitapIsmi;
                    std::cout << "Kutuphaneden almak istediginiz kitabin ismini giriniz: " << std::endl;
                    std::cin >> kitapIsmi;
                    kitapIslemleri->kitapSil(kitapIsmi);
                    break;
                }

                case 5: {
                    kitapIslemleri->kitapGoster();
                    break;
                }

                default:
                    std::cout << "Yanlis islem secimi yaptiniz!" << std::endl;
            }
        } 

};

class UyeIslemi {
    public:
        Uye* uye;
        UyeIslemleri* uyeIslemleri;

        void uyeIslem(int uyeIslemiSecimi) {
            switch(uyeIslemiSecimi) {
                case 1: {
                    std::string uyeIsmi;
                    std::cout << "Kutuphaneye uye olmak icin lutfen isminizi giriniz: " << std::endl;
                    std::cin >> uyeIsmi;
                    uyeIslemleri->uyeEkle(uyeIsmi);
                    break;
                }

                case 2: {
                    std::string uyeIsmi;
                    std::cout << "Kutuphaneden kaydinizi silmek icin lutfen isminizi giriniz: " << std::endl;
                    std::cin >> uyeIsmi;
                    uyeIslemleri->uyeSil(uyeIsmi);
                    break;
                }

                case 3: {
                    std::cout << "Kutuphanedeki uyeleri gormek icin lutfen islem yapiniz: " << std::endl;
                    uyeIslemleri->uyeGoster();
                    break;
                }

                default:
                    std::cout << "Yanlis islem secimi yaptiniz!" << std::endl;
            }
        }

};

int main() {
    KitapIslemi kitapIslemi;
    UyeIslemi uyeIslemi;

    int islemSecimi;

    std::cout << "Kutuphaneye hos geldiniz ;)" << std::endl;
    std::cout << "Kitap islemleri icin 1'e, uye islemleri icin 2'ye basiniz: " << std::endl;
    std::cin >> islemSecimi;

    if(islemSecimi == 1) {
        int kitapIslemiSecimi;

        std::cout << "Kitap islemi menusune hos geldiniz :)" << std::endl;
        std::cout << "Yapmak istediginiz islemi seciniz\n1 - Kitap odunc almak\n2 - Odunc alinan kitabi iade etmek\n 3 - Kutuphaneye kitap bagislamak\n4 - Kutuphaneden kitap almak\n5 - Kutuphanenin kitaplarina bakmak\n Seciminiz: ";
        std::cin >> kitapIslemiSecimi;

        kitapIslemi.kitapIslem(kitapIslemiSecimi);
    } else if(islemSecimi == 2) {
        int uyeIslemiSecimi;

        std::cout << "Uye islemleri menusune hos geldiniz :)" << std::endl;
        std::cout << "Yapmak istediginiz islemi seciniz\n1 - Kutuphaneye uye olmak\n2 - Kutuphaneden kaydini silmek\n3 - Kutuphanenin uyelerini gormek\n Seciminiz: ";
        std::cin >> uyeIslemiSecimi;

        uyeIslemi.uyeIslem(uyeIslemiSecimi);
    } else {
        std::cout << "Yanlis islem secimi yaptiniz!" << std::endl;
    }

    return 0;
}
