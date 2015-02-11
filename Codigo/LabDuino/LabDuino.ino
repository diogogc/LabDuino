#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define d1 = 2;
#define d2 = 3;
#define d3 = 4;
#define d5 = 5;

#define s1 = A0;
#define s2 = A1;
#define s3 = A2;
#define s4 = A3;

LiquidCrystal_I2C lcd(0x20,16,2); // set the LCD address to 0x20 for a 16 chars and 2 line display
int screenWidth = 16;
int screenHeight = 2;
/*
  ImputBotoes
*/
byte x=0;
/*
  Caracteres personalizados
*/
byte indicador[8] = {
	0b01000,
	0b01100,
	0b01110,
	0b01111,
	0b01110,
	0b01100,
	0b01000,
	0b00000
};

byte homeLogo[8] = {
	0b00000,
	0b00000,
	0b00100,
	0b01010,
	0b11111,
	0b10001,
	0b10101,
	0b10101
};

byte inicioLogo[8] = {
	0b11111,
	0b00000,
	0b01110,
	0b00100,
	0b00100,
	0b01110,
	0b00000,
	0b11111
};

byte fimLogo[8] = {
	0b11111,
	0b00000,
	0b01110,
	0b01000,
	0b01100,
	0b01000,
	0b01000,
	0b11111
};

byte capacitorLogo[8] = {
	0b11111,
	0b00000,
	0b01010,
	0b11011,
	0b11011,
	0b01010,
	0b00000,
	0b11111
};
/*
  Controle de Paginacao
*/
boolean onSubOption = false;
boolean isOnExperimento = false;

int currentSelection=0;
int optionSelected=0;

String mainOption1 = "Fisica";
String mainOption2 = "Quimica";
String mainOption3 = "Biologia";
String mainOption4 = "Matematica";
String mainOptions[4] = {mainOption1,mainOption2,mainOption3,mainOption4};

String optionFisica1 = "Velocidade Med";
String optionFisica2 = "Velocidade Inst";

String subOptionFisica[2] = {optionFisica1,optionFisica2};

/*
  Pega o click do botao e muda a opcao selecionada
*/

int pegaInputBotao()
{
  Wire.requestFrom(33,2);       //Se PCF8574A - mude de 33 para 57 
  if(Wire.available())     //If the request is available
  {
    x=Wire.read();       //Receive the data
  }
  if(x<255)                     //If the data is less than 255
  {
    if (x==249) {return 1; } //Down
    if (x==250) { return 2; } //Up
    if (x==252) { return 3; } //Enter
    if (x==251) { return 4; } //ES
  }
  else
  {
    return 0;
  }
//  return x;
}

void navegate(int limit)
{
  if((currentSelection < (limit-1)))
  {
//      if(digitalRead(2)==HIGH){
    if(pegaInputBotao()==2){
        currentSelection+=1;
        lcd.clear();
      }
      else
      {
        if(currentSelection >0){
//          if(digitalRead(3)==HIGH){
        if(pegaInputBotao()==1){
            currentSelection-=1;
            lcd.clear();
          }
        }
      }
   }
   if(currentSelection==(limit-1))
   {
//     if(digitalRead(3)==HIGH){
  if(pegaInputBotao()==1){
          currentSelection-=1;
          lcd.clear();
        }
   }
   if(currentSelection==0)
   {
//     if(digitalRead(2)==HIGH){
  if(pegaInputBotao()==2){
          currentSelection+=1;
          lcd.clear();
        }
   }
}
/*
  Pega o click no botao "Enter"
*/
void getEnterPress()
{
  if(pegaInputBotao()==3)
  {
    if(!onSubOption)
    {
      onSubOption = true;
      currentSelection=0;
      lcd.clear();
    }
    else
    {
      //TODO Implementar chamar experimentos
      if(pegaInputBotao()==4)
      {
        onSubOption = false;
        currentSelection = optionSelected;
        lcd.clear();
      }
//      else
//      { 
//        if(escapeString=="Velocidade")
//        {
//          currentSelection = optionSelected;
//          display.clearDisplay();
//          setExperimentoVelocidade();
//        }
//
//      }
    }
  }
}
/*
  Mostra as opcoes
*/
void setSelection()
{
  navegate(4);
  switch (currentSelection) {
    case 0:{
      lcd.setCursor(0,0);  //Seta a posição do cursor
      lcd.write((uint8_t)0);
      lcd.setCursor(2,0);  //Seta a posição do cursor
      lcd.print(mainOptions[currentSelection]);
      
      lcd.setCursor(2,1);  //Seta a posição do cursor
      lcd.print(mainOptions[currentSelection+1]);
      break;
    }
    case 1:{
      lcd.setCursor(0,1);  //Seta a posição do cursor
      lcd.write((uint8_t)0);
      lcd.setCursor(2,0);  //Seta a posição do cursor
      lcd.print(mainOptions[0]);
      
      lcd.setCursor(2,1);  //Seta a posição do cursor
      lcd.print(mainOptions[1]);
      break;
    }
    case 2:{
      lcd.setCursor(0,0);  //Seta a posição do cursor
      lcd.write((uint8_t)0);
      lcd.setCursor(2,0);  //Seta a posição do cursor
      lcd.print(mainOptions[2]);
      
      lcd.setCursor(2,1);  //Seta a posição do cursor
      lcd.print(mainOptions[3]);
      break;
    }
    case 3:{
      lcd.setCursor(0,1);  //Seta a posição do cursor
      lcd.write((uint8_t)0);
      lcd.setCursor(2,0);  //Seta a posição do cursor
      lcd.print(mainOptions[2]);
      
      lcd.setCursor(2,1);  //Seta a posição do cursor
      lcd.print(mainOptions[3]);
      break;
    }
  }
  optionSelected = currentSelection;
  getEnterPress();
  delay(200);
}

void setSubSelection()
{ 
  int qtdOptions = 0;
  String* mSubOpt;
  switch (optionSelected)
  {
    case 0:
    {
      mSubOpt = subOptionFisica;
      break;
    }
    default:{
      mSubOpt = subOptionFisica;
      break;
    }
  }
  qtdOptions = sizeof(mSubOpt);
  navegate(qtdOptions);
  int i;
//  Serial.println(qtdOptions);
//    Serial.println("<<<<< >>>>>");

  for(i=0; i<qtdOptions; i=i+1)
  {
    
    if(currentSelection==i)
    {
      //Serial.println(currentSelection);
      //Serial.println("<---------->");
      if(i%2 == 0)
      {
//        display.setTextColor(WHITE, BLACK);
//        display.setCursor(0,0);  //Seta a posição do cursor
//        display.println(suboptionsA[i]);
//        if((i+1)<=(qtdOptions -1)){
//          display.setTextColor(BLACK,WHITE);
//          display.setCursor(0,40);  //Seta a posição do cursor
//          display.println(suboptionsA[i+1]);
//        }
//        getEnterPress(suboptionsA[i]);
//        display.display();
          lcd.setCursor(0,0);  //Seta a posição do cursor
          lcd.write((uint8_t)0);
          lcd.setCursor(2,0);  //Seta a posição do cursor
          lcd.print(mSubOpt[currentSelection]);
      
          lcd.setCursor(2,1);  //Seta a posição do cursor
          lcd.print(mSubOpt[currentSelection+1]);
        
      }
      else
      {
//        display.setTextColor(BLACK, WHITE);
//        display.setCursor(0,0);  //Seta a posição do cursor
//        display.println(suboptionsA[i-1]);
//        
//        if((i)<=(qtdOptions -1)){
//          display.setTextColor(WHITE,BLACK);
//          display.setCursor(0,40);  //Seta a posição do cursor
//          display.println(suboptionsA[i]);
//        }
//        getEnterPress(suboptionsA[i]);
//        display.display();
          lcd.setCursor(0,1);  //Seta a posição do cursor
          lcd.write((uint8_t)0);
          lcd.setCursor(2,0);  //Seta a posição do cursor
          lcd.print(mSubOpt[currentSelection-1]);
      
          lcd.setCursor(2,1);  //Seta a posição do cursor
          lcd.print(mSubOpt[currentSelection]);
      }
      break;
    }
  }
  
  delay(200);
}

void setup()
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(7,INPUT);
  
  Wire.begin();

  lcd.init(); // initialize the lcd
  lcd.createChar(0, indicador);
  lcd.createChar(1,homeLogo);
  lcd.createChar(2,inicioLogo);
  lcd.createChar(3,fimLogo);
  lcd.begin(screenWidth,screenHeight); //lcd size
  
  lcd.setCursor(4,0);
  lcd.print("LabDuino");
  delay(2000);
  lcd.clear();
}

void loop() {
  if(!onSubOption){
    setSelection();
  }
  else
  {
    setSubSelection();
  }
//  lcd.scrollDisplayLeft();
  delay(100);

// lcd.setCursor(0,0);
//  lcd.print("X = ");
//   lcd.print(pegaInputBotao());
//   delay(125);
}
