int i,j;
int shuzi[12][7]={
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1},
  {1,0,0,0,1,1,1},//f是10
  {0,0,0,0,0,0,0}
  
};
float juli;
int x1,x2,x3;
int n;
int tim;
void setup() {
  for(i=0;i<=12;i++)
  {
    pinMode(i,OUTPUT);
  }
pinMode(13,INPUT);
tim=millis();
digitalWrite(12,LOW);
  delayMicroseconds(2);
  digitalWrite(12,HIGH);
  delayMicroseconds(10);
  digitalWrite(12,LOW);
  juli=pulseIn(13,HIGH)*17.0/1000.0;
}

void loop() {
  if(juli<5)
  {
    digitalWrite(1,LOW);
    digitalWrite(0,HIGH);
    x1=0;
    x2=10;
    x3=10;
  }
  else if(juli<10)
  {
    digitalWrite(1,LOW);
    digitalWrite(0,LOW);
    n=(int)(juli*100);
    x1=n/100;
    x2=(n-100*x1)/10;
    x3=(n-100*x1-10*x2);
  }
  else if(juli<100)
  {
    digitalWrite(1,LOW);
    digitalWrite(0,LOW);
    n=(int)(juli*10);
    x1=n/100;
    x2=(n-100*x1)/10;
    x3=(n-100*x1-10*x2);
  }
  else if(juli<=150)
  {
    digitalWrite(1,LOW);
    digitalWrite(0,LOW);
    n=(int)juli;
    x1=n/100;
    x2=(n-100*x1)/10;
    x3=(n-100*x1-10*x2);
  }
  else
  {
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    x1=0;
    x2=10;
    x3=10;
  }
  
  
  for(i=0;i<50;i++)
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);
    for(j=0;j<7;j++){
      digitalWrite(j+2,shuzi[x1][j]);
    }
    delay(5);
    digitalWrite(9,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    for(j=0;j<7;j++){
      digitalWrite(j+2,shuzi[x2][j]);
    }
    delay(5);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    for(j=0;j<7;j++){
      digitalWrite(j+2,shuzi[x3][j]);
    }
    delay(5);
  }
  
  digitalWrite(12,LOW);
  delayMicroseconds(2);
  digitalWrite(12,HIGH);
  delayMicroseconds(3);
  digitalWrite(12,LOW);
  
  juli=pulseIn(13,HIGH)*17.0/1000.0;
}
