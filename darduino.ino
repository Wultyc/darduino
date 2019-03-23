//Criamos uma constante com o nome de cada led (A..G) e guardamos o valor do pino onde o led está ligado
#define A 12
#define B 9
#define C 7
#define D 10
#define E 13
#define F 11
#define G 8

//O pino onde está ligado o botão
#define BTN 3

//delay de piscar os led
#define LED_DELAY 200

//Numero que vai ser sorteado
int numero = 0;

/** Mapa dos leds. Vai permitir não termos de fazer varios IF para definir o estdo dos led
	Neste mapa os 1 são os leds que vão ligar e o 0 são os que desligam
    No ambiente do arduino HIGH tem o valor 1 e LOW tem o valor 0, por isso escrever HIGH/LOW ou 1/0, respetivamente, é a mesma coisa
	
    	A	B	C	D	E	F	G
    0	0	0	0	0	0	0	0	-> Esta linha serve como estado inicial
    1	0	0	0	1	0	0	0	-> Desenha 1
    2	1	0	0	0	0	0	1	-> Desenha 2
    3	1	0	0	1	0	0	1	-> Desenha 3
    4	1	0	1	0	1	0	1	-> Desenha 4
    5	1	0	1	1	1	0	1	-> Desenha 5
    6	1	1	1	0	1	1	1	-> Desenha 6

**/

int ledMap[7][7] = {
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 0, 1},
  {1, 1, 1, 0, 1, 1, 1}
};


void setup(){
  pinMode(A, OUTPUT); //Os pinos dos leds ficam como pinos de output
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  pinMode(BTN, INPUT); //O pino do botão é um input
  
  //Este comando vai permitir que o arduino pare quando o botão for precionado
  //Mais info em: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt(digitalPinToInterrupt(BTN), sorting_start, RISING);
  
  Serial.begin(9600);
}

void loop(){
  
  //enquanto nenhum numero for selecionado a função spalh vai continuar a ser chamada
  while(numero == 0){ 
    splash();
  }
  
  //Os pinos vão ser ligados mediante o numero que for sorteado.
  digitalWrite(A, ledMap[numero][0]);
  digitalWrite(B, ledMap[numero][1]);
  digitalWrite(C, ledMap[numero][2]);
  digitalWrite(D, ledMap[numero][3]);
  digitalWrite(E, ledMap[numero][4]);
  digitalWrite(F, ledMap[numero][5]);
  digitalWrite(G, ledMap[numero][6]);
}

//Nesta função mudamos o estado de todos os leds
void ch_all(int state){
  digitalWrite(A, state);
  digitalWrite(B, state);
  digitalWrite(C, state);
  digitalWrite(D, state);
  digitalWrite(E, state);
  digitalWrite(F, state);
  digitalWrite(G, state);
}

//Nesta função definimos o comportamento dos leds antes de qualquer número ser sorteado
void splash(){
  ch_all(1); //Liga todos
  delay(LED_DELAY);
  ch_all(0); //Desliga todos
  
  //Começa o efeito
  digitalWrite(A, HIGH);
  delay(LED_DELAY);
  digitalWrite(A, LOW);
  
  digitalWrite(B, HIGH);
  delay(LED_DELAY);
  digitalWrite(B, LOW);
  
  digitalWrite(C, HIGH);
  delay(LED_DELAY);
  digitalWrite(C, LOW);
  
  digitalWrite(D, HIGH);
  delay(LED_DELAY);
  digitalWrite(D, LOW);
  
  digitalWrite(E, HIGH);
  delay(LED_DELAY);
  digitalWrite(E, LOW);
  
  digitalWrite(F, HIGH);
  delay(LED_DELAY);
  digitalWrite(F, LOW);
  
  digitalWrite(G, HIGH);
  delay(LED_DELAY);
  digitalWrite(G, LOW);
  
  digitalWrite(F, HIGH);
  delay(LED_DELAY);
  digitalWrite(F, LOW);
  
  digitalWrite(E, HIGH);
  delay(LED_DELAY);
  digitalWrite(E, LOW);
  
  digitalWrite(D, HIGH);
  delay(LED_DELAY);
  digitalWrite(D, LOW);
  
  digitalWrite(C, HIGH);
  delay(LED_DELAY);
  digitalWrite(C, LOW);
  
  digitalWrite(B, HIGH);
  delay(LED_DELAY);
  digitalWrite(B, LOW);
  
  digitalWrite(A, HIGH);
  delay(LED_DELAY);
  digitalWrite(A, LOW);
  
}

//Nesta função definimos o comportamento dos leds durante o sorteio
void sorting_led(){
  ch_all(1); //Liga todos
  delay(LED_DELAY);
  ch_all(0); //Desliga todos
  
  //Começa o efeito
  digitalWrite(A, HIGH);
  delay(LED_DELAY);
  digitalWrite(A, LOW);
  
  digitalWrite(B, HIGH);
  delay(LED_DELAY);
  digitalWrite(B, LOW);
  
  digitalWrite(C, HIGH);
  delay(LED_DELAY);
  digitalWrite(C, LOW);
  
  digitalWrite(D, HIGH);
  delay(LED_DELAY);
  digitalWrite(D, LOW);
  
  digitalWrite(E, HIGH);
  delay(LED_DELAY);
  digitalWrite(E, LOW);
  
  digitalWrite(F, HIGH);
  delay(LED_DELAY);
  digitalWrite(F, LOW);
  
  digitalWrite(G, HIGH);
  delay(LED_DELAY);
  digitalWrite(G, LOW);
  
  ch_all(1); //Liga todos
  delay(LED_DELAY);
  ch_all(0); //Desliga todos
}

//Esta função serve para definir um numero aleatorio e hama a função que muda o comportamento dos led durante o sorteio
void sorting_start(){
  numero= random(1, 6);
  Serial.println(numero);
  sorting_led();
}
