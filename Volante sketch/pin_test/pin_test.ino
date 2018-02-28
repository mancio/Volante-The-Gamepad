void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(14,INPUT_PULLUP);

}

void loop() {

        int x = digitalRead(14);
        Serial.println(x);
        
}
