#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{

int hana,secim=0 ,kazanma=0 ,kaybetme=0 ,beraberlik=0,skor=0;

/* kazanma 3 puan beraberlik 1 kaybetme -2 puan */

while(secim!=4)
{
printf("Tas Kagit Makas oyununa hos geldiniz. Lutfen hamlenizi seciniz(tas=1,kagit=2,makas=3,bitirmek icin 4 ). Bu arada Hana kim?\n ");	
scanf("%d",&secim);	
srand(time(NULL));
FILE *f = fopen("kayit.txt" , "w");
printf("\n");


if(f == NULL){
	printf("Kayit dosyasi bulunamadi!\n");
	exit (1);
}

hana=rand()%999;	/* tas=1 kagit=2 makas=3 */
hana=(hana%3)+1;
	if(hana==1) /*tas*/
{
	if(secim==1)
	{
		printf("Hana tas secti. Berabere kaldin.\n");	
		beraberlik+=1;
		skor+=1;
	
	}
	if(secim==2)
	{	
		printf("Hana tas secti. Helal reyiz kazandin.\n");
		kazanma+=1;
		skor+=3;
	}	
	if(secim==3)
	{	
		printf("Hana tas secti. Kaybol yenildin.\n");
		kaybetme+=1;
		skor-=2;
	}

}	
if(hana==2) /*kagit*/
{
	if(secim==1)
	{	
		printf("Hana kagit secti. Kaybol yenildin.\n");	
		kaybetme+=1;
		skor-=2;		
	}
	if(secim==2)
	{	
		printf("Hana kagit secti. Berabere kaldin.\n");	
		beraberlik+=1;
		skor+=1;
	}
	if(secim==3)
	{
		printf("Hana kagit secti. Helal reyiz kazandin.\n" );	 
		kazanma+=1;
		skor+=3;
		
	}
}	
if(hana==3) /*makas*/
{
	if(secim==1)
	{	
		printf("Hana makas secti. Helal reyiz kazandin.\n");	
		kazanma+=1;
		skor+=3;
		
	}
	if(secim==2)
	{	
		printf("Hana makas secti. Kaybol yenildin.\n");	
		kaybetme+=1;
		skor-=2;
	
	}	
	if(secim==3)
	{	
	printf("Hana tas secti. Berabere kaldin.\n");
	beraberlik+=1;
	skor+=1;
	}
}
printf("Skorun : %d \n",skor);	
printf("\n");
printf("Kazanma sayisi = %d ",kazanma);
	fprintf(f, "Kazanma: %d\n", kazanma);
printf("Kaybetme sayisi = %d ",kaybetme);
fprintf(f, "Kaybetme: %d\n", kaybetme);
printf("Beraberlik sayisi = %d \n",beraberlik); 
fprintf(f, "Beraberlik: %d\n", beraberlik);

}

printf("\n");
printf("Oyun Bitti\n");
return 0;	
}	