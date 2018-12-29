//Tas kagit makas versiyon 2
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int hana_secim(void);
void oyun(void);
void sonuclar(void);
void kapisma(int h,int o);
int maxi(const int m[]);
int konum_max(int m);
int hana=0,skor=0,galibiyet=0,beraberlik=0,yenilgi=0,secim=0,maksimum=0;
int hamleler[3]={0};//[0]= tas [1]=kagit [2]=makas
void kayit(int h);
//Main fonksiyonu başı
int main()
{
	char asd,bsd;
  srand(time(NULL));
  printf("Dunyanin en azili robotu olan HANA ile karsilasacaksin. \nHerkesin aklinda tek bir soru var \"Hana kim?\" ama cevabi bilen yok.\nIyi sanslar.\n\n\n");

  oyun();
  sonuclar();
  printf("Kapatmak icin bir tusa basabilirsiniz.");
  scanf("%c%c",&asd,&bsd);
return 0;
}
//Main fonksiyonu sonu

int maxi(const int m[])//max yapılan hamleyi bulalım
	{
		int sayac;
		for(sayac=0;sayac<=2;sayac++)
		{
			if(hamleler[sayac]>=maksimum)
			{
				maksimum=hamleler[sayac];
			}
		}
	return maksimum;
	}

int konum_max(int m)//maksimumun konumunu bulalım 0=tas 1=kagit 2=makas
{
		if(m==hamleler[0])//tas
		{
			return 0;
		}
		else if(m==hamleler[1])//kagit
		{
			return 1;
		}
		else if(m==hamleler[2])//makas
		{
			return 2;
		}
}


int hana_secim(void) //Hana'nın hamlesini belirledik
{
	int random;
	random=rand()%100;
  int max_hamle= konum_max(maxi(hamleler));//0=tas 1=kagit 2=makas
	if (max_hamle==0)//Kullanici en cok tas hamlesi yapti
	{

		if(random<=9)//makas cekme ihtimali(en az olacak)
		{
			hana=2;
		}
		else if(random>9 && random <=34)//tas cekme ihtimali(berabere)
		{
			hana=0;
		}
		else if(random>34)//kagit cekme ihtimali(pc-zafer)
		{
			hana=1;
		}
	}
		if (max_hamle==1)//Kullanici en cok kagit hamlesi yapti
		{

			if(random<=9)//tas cekme ihtimali(en az olacak)
			{
				hana=0;
			}
			else if(random>9 && random <=34)//kagit cekme ihtimali(berabere)
			{
				hana=1;
			}
			else if(random>34)//Makas cekme ihtimali(pc-zafer)
			{
				hana=2;
			}
		}
			if (max_hamle==2)//Kullanici en cok makas hamlesi yapti
			{

				if(random<=9)//kagit cekme ihtimali(en az olacak)
				{
					hana=1;
				}
				else if(random>9 && random <=34)//makas cekme ihtimali(berabere)
				{
					hana=2;
				}
				else if(random>34)//tas cekme ihtimali(pc-zafer)
				{
					hana=0;
				}
			}
return hana;
}
void oyun(void) //tas=1 kagit=2 makas=3
{
  int o;
  printf("O azili robotla karsi karsiyasin.\n");
  printf("Sana kivilcim sacan gozleriyle bakiyor.\n");
  printf("Hamle yapmanin tam zamani.\n");
  printf("Unutma tas icin 1 makas icin 2 kagit icin 3.\n");
  printf("Musabakayi bitirmek icin 4 tuslamalisin.\n\n\n");
  while(secim!=4)
  {
    printf("Bir acik yakaladin yap hamleni!!!\n\n");
    scanf("%d",&secim);
		kayit(secim);
		if(secim!=4)
		{
    o=hana_secim();
    kapisma(secim,o);
		}
  }
}//oyun fonk sonu
//kayit fonksiyonu
void kayit(int h)
{
	if(h==1)
	{
		hamleler[0]++;
	}
	else if(h==2)
	{
		hamleler[1]++;
	}
	else if(h==3)
	{
		hamleler[2]++;
	}
}

  //kapisma fonksiyonu
void kapisma(int secim,int o)
{
  switch (o)//o= hananin cektigi sonuc
  {
      case 0:

        if(secim==1)//tas-tas beraberligi
        {
          printf("Tas roketleriniz havada carpisti ve ortada patladi.\n");
          printf("Yenisemediniz! Hemen toparlan ve yeni bir acik kolla.\n");
          beraberlik++;
          skor+=1;
        }
        else if(secim==2)//tas - kagit zafer
        {
          printf("Hananin tas roketini atlattin ve kagit patlayicini arkasina yerlestirdin\n");
          printf("Bip .. Bip .. Bip .. BOOM\n");
          printf("Bu onu sersemletti aferin.\n");
          printf("Dikkati elden birakma ve yeni bir firsat bul!\n\n\n");
          skor+=3;
          galibiyet++;
        }
        else if(secim==3)//tas-makas yenilgisi
        {
          printf("Ahhh! Anlik bir dikkatsizlik sana pahaliya mal oldu.\n");
          printf("Makas-droidin kontrolunu kaybettin ve roketin hedefi oldun.\n");
          printf("Yaralarini sar ve hemen savasa don Hana durdurulmali!\n\n\n");
          skor-=2;
          yenilgi++;
        }

      break;
      case 1:

        if(secim==1)//kagit-tas yenilgisi
        {
          printf("Hananin kagit jiletleri tas duvarlarindan gecti.\n");
          printf("Sol kolun kesiklerle dolu ama aylaklik yapacak zaman yok!!\n");
          printf("Hananin omzunda bir kivilcim kesfettin belki bunu degerlendirebilirsin.\n\n\n");
          skor -=2;
          yenilgi++;
        }
      else if(secim==2)//kagit kagit beraberligi
        {
          printf("Kagittan tsunamin hanain kagit gemilerini batiramadi.\n");
          printf("Bu tur galip yok ama vazgecemezsin.\n");
          printf("Soluklan ve yeni hamleni dusun.\n\n\n");
            skor+=1;
            beraberlik++;
        }
      else if(secim==3)//kagit-makas galibiyeti
        {
          printf("Hananin kagit kopyalarini makas kilicinla kestin ve gercek hanaya ulastin.\n");
          printf("Bi anda arkasina gectin ve devrelerinin bazilarini kesip attin.\n");
          printf("Bu eski moda silahlarin hala ise yaramasi cok ilginc degil mi ?\n");
          printf("Mesafenizi yeniden ayarladin ve bi atak sansi beklemeye basladin\n\n\n");
          skor+=3;
          galibiyet++;
        }

      break;
      case 2:

        if(secim==1)//makas tas galibiyeti
        {
          printf("Tas ellerinle hananin makas-dronlarini yakaladin ve birbirlerine vurarak yok ettin.\n");
          printf("Bu sana da biraz vahsi gelmedi mi ?\n");
          printf("Hana ne oldugunu anlayamadan bir strateji bulmalisin\n\n\n");
          skor+=3;
          galibiyet++;
        }
      else if(secim==2)//makas makas beraberligi
        {
          printf("Celiklerin carpismasiyla kulaklari tirmalayan bir ses cikti.\n");
          printf("Kivilcimlar ve toz bulutu kalktiginda hasar alanin olmadigi anlasildi\n");
          printf("Hana sana dehset dolu gozlerle bakti\n");
          printf("Yiktigi sehirlerin intikamini alacagina yemin ettin.\n\n\n");
          skor +=1;
          beraberlik++;
        }
      else if(secim==3)//makas kagit maglubiyeti
        {
          printf("Kagit kalkanin kolayca kesildi!\n");
          printf("Kim kagittan kalkan yapar ki zaten ?\n");
          printf("Guclukle yerinden kalkmayi basardin.\n\n\n");
          skor-=1;
          yenilgi++;
        }

      break;
      default:
      {
        printf("Oyun hatali lutfen yapimciya ulasiniz!\n");
      }

  }
  sleep(2);
}


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
