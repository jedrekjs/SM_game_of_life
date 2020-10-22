#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// Zadefiniowanie kolorów
#define  BLACK   0x0000 
#define WHITE   0xFFFF

#define __CS 10
#define __DC 9
TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

int Scene = 0; //indeks planszy
const int Wcount = 16; //liczba kolumn
const int Hcount = 17; //liczba wierszy
int Size = 8; //wielkosc kwadratu (w pikselach)

bool BoardOne[Hcount + 1][Wcount + 1];

void PrintBoard(bool BoardOne[Hcount + 1][Wcount + 1]);
void Check(bool BoardOne[Hcount + 1][Wcount + 1]);
void ClearBottom(){ //funkcja "czyszcząca" napisy na dole ekranu
  for (int a = 0; a < 3; a++)
  {
    for (int b = 0; b < 16; b++)
    {
      
        DrawSquare(a*Size + Size*17, b*Size, BLACK);
      
    }
  }
}
void DrawSquare(int x, int y, float type) { //uproszczona funkcja rysowania kwadratów
  tft.fillRect(y, x, Size, Size, type);
}
void Scene0() //ekran powitalny
{
  tft.setTextSize(2);
  tft.print("Welcome to");
  tft.setCursor(20, 40);
  tft.println("Game of");
  tft.setCursor(35, 60);
  tft.println("Life!");
  tft.setTextSize(1);
  tft.setCursor(0, tft.height()-60);
  tft.println("Press Buttons");
  tft.println("to choose a pattern");
  tft.println("from 1 to 12");
  for(int i=0; i<16; i++)
  {
     delay(500);
     DrawSquare(19*Size, i*Size, WHITE);
  }
  
}
void SetBoard(){ //funkcja rozstawiająca planszę
  for(int i=0; i<(Hcount+1); i++){
    for(int j=0; j<(Wcount+1); j++){
      BoardOne[i][j] = 0;
    }
  }
  ClearBottom();
  tft.setTextSize(2);
  tft.setCursor(0, Size*18);
  if(Scene == 0)
  {
     for(int i=0; i<(Hcount+1); i++){
      for(int j=0; j<(Wcount+1); j++){
        BoardOne[i][j] = rand()%2;
      }
    }
    tft.print("1.RANDOM");
    
  }
  
  else if(Scene == 1) //block
  {
     BoardOne[9][7] = 1;
     BoardOne[10][7] = 1;
     BoardOne[10][8] = 1;
     BoardOne[9][8] = 1;
     
     tft.print("2.BLOCK");
  }
  else if(Scene == 2) //bee-hive
  {
     BoardOne[9][6] = 1;
     BoardOne[10][7] = 1;
     BoardOne[10][8] = 1;
     BoardOne[9][9] = 1;
     BoardOne[8][8] = 1;
     BoardOne[8][7] = 1;

     tft.print("3.BEE-HIVE");
  }
  else if(Scene == 3) //loaf
  {
     BoardOne[8][6] = 1;
     BoardOne[9][7] = 1;
     BoardOne[10][8] = 1;
     BoardOne[9][9] = 1;
     BoardOne[8][9] = 1;
     BoardOne[7][8] = 1;
     BoardOne[7][7] = 1;

     tft.print("4.LOAF");
  }
  else if(Scene == 4) //boat
  {
     BoardOne[9][6] = 1;
     BoardOne[8][7] = 1;
     BoardOne[9][8] = 1;
     BoardOne[10][7] = 1;
     BoardOne[8][6] = 1;

     tft.print("5.BOAT");
  }
  else if(Scene == 5) //tub
  {
     BoardOne[9][6] = 1;
     BoardOne[8][7] = 1;
     BoardOne[9][8] = 1;
     BoardOne[10][7] = 1;

     tft.print("6.TUB");
  }
  else if(Scene == 6) //blinker
  {
     BoardOne[9][7] = 1;
     BoardOne[9][8] = 1;
     BoardOne[9][9] = 1;

     tft.print("7.BLINKER");
  }
  else if(Scene == 7) //toad
  {
     BoardOne[9][7] = 1;
     BoardOne[9][8] = 1;
     BoardOne[9][9] = 1;

     BoardOne[8][8] = 1;
     BoardOne[8][9] = 1;
     BoardOne[8][10] = 1;

     tft.print("8.TOAD");
  }
  else if(Scene == 8) //beacon
  {
     BoardOne[9][7] = 1;
     BoardOne[10][7] = 1;
     BoardOne[10][8] = 1;
     BoardOne[9][8] = 1;
     
     BoardOne[8][9] = 1;
     BoardOne[7][9] = 1;
     BoardOne[7][10] = 1;
     BoardOne[8][10] = 1;

     tft.print("9.BEACON");
  }
  else if(Scene == 9) //small exploder
  {
     BoardOne[10][8] = 1;
     BoardOne[9][7] = 1;
     BoardOne[9][9] = 1;
     BoardOne[8][7] = 1;
     BoardOne[8][8] = 1;
     BoardOne[8][9] = 1;
     BoardOne[7][8] = 1;

     tft.print("10.");
     tft.setTextSize(1);
     tft.print("SMALL EXPLODER");
  }
  else if(Scene == 10) //10 cell row
  {
     BoardOne[4][8] = 1;
     BoardOne[5][8] = 1;
     BoardOne[6][8] = 1;
     BoardOne[7][8] = 1;
     BoardOne[8][8] = 1;
     BoardOne[9][8] = 1;
     BoardOne[10][8] = 1;
     BoardOne[11][8] = 1;
     BoardOne[12][8] = 1;
     BoardOne[13][8] = 1;

     tft.print("11.");
     tft.setTextSize(1);
     tft.print("10 CELL ROW");
  }
  else if(Scene == 11) //pulsar
  {
     BoardOne[3][4] = 1;
     BoardOne[3][5] = 1;
     BoardOne[3][6] = 1;
     BoardOne[3][10] = 1;
     BoardOne[3][11] = 1;
     BoardOne[3][12] = 1;
     
     BoardOne[8][4] = 1;
     BoardOne[8][5] = 1;
     BoardOne[8][6] = 1;
     BoardOne[8][10] = 1;
     BoardOne[8][11] = 1;
     BoardOne[8][12] = 1;

     BoardOne[10][4] = 1;
     BoardOne[10][5] = 1;
     BoardOne[10][6] = 1;
     BoardOne[10][10] = 1;
     BoardOne[10][11] = 1;
     BoardOne[10][12] = 1;

     BoardOne[15][4] = 1;
     BoardOne[15][5] = 1;
     BoardOne[15][6] = 1;
     BoardOne[15][10] = 1;
     BoardOne[15][11] = 1;
     BoardOne[15][12] = 1;

     
     BoardOne[5][2] = 1;
     BoardOne[6][2] = 1;
     BoardOne[7][2] = 1;
     BoardOne[11][2] = 1;
     BoardOne[12][2] = 1;
     BoardOne[13][2] = 1;

     BoardOne[5][7] = 1;
     BoardOne[6][7] = 1;
     BoardOne[7][7] = 1;
     BoardOne[11][7] = 1;
     BoardOne[12][7] = 1;
     BoardOne[13][7] = 1;

     BoardOne[5][9] = 1;
     BoardOne[6][9] = 1;
     BoardOne[7][9] = 1;
     BoardOne[11][9] = 1;
     BoardOne[12][9] = 1;
     BoardOne[13][9] = 1;

     BoardOne[5][14] = 1;
     BoardOne[6][14] = 1;
     BoardOne[7][14] = 1;
     BoardOne[11][14] = 1;
     BoardOne[12][14] = 1;
     BoardOne[13][14] = 1;


     tft.print("12.PULSAR");
  }
}

void PrintBoard(bool BoardOne[Hcount + 1][Wcount + 1]){ //funkcja wyswietlająca planszę
  for (int a = 0; a < Hcount; a++)
  {
    for (int b = 0; b < Wcount; b++)
    {
      if (BoardOne[a][b] == true)
      {
        DrawSquare(a*Size, b*Size, WHITE);
      }
      else
      {
        DrawSquare(a*Size, b*Size, BLACK);
      }
    }
  }
}

void Compare(bool BoardOne[Hcount + 1][Wcount + 1], bool BoardTwo[Hcount+ 1][Wcount+1]) //funkcja przypisująca wartości pierwszej tablicy do drugiej
{
  for(int a=0; a<Hcount; a++)
  {
    for(int b=0; b<Wcount; b++)
    {
      BoardTwo[a][b] = BoardOne[a][b];
    }
  }
}

void Check(bool BoardOne[Hcount + 1][Wcount + 1]) //funkcja sprawdzająca tablice według zasad GoL
{
  bool BoardTwo[Hcount+1][Wcount+1] = {};
  Compare(BoardOne, BoardTwo);
  
   for(int a=1; a<Hcount; a++)
  {
    for(int b=1; b<Wcount; b++)
    {
      int alive = 0;
      for (int c = -1; c < 2; c++)
      {
        for (int d = -1; d < 2; d++)
        {
          if (!(c == 0 && d == 0))
          {
            if (BoardTwo[a  + c][b + d])
            {
              ++alive;
            }
          }
        }
      }
      if(alive<2)
      {
        BoardOne[a][b] = false;
      }
      else if(alive==3)
      {
        BoardOne[a][b] = true;
      }
      else if(alive > 3)
      {
        BoardOne[a][b] = false;
      }
    }
  }
}

void setup() {
  tft.begin();
  tft.setTextWrap(1); //zaokrąglanie tekstu
  tft.setRotation(2); //obrót wyświetlanego obrazu o 180 stopni
  pinMode(2, INPUT_PULLUP); //przycisk "w lewo"
  pinMode(3, INPUT_PULLUP); //przycisk "w prawo"
  Scene0(); //ekran powitalny
  SetBoard(); //domyślne ustawienie planszy
}

void loop() {
  if(digitalRead(3) == LOW) //przeskok w prawo
  {
    Scene++;
    if(Scene>11) Scene = 0;
    SetBoard();
  }
  if(digitalRead(2) == LOW) //przeskok w lewo
  {
    Scene--;
    if(Scene<0) Scene = 11;
    SetBoard();
  }
  PrintBoard(BoardOne);
  Check(BoardOne);
}
