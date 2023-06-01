#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int simpson_fonk(int altsinir,int ustsinir,int bolum,int katsayi1,int katsayi2,int katsayi3,int katsayi4)
{
float f(float x)
    {
        float fonksiyon;
        fonksiyon=katsayi1*(pow(x, 3)) + katsayi2*(pow(x, 2))+katsayi3*pow(x,1)+katsayi4*pow(x,0);
        return(fonksiyon);
    }

    int i;
    float toplam=0.0;
    float alan_1=0.0;
    float  alan_2=0.0;
    double a=altsinir;

    printf("%d",a);
    double b=ustsinir;
    printf("%d",b);
    double n=bolum;
    printf("%f",n);
    double h;
    h= (b-a)/n;
    printf("%lf",h);

{
for(i=1;i<=bolum-1;i++)
  {
     if(i%2==0)
       {
            alan_1+=f(altsinir+i*h);
        }
        else
        {
            alan_2+=f(altsinir+i*h);
         }
  }
  toplam=(h/3)*(f(altsinir)+f(ustsinir)+4*alan_2+2*alan_1);

   printf("Simpson Alan Hesabi = %f\n",toplam);
}

}
//////////////////////////////
float rectangle_fonk(int altsinir,int ustsinir,int bolum,int katsayi1,int katsayi2,int katsayi3,int katsayi4)
{
double fonk(double x,double h,int i)
{
double sonuc;
sonuc=katsayi1*pow(x+h*i,3)+katsayi2*pow(x+h*i,2)+katsayi3*pow(x+h*i,1)+katsayi4*pow(x+h*i,0);
return sonuc;
}
    double alan=0.0;
    double h=0.0;
    h=(float)(ustsinir-altsinir)/bolum;
    int j;
    for(j=1;j<=bolum;j++)
    {
        alan+=h*fonk(altsinir,h,j-1);
    }
    printf("Rectangle Alan Hesabi = %f\n",alan);
}

int main(int argc, char* argv[])
{
    int giris;
    int i,j, cevap, katsayi1, katsayi2, katsayi3, katsayi4, altsinir, ustsinir, secim,bolum;

    katsayi1 = atoi(argv[1]);
    katsayi2 = atoi(argv[6]);
    katsayi3 = atoi(argv[11]);
    katsayi4 = atoi(argv[16]);
    altsinir = atoi(argv[20]);
    ustsinir = atof(argv[21]);
    bolum=atof(argv[22]);
    giris=atof(argv[23]);

    switch(giris)
    {
    case 0:
        rectangle_fonk(altsinir,ustsinir,bolum,katsayi1,katsayi2,katsayi3,katsayi4);
        break;
    case 1:
        simpson_fonk(altsinir,ustsinir,bolum,katsayi1,katsayi2,katsayi3,katsayi4);
        break;
    default:
        printf("Yanlis girdiniz");
    }
}
