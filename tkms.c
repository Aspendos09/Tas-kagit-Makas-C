#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
printf("Tas Kagit Makas oyununa hos geldiniz. Lutfen hamlenizi seciniz(tas=1,kagit=2,makas=3). Bu arada Hana kim?\n ");
int hana,secim;
srand(time(NULL));
hana=rand()%2;/* tas=0 kagit=1 makas=2 */

scanf("%d",&secim);
	if(hana==0) /*tas*/
{
	if(secim==1)
	printf("Hana tas secti. Berabere kaldin.\n");	
	
	if(secim==2)
	printf("Hana tas secti. Helal reyiz kazandin.\n");	
	if(secim==3)
	printf("Hana tas secti. Kaybol yenildin.\n");	
}	
if(hana==1) /*kagit*/
{
	if(secim==1)
	printf("Hana kagit secti. Kaybol yenildin.\n");	
	
	if(secim==2)
	printf("Hana kagit secti. Berabere kaldin.\n");	
	if(secim==3)
	printf("Hana kagit secti. Helal reyiz kazandin.\n" );	 
}	
if(hana==2) /*makas*/
{
	if(secim==1)
	printf("Hana makas secti. Helal reyiz kazandin.\n");	
	
	if(secim==2)
	printf("Hana makas secti. Kaybol yenildin.\n");	
	if(secim==3)
	printf("Hana tas secti. Berabere kaldin.\n");	
}
printf("Oyun Bitti\n");
return 0;	
}	