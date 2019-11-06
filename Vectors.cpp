#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<iostream.h>

void readOption(int &escolha);
int chooseOption();
int chooseOptionII();
int chooseOptionIII();
int readNumber();
void readName(char nome[30]);
void insertElementBeginning(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha);
void insertElementsIV(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha);
void insertElementsEnding(int VetorNumerico[100], char VetorString[100][30], int escolha, int &contnum, int &contchar);
void checkLarger(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void checkLargerIndex(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void checkMinor(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void checkMinorIndex(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void displayElements(int VetorNumerico[100], char VetorString[100][30], int contchar, int contnum, int escolha);
void insertElementsIII (int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha);


void readOption(int &escolha)
{
    do
    {
        printf("Enter the structure you want to work with\n");
        printf("1. Numerical array\n");
        printf("2. String array\n\n  -  ");
        scanf("%d",&escolha);
        if(escolha!=1 && escolha!=2)
        {
            printf("\n\nInvalid option! Try again!\n\n");
        }
    }
    while(escolha!=1 && escolha!=2);
}



int chooseOption()
{
    int opcao;
    do
    {
        printf("\nChoose one of the options below:\n");
        printf("1. Insert an element at the beginning of the vector\n");
        printf("2. Insert an element at the end of the vector\n");
        printf("3. Insert an element before an informed element \n   OBS: If the informed element does not exist, the insertion will be at the end of the vector\n");
        printf("4. Insert an element after an informed element \n   OBS: If the informed element does not exist, the insertion will be at the beginning of vector\n");
        printf("5. Find the largest element of the vector\n");
        printf("6. Find the smallest element of the vector\n");
        printf("7. Find the position of the largest element of the vector\n");
        printf("8. Find the position of the smallest vector element\n");
        printf("9. Show the vector elements\n\n  -  ");
        scanf("%d",&opcao);
        if(opcao<1 || opcao>9)
        {
            printf("\n\nInvalid option! Try again\n\n");
        }
    }
    while(opcao<1 || opcao>9);
    return (opcao);
}


int chooseOptionII()
{
    int opcao;
    do
    {
        printf("\n\nIt is no longer possible to insert elements !! The chosen structure is complete!\n\n");
        printf("5. Find the largest element of the vector\n");
        printf("6. Find the smallest element of the vector\n");
        printf("7. Find the position of the largest element of the vector\n");
        printf("8. Find the position of the smallest vector element\n");
        printf("9. Show the vector elements\n\n  -  ");
        scanf("%d",&opcao);
        if(opcao<5 || opcao>9)
        {
            printf("\n\nInvalid option! Try again!\n\n");
        }
    }
    while(opcao<5 || opcao>9);
    return (opcao);
}


int chooseOptionIII()
{
    int opcao;
    do
    {
        printf("\nChoose one of the options below:\n");
        printf("1. Insert an element at the beginning of the vector\n");
        printf("2. Insert an element at the end of the vector\n\n  -  ");
        scanf("%d",&opcao);
        if(opcao!=1 && opcao!=2)
        {
            printf("\n\nInvalid option! Try again\n\n");
        }
    }
    while(opcao!=1 && opcao!=2);
    return (opcao);
}        


int readNumber()
{
    int num;
    printf("\n\nEnter a number\n\n  -  ");
    scanf("%d",&num);
    return (num);
}

void readName(char nome[30])
{
    
    printf("\n\nEnter a name\n\n  -  ");
    fflush(stdin);
    gets(nome);
}
   

//Inserir um elemento no inicio
void insertElementBeginning(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha)
{   
    int num,i,j,VetorAuxiliarNum[100];
    char nome[30],VetorAuxiliarStr[100][30];
    j=0;
    switch(escolha)
    {
        case 1:
            if(contnum==0)
            {   
                num=readNumber();
                VetorNumerico[0]=num;
                printf("\n\nElement inserted successfully\n\n");
                contnum++;
            }
            else
            {
                if(contnum>=100)
                {
                    printf("\n\nThe Numeric Vector is now complete\n\n");
                }
                else
                {
                    num=readNumber();
                    VetorAuxiliarNum[0]=num;
                    for(i=0;i<contnum;i++)
                    {   
                        j=i+1;
                        VetorAuxiliarNum[j]=VetorNumerico[i];
                    }
                    for(i=0;i<=contnum;i++)
                    {
                        VetorNumerico[i]=VetorAuxiliarNum[i];
                    }
                    printf("\n\nElement inserted successfully\n\n");
                    contnum++;
                }
            }
            break;
        
        case 2:
            if(contchar==0)
            {
                readName(nome);
                strcpy(VetorString[0],nome);
                contchar++;
                printf("\n\nName inserted successfully\n\n");
            }
            else
            {
                if(contchar>=100)
                {   
                    printf("\n\nThe String Vector is now complete\n\n");
                }
                else
                {
                    readName(nome);
                    strcpy(VetorAuxiliarStr[0],nome);
                    for(i=0;i<contchar;i++)
                    {
                        j=i+1;
                        strcpy(VetorAuxiliarStr[j],VetorString[i]);
                    }
                    for(i=0;i<=contchar;i++)
                    {
                                
                        strcpy(VetorString[i],VetorAuxiliarStr[i]);
                    }
                    printf("\n\nName inserted successfully\n\n");
                    contchar++;
                }
            }
            break;
    }
}
// Inserir um elemento no final do Vetor

void insertElementsEnding(int VetorNumerico[100], char VetorString[100][30], int escolha, int &contnum, int &contchar)
{
    int num;
    char nome[30];
    switch(escolha)
    {
        case 1:
            if(contnum>=100)
            {
                printf("\n\nThe Numeric Vector is now complete\n\n");
            }
            else
            {
                num=readNumber();
                VetorNumerico[contnum]=num;
                contnum++;
                printf("\n\nElement inserted successfully\n\n");
            }
            break;
        
        case 2:
            if(contchar>=100)
            {
                printf("\n\nThe String Vector is now complete\n\n");
            }
            else
            {
                readName(nome);
                strcpy(VetorString[contchar],nome);
                contchar++;
                printf("\n\nName inserted successfully\n\n");
            }
            break;
    }
}

// Encontrar o maior elemento

void checkLarger(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
{
    int maiornum,i;
    char maiorchar[30];
    switch(escolha)
    {
        case 1:
            maiornum=VetorNumerico[0];
            for(i=1;i<contnum;i++)
            {
                if(VetorNumerico[i]>maiornum)
                {
                    maiornum=VetorNumerico[i];
                }
            }
            printf("\n\nThe largest element is %d",maiornum);
            break;
            
        case 2:
            strcpy(maiorchar,VetorString[0]);
            for(i=1;i<contchar;i++)
            {
                if(strcmp(VetorString[i],maiorchar)>0)
                {
                    strcpy(maiorchar,VetorString[i]);
                }
            }
            printf("The largest element in alphabetical order is the name %s",maiorchar);
            break;
    }
}

//Encontrar a posicao do maior elemento

void checkLargerIndex(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
{
    int maiornum,indice,i;
    char maiorchar[30];
    switch(escolha)
    {
        case 1:
            maiornum=VetorNumerico[0];
            indice=0;
            for(i=1;i<contnum;i++)
            {
                if(VetorNumerico[i]>maiornum)
                {
                    indice=i;
                }
            }
            printf("\n\nThe largest element is stored in the index %d",indice);
            break;
        
        case 2:
            strcpy(maiorchar,VetorString[0]);
            indice=0;
            for(i=1;i<contchar;i++)
            {
                if(strcmp(VetorString[i],maiorchar)>0)
                {
                    indice=i;
                }
            }
            printf("\n\nThe index of the largest alphabetical order element is stored at the position %d",indice);
            break;
    }
}

//Encontrar o menor elemento do Vetor
void checkMinor(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
{
    int menornum,i;
    char menorchar[30];
    switch(escolha)
    {
        case 1:
            menornum=VetorNumerico[0];
            for(i=1;i<contnum;i++)
            {
                if(VetorNumerico[i]<menornum)
                {
                    menornum=VetorNumerico[i];
                }
            }
            printf("\n\nThe smallest element is %d",menornum);
            break;
            
        case 2:
            strcpy(menorchar,VetorString[0]);
            for(i=1;i<contchar;i++)
            {
                if(strcmp(VetorString[i],menorchar)<0)
                {
                    strcpy(menorchar,VetorString[i]);
                }
            }
            printf("The largest element in alphabetical order is the name %s",menorchar);
            break;
    }
}
 
//Encontrar a posicao do menor elemento do Vetor
              
void checkMinorIndex(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
{
    
    int i,indice,menornum;
    char menorchar[30];
    switch(escolha)
    {
        case 1:
            menornum=VetorNumerico[0];
            indice=0;
            for(i=1;i<contnum;i++)
            {
                if(VetorNumerico[i]<menornum)
                {
                    indice=i;
                }
            }
            printf("\n\nThe smallest element is stored in the index %d",indice);
            break;
            
        case 2:
            strcpy(menorchar,VetorString[0]);
            indice=0;
            for(i=1;i<contchar;i++)
            {
                if(strcmp(VetorString[i],menorchar)<0)
                {
                    indice=i;
                }
            }
            printf("\n\nThe smallest index of the smallest element in alphabetical order is at position %d",indice);
            break;
    }
}


//Mostrar os elementos do Vetor
void displayElements(int VetorNumerico[100], char VetorString[100][30], int contchar, int contnum, int escolha)
{
    int i;
    switch(escolha)
    {
        case 1:
            for(i=0;i<contnum;i++)
            {
                printf("Vetor[%d] = %d\n",i,VetorNumerico[i]);
            }
            break;
        
        case 2:
            for(i=0;i<contchar;i++)
            {
                printf("Vetor[%d] = %s\n",i,VetorString[i]);                    
            }
            break;
    }
}

//Inserir elemento antes do elemento informado pelo usuario

void insertElementsIII (int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha)
{
    bool logica;
    int x,i,num,novonum,VetorAuxiliarNum[100];
    char nome[30],novonome[30],VetorAuxiliarStr[100][30];
    logica=false;
    x=0;
    switch(escolha)
    {
        case 1:
            printf("\n\nDo you want to insert element before...\n");
            displayElements(VetorNumerico,VetorString,contchar,contnum,escolha);
            printf("\n  -  ");
            scanf("%d",&num);
            printf("Enter the element you want to insert\n\n  -  ");
            scanf("%d",&novonum);
            for(i=0;i<contnum;i++)
            {
                if(VetorNumerico[i]==num)
                {
                    VetorAuxiliarNum[x]=novonum;
                    x++;
                    logica=true;
                }
                VetorAuxiliarNum[x]=VetorNumerico[i];
                x++;
            }
            printf("\n\nElement inserted successfully\n\n");
            if(logica==true)
            {
                for(i=0;i<=contnum;i++)
                {
                    VetorNumerico[i]=VetorAuxiliarNum[i];
                }
            }
            else
            {
                VetorNumerico[contnum]=novonum;
            }
            contnum++;
            break;

       case 2:
            printf("Do you want to insert the name before...\n");
            displayElements(VetorNumerico,VetorString,contchar,contnum,escolha);
            printf("\n  -  ");
            fflush(stdin);
            gets(nome);
            printf("Enter the new name\n\n  -  ");
            fflush(stdin);
            gets(novonome);
            for(i=0;i<contchar;i++)
            {
                if(strcmp(VetorString[i],nome)==0)
                {
                    strcpy(VetorAuxiliarStr[x],novonome);
                    x++;
                    logica=true;
                }
                strcpy(VetorAuxiliarStr[x],VetorString[i]);
                x++;
            }
            printf("\n\nName inserted successfully\n\n");
            if(logica==true)
            {
                for(i=0;i<=contchar;i++)
                {
                    strcpy(VetorString[i],VetorAuxiliarStr[i]);
                }
            }
            else
            {
                strcpy(VetorString[contchar],novonome);
            }
            contchar++;
    }   
}

//Inserir depois do elemento informado pelo usuario
void insertElementsIV(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha)
{
     bool logica;
     int x,i,j,num,novonum,VetorAuxiliarNum[100];
     char novonome[30],nome[30],VetorAuxiliarStr[100][30];
     logica=false;
     x=0;
     switch(escolha)
     {
         
            case 1:
                printf("Do you want to insert element after...\n");
                displayElements(VetorNumerico,VetorString,contchar,contnum,escolha);
                printf("\n  -  ");
                scanf("%d",&num);
                printf("Enter the element you want to insert\n\n  -  ");
                scanf("%d",&novonum);
                for(i=0;i<contnum;i++)
                {
                    VetorAuxiliarNum[x]=VetorNumerico[i];
                    x++;                
                    if (VetorNumerico[i]==num)
                    {
                        VetorAuxiliarNum[x]=novonum;
                        logica=true;
                        x++;
                        contnum++;
                    }
                }
                if(logica==true)
                {
                    for(i=0;i<=contnum;i++)
                    {
                            VetorNumerico[i]=VetorAuxiliarNum[i];
                    }
                }
                else
                {
                    j=0;
                    VetorNumerico[j]=novonum;
                    j++;
                    contnum++;                       
                    for(i=0;i<contnum-1;i++)
                    {
                        VetorNumerico[j]=VetorAuxiliarNum[i];
                        j++;
                    }
                    printf("\n\nElement inserted successfully\n\n");
                }
                break;

        case 2:
            printf("\n\nDo you want to insert the name after...\n");
            displayElements(VetorNumerico,VetorString,contchar,contnum,escolha);
            printf("\n  -  ");
            fflush(stdin);
            gets(nome);
            printf("Enter the new name\n\n  -  ");
            fflush(stdin);
            gets(novonome);
            contchar++;
            for(i=0;i<contchar;i++)
            {
                strcpy(VetorAuxiliarStr[x],VetorString[i]);
                x++;
                if(strcmp(VetorString[i],nome)==0)
                {
                    strcpy(VetorAuxiliarStr[x],novonome);
                    logica=true;
                    x++;
                }
            }
            printf("\n\nName inserted successfully\n\n");
            if(logica==true)
            {
                for(i=0;i<=contchar;i++)
                {
                    strcpy(VetorString[i],VetorAuxiliarStr[i]);
                }
            }
            else
            {
                strcpy(VetorAuxiliarStr[0],novonome);
                for(i=0;i<contchar;i++)
                {
                    j=i+1;
                    strcpy(VetorAuxiliarStr[j],VetorString[i]);
                }
                for(i=0;i<contchar;i++)
                {
                    strcpy(VetorString[i],VetorAuxiliarStr[i]);
                }
                printf("\n\nName inserted successfully\n\n");
            }
            break;
    }
}
    
                        
main()
{
    int VetorNumerico[100],contnum,contchar,opcao,escolha;
    char VetorString[100][30],resp;
    contchar=0;
    contnum=0;
    do
    {
        system("cls");
        readOption(escolha);
        switch(escolha)
        {
            case 1:
                if(contnum==0)
                {
                    opcao=chooseOptionIII();
                }
                
                else
                {
                    if(contnum>=100)
                    {
                        opcao=chooseOptionII();
                    }
                    else
                    {
                        opcao=chooseOption();
                    }
                }
                break;
                
            case 2:
                if(contchar==0)
                {
                   opcao=chooseOptionIII();
                }
                else
                {
                    if(contchar>=100)
                    {
                        opcao=chooseOptionII();
                    }
                    else
                    {
                        opcao=chooseOption();
                    }
                } 
                break;
        }
        switch(opcao)
        {
            case 1:
                insertElementBeginning(VetorNumerico,VetorString,contnum,contchar,escolha);
                break;
                
            case 2:
                insertElementsEnding(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 3:
                insertElementsIII(VetorNumerico,VetorString,contnum,contchar,escolha);
                break;
                
            case 4:
                insertElementsIV(VetorNumerico,VetorString,contnum,contchar,escolha);
                break;
                
            case 5:
                checkLarger(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 6:
                checkMinor(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 7:
                checkLargerIndex(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 8:
                checkMinorIndex(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 9:
                displayElements(VetorNumerico,VetorString,contchar,contnum,escolha);
                break;
                
        }
        do
        {
            printf("\n\nDo you want to continue..<S/N>\n\n  -  ");
            fflush(stdin);
            scanf("%c",&resp);
            if(resp!='s' && resp!='S' && resp!='n' && resp!='N')
            {
                printf("\n\nInvalid option! Try again!\n\n");
            }
        }
        while(resp!='s' && resp!='S' && resp!='n' && resp!='N');
    }
    while(resp=='s' || resp=='S');
    if(resp=='n' || resp=='N')
    {
        system("PAUSE");
    }
    getch();
}
