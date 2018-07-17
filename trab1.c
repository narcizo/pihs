#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char telaabertura[] = "\nPrograma que interpreta e calcula expressões matemáticas\n";
char pedeexpressao[] = "\nEntre com a expressão matemática => ";
char mostraS[] = "\nExpressão =";
char tituloMostra[] = "\nLista de Tokens:\n";

char express[200];

int poscar = 0;
int contapar = 0;
int listaToken = 0;
int contapar = 0;
int tipoToken = 0;

char mostraC[] = "\nCaracter =";

char msgerro1[] = "\nSímbolo Indefinido!\n";
char msgerro2[] = "\nFalta Fecha Parenteses!\n";
char msgerro3[] = "\nFecha Parentese em Excesso!\n";
char msgerro4[] = "\nFunção Inexistente!\n";
char msgerro5[] = "\nFormato Numérico Incorreto!\n";
char msgerro6[] = "\nFalta Operador Após Número!\n";

int abertura();
int le_expressao();
void fim();
void erroFim();
int pegaProx();
void cria_lista();
void trataErro(char mensagemErro[]);
void mostra_lista();
void checa_lista();
void reduz_lista();
int trataFimString();
void trataEspaco();
void trataSoma();
void trataSubtracao();
void trataMultiplicacao();
void trataDivisao();
void trataAbreParentese();
void trataFechaParentese();
void trataSeno();
void trataCosseno();
void trataTangente();
void trataLogaritmo();
void trataPotencia();
void trataRaiz();
void trataNumero();
void insereLista();
void erroPar();

int abertura(){
  printf("%s", telaabertura);

  return 0;
}

int le_expressao(){
  printf("%s", pedeexpressao);
  scanf(" %[^\n]", express);
  printf("%s %s\n", mostraS, express);

  return 0;
}

void fim(){
  exit(0);
}

void erroFim(){
  trataErro(msgerro2);
}

int trataFimString(){
  if(contapar > 0){
    erroFim();
  }

  return 0;
}

int pegaProx(){
  if(poscar == (strlen(express) - 1))
    trataFimString();
  
  switch(express[poscar]){
    case ' ':
      trataEspaco();
      break;

    case '+':
      trataSoma();
      break;

    case '-':
      trataSubtracao();
      break;

    case '*':
      trataMultiplicacao();
      break;

    case '/':
      trataDivisao();
      break;

    case '(':
      trataAbreParentese();
      break;

    case ')':
      trataFechaParentese();
      break;

    case 's':
      trataSeno();
      break;

    case 'c':
      trataCosseno();
      break;

    case 't':
      trataTangente();
      break;

    case 'l':
      trataLogaritmo();
      break;

    case 'p':
      trataPotencia();
      break;

    case 'r':
      trataRaiz();
      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      trataNumero();
      break;
    
    default:
      fim();
      break;
  }

  return 0;
}

void trataEspaco(){
  poscar++;
  pegaProx();
}

void trataSoma(){
  tipoToken = 1;
  printf("%s %c", mostraC, express[poscar]);
  insereLista();
  poscar++;
  pegaProx();
}

void trataSubtracao(){
  tipoToken = 2;
  printf("%s %c", mostraC, express[poscar]);
  insereLista();
  poscar++;
  pegaProx();
}

void trataMultiplicacao(){
  tipoToken = 3;
  printf("%s %c", mostraC, express[poscar]);
  insereLista();
  poscar++;
  pegaProx();
}

void trataDivisao(){
  tipoToken = 4;
  printf("%s %c", mostraC, express[poscar]);
  insereLista();
  poscar++;
  pegaProx();
}

void trataAbreParentese(){
  tipoToken = 5;
  printf("%s %c", mostraC, express[poscar]);
  insereLista();
  contapar++;
  poscar++;
  pegaProx();
}

void trataFechaParentese(){
  tipoToken = 6;
  printf("%s %c", mostraC, express[poscar]);
  insereLista();
  contapar--;
  if(contapar < 0)
    erroPar();
  poscar++;
  pegaProx();
}

void erroPar(){
  trataErro(msgerro3);
}

void trataSeno(){
  
}

void insereLista(){
  // malloc()
}

void cria_lista(){
  poscar = 1;
  pegaProx();
}

void trataErro(char mensagemErro[]){
  printf("%s", mensagemErro);
  fim();
}

void mostra_lista(){
  printf("%s", tituloMostra);
}

void checa_lista(){}

void reduz_lista(){}

int main(){
  abertura();
  le_expressao();
  cria_lista();
  mostra_lista();
  checa_lista();
  reduz_lista();
  fim();
}