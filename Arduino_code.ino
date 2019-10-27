//1. Set the Arduino off as Default value when connection starts.

int on = 0; // off

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


void exeCmd() {
  
  if( cmdStartsWith("on") ) on = 1;
  if( cmdStartsWith("off") ) on = 0;
     
}



void setup() {
  
  delay(500); 

  Serial.begin(576000);
  
  //analogReference(INTERNAL); // 1.1V on UNO/NANO
  
  cmdIndex = 0;
}



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
  
  if(on) {
    int val = analogRead(A0);
    String st = (String)"v " + ((val * (5.0 / 1023.0))-0.6529)*1.68 + "\n";
    Serial.print(st);
    delay(1);
  }
  
}
