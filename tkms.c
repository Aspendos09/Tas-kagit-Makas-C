#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{

int hana,secim=0 ,kazanma=0 ,kaybetme=0 ,beraberlik=0;
/* tas=0 kagit=1 makas=2 */


while(secim!=4)
{
printf("Tas Kagit Makas oyununa hos geldiniz. Lutfen hamlenizi seciniz(tas=1,kagit=2,makas=3,bitirmek icin 4 ). Bu arada Hana kim?\n ");	
scanf("%d",&secim);	
srand(time(NULL));
hana=rand()%2;	/* tas=0 kagit=1 makas=2 */
	if(hana==0) /*tas*/
{
	if(secim==1)
	{
		printf("Hana tas secti. Berabere kaldin.\n");	
		beraberlik+=1;
	}
	if(secim==2)
	{	
		printf("Hana tas secti. Helal reyiz kazandin.\n");
		kazanma+=1;
	}	
	if(secim==3)
	{	
		printf("Hana tas secti. Kaybol yenildin.\n");
		kaybetme+=1;
	}

}	
if(hana==1) /*kagit*/
{
	if(secim==1)
	{	
		printf("Hana kagit secti. Kaybol yenildin.\n");	
		kaybetme+=1;
	}
	if(secim==2)
	{	
		printf("Hana kagit secti. Berabere kaldin.\n");	
		beraberlik+=1;
	}
	if(secim==3)
	{
		printf("Hana kagit secti. Helal reyiz kazandin.\n" );	 
		kazanma+=1;
	}
}	
if(hana==2) /*makas*/
{
	if(secim==1)
	{	
		printf("Hana makas secti. Helal reyiz kazandin.\n");	
		kazanma+=1;
	}
	if(secim==2)
	{	
		printf("Hana makas secti. Kaybol yenildin.\n");	
		kaybetme+=1;
	}	
	if(secim==3)
	{	
	printf("Hana tas secti. Berabere kaldin.\n");
	beraberlik+=1;
	}
}	
printf("\n");
printf("Kazanma sayisi = %d ",kazanma);
printf("Kaybetme sayisi = %d ",kaybetme);
printf("Beraberlik sayisi = %d \n",beraberlik); 

}

printf("\n");
printf("Oyun Bitti\n");
return 0;	
}	
