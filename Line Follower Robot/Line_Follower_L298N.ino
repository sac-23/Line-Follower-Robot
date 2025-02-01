#define rightIR_Sensor 11
#define leftIR_Sensor 12
#define MotorSpeed 180

// Right motor
int enableRightMotor = 6;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left motor
int enableLeftMotor = 5;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

void setup()
{
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(rightIR_Sensor, INPUT);
  pinMode(leftIR_Sensor, INPUT);
}

void loop()
{
  int rightIR_SensorValue = digitalRead(rightIR_Sensor);
  int leftIR_SensorValue = digitalRead(leftIR_Sensor);

  if (rightIR_SensorValue == LOW && leftIR_SensorValue == LOW)
  {
    MoveForward();
  }
  else if (rightIR_SensorValue == LOW && leftIR_SensorValue == HIGH)
  {
    MoveLeft();
  }
  else if (rightIR_SensorValue == HIGH && leftIR_SensorValue == LOW)
  {
    MoveRight();
  }
  else
  {
    stopMoving();
  }
}

void MoveForward()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);

  analogWrite(enableRightMotor, MotorSpeed);
  analogWrite(enableLeftMotor, MotorSpeed);
}

void MoveLeft()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW); // Stop left motor for a turn

  analogWrite(enableRightMotor, MotorSpeed);
  analogWrite(enableLeftMotor, 0);
}

void MoveRight()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW); // Stop right motor for a turn

  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);

  analogWrite(enableRightMotor, 0);
  analogWrite(enableLeftMotor, MotorSpeed);
}

void stopMoving()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);

  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);

  analogWrite(enableRightMotor, 0);
  analogWrite(enableLeftMotor, 0);
}
