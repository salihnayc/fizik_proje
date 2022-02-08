#include<SPI.h>
#include<RFID.h>

RFID rfid(10, 9);

int kisi_sayisi = 0;
int kisi_yuzdesi = 0;
int max_kisi = 50;

void setup{
    Serial.begin(9600);
    SPI.begin();
    rfid.init();
}

void loop{
    if(rfid.isCard()){
        kisi_sayisi += 1;
        rfid.halt();
    }
    
    kisi_yuzdesi = kisi_sayisi * (100/max_kisi);
    
    Serial.print("*s" + String(kisi_sayisi) + "*");
    Serial.print("*y" + String(kisi_yuzdesi) + "*");
}
