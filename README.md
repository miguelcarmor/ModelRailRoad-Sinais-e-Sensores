ModelRailRoad-Sinais-e-Sensores

Este projecto destina-se à minha aprendizagem. Nāo serve e penso que nunca servirá para qualquer integração com sistemas de automação. Escolhi este projecto para aplicar os conhecimentos que vou adquirindo na programação em Arduino. 
Os modelos de comboios são uma área muito interessante e exigente em termos técnicos, em especial a detecção de movimento.

Vou tentar manter as várias versões que vou fazendo e documentar/comentar o mais possível.
Nesta versão está a funcionar a identificação dos próximos sensores que podem ser accionados pela mesma locomotiva.

REPITO, SE A INTENÇÃO É UTILIZAR ESTE PROJECTO PARA UM SISTEMA DE AUTOMACAO DIY! NÃO ESTÁ NO LOCAL CERTO

Identifica a posição e direcção de uma locomotiva e activa as respectivas luzes de aviso. Este Sketch faz com que o Arduino detecte, através de sensores Hall Effect, a passagem de comboios por um determinado ponto na linha e de seguida executa uma série de tarefas.

Quando uma locomotiva, com um íman colado no fundo, activa um sensor, o sketch faz o seguinte: 
-Identifica o sensor que foi activado; 
-Identifica quais são os próximos sensores possíveis de serem activados
-Sabe qual a direcção que o comboio leva; 
-Liga e desliga os sinais vermelhos e verdes, correspondentes aos blocos que estão em utilização ou que deixaram de estar.


THIS IS A LEARNING PROJECT NOT A SOLUTION FOR ANYTHING. IF YOU ARE LOOKING FOR A DIY BLOCK DETECTION OR ANY FORM OF MODEL RAILROAD AUTOMATION? YOU NEED TO LOOK ELSEWHERE :)

Identify the position and direction of a train and activate de light signals This sketch uses Hall Sensores to identify the actual position of the train and trigger a few commands.

When a loco, with a magnet on the bottom, passes over one sensor, the sketch does the following: 
-Identify the position; 
-Knows the direction; 
-Knows the next expect position 
-Turn the red and green leds, on and off, accordingly
