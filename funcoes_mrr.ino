
/* Model Railroad - Hall Effect Position Sensores

    Definição de funções especificas deste sketch
      - DisplayStatus() Função que envia para o serial monitor a situação das variáveis
      - SensorStatus() Função que envia para o serial monitor a condição dos sensores
      - SensorExecute() Função que executa as tarefas de cada um dos sensores
      - DirectionStatus() Função que determina a direcção seguida
      - ExpectPositionStatus() Função que estabelece  qual a posição expectável do próximo sensor


*/


// Função que envia para o serial monitor a situação das variáveis
void DisplayStatus() {


  Serial.println("");

  Serial.print(" - Actual Position: ");
  Serial.print(Position);

  Serial.print(" - Last Position: ");
  Serial.print(LastPosition);

  Serial.print(" - Direction: ");
  Serial.print(Direction);

  Serial.print(" - Expect: ");
  Serial.print(ExpectPosition[0]);
  Serial.print(ExpectPosition[1]);
  Serial.println(ExpectPosition[2]);

  Serial.println("");
  Serial.println("");

}

//Função que envia para o serial monitor a condição dos sensores
void SensorStatus()
{
  Serial.print(" - Sensor ");
  Serial.print(HallId[i]);
  Serial.print(": ");
  Serial.println(HallPinStatus[i]);
}

//Função que executa as tarefas de cada um dos sensores
//Para já só liga e desliga os LEDs verdes e vermelhos consoante o sensor que foi activado
void SensorExecute()
{
  if (Position > 1 && Position <= n_sensor - 2) {

    digitalWrite(LedGreen[Position - 2], HIGH);
    digitalWrite(LedRed[Position - 2], LOW);

    digitalWrite(LedGreen[Position - 1], LOW);
    digitalWrite(LedRed[Position - 1], HIGH);

    digitalWrite(LedGreen[Position], LOW);
    digitalWrite(LedRed[Position], HIGH);

    digitalWrite(LedGreen[Position + 1], HIGH);
    digitalWrite(LedRed[Position + 1], LOW);
  }

  else if (Position == 1) {

    digitalWrite(LedGreen[n_sensor - 1], HIGH);
    digitalWrite(LedRed[n_sensor - 1], LOW);

    digitalWrite(LedGreen[Position - 1], LOW);
    digitalWrite(LedRed[Position - 1], HIGH);

    digitalWrite(LedGreen[Position], LOW);
    digitalWrite(LedRed[Position], HIGH);

    digitalWrite(LedGreen[Position + 1], HIGH);
    digitalWrite(LedRed[Position + 1], LOW);
  }

  else if (Position == n_sensor - 1 ) {

    digitalWrite(LedGreen[Position - 2], HIGH);
    digitalWrite(LedRed[Position - 2], LOW);

    digitalWrite(LedGreen[Position - 1], LOW);
    digitalWrite(LedRed[Position - 1], HIGH);

    digitalWrite(LedGreen[Position], LOW);
    digitalWrite(LedRed[Position], HIGH);

    digitalWrite(LedGreen[Position - n_sensor + 1], HIGH);
    digitalWrite(LedRed[Position - n_sensor + 1], LOW);
  }

  else if (Position == n_sensor ) {

    digitalWrite(LedGreen[Position - 2], HIGH);
    digitalWrite(LedRed[Position - 2], LOW);

    digitalWrite(LedGreen[Position - 1], LOW);
    digitalWrite(LedRed[Position - 1], HIGH);

    digitalWrite(LedGreen[Position], LOW);
    digitalWrite(LedRed[Position], HIGH);

    digitalWrite(LedGreen[Position - n_sensor ], LOW);
    digitalWrite(LedRed[Position - n_sensor ], HIGH);

    digitalWrite(LedGreen[Position - n_sensor + 1 ], HIGH);
    digitalWrite(LedRed[Position - n_sensor + 1 ], LOW);
  }
}

//Função que determina a direcção seguida. Baseada na última posição conhecia e pela posição actual

void DirectionStatus() {
  if (Position == 1 && LastPosition == n_sensor) {
    Direction = 2;
  }
  else if (Position == n_sensor && LastPosition == 1) {
    Direction = 1;
  }
  else if (Position < LastPosition) {
    Direction = 1;
  }
  else if (Position > LastPosition) {
    Direction = 2;
  }
  else {
    Direction = 0;
  }
}

//Estabelecer e manter a posição expectável do próximo sensor
//Se passou pelo sensor 2 então as posições esperadas são 1, 2 e 3.
//Fora deste espectrum é porque se trata de outra composição

void ExpectPositionStatus() {
   if (Position == 0) {
    ExpectPosition [0] = 0;
    ExpectPosition [1] = 0;
    ExpectPosition [2] = 0;
  }
  else if (Position == 1) {
    ExpectPosition [0] = n_sensor;
    ExpectPosition [1] = Position;
    ExpectPosition [2] = Position + 1;
  }
  else if (Position == n_sensor) {
    ExpectPosition [0] = Position - 1;
    ExpectPosition [1] = Position;
    ExpectPosition [2] = 1;
  }
  else {
    ExpectPosition [0] = Position - 1;
    ExpectPosition [1] = Position;
    ExpectPosition [2] = Position + 1;
  }
}
