class Btn
{
 public:
 int *pino;
 bool btnclicado;
 bool btnliberado;
 int ultimoEstadoBtn=LOW;
 unsigned long tempoPrimeiroAcionamento=0;
 unsigned long tempoDebounce=50;
 typedef void (funcao){void};
 //typedef retorno (nome_funcao)(Paramentros de entrada);

  Btn(int p){
   btnclicado=false;
   btnliberado=false;
   this->pino=p;
  }

 void clique(funcao *f){
  //Rotina Debounce
  int leitura=digitalRead(*pino);
  if (leirura!=ultimoEstadoBtn){tempoPrimeiroAcionamento=millis();}
   if((millis()-tempoPrimeiroAcionamento>tempoDebounce){
    //Debounce tratado, comanndos que serão executados no acionamento do botão
    if(digitalRead(*pino)){
     btnclicado=true;
     btnliberado=false;
     }else {
       btnliberado=true;
     }

    if((btnclicado)and(btnliberado)){
     btnclicado=false;
     btnliberado=false;
     f();
    }

   ultimoEstadoBtn=leitura;

  }
};
