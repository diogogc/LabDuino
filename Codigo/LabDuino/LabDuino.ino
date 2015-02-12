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


Mais informacoes (More info):
https://github.com/diogogc/LabDuino
diogo.guimaraes.carvalho@gmail.com

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
/*
define portas digitais conectadas aos conectores de fone d1 ao d4
define digital ports wired to phone jacks d1 to d4
*/
#define D1 2
#define D2 3
#define D3 4
#define D4 5
/*
define portas analogicas conectadas aos conectores de fone (s1 ao s4)
define analog ports wired to phone jacks (s1 to s4)
*/
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3


LiquidCrystal_I2C lcd(0x20, 16, 2); // set the LCD address to 0x20 for a 16 chars and 2 line display
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
boolean emExpFis = false;
boolean emExpQuim = false;
boolean emExpBio = false;
boolean emExpMat = false;

// Stores user selected options
int currentSelection = 0;
int optionSelected = 0;

// Main menu options
String mainOption1 = "Fisica"; //Physic
String mainOption2 = "Quimica"; // Chemestry
String mainOption3 = "Biologia"; // Biology
String mainOption4 = "Matematica";// Math
String mainOptions[4] = {mainOption1, mainOption2, mainOption3, mainOption4};

// Physics SubOptions
String optionFisica1 = "Vel. Med.";
String optionFisica2 = "Vel. Inst.";
String subOptionFisica[2] = {optionFisica1, optionFisica2};

// TODO: Add Here all other SubOtions
// TODO: adicione aqui todas as outras subopicoes

/*
  Pega o click do botao (i2c)
  Listen for Button click (i2c)
*/

int pegaInputBotao()
{
  byte x = 0;
  Wire.requestFrom(33, 2);      //Se PCF8574A - mude de 33 para 57 If PCF8574A - change from 33 to 57
  if (Wire.available())    //If the request is available
  {
    x = Wire.read();     //Receive the data
  }
  else
  {
    return 0;
  }
  /*
    Para teste de checagem dos inputs i2c, comente daqui...
    For i2c input check comment from here...
  */

  /*
    Para chegar a estes valores, realizei o teste de input
    To get this values, i've run input check
  */
  if (x == 241) {
    return 1;  // para Baixo Down
  }
  if (x == 242) {
    return 2;  // para cima Up
  }
  if (x == 244) {
    return 3;  // Enter
  }
  if (x == 248) {
    return 4;  // Voltar ESC
  }
  /*
   ...ate aqui
   ...to here
  */

  /*
    Para teste de checagem dos inputs i2c, descomente esta linha
    For i2c input check uncomment this line
  */
  //  return x;
}

/*
  Controle de Paginacao e muda selecao
  Pagging control and change selected option
*/
void navegate(int limit)
{
  if ((currentSelection < (limit - 1)))
  {

    if (pegaInputBotao() == 2) {
      currentSelection += 1;
      lcd.clear();
    }
    else
    {
      if (currentSelection > 0)
      {
        if (pegaInputBotao() == 1) {
          currentSelection -= 1;
          lcd.clear();
        }
      }
    }
  }
  if (currentSelection == (limit - 1))
  {
    if (pegaInputBotao() == 1) {
      currentSelection -= 1;
      lcd.clear();
    }
  }
  if (currentSelection == 0)
  {
    if (pegaInputBotao() == 2) {
      currentSelection += 1;
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
  if (pegaInputBotao() == 3)
  {
    if (!onSubOption)
    {
      onSubOption = true;
      currentSelection = 0;
      lcd.clear();
    }
    // Ir aos experimentos
    //Go to experiments
    else
    {
      if (emExpFis)
      {
        switch (currentSelection)
        {
          case 0:
            {
              velociadeMedia();
              break;
            }
            case 1:
            {
              velocidadeInst();
              break;
            }
          default:
            break;
        }
      }
    }
  }
  else if (pegaInputBotao() == 4)
  {
    if (onSubOption && (!emExpFis || !emExpQuim || !emExpBio || !emExpMat))
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
  lcd.setCursor(15, 0);
  lcd.write((uint8_t)1);
  switch (currentSelection) {
    case 0: {
        // Escreve a logo Home
        //prints home Logo
        lcd.setCursor(0, 0);
        lcd.write((uint8_t)0);
        lcd.setCursor(2, 0);
        lcd.print(mainOptions[currentSelection]);

        lcd.setCursor(2, 1);
        lcd.print(mainOptions[currentSelection + 1]);
        break;
      }
    case 1: {
        lcd.setCursor(0, 1);
        lcd.write((uint8_t)0);
        lcd.setCursor(2, 0);
        lcd.print(mainOptions[0]);

        lcd.setCursor(2, 1);
        lcd.print(mainOptions[1]);
        break;
      }
    case 2: {
        lcd.setCursor(0, 0);
        lcd.write((uint8_t)0);
        lcd.setCursor(2, 0);
        lcd.print(mainOptions[2]);

        lcd.setCursor(2, 1);
        lcd.print(mainOptions[3]);
        break;
      }
    case 3: {
        lcd.setCursor(0, 1);
        lcd.write((uint8_t)0);
        lcd.setCursor(2, 0);
        lcd.print(mainOptions[2]);

        lcd.setCursor(2, 1);
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
  /*
    Adicione aqui as subopcoes
    Add here the suboptions
    Neste caso:
    On this case:

    optionSelected = 0 <-- Fisica (Physic)
    optionSelected = 1 <-- Quimica (Chemestry)
    optionSelected = 2 <-- Biologia (Biology)
    optionSelected = 3 <-- Math (Math)

    Note que e a mesma ordem das mainOptions;
    Sinta-se livre para muda-lo para suas nescecidades
    Note that it follows mainOption order;
    Fell free to change it according to your need.
  */
  switch (optionSelected)
  {
    //Fisica
    case 0:
      {
        mSubOpt = subOptionFisica;
        emExpFis = true;
        break;
      }
    //Quimica
    case 1:
      {
        emExpQuim = true;
        break;
      }
    //Biologia
    case 2:
      {
        emExpBio = true;
        break;
      }
    //Math
    case 3:
      {
        emExpMat = true;
        break;
      }
    default: {
        mSubOpt = subOptionFisica;
        break;
      }
  }
  qtdOptions = sizeof(mSubOpt);
  navegate(qtdOptions);
  int i;
  for (i = 0; i < qtdOptions; i = i + 1)
  {

    if (currentSelection == i)
    {
      if (i % 2 == 0)
      {

        lcd.setCursor(0, 0);
        lcd.write((uint8_t)0);
        lcd.setCursor(2, 0);
        lcd.print(mSubOpt[currentSelection]);

        lcd.setCursor(2, 1);
        lcd.print(mSubOpt[currentSelection + 1]);

      }
      else
      {

        lcd.setCursor(0, 1);
        lcd.write((uint8_t)0);
        lcd.setCursor(2, 0);
        lcd.print(mSubOpt[currentSelection - 1]);

        lcd.setCursor(2, 1);
        lcd.print(mSubOpt[currentSelection]);
      }
      getEnterPress();
      break;
    }
  }
  delay(200);
}

/*
Metodos dos experimentos aqui
Experiments methods here
*/

void velociadeMedia()
{
  /*
  setar portas utilizadas
  set used ports
  */
  pinMode(D1, INPUT); //Sensor IR
  pinMode(D3, INPUT); //Sensor IR
  pinMode(D2, OUTPUT); //Emissor IR (Emiter)
  pinMode(D4, OUTPUT); //Emissor IR (Emiter)

  /*
    Parametros
    Parameters
  */

  float start, finish, elapsed, elapsedInSec;
  float velMed;
  float distancia ;

  boolean pegouDistancia = false;
  boolean started = false;
  boolean finished = false;
  lcd.clear();
  while (true)
  {
    if (!pegouDistancia)
    {
      lcd.setCursor(0, 0);
      lcd.print("qual dist em M?");
      lcd.setCursor(0, 1);
      lcd.print(distancia);

      if (distancia > 0.1)
      {
        if (pegaInputBotao() == 2)
        {
          distancia = distancia - 0.1;
        }
        else if (pegaInputBotao() == 1)
        {
          distancia = distancia + 0.1;
        }
        else if (pegaInputBotao() == 3)
        {
          pegouDistancia = true;
          lcd.clear();
        }
      }
      else
      {
        if (pegaInputBotao() == 1)
        {
          distancia = distancia + 0.1;
        }
      }
    }
    else
    {
      if((digitalRead(D2)!=HIGH) && (digitalRead(D4)!=HIGH))
      {
        digitalWrite(D2,HIGH);
        digitalWrite(D4,HIGH);
      }
      if (!started && !finished) {
        lcd.setCursor(0, 0);
        lcd.print("esperando carro");
        lcd.setCursor(0, 1);
        lcd.print("passar P inicial");
        if(digitalRead(D1)==HIGH)
        {
          started = true;
          start=millis();
          lcd.clear();
        }
      }
      else
      {
        if (started && !finished) {
          lcd.setCursor(0, 0);
          lcd.print("Iniciou!");
          lcd.setCursor(0, 1);
          lcd.print("Tempo:");
          lcd.print((millis() - start)*0.001);
          
          if(digitalRead(D3)==LOW)
          {
            finished = true;
            finish=millis();
            lcd.clear();
          }
        }
        else if(started && finished)
        {
          elapsed=finish-start;
          elapsedInSec = elapsed *0.001;
          velMed = distancia / elapsedInSec;
          lcd.setCursor(0, 0);
          lcd.print("Terminou ");
          lcd.print("T:");
          lcd.print(elapsedInSec);
          lcd.print("s");
          lcd.setCursor(0, 1);
          lcd.print("Vel :");
          lcd.print(velMed);
          lcd.print(" m/s");
        }

      }
    }
    if (pegaInputBotao() == 4)
    {
      if (pegouDistancia)
      {
        pegouDistancia = false;
      }
      else {
        break;
      }
    }
    delay(100);
  }
  lcd.clear();
}

void velocidadeInst()
{
  /*
  setar portas utilizadas
  set used ports
  */
  pinMode(D1, INPUT); //Sensor IR
  pinMode(D2, OUTPUT); //Emissor IR (Emiter)
  

  /*
    Parametros
    Parameters
  */

  float start, finish, elapsed, elapsedInSec;
  float velInst;
  float tamanhoCarro ;

  boolean pegouTamanho = false;
  boolean started = false;
  boolean finished = false;
  lcd.clear();
  while (true)
  {
    if (!pegouTamanho)
    {
      lcd.setCursor(0, 0);
      lcd.print("Qual o tamanho");
      lcd.setCursor(0, 1);
      lcd.print("do carro? ");
      lcd.print(tamanhoCarro);
      lcd.print(" m");

      if (tamanhoCarro > 0.01)
      {
        if (pegaInputBotao() == 2)
        {
          tamanhoCarro = tamanhoCarro - 0.01;
        }
        else if (pegaInputBotao() == 1)
        {
          tamanhoCarro = tamanhoCarro + 0.01;
        }
        else if (pegaInputBotao() == 3)
        {
          pegouTamanho = true;
          lcd.clear();
        }
      }
      else
      {
        if (pegaInputBotao() == 1)
        {
          tamanhoCarro = tamanhoCarro + 0.1;
        }
      }
    }
    else
    {
      if((digitalRead(D2)!=HIGH))
      {
        digitalWrite(D2,HIGH);
      }
      if (!started && !finished) {
        lcd.setCursor(0, 0);
        lcd.print("esperando carro");
        lcd.setCursor(0, 1);
        lcd.print("passar P inicial");
        if(digitalRead(D1)==HIGH)
        {
          started = true;
          start=millis();
          lcd.clear();
        }
      }
      else
      {
        if (started && !finished) {
          lcd.setCursor(0, 0);
          lcd.print("Iniciou!");
          lcd.setCursor(0, 1);
          lcd.print("Tempo:");
          lcd.print((millis() - start)*0.001);
          
          if(digitalRead(D1)==LOW)
          {
            finished = true;
            finish=millis();
            lcd.clear();
          }
        }
        else if(started && finished)
        {
          elapsed=finish-start;
          elapsedInSec = elapsed *0.001;
          velInst = tamanhoCarro / elapsedInSec;
          lcd.setCursor(0, 0);
          lcd.print("Terminou ");
          lcd.print("T:");
          lcd.print(elapsedInSec);
          lcd.print("s");
          lcd.setCursor(0, 1);
          lcd.print("Vel Inst:");
          lcd.print(velInst);
          lcd.print(" m/s");
        }

      }
    }
    if (pegaInputBotao() == 4)
    {
      if (pegouTamanho)
      {
        pegouTamanho = false;
      }
      else {
        break;
      }
    }
    delay(100);
  }
  lcd.clear();
}

void setup()
{
  /*
    Neste projeto Utiliza-se protocolo I2C com o display e para input dos botoes
    On this project uses I2C protocol with display and buttons inputs
  */
  Wire.begin();

  lcd.init(); // initialize the lcd
  //Cria os caracteres customizados
  //Creates custom Characters
  lcd.createChar(0, indicador);
  lcd.createChar(1, homeLogo);
  lcd.createChar(2, inicioLogo);
  lcd.createChar(3, fimLogo);
  lcd.begin(screenWidth, screenHeight);
  //Mensagem de incializacao
  //Startup Lettering
  lcd.setCursor(4, 0);
  lcd.print("LabDuino");


  delay(2000);
  lcd.clear();
}

void loop() {
  //Main rotine;
  if (!onSubOption) {
    setSelection();
  }
  else
  {
    setSubSelection();
  }

  /*
     Teste de checagem dos inputs i2c
      i2c input Check

      Para executar, comente as linhas de cima e descomente as de baixo
      To run it, comment above lines and uncomment the below ones.
  */

  // lcd.setCursor(0,0);
  //  lcd.print("X = ");
  //   lcd.print(pegaInputBotao());
  //   delay(125);
}
