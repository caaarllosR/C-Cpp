#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
 
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

char DiaIniIn[7];
char MomentoIniIn[13];

char DiaFimIn[7];
char MomentoFimIn[13];


scanf("%[^\n]",&DiaIniIn);
flush_in();

scanf("%[^\n]",&MomentoIniIn);
flush_in();

scanf("%[^\n]",&DiaFimIn);
flush_in();

scanf("%[^\n]",&MomentoFimIn);


char *DiaIni_param  = strtok(DiaIniIn, "Dia ");
char *HoraIni_param = strtok(MomentoIniIn, " : ");
char *MinIni_param = strtok(NULL, " : ");
char *SegIni_param = strtok(NULL, " : ");

char *DiaFim_param  = strtok(DiaFimIn, "Dia ");
char *HoraFim_param = strtok(MomentoFimIn, " : ");
char *MinFim_param = strtok(NULL, " : ");
char *SegFim_param = strtok(NULL, " : ");

int DiaIni, HoraIni, MinIni, SegIni;
int DiaFim, HoraFim, MinFim, SegFim;

DiaIni  = atoi(DiaIni_param);
HoraIni = atoi(HoraIni_param);
MinIni  = atoi(MinIni_param);
SegIni  = atoi(SegIni_param);
  
DiaFim  = atoi(DiaFim_param);
HoraFim = atoi(HoraFim_param);
MinFim  = atoi(MinFim_param);
SegFim  = atoi(SegFim_param);


int TotalSeg = SegFim-SegIni;
int TotalMin = MinFim-MinIni;
int TotalHoras = HoraFim-HoraIni;
int TotalDias  = DiaFim-DiaIni;


int DiasAux = 0;
if(TotalHoras < 0)
{
   DiasAux = 1;
}
else if(TotalHoras == 0)
{
    if(TotalMin < 0)
    {
       DiasAux = 1;
    }
    else if(TotalMin == 0)
    {
        if(TotalSeg < 0)
        {
           DiasAux = 1;
        }
    }

}


int HoraAux = 0;
if(TotalMin < 0)
{
   HoraAux = 1;
}
else if(TotalMin == 0)
{
    if(TotalSeg < 0)
    {
       HoraAux = 1;
    }
}


int MinAux = 0;
if(TotalSeg < 0)
{
   MinAux = 1;
}


TotalSeg = MinAux*60+TotalSeg;
TotalMin = HoraAux*60+TotalMin-MinAux;
TotalHoras = DiasAux*24+TotalHoras-HoraAux;
TotalDias  = TotalDias - DiasAux;



    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", TotalDias, TotalHoras, TotalMin, TotalSeg);

    return 0;
}