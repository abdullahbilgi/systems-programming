#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"

int main(int argc, char **argv)
{
  IS is,is2;
  int i;

   if (argc != 3) { fprintf(stderr, "Hata: Eksik yada fazla dosya girildi ! %s\n",argv[0]); exit(1); }

    if (strcmp(argv[1] + strlen(argv[1]) - 4, ".dat") != 0) {
        fprintf(stderr, "Hata: Giris dosyasi uzantisi yanlis!\n.dat uzantili girin! '%s'\n",argv[1]);
        exit(1);
        
    }

    if (strcmp(argv[2] + strlen(argv[2]) - 4, ".dat") != 0) {
        fprintf(stderr, "Hata: Cikis dosyasi uzantisi yanlis!\n.dat uzantili girin! '%s'\n",argv[2]);
        exit(1);
    }


   is = new_inputstruct(argv[1]);
   is2 = new_inputstruct(argv[1]);

   if (is == NULL) {
     perror(argv[1]);
     exit(1);
   }

    FILE *output_file = fopen("dat/cikis.dat", "w");

    if (output_file == NULL)
    {
        fprintf(stderr, "Hata: Cikis dosyasi mevcut değil!\nCikis dosyasini kontrol ediniz! '%s'",argv[2]);
        exit(1);
    }
    

    const int MAX_STRINGS = 50;
    const int MAX_LENGTH = 20;

    int a =0;
    char strings[MAX_STRINGS][MAX_LENGTH];
    
    char line[10];
    while(get_line(is) >= 0) {
    strncpy(line,is->text1,4);
    line[4] = '\0';

    if (strcmp(line,"yaz:") == 0)
    {
        for (i = 0; i < is->NF; i++) {
    
      strcpy(strings[a], is->fields[i]);
      a++;
      
    }
    strcpy(strings[a], "-1");
        
    }
   
  }

    int b =0;
    char silString[MAX_STRINGS][MAX_LENGTH];

    char line2[10];
    while(get_line(is2) >= 0) {
    strncpy(line2,is2->text1,4);
    line2[4] = '\0';
     if (strcmp(line2,"sil:") == 0)
    {
        for (i = 0; i < is2->NF; i++) {
    
      strcpy(silString[b], is2->fields[i]);
      b++;
      
    }
    strcpy(silString[b], "-1");
    }
    
    }
    
    int yazdirSayiDizi[20];
    char yazdirCharDizi[20];


    int sayiDizi =0;
    int sayac = 0;
    int sayiChar=0;

    for (int i = 0; i < MAX_STRINGS ; i++) {
        if (strcmp(strings[i],"-1")==0)
        {
            break;
        }
        else if (strcmp(strings[i],"yaz:")==0)
        {
            sayac+=2;
            continue;
        }
        
        if (sayac%2 == 0)
        {
            yazdirSayiDizi[sayiDizi] = atoi(strings[i]);
            sayiDizi++;

        }

        if (sayac%2 != 0)
        {
            if(strcmp(strings[i],"\\b")==0){
            yazdirCharDizi[sayiChar] = '9';
            sayiChar++;

            }
            else if (strcmp(strings[i],"\\n")==0)
            {
                yazdirCharDizi[sayiChar] = '8';
                sayiChar++;
            }
            else{
            yazdirCharDizi[sayiChar] = strings[i][0];
            sayiChar++;
            }
            
        }
        
            sayac++;

    }

    int silSayiDizi[20];
    char silCharDizi[20];

    int sayiDizi2 =0;
    int sayac2 = 0;
    int sayiChar2=0;

    for (int i = 0; i < MAX_STRINGS ; i++) {
        if (strcmp(silString[i],"-1")==0)
        {
            break;
        }
        else if (strcmp(silString[i],"sil:")==0)
        {
            sayac2+=2;
            continue;
        }
        
        
        
        if (sayac2%2 == 0)
        {
            silSayiDizi[sayiDizi2] = atoi(silString[i]);
            sayiDizi2++;

        }

        if (sayac2%2 != 0)
        {
            
            silCharDizi[sayiChar2] = silString[i][0];
            sayiChar2++;
            
            
        }
            sayac2++;

    }

    for (int i = 0; i < sayiDizi2; i++)
    {
        for (int j = 0; j < sayiDizi; j++)
        {
            if ((silCharDizi[i] == yazdirCharDizi[j]) && (yazdirSayiDizi[j]>= 0))
            {
                yazdirSayiDizi[j] -= silSayiDizi[i];
            }
            
        }
        
    }


    int sonSayac = 0;
    if (output_file != NULL) {

        for (int i = 0; i < sayiDizi; i++)
        {
            sonSayac = yazdirSayiDizi[i];
            for (int j = 0;  j < sonSayac; j++)
            {
                if (yazdirCharDizi[i] == '9')
                {
                   fprintf(output_file, "\b");
                }
                else if (yazdirCharDizi[i] == '8')
                {
                   fprintf(output_file, "\n");
                }
                else
                {
                   fprintf(output_file, "%c", yazdirCharDizi[i]);
                }
                
            }
            
        }
        
    }

    printf("dur: Program sonlanmistir!\n");

    fclose(output_file);
    jettison_inputstruct(is);
    jettison_inputstruct(is2);

    return 0;

}
