#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>
Servo myservo;
int pos=0; // position of servo motor
LiquidCrystal lcd(A4, A5, A3, A2, A1, A0);
const byte rows=4;
const byte cols=3;
 
char key[rows][cols]={
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};
byte rowPins[rows]={0,1,2,3};
byte colPins[cols]={4,5,6};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="3235";
int currentposition=0;
 
int red = 13;
int green = 12;
 
void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  myservo.attach(9);  
  lcd.begin(16,2); 
}
 
void loop(){
  if( currentposition==0){
  displayscreen(); 
  }

  int l ;
  char code=keypad.getKey();
  if(code!=NO_KEY){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PASSWORD::");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);

  for(l=0;l<=currentposition;++l){
     lcd.print("*");
   }
  
  if(code==password[currentposition]){
       ++currentposition;
       if(currentposition==4){
          unlockdoor();
          currentposition=0;
        }
    }else{
       incorrect();
       currentposition=0;
     }
   }
}
 
//------------------ unlock door()--------------//
 
void unlockdoor(){
  digitalWrite(12,HIGH);
  delay(800);
  digitalWrite(12,LOW);
  delay(900);
  lcd.setCursor(0,0);
  lcd.println(" ");
  lcd.setCursor(1,0);
  lcd.print("Access Granted");
  lcd.setCursor(4,1);
  lcd.println("WELCOME");
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(16,1);
  lcd.println(" ");
  lcd.setCursor(14,1);
  lcd.println(" ");
  lcd.setCursor(13,1);
  lcd.println(" ");

  for(pos =0; pos<=180; pos +=5){
      myservo.write(pos); 
      delay(5); 
   }
  delay(800);
  counterbeep();
 
  delay(600);
  for(pos = 180; pos >= 0; pos -=5){ 
     myservo.write(pos); 
     delay(15);
     currentposition=0;
     lcd.clear();
     displayscreen();
   }
}
 
//--------------------incorrect()--------------//
 
void incorrect(){
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("CODE ");
  lcd.setCursor(5,0);
  lcd.print("INCORRECT");
  delay(700);
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(0,1);
  lcd.println("CALLING AUTOBOTS"); 
  delay(1700);
  lcd.clear();
  displayscreen();
}

//-------clearscreen()--------------------/
void clearscreen(){
  lcd.setCursor(0,0);
  lcd.println(" ");
  lcd.setCursor(0,1);
  lcd.println(" ");
  lcd.setCursor(0,2);
  lcd.println(" ");
  lcd.setCursor(0,3);
  lcd.println(" ");
}

//------------displayscreen()--------------------//
void displayscreen(){
  lcd.setCursor(0,0);
  lcd.println("ENTER CODE");
  lcd.setCursor(0 ,1);
  lcd.println("TO UNLOCK DOOR");
}


 
//-------------- counterbeep()------------------//
void counterbeep(){
  delay(500); 
  lcd.clear();

  lcd.setCursor(2,0);
  delay(400);
  lcd.println("GET IN PLEASE");
  lcd.setCursor(4,1);
  lcd.print(" 5 ");
  delay(400);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.println("DOOR IS OPEN");
  delay(500);

  lcd.setCursor(2,0);
  lcd.println("GET IN PLEASE");
  lcd.setCursor(4,1); 
  lcd.print(" 4 ");
  delay(400);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.println("DOOR IS OPEN");
  delay(500);

  lcd.setCursor(2,0);
  lcd.println("GET IN PLEASE");
  lcd.setCursor(4,1); 
  lcd.print(" 3 ");
  delay(400);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.println("DOOR IS OPEN");
  delay(500);

  lcd.setCursor(2,0);
  lcd.println("GET IN PLEASE");
  lcd.setCursor(4,1); 
  lcd.print(" 2 ");
  delay(400);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.println("DOOR IS OPEN");
  delay(500);

  lcd.setCursor(2,0);
  lcd.println("GET IN PLEASE");
  lcd.setCursor(4,1);
  lcd.print(" 1 ");
  delay(400);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.println("DOOR IS OPEN");
  delay(500);


  delay(500);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("RE-LOCKING");
  delay(400);
  lcd.setCursor(12,0);
  lcd.print(".");
  delay(400);
  lcd.setCursor(13,0);
  lcd.print(".");
  delay(400);
  lcd.setCursor(14,0);
  lcd.print(".");
  delay(400);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("GOOD BYE!");
  delay(600);
}
