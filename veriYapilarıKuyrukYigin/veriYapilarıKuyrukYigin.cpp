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
    Yigin* ygn = new Yigin();
    ygn->olustur();

    ygn->ekle(3);
    ygn->ekle(1);
    ygn->ekle(7);
    ygn->ekle(4);
    ygn->ekle(8);
    ygn->cikar();
    

    ygn->yazdir();

    ygn->kapat();

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
    if (bosMu())
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
    k1.bas = NULL;
    k2.bas = NULL;
}

void Yigin::kapat()
{
    Dugum* n;
    while (k1.bas)
    {
        n = k1.bas;
        k1.bas = k1.bas->sonraki;
        delete n;
    }
}

void Yigin::ekle(int deger)
{
    Kuyruk* kyrk = new Kuyruk();
    
    k2.ekle(deger);
    
    while (!bosMu())
    {
        k2.ekle(k1.bas->veri);
        k1.cikar();
    }
    
    Kuyruk temp = k1;
    k1 = k2;
    k2 = temp;
}

int Yigin::cikar()
{
    if (bosMu())
    {
        printf("Yigin yapisi bos");
        return -1;
    }
    return k1.cikar();
}

bool Yigin::bosMu()
{
    return k1.bosMu();
}

int Yigin::tepe()
{
    if (k1.bosMu())
    {
        return -1;
    }

    return k1.bas->veri;
}

void Yigin::yazdir()
{
    while (k1.bas != NULL)
    {
        printf("%d ", k1.bas->veri);
        k1.bas = k1.bas->sonraki;
    }
}



void yiginCikar(Yigin* s) 
{

}

void siraliEkle(Yigin* s, int x)
{
    Yigin* ygn = new Yigin();

    if (ygn->bosMu())
    {
        
    }

}