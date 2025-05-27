#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Kitap {
    public:
        std::vector<std::string> kitapIsmi = {
            "Kucuk Prens", "Gökcen", "Nutuk", "Dönüşüm", "Genclerle Bas Basa",
            "Yanliziz", "İki Sehrin Hikayesi", "Yaralasar", "Handan", "Amok Kosucusu"
            };

        Kitap() {
            std::cout << "Kitap sinifi olusturuldu." << std::endl;
        }
};

class Uye {
    public:
        std::vector<std::string> uyeIsmi = {
            "Muhammet", "Mustafa", "Meryem", "Zeynep Akca", "Aslan"
        };

        Uye() {
            std::cout << "Uye sinifi olusturuldu." << std::endl;
        }
};

class KutuphaneIslemleri {
    protected:
        std::vector<std::string>* veriListesi;

    public:
        KutuphaneIslemleri(std::vector<std::string>* ptr) {
            veriListesi = ptr;
        }

        int kutuphaneEkle(std::string eklenecekObje) {
            if (std::find(veriListesi->begin(), veriListesi->end(), eklenecekObje) != veriListesi->end()) {
                std::cout << eklenecekObje << " zaten mevcut." << std::endl;
            } else {
                veriListesi->push_back(eklenecekObje);
                std::cout << eklenecekObje << " eklendi." << std::endl;
            }

            return veriListesi->size();
        }

        int kutuphaneSil(std::string silinecekObje) {
            auto it = std::find(veriListesi->begin(), veriListesi->end(), silinecekObje);
            if (it != veriListesi->end()) {
                veriListesi->erase(it);
                std::cout << silinecekObje << " silindi." << std::endl;
            } else {
                std::cout << silinecekObje << " mevcut degil" << std::endl;
            }
            return veriListesi->size();
        }

        void kutuphaneGoster() {
            for(size_t i = 0; i < veriListesi->size(); i++) {
                std::cout << i + 1 << ". Eleman: " << (*veriListesi)[i] << std::endl;
            }
        }

};

class KitapIslemleri : public KutuphaneIslemleri {
    public:
        Kitap* kitap;

        int kitapSayisi;

        KitapIslemleri(Kitap* kitap_ptr) : KutuphaneIslemleri(&kitap_ptr->kitapIsmi) {
            kitap = kitap_ptr;
            kitapSayisi = kitap->kitapIsmi.size();
        }

        int oduncAl(std::string oduncAlinanKitap) {
            auto it = std::find(kitap->kitapIsmi.begin(), kitap->kitapIsmi.end(), oduncAlinanKitap);
            if (it != kitap->kitapIsmi.end()) {
                std::cout << oduncAlinanKitap << " odunc alindi." << std::endl;
                kutuphaneSil(oduncAlinanKitap);
                kitapSayisi--;
            } else {
                std::cout << oduncAlinanKitap << " mevcut degil." << std::endl;
            }
            return kitapSayisi;
        };

        int geriIade(std::string iadeEdilecekK) {
            kitapEkle(iadeEdilecekK);
            return kitapSayisi;
        };

        void kitapEkle(std::string kitapIsmi) {
            kitapSayisi = kutuphaneEkle(kitapIsmi);
        }

        void kitapSil(std::string kitapIsmi) {
            kitapSayisi = kutuphaneSil(kitapIsmi);
        }

        void kitapGoster() {
            std::cout << "Kütüphanedeki kitaplar:" << std::endl;
            kutuphaneGoster();
        }
};

class UyeIslemleri : public KutuphaneIslemleri {
    public:
        Uye* uye;

        int uyeSayisi = 5;

        UyeIslemleri(Uye* uye_ptr) : KutuphaneIslemleri(&uye_ptr->uyeIsmi) {
            uye = uye_ptr;
            uyeSayisi = uye->uyeIsmi.size();
        }

        void uyeEkle(std::string uyeIsmi) {
            uyeSayisi = kutuphaneEkle(uyeIsmi);
        }

        void uyeSil(std::string uyeIsmi) {
            uyeSayisi = kutuphaneSil(uyeIsmi);
        }

        void uyeGoster() {
            std::cout << "Kütüphanenin üyeleri:" << std::endl;
            kutuphaneGoster();
        }
};
