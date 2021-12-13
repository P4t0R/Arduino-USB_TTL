//Variables auxiliares
int cnt=1;       
String msj = "";
int c=0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //Configuramos led
  Serial1.begin(9600);              //Configuramos puerto serial

  //Enviamos mensajes de inicio comunicación serial
  Serial1.println("\t##### Conexión Serial #####\n");
  Serial1.println("Escriba un mensaje y este será retornado por Raspberry Pico,\r\nindicando cantidad de caracteres y el mensaje.\r\n\n");
}

void loop() {
  
  if (Serial1.available() > 0) {        //Si la condición se cumple existe msj
    digitalWrite(LED_BUILTIN, LOW);    //Enciende led al tipear msj
    delay(3000);                        //Tiempo de espera tipeo
    c = Serial1.available();            //Cantidad de caracteres del msj
    msj = Serial1.readString();         //La variable msj contiene el mensaje
  }
  
  if (msj != "") {                      //Condición para saber si es que existe un msj
    digitalWrite(LED_BUILTIN, HIGH);     //Apaga el led
    Serial1.print(String(cnt) + ".- MSJ " +String(c)+ " Caracteres --> " + msj + "\r\n");   //Imprime msj 
    Serial.print(String(cnt) + ".- MSJ " +String(c)+ " Caracteres --> " + msj + "\r\n");   //Imprime msj en serial monitor de arduino
    
    msj = "";                           //Borramos el msj anterior
    cnt+=1;                             //Contador
  }
}
