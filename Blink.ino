int mot1r = 9;  //right motor reverse
int mot1s = 6; //right motor straight
int mot2r = 5;  // left motor reverse
int mot2s = 3;  //left motor straight

int l1 = 7;
int l2 = 2;
int m = 4;
int r2 = 13;
int r1 = 12;

void setup() {
  // put your setup code here, to run once:

  pinMode(mot1r, OUTPUT);
  pinMode(mot1s, OUTPUT);
  pinMode(mot2r, OUTPUT);
  pinMode(mot2s, OUTPUT);

  pinMode(l1, INPUT);
  pinMode(l2, INPUT);
  pinMode(m, INPUT);
  pinMode(r2, INPUT);
  pinMode(r1, INPUT);
  Serial.begin(9600);
}


void forward() {
  analogWrite(mot1s, 125);
  analogWrite(mot1r, 0);
  analogWrite(mot2r, 0);
  analogWrite(mot2s, 125);
}

void right() {
  analogWrite(mot1s, 0);
  analogWrite(mot1r, 125);
  analogWrite(mot2r, 0);
  analogWrite(mot2s, 125);
}

void left() {
  analogWrite(mot1s, 125);
  analogWrite(mot1r, 0);
  analogWrite(mot2r, 125);
  analogWrite(mot2s, 0);
}

void Stop() {
  analogWrite(mot1s, 0);
  analogWrite(mot1r, 0);
  analogWrite(mot2r, 0);
  analogWrite(mot2s, 0);
}

void back() {
  analogWrite(mot1s, 0);
  analogWrite(mot1r, 125);
  analogWrite(mot2r, 0);
  analogWrite(mot2s, 125);
}

void loop() {
  if ((digitalRead(r2) == 1) && (digitalRead(l2) == 1) && (digitalRead(r1) == 1) && (digitalRead(l1) == 1) && (digitalRead(m) == 1)) {
    forward();
    Serial.println("cross t");
    delay(200);
    Stop();
    if ((digitalRead(r2) == 1) && (digitalRead(l2) == 1) && (digitalRead(r1) == 1) && (digitalRead(l1) == 1) && (digitalRead(m) == 1)) {
      Stop();
    }
    else
    {
      while ( (digitalRead(l2) != 0) && (digitalRead(l1) != 0) ) {
        left();
      }
    }
  }//crossroads,t-intersection,end

  else if ((digitalRead(r2) == 0) && (digitalRead(l2) == 1) && (digitalRead(l1) == 1) && (digitalRead(m) == 1) && (digitalRead(r1) == 0)) {
    Stop();
    while ( (digitalRead(l2) != 0) && (digitalRead(l1) != 0) ) {
      left();
    }
  }// leftt t intersection,left90

  else if ((digitalRead(r2) == 1) && (digitalRead(l2) == 0) && (digitalRead(r1) == 1) && (digitalRead(m) == 1) && (digitalRead(l1) == 0)) {
    forward();
    delay(100);
    if (digitalRead(m) == 1) {
      forward();
    }
    else if( (digitalRead(r2) != 0) && (digitalRead(r1) != 0)){
      Stop();
      while ( (digitalRead(l2) != 0) && (digitalRead(l1) != 0) ) {
      left();
    }
    }
    else
    {
      Stop();
      while ( (digitalRead(r2) != 0) && (digitalRead(r1) != 0) ) {
        right();
      }
    }
  }// right t intersection,right90

  else if ((digitalRead(r2) == 0) && (digitalRead(l2) == 0) && (digitalRead(m) == 1) && (digitalRead(l1) == 0) && (digitalRead(r1) == 0) ) {
    forward();
  }//forward

  else if ((digitalRead(r2) == 0) && (digitalRead(l2) == 1) && (digitalRead(l1) == 0) && (digitalRead(r1) == 0) && (digitalRead(m) == 0)) {
    left();
  }
  else if ((digitalRead(r2) == 1) && (digitalRead(l2) == 0) && (digitalRead(l1) == 0) && (digitalRead(r1) == 0) && (digitalRead(m) == 0)) {
    right();
    Serial.println("right");
  }
  else if ((digitalRead(r2) == 0) && (digitalRead(l2) == 0) && (digitalRead(r1) == 0) && (digitalRead(l1) == 0) && (digitalRead(m) == 0)) {
    Stop();
    back();
    delay(500);
    Serial.println("back");
    Stop();
  }//to turn back
}