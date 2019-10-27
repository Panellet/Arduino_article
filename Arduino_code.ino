//1. Defining the communication protocol between Arduino and RoboRemo app

int on = 0; // means that Arduino is off as default.
char cmd[100];
int cmdIndex;


boolean cmdStartsWith(char *st) {
  for(int i=0; ; i++) {
    if(st[i]==0) return true;
    if(cmd[i]==0) return false;
    if(cmd[i]!=st[i]) return false;;
  }
  return false;
}


//2. Defining the relation between buttons in the roboremo-interface.interface and what Arduino recieves. 

void exeCmd() {
  
  if( cmdStartsWith("on") ) on = 1; //The command named "on" in the interface changes the variable on to 1.
  if( cmdStartsWith("off") ) on = 0;//The command named "off" in the interface changes the variable on to 0.
     
}

//3. Initiating the USB OTG Serial communication protocol between Arduino/Genuino and the RoboRemo app.

void setup() {
  
  delay(500); 

  Serial.begin(115200); //This value corresponds to the speed in bits per second (baud). 
  
  cmdIndex = 0;
}

//4. Defining variables to allow communication between the Arduino/Genuino board and the RoboRemo app.

void loop() {
  
  while(Serial.available()) {
    
    char c = (char)Serial.read();
    
    if(c=='\n') {
      cmd[cmdIndex] = 0;
      exeCmd();  // execute the command
      cmdIndex = 0; // reset the cmdIndex
    } else {      
      cmd[cmdIndex] = c;
      if(cmdIndex<99) cmdIndex++;
    }
    
  }
  
//5.   
  
  if(on) {
    int val = analogRead(A0); //Sets the A0 pin in Arduino/Genuino Board as the input pin.
    String st = (String)"v " + ((val * (5.0 / 1023.0))-0.6529)*1.68 + "\n"; //
    Serial.print(st);
    delay(1);
  }
  
}
