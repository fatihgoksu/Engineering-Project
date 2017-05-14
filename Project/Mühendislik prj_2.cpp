#include <stdio.h>
int main()
{
	int sayici=0;
	int i=0,a=0;
	char bosluk=32, bir=49, sifir=48; //ascii karþýlýkkarý
	
	FILE *ham;
	ham=fopen("dizi.txt","r+");
	while(!feof(ham))
	{
		fscanf(ham,"%c",&a);
		sayici++;
	}
	fclose(ham);
	sayici--; //dizin son boslugu saymasýn diye cýkardýk
	printf("Half sayisi ve bosluk sayisi:%d\n",sayici);
	
	char dizi[sayici];
	ham=fopen("dizi.txt","r+");
		while(!feof(ham))
	{
		fscanf(ham,"%c",&dizi[i]);
		i++;
	}
	fclose(ham);
	
	for(int j=0;j<=sayici;j++)  
	printf("%c",dizi[j]);
	printf(""); //elimizde dogru dizi varmý dýye kontrol
////////////////////////////////////////////////////////////////	
	printf("Birinci Kural:Tek sayida 1 icerenler:\n");
	int binary=1;     //birinci kelimeden baþlamak için
	int sayiyor=0;
	int var=0;
	for(i=0;i<=sayici;i++)
	{
		if(dizi[i]==bosluk)
		{
			if(sayiyor%2==1) 
				printf("%d. Kelime\n",binary);
				binary++;
				sayiyor=0;
		}
			if(dizi[i]==bir) //birleri sayýyoruz
			   sayiyor++;
	}
////////////////////////////////////////////////////////////////
	printf("Ikinci Kural:En fazla 3 tane 0 icerenler:\n");//kural en fazla uc sýfýr iceren kelimeler
    binary=1, sayiyor=0;
	for(i=0;i<=sayici;i++)
	{
		if(dizi[i]==bosluk)
		{
			if(sayiyor <=3) 	
				printf("%d. Kelime\n",binary);
				binary++;
				sayiyor=0;
		}
			if(dizi[i]==sifir) //sýfýrlarý sayýyoruz
				sayiyor++;
	}
////////////////////////////////////////////////////////////////
	printf("Ucuncu Kural:Icinde 010 icerenler:\n");//kural en fazla uc sýfýr iceren kelimeler
    binary=1, sayiyor=0;
	for(i=0;i<=sayici;i++)
	{
		if(dizi[i]==bosluk)
		{ 
		        if(var!=1)
		        printf("%d. Kelimeler\n",binary);
				binary++;
				var=0;
		}
			if(dizi[i]==sifir)     //sýfýrlarý sayýyoruz
			   if(dizi[i+1]==bir)
		          if(dizi[i+2]==sifir)
				     {
				     	if(var!=1)
				     	var=1;
				     }
		
	}
////////////////////////////////////////////////////////////////
   	printf("Dortuncu Kural:11'den once 00 icerenler:\n");//kural en fazla uc sýfýr iceren kelimeler
    binary=1, sayiyor=0;
	for(i=0;i<=sayici;i++)
	{
		if(dizi[i]==bosluk)
		{ 
				binary++;	
		}
			if(dizi[i]==sifir) //sýfýrlarý sayýyoruz
			   if(dizi[i+1]==sifir)
	       	      if(dizi[i+2]==bir)
		  		     if(dizi[i+3]==bir)  
				        printf("%d. Kelime\n",binary);
		
	}
	return 0;
}

