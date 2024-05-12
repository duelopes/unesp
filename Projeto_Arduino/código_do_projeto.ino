//Eduardo Lopes de Oliveira
//RA 161490336


#include <LiquidCrystal.h> 
#include <Keypad.h>


	int variavel=0; 
	int num1=0, num2=0, num3=0, num4=0, num5=0, num6=0, num7=0, num8=0, num9=0, num10=0; 
	int dig1=1, dig2=2, dig3=3, dig4=4, dig5=5, dig6=6, dig7=7, dig8=8, dig9=9, dig10=0; 
	
	const byte filas = 4; 
	const byte columnas = 4; 
	char tecla[filas][columnas] = {
 	{'1','2','3','A'},
 	{'4','5','6','B'},
 	{'7','8','9','C'},
  	{'*','0','#','D'}
};

//ARDUINO
	byte pinFilas[filas] = {7, 6, 5, 4}; 
	byte pinColumnas[columnas] = {3, 2, 1, 0};
	Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas );
	LiquidCrystal lcd(8,9,10,11,12,13); 

void setup(){
	lcd.begin(16,2);
	pinMode (A0, OUTPUT);
  	pinMode (A1, OUTPUT);
}

  
void loop(){
	char key = keypad.getKey();
  	if (key){
   	lcd.setCursor(3+variavel,1);
   	lcd.print(key);
   	key=key-48; //CONVERÇÃO DOS DIGITOS DO TECLADO
   	variavel++; 
   	switch(variavel){
    case 1:
    num1=key; //ARMAZENAR O 1º DIGITO
    break;
    case 2:
    num2=key; //ARMAZENAR O 2º DIGITO
    break;
    case 3:
    num3=key; //ARMAZENAR O 3º DIGITO
    break;
    case 4:
    num4=key; //ARMAZENAR O 4º DIGITO
    break; 
    case 5:
    num5=key; //ARMAZENAR O 5º DIGITO
    break;
    case 6:
    num6=key; //ARMAZENAR O 6º DIGITO
    break;
    case 7:
    num7=key; //ARMAZENAR O 7º DIGITO
    break;
    case 8:
    num8=key; //ARMAZENAR O 8º DIGITO 
    break;
    case 9:
    num9=key; //ARMAZENAR O 9º DIGITO
    break;
    case 10:
    num10=key; //ARMAZENAR O 10º DIGITO
  	delay(100);
    
    //SENHA CORRETA
  	if(num1==dig1 && num2==dig2 && num3==dig3 && num4==dig4 && num5==dig5 && num6==dig6 && num7==dig7 && num8==dig8 && num9==dig9 && num10==dig10){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("ACESSO");
    lcd.setCursor(4,1);
    lcd.print("LIBERADO");
    delay(1000); 
    lcd.clear();
    }
    //SENHA ERRADA  
  	else{
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("ACESSO");
    lcd.setCursor(5,1);
    lcd.print("NEGADO");
    delay(1000); 
    lcd.clear();
    }
      
  	variavel=0;
  	lcd.clear();

  	break;
  }

 }
 if(!key){lcd.setCursor(1,0),lcd.print("DIGITE A SENHA:");}//INÍCIO
	analogWrite (A0, HIGH);
  delay(2);
}
