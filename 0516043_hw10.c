#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char SiteName[100];
    char MonitorMate[20];
    char Concentration[15];
    char ItemUnit[15];
}Item;
int n=0;
Item items[1005];
int compareSiteName (const void *ptra, const void *ptrb){
    Item *a = (Item*)ptra;
    Item *b = (Item*)ptrb;
    return strcmp(a->SiteName,b->SiteName);
}
int compareConcentration (const void *ptra, const void *ptrb){
    Item *a = (Item*)ptra;
    Item *b = (Item*)ptrb;

    long int la = strtol(a->Concentration,NULL,10);
    long int lb = strtol(b->Concentration,NULL,10);

    return (int) (lb-la);
}

int compareII (const void *ptra, const void *ptrb){
    int cmp = compareSiteName(ptra,ptrb);
    if (cmp!=0) return cmp;

    return compareConcentration(ptra,ptrb);
}
int main(){
    char inputFile[100];
    printf("input file name : ");
    scanf("%s", inputFile);
    
    FILE *fptr = fopen(inputFile,"r");
    if (fptr==NULL){
        puts("file no found");
        exit(0);
    }
    char s[200];
    while ( fgets(s,200,fptr)!=NULL ){
        char *pch = strtok(s,",\n");
        strcpy(items[n].SiteName,pch);

        pch = strtok(NULL,",\n");
        strcpy(items[n].MonitorMate,pch);

        pch = strtok(NULL,",\n");
        strcpy(items[n].Concentration,pch);

        pch = strtok(NULL,",\n");
        strcpy(items[n].ItemUnit,pch);

        n++;
    }
    fclose(fptr);
    int Itemsize=sizeof(Item);
    qsort(items+1, n-1, Itemsize, compareSiteName);
    FILE *fptrt = fopen("outcomeSingle.csv","w");
    for (int i=0; i<n; i++){
        fprintf(fptrt,"%s,%s,%s,%s\n",items[i].SiteName,items[i].MonitorMate,items[i].Concentration,items[i].ItemUnit);
    }
    fclose(fptrt);
    qsort(items+1, n-1, Itemsize, compareII);

    FILE *fptrtt = fopen("outcomePair.csv","w");
    for (int i=0; i<n; i++){
        fprintf(fptrtt,"%s,%s,%s,%s\n",items[i].SiteName,items[i].MonitorMate,items[i].Concentration,items[i].ItemUnit);
    }
    fclose(fptrtt);
    printf("Enter an integer n as a threshold : ");
    int bound; scanf("%d",&bound);

    int cnt=0;
    for (int i=0; i<n; i++){
        if (i!=0 && strtol(items[i].Concentration,NULL,10)<bound)continue;
        cnt++;
        fprintf(stdout,"%s,%s,%s,%s\n",items[i].SiteName,items[i].MonitorMate,items[i].Concentration,items[i].ItemUnit);
    }
    printf("%d warning data in total\n", cnt-1);
    system("pause");
}
