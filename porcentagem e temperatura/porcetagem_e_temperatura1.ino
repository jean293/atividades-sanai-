
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  ///EXERCICIO 1
  
  int valor = analogRead(A0);
  int contagem = 0;
  
  contagem = map (valor, 0, 1023, 0, 100);
  Serial.println(contagem);
  
   //EXERCICIO 2
  
  if(valor <200){
  Serial.println("muito frio");
    
  }else if(valor <= 500){
  Serial.println("FRIO");
    
  }else if (valor <=850){
  Serial.println("normal");
    
  }else if (valor <=950){
  Serial.println("quente");
    
  }else{
  Serial.println("muito quente");
  }

}