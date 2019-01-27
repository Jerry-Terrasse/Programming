#define led 2
void setup()
{
  // put your setup code here, to run once:
  srand(rand());
  for(int rp=0;rp;rp++);
  pinMode(led,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if((rand()%2)&1)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
