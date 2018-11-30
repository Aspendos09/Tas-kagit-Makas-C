//Taş kağıt makas versiyon 2
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void hana_secim(void);
void oyun(int o);
void sonuclar(void);
int hana=0,karmahana,skor=0,galibiyet=0,beraberlik=0,yenilgi=0,secim=0;
int main()
{
  srand(time(NULL));
  printf("Dunyanın en azili robotu olan HANA ile karsilasacaksin.\nOnun aslinda kim oldugunu kimse bilmiyor. \nHerkesin aklinda tek bir soru var \"Hana kim?\" ama cevabi bilen yok.\nIyi sanslar.\n\n\n");

hana_secim();
sonuclar();
  return 0;
}

void hana_secim(void) //Hana ya rastgele bir sayi cektirdik.
{
  int onceki=hana;
  hana=rand();
  karmahana=hana+rand();
  if(karmahana%2==0) //kaosu arttirdik.
  {
    while(hana==onceki)
    {
        hana=(rand()%3)+1;
    }

  }
  else
  hana=(rand()%3)+1;
  oyun(hana);//hananin sayisini oyuna yolladık
}

void oyun(int o) //tas=1 kagit=2 makas=3
{
  printf("O azili robotla karsi karsiyasin.\n");
  printf("Sana kivilcim sacan gozleriyle bakiyor.\n");
  printf("Hamle yapmanin tam zamani.\n");
  printf("Unutma tas icin 1 makas icin 2 kagit icin 3.\n");
  printf("Musabakayi bitirmek icin 4 tuslamalisin.\n\n\n");
  while(secim!=4)
  {
    printf("Bir acik yakaladin yap hamleni!!!\n\n");
    scanf("%d",&secim);


    switch (o)//o= hananin cektigi sonuc
    {
        case 1:

          if(secim==1)//tas-tas beraberligi
          {
            printf("Tas roketleriniz havada carpisti ve ortada patladi.\n");
            printf("Yenisemediniz! Hemen toparlan ve yeni bir acik kolla.\n");
            beraberlik++;
            skor+=1;
          }
          if(secim==2)//tas - kagit zafer
          {
            printf("Hananin tas roketini atlattin ve kagit patlayicini arkasina yerlestirdin\n");
            printf("Bip .. Bip .. Bip .. BOOM\n");
            printf("Bu onu sersemletti aferin.\n");
            printf("Dikkati elden birakma ve yeni bir firsat bul!\n\n\n");
            skor+=3;
            galibiyet++;
          }
          if(secim==3)//tas-makas yenilgisi
          {
            printf("Ahhh! Anlik bir dikkatsizlik sana pahaliya mal oldu.\n");
            printf("Makas-droidin kontrolunu kaybettin ve roketin hedefi oldun.\n");
            printf("Yaralarini sar ve hemen savasa don Hana durdurulmali!\n\n\n");
            skor-=2;
            yenilgi++;
          }

        break;
        case 2:

          if(secim==1)//kagit-tas yenilgisi
          {
            printf("Hananin kagit jiletleri tas duvarlarindan gecti.\n");
            printf("Sol kolun kesiklerle dolu ama aylaklik yapacak zaman yok!!\n");
            printf("Hananin omzunda bir kivilcim kesfettin belki bunu degerlendirebilirsin.\n\n\n");
            skor -=2;
            yenilgi++;
          }
          if(secim==2)//kagit kagit beraberligi
          {
            printf("Kagittan tsunamin hanain kagit gemilerini batiramadi.\n");
            printf("Bu tur galip yok ama vazgecemezsin.\n");
            printf("Soluklan ve yeni hamleni dusun.\n\n\n");
              skor+=1;
              beraberlik++;
          }
          if(secim==3)//kagit-makas galibiyeti
          {
            printf("Hananin kagit kopyalarini makas kilicinla kestin ve gercek hanaya ulastin.\n");
            printf("Bi anda arkasina gectin ve devrelerinin bazilarini kesip attın.\n");
            printf("Bu eski moda silahlarin hala ise yaramasi cok ilginc degil mi ?\n");
            printf("Mesafenizi yeniden ayarladin ve bi atak sansi beklemeye basladin\n\n\n");
            skor+=3;
            galibiyet++;
          }

        break;
        case 3:

          if(secim==1)//makas tas galibiyeti
          {
            printf("Tas ellerinle hananin makas-dronlarini yakaladin ve birbirlerine vurarak yok ettin.\n");
            printf("Bu sana da biraz vahsi gelmedi mi ?\n");
            printf("Hana ne oldugunu anlayamadan bir strateji bulmalisin\n\n\n");
            skor+=3;
            galibiyet++;
          }
          if(secim==2)//makas makas beraberligi
          {
            printf("Celiklerin carpismasiyla kulaklari tirmalayan bir ses cikti.\n");
            printf("Kivilcimlar ve toz bulutu kalktiginda hasar alanin olmadigi anlasildi\n");
            printf("Hana sana dehset dolu gozlerle bakti\n");
            printf("Yiktigi sehirlerin intikamini alacagina yemin ettin.\n\n\n");
            skor +=1;
            beraberlik++;
          }
          if(secim==3)//makas kagit maglubiyeti
          {
            printf("Kagit kalkanin kolayca kesildi!\n");
            printf("Kim kagittan kalkan yapar ki zaten ?\n");
            printf("Güclükle yerinden kalkmayi basardin.\n\n\n");
            skor-=1;
            yenilgi++;
          }

        break;
    }
    int onceki=hana;// hanaya yeniden cektirdik
    hana=rand();
    karmahana=hana+rand();
    if(karmahana%2==0) //kaosu arttirdik.
    {
      while(hana==onceki)
      {
          hana=(rand()%3)+1;
      }

    }
    else
    hana=(rand()%3)+1;
    o=hana;
  }


}//oyun fonk sonu
void sonuclar(void)
{
  printf("\n\nToz bulutu kalktiginda hana ortalikta gozukmuyordu.\n");
  printf("Geri gelmeyecegini umarak zorlukla bir tasin ustune oturdun.\n");
  printf("Zirh ekranina gorev raporun gelmeye basladi.\n");
  printf("GOREV TAMAMLANDI\n\n\n");
  printf("Basarili hasar: %d \n",galibiyet);
  printf("Etkisiz hasar: %d \n",beraberlik);
  printf("Alinan hasar: %d \n",yenilgi);
  printf("Kazanilan tecrube: %d \n",skor);
}
