int incomingByte = 0;   // for incoming serial data
#define GREEN 1

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(GREEN, OUTPUT);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                if (incomingByte == 103) //103 is g in ASCII table
                  digitalWrite(GREEN, HIGH);
                else digitalWrite(GREEN, LOW);
                
        }

        delay(500);

}
