/***********************************************************************************

İSİM SOYİSİM:   BILYAL MUSTAFA YARMADZHA
Proje:          ALGORİTMALAR VE PROGRAMLAMA DERSİ - 2021-2022 GÜZ DÖNEMİ PROJESİ
Proje İsmi:     TAŞ, KAĞIT, MAKAS OYUNU

***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Bilgisayara rastgele taş, kağıt veya makas seçimini yaptıran fonksiyon.
//Geriye rastgele seçimin sonucunu döndürür.
char rastgele_pc()
{
    short int sayi;
    char sonuc;
    srand(time(0));
    sayi=(rand()%3)+1;     //%3 + 1 olarak tanımlandığı için 1-3 dahili aralığında sayılar üretilecek.

    /* Rastgele üretilen sayıya göre 'sonuc' isimli char değişkenine taş,kağıt veya makas (t/k/m)
    değerini atayan switch case yapısı. */
    switch (sayi)
    {
    case 1:
        sonuc='t';
        break;
    case 2:
        sonuc='k';
        break;
    case 3:
        sonuc='m';
        break;
    default:
        sonuc='m';
        break;
    }

    return sonuc;
}

//Oyuncudan taş, kağıt veya makas seçimini alan fonksiyon.
//Geriye oyuncunun seçimini döndürür.
char girdi_oyuncu()
{
    char girdi;
    printf("Tas, kagit veya makas? (t/k/m) : ");
    scanf("%c",&girdi);
    
    //Oyuncu doğru giriş yapana kadar tekrar girdi isteyen sonsuz döngü.
    while(1)
    {
        if(girdi=='t' || girdi=='k' || girdi=='m')
            break;
        else
            scanf("%c",&girdi);
    }

    return girdi;
}

//Bilgisayarın ve oyuncunun seçimlerini alarak bu seçimlere göre puanlarını güncelleyen fonksiyon.
//Void türünde olan bu fonksiyon geriye bir şey döndürmez.
void karsilastir(char bilgisayar, char oyuncu, short int* puan_bilgisayar, short int* puan_oyuncu)
{
    if(bilgisayar=='t' && oyuncu=='m')
        *puan_bilgisayar+=1;
    else if(oyuncu=='t' && bilgisayar=='m')
        *puan_oyuncu+=1;
    else if(bilgisayar=='k' && oyuncu=='t')
        *puan_bilgisayar+=1;
    else if(oyuncu=='k' && bilgisayar=='t')
        *puan_oyuncu+=1;
    else if(bilgisayar=='m' && oyuncu=='k')
        *puan_bilgisayar+=1;
    else if(oyuncu=='m' && bilgisayar=='k')
        *puan_oyuncu+=1;
    else
    {
        *puan_bilgisayar+=0;
        *puan_oyuncu+=0;
    }
}

int main()
{
    //Bilgisayarın ve oyuncunun seçimini tutatacak değişkenler.
    char pc, oyuncu;
    
    //Bilgisayarın ve oyuncunun puanlarını tutan değişkenler ve sayaçlar.
    short int puan_pc=0, puan_oyuncu=0, sayac=0, el_sayisi=1;
    
    //Bilgisayarın ve oyuncunun seçimlerinin saklanacağı diziler.
    char dizi_pc[99], dizi_oyuncu[99];

    //Herhangi bir oyuncunun puanı 5 olana kadar oyunun çalışmasını sağlayan sonsuz döngü.
    while(1)
    {   
        if(puan_pc==5)
        {
            printf("\nBilgisayar kazandi! Skor %d-%d.\n",puan_pc,puan_oyuncu);
            break;
        }
        else if (puan_oyuncu==5)
        {
            printf("\nOyuncu kazandi! Skor %d-%d.\n",puan_oyuncu,puan_pc);
            break;
        }
        else
        {
            printf("\n%d. el:\n",el_sayisi);
            el_sayisi++;

            oyuncu=girdi_oyuncu();
            pc=rastgele_pc();
            karsilastir(pc,oyuncu,&puan_pc,&puan_oyuncu);
            printf("Oyuncu %c-%c Bilgisayar\n",oyuncu,pc);
            printf("Oyuncu %d-%d Bilgisayar\n",puan_oyuncu,puan_pc);
            dizi_pc[sayac]=pc;
            dizi_oyuncu[sayac++]=oyuncu;
        }
    }

    //Oyun bittiğinde dizinin son elemanından sonra 'sonlandırıcı' karakter eklenir.
    dizi_oyuncu[sayac]='\0'; 
    dizi_pc[sayac]='\0';
    return 0;
}
