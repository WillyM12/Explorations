#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>

TMRpcm tmrpcm;

void setup(){
    tmrpcm.speakerPin=9;
    Serial.begin(115200);
    if(!SD.begin(SD_ChipSelectPin)){
        Serial.println("SD fail");
    } else {
        Serial.println("SD success");
        tmrpcm.setVolume(5);
        tmrpcm.loop(1);
    }    
    
}

void loop (){
    char command = Serial.read();
    if(command == '1'){
        Serial.println("Play sound");
        tmrpcm.play("Birds.wav");
    } else if(command == '0'){
        Serial.println("Stop loop sound");
        tmrpcm.loop(0);
    } else if(command == '+'){
        Serial.println("Volume up");
        tmrpcm.volume(1);
    } else if(command == '-'){
        Serial.println("Volume down");
        tmrpcm.volume(0);
    } else if(command == 'x'){
        Serial.println("Stop sound");
        tmrpcm.stopPlayback();
    } 

}