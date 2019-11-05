#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<iostream.h>

void LerOpcao(int &escolha);
int EscolherOpcao();
int EscolherOpcaoII();
int EscolherOpcaoIII();
int LerNumero();
void LerNome(char nome[30]);
void InserirElementoInicio(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha);
void InserirElementosIV(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha);
void InserirElementoFinal(int VetorNumerico[100], char VetorString[100][30], int escolha, int &contnum, int &contchar);
void VerificarMaior(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void VerificarMaiorIndice(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void VerificarMenor(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void VerificarMenorIndice(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar);
void MostrarElementos(int VetorNumerico[100], char VetorString[100][30], int contchar, int contnum, int escolha);
void InserirElementosIII (int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha);


void LerOpcao(int &escolha)
{
    do
    {
        printf("Digite a estrutura com que deseja trabalhar\n");
        printf("1. Vetor Numerico\n");
        printf("2. Vetor de String\n\n  -  ");
        scanf("%d",&escolha);
        if(escolha!=1 && escolha!=2)
        {
            printf("\n\nOpcao Invalida!! Tente Novamente!!\n\n");
        }
    }
    while(escolha!=1 && escolha!=2);
}



int EscolherOpcao()
{
    int opcao;
    do
    {
        printf("\nEscolha uma das opcoes abaixo para ser analisada:\n");
        printf("1. Inserir um elemento no inicio do vetor\n");
        printf("2. Inserir um elemento no final do vetor\n");
        printf("3. Inserir um elemento antes de um elemento informado \n   OBS: Se o elemento informado nao existir a insercao sera no final do vetor\n");
        printf("4. Inserir um elemento depois de um elemento informado \n   OBS: Se o elemento informado nao existir a insercao sera no inicio de vetor\n");
        printf("5. Encontrar o maior elemento do vetor\n");
        printf("6. Encontrar o menor elemento do vetor\n");
        printf("7. Encontrar a posicao do maior elemento do vetor\n");
        printf("8. Encontrar a posicao do menor elemento do vetor\n");
        printf("9. Mostrar os elemento do vetor\n\n  -  ");
        scanf("%d",&opcao);
        if(opcao<1 || opcao>9)
        {
            printf("\n\nOpcao Invalida!! Tente Novamente\n\n");
        }
    }
    while(opcao<1 || opcao>9);
    return (opcao);
}


int EscolherOpcaoII()
{
    int opcao;
    do
    {
        printf("\n\nNao e mais possivel inserir elementos!! O estrutura escolhida esta completa!\n\n");
        printf("5. Encontrar o maior elemento do vetor\n");
        printf("6. Encontrar o menor elemento do vetor\n");
        printf("7. Encontrar a posicao do maior elemento do vetor\n");
        printf("8. Encontrar a posicao do menor elemento do vetor\n");
        printf("9. Mostrar os elemento do vetor\n\n  -  ");
        scanf("%d",&opcao);
        if(opcao<5 || opcao>9)
        {
            printf("\n\nOpcao Invalida!! Tente Novamente!!\n\n");
        }
    }
    while(opcao<5 || opcao>9);
    return (opcao);
}


int EscolherOpcaoIII()
{
    int opcao;
    do
    {
        printf("\nEscolha uma das opcoes abaixo para ser analisada:\n");
        printf("1. Inserir um elemento no inicio do vetor\n");
        printf("2. Inserir um elemento no final do vetor\n\n  -  ");
        scanf("%d",&opcao);
        if(opcao!=1 && opcao!=2)
        {
            printf("\n\nOpcao Invalida!! Tente Novamente\n\n");
        }
    }
    while(opcao!=1 && opcao!=2);
    return (opcao);
}        


int LerNumero()
{
    int num;
    printf("\n\nDigite um numero\n\n  -  ");
    scanf("%d",&num);
    return (num);
}

void LerNome(char nome[30])
{
    
    printf("\n\nDigite um nome\n\n  -  ");
    fflush(stdin);
    gets(nome);
}
   

//Inserir um elemento no inicio
void InserirElementoInicio(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha)
{   
    int num,i,j,VetorAuxiliarNum[100];
    char nome[30],VetorAuxiliarStr[100][30];
    j=0;
    switch(escolha)
    {
        case 1:
            if(contnum==0)
            {   
                num=LerNumero();
                VetorNumerico[0]=num;
                printf("\n\nElemento inserido com sucesso\n\n");
                contnum++;
            }
            else
            {
                if(contnum>=100)
                {
                    printf("\n\nO Vetor Numerico ja esta completo\n\n");
                }
                else
                {
                    num=LerNumero();
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
                    printf("\n\nElemento inserido com sucesso\n\n");
                    contnum++;
                }
            }
            break;
        
        case 2:
            if(contchar==0)
            {
                LerNome(nome);
                strcpy(VetorString[0],nome);
                contchar++;
                printf("\n\nNome inserido com sucesso\n\n");
            }
            else
            {
                if(contchar>=100)
                {   
                    printf("\n\nO Vetor de String ja esta cheio\n\n");
                }
                else
                {
                    LerNome(nome);
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
                    printf("\n\nNome inserido com sucesso\n\n");
                    contchar++;
                }
            }
            break;
    }
}
// Inserir um elemento no final do Vetor

void InserirElementoFinal(int VetorNumerico[100], char VetorString[100][30], int escolha, int &contnum, int &contchar)
{
    int num;
    char nome[30];
    switch(escolha)
    {
        case 1:
            if(contnum>=100)
            {
                printf("\n\nO Vetor Numerico ja esta completo\n\n");
            }
            else
            {
                num=LerNumero();
                VetorNumerico[contnum]=num;
                contnum++;
                printf("\n\nElemento inserido com sucesso\n\n");
            }
            break;
        
        case 2:
            if(contchar>=100)
            {
                printf("\n\nO Vetor de String ja esta cheio\n\n");
            }
            else
            {
                LerNome(nome);
                strcpy(VetorString[contchar],nome);
                contchar++;
                printf("\n\nNome inserido com sucesso\n\n");
            }
            break;
    }
}

// Encontrar o maior elemento

void VerificarMaior(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
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
            printf("\n\nO maior elemento digitado foi %d",maiornum);
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
            printf("O maior elemento em ordem alfabetica e o nome %s",maiorchar);
            break;
    }
}

//Encontrar a posicao do maior elemento

void VerificarMaiorIndice(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
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
            printf("\n\nO maior elemento esta armazenado do indice %d",indice);
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
            printf("\n\nO indice do maior elemenro ordem alfabetica esta armazenado na posicao %d",indice);
            break;
    }
}

//Encontrar o menor elemento do Vetor
void VerificarMenor(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
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
            printf("\n\nO menor elemento digitado foi %d",menornum);
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
            printf("O maior elemento em ordem alfabetica e o nome %s",menorchar);
            break;
    }
}
 
//Encontrar a posicao do menor elemento do Vetor
              
void VerificarMenorIndice(int VetorNumerico[100], char VetorString[100][30], int escolha, int contnum, int contchar)
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
            printf("\n\nO menor elemento esta armazenado no indice %d",indice);
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
            printf("\n\nO indice de menor do menor elemento em ordem alfabetica esta na posicao %d",indice);
            break;
    }
}


//Mostrar os elementos do Vetor
void MostrarElementos(int VetorNumerico[100], char VetorString[100][30], int contchar, int contnum, int escolha)
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

void InserirElementosIII (int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha)
{
    bool logica;
    int x,i,num,novonum,VetorAuxiliarNum[100];
    char nome[30],novonome[30],VetorAuxiliarStr[100][30];
    logica=false;
    x=0;
    switch(escolha)
    {
        case 1:
            printf("\n\nDeseja inserir antes de que elemento..\n");
            MostrarElementos(VetorNumerico,VetorString,contchar,contnum,escolha);
            printf("\n  -  ");
            scanf("%d",&num);
            printf("Informe o elemento que deseja inserir\n\n  -  ");
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
            printf("\n\nElemento inserido com sucesso\n\n");
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
            printf("Deseja inserir antes de que nome..\n");
            MostrarElementos(VetorNumerico,VetorString,contchar,contnum,escolha);
            printf("\n  -  ");
            fflush(stdin);
            gets(nome);
            printf("Digite o novo nome\n\n  -  ");
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
            printf("\n\nElemento inserido com sucesso\n\n");
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
void InserirElementosIV(int VetorNumerico[100], char VetorString[100][30], int &contnum, int &contchar, int escolha)
{
     bool logica;
     int x,i,j,num,novonum,VetorAuxiliarNum[100];
     char novonome[30],nome[30],VetorAuxiliarStr[100][30];
     logica=false;
     x=0;
     switch(escolha)
     {
         
            case 1:
                printf("Deseja inserir depois de que elemento..\n");
                MostrarElementos(VetorNumerico,VetorString,contchar,contnum,escolha);
                printf("\n  -  ");
                scanf("%d",&num);
                printf("Informe o elemento que deseja inserir\n\n  -  ");
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
                    printf("\n\nElemento inserido com sucesso\n\n");
                }
                break;

        case 2:
            printf("\n\nDeseja inserir depois de que nome..\n");
            MostrarElementos(VetorNumerico,VetorString,contchar,contnum,escolha);
            printf("\n  -  ");
            fflush(stdin);
            gets(nome);
            printf("Digite o nome que deseja inserir\n\n  -  ");
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
            printf("\n\nNome inserido com sucesso\n\n");
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
                printf("\n\nNome inserido com sucesso\n\n");
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
        LerOpcao(escolha);
        switch(escolha)
        {
            case 1:
                if(contnum==0)
                {
                    opcao=EscolherOpcaoIII();
                }
                
                else
                {
                    if(contnum>=100)
                    {
                        opcao=EscolherOpcaoII();
                    }
                    else
                    {
                        opcao=EscolherOpcao();
                    }
                }
                break;
                
            case 2:
                if(contchar==0)
                {
                   opcao=EscolherOpcaoIII();
                }
                else
                {
                    if(contchar>=100)
                    {
                        opcao=EscolherOpcaoII();
                    }
                    else
                    {
                        opcao=EscolherOpcao();
                    }
                } 
                break;
        }
        switch(opcao)
        {
            case 1:
                InserirElementoInicio(VetorNumerico,VetorString,contnum,contchar,escolha);
                break;
                
            case 2:
                InserirElementoFinal(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 3:
                InserirElementosIII(VetorNumerico,VetorString,contnum,contchar,escolha);
                break;
                
            case 4:
                InserirElementosIV(VetorNumerico,VetorString,contnum,contchar,escolha);
                break;
                
            case 5:
                VerificarMaior(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 6:
                VerificarMenor(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 7:
                VerificarMaiorIndice(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 8:
                VerificarMenorIndice(VetorNumerico,VetorString,escolha,contnum,contchar);
                break;
                
            case 9:
                MostrarElementos(VetorNumerico,VetorString,contchar,contnum,escolha);
                break;
                
        }
        do
        {
            printf("\n\nDeseja continuar..<S/N>\n\n  -  ");
            fflush(stdin);
            scanf("%c",&resp);
            if(resp!='s' && resp!='S' && resp!='n' && resp!='N')
            {
                printf("\n\nOpcao invalida!! Tente novamente!!\n\n");
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
