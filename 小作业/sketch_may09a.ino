void setup() {
  Serial.begin(9600);
  

}

void loop() {
  char c;
  if(Serial.available())
  {
    while(c=Serial.read())
    {
      if(c>47&&c<58)
      {
        Serial.print(c-48,DEC);
      }
    }
  }

}
