#include<stdio.h> 
void elemanlari_goster( int [10][10] );
void x( int [10][10] );
int main( void )
{	
    int i,j,n;
    int t[10][10];
    int y[10][10];
    int b[10][10] =      {0,1,0,0,0,0,0,0,0,0,
                          1,1,0,0,0,0,1,0,0,0,
                          0,1,1,1,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,1,1,1,1,1,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,1,1,0,0,0,0,0,0,
                          0,0,1,1,0,0,0,0,0,0,
                          1,1,1,1,0,0,0,0,0,0,
                          1,1,1,0,0,0,0,0,0,0};  
 while(1)          //MATRÝSSÝN DÖNGÜSÜ                                                                          
   {
       printf("Devam etmek icin birden buyuk sayi giriniz \nCikmak icin bir giriniz ");
       scanf("%ld",&n);

       if(n<2) break;
   
	elemanlari_goster( b ); //EKRANA ÝÞLEM YAPMADAN ÖNCEKÝ FONKSÝYONU BASAR VE BU MATRÝSÝ DÝYER FONKSÝYONDA KULLANMAK ÝÇÝN SAKLAR
	x(b);                  //MATRÝSÝN KONTROLLERÝNÝN YAPILDIÐI VE SON DEÐERÝ TEKRAR KULLANMAK ÝÇÝN TXT DOSYASINA KAYIT YAPAR
    
   }

    
	 return 0;
	}

void elemanlari_goster( int y[10][10] ) //ÝLK OLARAK B MATRÝSÝNÝ EKRANA BASTIRIR DÖNGÜ ÇALIÞTIKDAN SONRA BÝR ÖNCEKÝ MATRÝSÝ BASAR
{
	int i,j;
	 FILE *matris;  //ilk dünyayý dosyaya yazma
   
	matris = fopen("ilkdunya.txt", "w");
 	 
 	
		for(i=0;i<10;i++)
		{
 	      for(j=0;j<10;j++) 
 	       fprintf(matris,"%d ", y[i][j]);
 	       fprintf(matris,"\n");
         }
         
         
    fclose(matris);     
	}


void x( int b[10][10] ) //ÜST FONKSÝYONDA TXT DOSYASINA YAZILAN MATRÝSÝ ÇEKER VE KONTROLLERÝ YAPAR AYRICA DEÐÝÞEN MATRÝSÝ DÖNGÜYE SOKMAK ÝÇÝN TXT DOSYASINDA GÜNCELLER
{
	 int i,j,komsu;
     int w[10][10];  
     
	FILE *matris;  //DOSYA OKUMA ÝÞLEMÝ
   
	matris = fopen("ilkdunya.txt", "r+");
 	    for(i=0;i<10;i++)
	        for(j=0;j<10;j++)  
 	        fscanf(matris,"  %d",&w[i][j]);
 	                  
 	          for(i=0;i<10;i++)
	{
	     for(j=0;j<10;j++)  
 	         printf(" %d",w[i][j]);
 	         printf("\n"); 
 	         
 	     }
 	           for(i=0;i<10;i++){ 
               for(j=0;j<10;j++){ 
			   komsu=0;
         // MATRÝS KOMÞULARINI KONTROL ETME
            if(i>0 && j>0 )     {     if(w[i-1][j-1]==1) komsu+=1; }   
            if(i>0)              {     if(w[i-1][j]==1)   komsu+=1; }
            if(i>0 && j<10)     {     if(w[i-1][j+1]==1) komsu+=1; }        
            if(j<10)             {     if(w[i][j+1]==1)   komsu+=1; }
            if(j>0)              {     if(w[i][j-1]==1)   komsu+=1; }
            if(i<10 && j>0)     {     if(w[i+1][j-1]==1) komsu+=1; }
            if(i<10)             {     if(w[i+1][j]==1)   komsu+=1; }
            if(i<10 && j<10 )   {     if(w[i+1][j+1]==1) komsu+=1; }
 
           // ORGANÝZMA KURALLAR
 
             if ((w[i][j]==1) && komsu>3)
              b[i][j]=0;
             else if ((w[i][j]==1) && komsu <=2)
              b[i][j]=0;
             else if ((w[i][j]==1) &&komsu == 3)
              b[i][j]=1;
             else if ((w[i][j]==0) && komsu == 3)
              b[i][j]=1;
                }}  
				printf ("YENI DUNYA \n"); 
                	for(i=0;i<10;i++) {   //EKRANA MATRÝSÝN SON DEÐERÝNÝ BASMA
		 for(j=0;j<10;j++) {                    
         if(b[i][j]==1)     printf(" 1");
         else printf(" 0"); } printf("\n");  } printf("\n"); 
         
      

 		matris = fopen("ilkdunya.txt", "w"); //ÝÞLEM GÖRMÜÞ MATRÝSÝ TXT DOSYASINA KAYIT EDER
		for(i=0;i<10;i++)
		{
 	      for(j=0;j<10;j++) 
 	       fprintf(matris,"  %d",b[i][j]);
 	       fprintf(matris,"\n");
         }
         
         
    fclose(matris);  
     }
