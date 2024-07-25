#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>
#include <Audio.h> // https://github.com/schreibfaul1/ESP32-audioI2S
Audio audio;

#define I2S_DOUT      17
#define I2S_BCLK      42
#define I2S_LRC       18

//7.0
#define SD_MOSI 11
#define SD_MISO 13
#define SD_SCK 12
#define SD_CS 10

const char *ssid = "********"; //Change to your SSID
const char *password = "********"; //Change to your password

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); /*Initialize the serial port*/
  Serial.println("Audio example");

  pinMode(SD_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH);
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI);
  SPI.setFrequency(1000000);
  SD.begin(SD_CS);

  WiFi.begin(ssid, password);
  WiFi.setAutoReconnect(true);//Set up automatic reconnection
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("connecting to WiFi");
  }
  Serial.println("WiFi is connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(21); // 0...21

  //  *** radio streams ***
  audio.connecttohost("http://stream.radioparadise.com/flac");

  //*** local files ***
  //audio.connecttoFS(SD, "/123.mp3");
}

void loop() {
  // put your main code here, to run repeatedly:
  audio.loop();
  //audio.stopSong();//close
}
