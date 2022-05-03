#include <iostream>


struct Dugum {
    int veri;   //Düğümün sayısal değeri
    Dugum* sonraki; //Sonraki düğüme işaretçi
};


struct Kuyruk {
    Dugum* bas; //Kuyruğun başındaki elemanın değerini tutar.
    Dugum* son; //Kuyruğun sonudaki elemanın değerini tutar.
    void olustur(); //Başlangıç için gereken tanımları içerir.
    void kapat();   //Program bitiminde bellek iadesi yapar.
    void ekle(int deger);   //Kuyruğa yeni veri ekler.
    int cikar();    //Kuyruktan sıradaki elemanı çıkarır.
    bool bosMu();   //Kuyruk boş mu dolu mu kontrol eder.
    void yazdir();
    
};

struct Yigin {
    Kuyruk k1, k2;	//yığın için kullanılacak kuyruk değişkenleri
    void olustur();	 //başlangıç için gereken tanımları içerir
    void kapat();	//program bitiminde bellek iadesi yapar
    void ekle(int deger);		//kuyruğa yeni veri ekler
    int cikar();	//kuyruktan sıradaki elemanı çıkarır
    bool bosMu();	 //kuyruk boş mu kontrol eder
    int tepe();	 //yığının tepesindeki elemanı okur
    void yazdir();	//yığın elemanlarını sırayla ekrana yazar
};




int main()
{
    Kuyruk* kyrk = new Kuyruk();

    kyrk->olustur();
    kyrk->ekle(5);
    kyrk->ekle(2);
    kyrk->ekle(3);
    kyrk->ekle(4);
    kyrk->cikar();
    
    kyrk->yazdir();
        
    if (kyrk->bosMu())
    {
        std::cout << "Kuyruk Bos\n";
    }
    kyrk->kapat();
  
}



void Kuyruk::olustur()
{
    std::cout << "Olustur Fonksiyonu Calisti\n\n";
    bas = NULL;
    son = NULL;

}

void Kuyruk::kapat()
{
    Dugum* n;
    while (bas)
    {
        n = bas;
        bas = bas->sonraki;
        delete n;
    }
}

void Kuyruk::ekle(int deger)
{
    if (bas ==NULL)
    {
        bas = (Dugum*)malloc(sizeof(Dugum));
        bas->veri = deger;
        bas->sonraki = NULL;
        son = bas;
    }
    else
    {
        son->sonraki = (Dugum*)malloc(sizeof(Dugum));
        son->sonraki->veri = deger;
        son = son->sonraki;
        son->sonraki = NULL;
    }   
}

int Kuyruk::cikar()
{
    if (bas == NULL)
    {
        std::cout << "Bu Kuyruk Bos";
        return -1;
    }
    int value = bas->veri;
    Dugum* temp = bas;
    bas = bas->sonraki;
    delete(temp);
    return value;
}

bool Kuyruk::bosMu()
{
    return (bas==NULL);
}

void Kuyruk::yazdir()
{
    while (bas !=NULL)
    {
        printf("%d  ", bas->veri);
        bas = bas->sonraki;
        
    }
}




void Yigin::olustur()
{
    

}

void Yigin::kapat()
{
    
}

void Yigin::ekle(int deger)
{
    
    k1.son->veri = deger;
    k2.bas->veri = k1.son->veri;
    k1.son->sonraki = k2.bas;
    k2.bas = k1.son;

}

int Yigin::cikar()
{
    
    return 0;
}

bool Yigin::bosMu()
{
    return false;
}

int Yigin::tepe()
{
    return 0;
}

void Yigin::yazdir()
{

}

void yiginCikar(Yigin* s) {

}

void siraliEkle(Yigin* s, int x) {

}