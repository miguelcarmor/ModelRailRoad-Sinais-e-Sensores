
/* Model Railroad - Hall Effect Position Sensores

  Identifica a posição e direcção de uma locomotiva e activa as luzes de aviso.
  Limitada a uma locomotiva

  Este Sketch detecta, através de sensores Hall Effect, a passagem de um comboio por um
  determinado ponto na linha e de seguida executa uma série de tarefas.

  Quando a locomotiva, com um íman colado no fundo, activa um sensor, o sketch
  faz o seguinte:

  - Identifica o sensor que foi activado;
  - Sabe qual a direcção que o comboio leva;
  - Liga os leds vermelhos e desliga os verdes, correspondentes aos blocos que estão em utilização
  - Liga os leds verdes e desliga os vermelhos, correspondentes aos blocos que deixaram de estar em utilização

  O pin 3 dos sensores está ligado ao arduino aos pins 14 a 18

  Esta versão só está a trabalhar com 5 sensores mas o procedimento é o mesmo até que se esgotem os pins disponiveis do arduino
*/

#define n_sensor 5 //Insira aqui o número de sensores com que vai operar no layout

int HallPin [n_sensor] = {18, 17, 16, 15, 14};     //Definir a que pinos estão ligados os sensores
int LedGreen [n_sensor] = {4, 5, 6, 7, 8};        //Definir a que pinos estão ligados os leds verdes
int LedRed [n_sensor] = {9, 10, 11, 12, 13};      //Definir a que pinos estão ligados os leds verdes

int i;

int HallPinStatus [n_sensor];                     //Variável que conterá o estado de cada um dos sensores após cada ciclo
int HallId[n_sensor];           //Identificação dos sensores para leitura "Humana"

int Position = 0;       //Variável que conterá o numero dos sensores que foram activados
int LastPosition = 0;   //Variável que conterá o numero dos sensores que foram activados anteriormente

int Direction = 0;      //Indica qual a direcção. Sentido ascendente (2) Sentido descendente (1)


void setup() {

  //Abrir a porta série
  Serial.begin(115200);

  //Definir pins e ligar leds verdes
  for (i = 0; i < n_sensor; i++) {
    pinMode (HallPin[i], INPUT);          // Definir os PINs dos sensores (14 a 18)
    pinMode (LedGreen[i], OUTPUT);        // Definir os PINs dos leds verdes (4 a 8)
    pinMode (LedRed[i], OUTPUT);          // Definir os PINs dos leds vermelhos (9 a 13)

    digitalWrite (LedGreen[i], HIGH);     // ligar os leds verdes - No arranque liga todos os LEDS em modo de linha livre até ao primeiro contacto com um sensor.
  }

  // Popular a variável com os numeros correctos
  for (i = 0; i < n_sensor; i++) {
    HallId[i] = i + 1;
  }
}


void loop() {

  // Ler o estado dos sensores
  for (i = 0; i < n_sensor; i++) {
    HallPinStatus [i] = digitalRead(HallPin[i]);
    //SensorStatus(); //Se quiser visualizar o estado dos sensores em todos os ciclos apague "//" no inicio desta linha
  }

  //Determinar qual o sensor que foi activado e executar a respectiva função.
  for (i = 0; i < n_sensor; i++) {
    if (HallPinStatus[i] == LOW) {
      SensorExecute();
      Position = i + 1;
    }
  }

  //Função que determina a direcção seguida
  DirectionStatus();

  //Estabelecer e manter a ultima posição conhecida
  if (Position != LastPosition) {

    //Chamar a função que envia para o serial monitor o status das variáveis
    //O estado das variáveis. Só são enviados para o serial monitor quando existe uma alteração de posição
    DisplayStatus();

    //Redefinir as variáveis em função das novas alterações
    LastPosition = Position;

  }

  //Chamar a função que envia para o serial monitor o status das variáveis
  //StatusDisplay(); //Se quiser visualizar todos os ciclos no serial monitor apague "//" antes da função StatusDisplay

}
