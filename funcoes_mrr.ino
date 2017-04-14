
/* Model Railroad - Hall Effect Position Sensores

    Definição de funções especificas deste sketch
      - DisplayStatus() Função que envia para o serial monitor a situação das variáveis
      - SensorStatus() Função que envia para o serial monitor a condição dos sensores
      - SensorExecute() Função que executa as tarefas de cada um dos sensores

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
void SensorExecute()
{
  if (Position > 1 && Position <= n_sensor - 2) {
    //Desliga os LEDs verdes no bloco que foi accionado bem como do bloco seguinte

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
