/*
The MIT License (MIT)

Copyright (c) 2015 Diogo Guimaraes Carvalho

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//define digital ports wired to phone jacks (d1 to d4)
#define d1 = 2;
#define d2 = 3;
#define d3 = 4;
#define d5 = 5;
//define analog ports wired to phone jacks (s1 to s4)
#define s1 = A0;
#define s2 = A1;
#define s3 = A2;
#define s4 = A3;

LiquidCrystal_I2C lcd(0x20,16,2); // set the LCD address to 0x20 for a 16 chars and 2 line display
int screenWidth = 16;
int screenHeight = 2;
/*
  InputBotoes
  Buttons Input
*/

/*
  Caracteres personalizados
  Custom Character
*/

// indicator 
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
//Home Logo
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
// start Logo
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
// End Logo
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
// Capacitor Logo
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

// Control flags to check when is on main option or sub options or on experiment
boolean onSubOption = false;
boolean isOnExperimento = false;

// Stores user selected options
int currentSelection=0;
int optionSelected=0;
// Main menu options
String mainOption1 = "Fisica"; //Physic
String mainOption2 = "Quimica"; // Chemestry  
String mainOption3 = "Biologia"; // Biology
String mainOption4 = "Matematica";// Math
String mainOptions[4] = {mainOption1,mainOption2,mainOption3,mainOption4};

// Physics SubOptions
String optionFisica1 = "Vel. Med.";
String optionFisica2 = "Vel. Inst.";
String subOptionFisica[2] = {optionFisica1,optionFisica2};

// TODO: Add Here all other SubOtions

/*
  Pega o click do botao (i2c)
  Listen for Button click (i2c)
*/

int pegaInputBotao()
{
  byte x=0;
  Wire.requestFrom(33,2);       //Se PCF8574A - mude de 33 para 57 If PCF8574A - change from 33 to 57
  if(Wire.available())     //If the request is available
  {
    x=Wire.read();       //Receive the data
  }
  if(x<255)                     //If the data is less than 255
  {
    if (x==241) {return 1; } //Down
    if (x==242) { return 2; } //Up
    if (x==244) { return 3; } //Enter
    if (x==248) { return 4; } //ESC
  }
  else
  {
    return 0;
  }
//  return x;
}

/*
  Controle de Paginacao e muda selecao
  Pagging control and change selected option
*/
void navegate(int limit)
{
  if((currentSelection < (limit-1)))
  {

    if(pegaInputBotao()==2){
        currentSelection+=1;
        lcd.clear();
      }
      else
      {
        if(currentSelection >0)
        {
          if(pegaInputBotao()==1){
              currentSelection-=1;
              lcd.clear();
           }
        }
      }
   }
   if(currentSelection==(limit-1))
   {
        if(pegaInputBotao()==1){
          currentSelection-=1;
          lcd.clear();
        }
   }
   if(currentSelection==0)
   {
        if(pegaInputBotao()==2){
          currentSelection+=1;
          lcd.clear();
        }
   }
}
/*
  Pega o click no botao "Enter". Tambem chama os experimentos.
  Listen for enter or Esc buttons. Also Starts Experiment rotines.
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
    // Ir aos experimentos
    //Go to experiments
    else
    {
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
  else if(pegaInputBotao()==4)
  {
        if(onSubOption)
        {
          onSubOption = false;
          currentSelection = optionSelected;
          lcd.clear();
        }
  }
}
/*
  Mostra as opcoes Main Menu
  Shows Main Menu Options
*/
void setSelection()
{
  navegate(4);
  lcd.setCursor(15,0);  //Seta a posição do cursor
      lcd.write((uint8_t)1);
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
/*
  Mostra o subMenu selecionado
  Shows selected subMenu
*/
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
  for(i=0; i<qtdOptions; i=i+1)
  {
    
    if(currentSelection==i)
    {
      if(i%2 == 0)
      {

          lcd.setCursor(0,0);  
          lcd.write((uint8_t)0);
          lcd.setCursor(2,0); 
          lcd.print(mSubOpt[currentSelection]);
      
          lcd.setCursor(2,1);
          lcd.print(mSubOpt[currentSelection+1]);
        
      }
      else
      {

          lcd.setCursor(0,1);
          lcd.write((uint8_t)0);
          lcd.setCursor(2,0);
          lcd.print(mSubOpt[currentSelection-1]);
      
          lcd.setCursor(2,1);
          lcd.print(mSubOpt[currentSelection]);
      }
      getEnterPress();
      break;
    }
  }
  delay(200);
}

void setup()
{
 // Neste projeto Utiliza-se protocolo I2C 
  Wire.begin();

  lcd.init(); // initialize the lcd
  //Cria os caracteres customizados
  //Creates custom Characters
  lcd.createChar(0, indicador);
  lcd.createChar(1,homeLogo);
  lcd.createChar(2,inicioLogo);
  lcd.createChar(3,fimLogo);
  lcd.begin(screenWidth,screenHeight);
  //Mensagem de incializacao
  //Startup Lettering
  lcd.setCursor(4,0);
  lcd.print("LabDuino");
  delay(2000);
  lcd.clear();
}

void loop() {
  //Main rotine;
  if(!onSubOption){
    setSelection();
  }
  else
  {
    setSubSelection();
  }

/* 
   Teste de checagem dos inputs i2c
    i2c input Check
    
    Para executar, comente as linhas de cima
    To run it, comment above lines.
*/ 

// lcd.setCursor(0,0);
//  lcd.print("X = ");
//   lcd.print(pegaInputBotao());
//   delay(125);
}
