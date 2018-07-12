void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(1,INPUT);

}

void loop() {

        int x = digitalRead(1);
        Serial.println(x);
        
}
