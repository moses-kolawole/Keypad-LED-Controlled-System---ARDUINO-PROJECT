#include <Key.h>
#include <Keypad.h>


const char no_row = 4;
const char no_column = 4;

char rowpin[no_row] = {A0, A1,  A2, A3};
char columnpin[no_column] = {A4, A5, 11, 12};

char key_array[no_row][no_column] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'}, 
  {'*', '0', '#', 'D'},
  {'7', '8', '9', 'C'}
};

Keypad k = Keypad(makeKeymap(key_array), rowpin, columnpin, no_row, no_column);

int ledpin = 10;
int led[] = {2, 3, 4, 5, 6, 7, 8};
int display1 = 9;



int zero[] = {1, 1, 1, 1, 1, 1, 0};
int one[] = {0, 1, 1, 0, 0, 0, 0};
int two[] = {1, 1, 0, 1, 1, 0, 1};
int three[] = {1, 1, 1, 1, 0, 0, 1};
int four[] = {0, 1, 1, 0, 0, 1, 1};
int five[] = {1, 0, 1, 1, 0, 1, 1};
int six[] = {1, 0, 1, 1, 1, 1, 1};
int seven[] = {1, 1, 1, 0, 0, 0, 0};
int eight[] = {1, 1, 1, 1, 1, 1, 1};
int nine[] = {1, 1, 1, 0, 0, 1, 1};


void display_led(int display, int n){
  digitalWrite(display, LOW);
  switch(n){
    case 0:
    brightness(0);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], zero[i]);
    }
    break;
    
    case 1:
    brightness(1);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], one[i]);
    }
    break;

    case 2:
    brightness(2);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], two[i]);
    }
    break;

    case 3:
    brightness(3);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], three[i]);
    }
    break;


    case 4:
    brightness(4);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], four[i]);
    }
    break;


    case 5:
    brightness(5);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], five[i]);
    }
    break;


    case 6:
    brightness(6);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], six[i]);
    }
    break;


    case 7:
    brightness(7);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], seven[i]);
    }
    break;

    case 8:
    brightness(8);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], eight[i]);
    }
    break;

    case 9:
    brightness(9);
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], nine[i]);
    }
    break;

  }
}


void brightness(int k){
  switch(k){
    case 0:
    analogWrite(ledpin, 0);
    break;

    case 1:
    analogWrite(ledpin, 25);
    break;

    case 2:
    analogWrite(ledpin, 55);
    break;

    case 3:
    analogWrite(ledpin, 80);
    break;

    case 4:
    analogWrite(ledpin, 110);
    break;

    case 5:
    analogWrite(ledpin, 140);
    break;

    case 6:
    analogWrite(ledpin, 170);
    break;

    case 7:
    analogWrite(ledpin, 200);
    break;

    case 8:
    analogWrite(ledpin, 225);
    break;

    case 9:
    analogWrite(ledpin, 255);
    break;

  }
}


void setup() {
  // put your setup code here, to run once:
for(int i = 2; i < 11; i++){
  pinMode(i, OUTPUT);
}

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

int key_pressed = k.getKey();

switch(key_pressed){
  case 48:
  Serial.println("0");
  display_led(display1, 0);
  break;

  case 49:
  Serial.println("1");
  display_led(display1, 1);
  break;

  case 50:
  Serial.println("2");
  display_led(display1, 2);
  break;

  case 51:
  Serial.println("3");
  display_led(display1, 3);
  break;

  case 52:
  Serial.println("4");
  display_led(display1, 4);
  break;

  case 53:
  Serial.println("5");
  display_led(display1, 5);
  break;

  case 54:
  Serial.println("6");
  display_led(display1, 6);
  break;

  case 55:
  Serial.println("7");
  display_led(display1, 7);
  break;

  case 56:
  Serial.println("8");
  display_led(display1, 8);
  break;

  case 57:
  Serial.println("9");
  display_led(display1, 9);
  break;
}




}
