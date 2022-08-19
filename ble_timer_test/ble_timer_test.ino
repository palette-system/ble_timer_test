#include "ble_keyboard_jis.h"

// BLEキーボードクラス
BleKeyboardJIS bleKeyboard = BleKeyboardJIS();

void setup() {
  bleKeyboard.begin();
}

void key_press(int key_code) {
    bleKeyboard.press_raw(key_code);
    delay(50);
    bleKeyboard.release_raw(key_code);
    delay(50);
}

void loop() {
  unsigned long n = millis() / 60000; // 経過分
  int i;
  char s[32];
  unsigned long sn = millis(); // 開始
  if(bleKeyboard.isConnected()) {
    sprintf(s, "%d", n);
    i = 0;
    while (s[i]) {
      if (s[i] == 0x30) key_press(0x27);
      if (s[i] == 0x31) key_press(0x1E);
      if (s[i] == 0x32) key_press(0x1F);
      if (s[i] == 0x33) key_press(0x20);
      if (s[i] == 0x34) key_press(0x21);
      if (s[i] == 0x35) key_press(0x22);
      if (s[i] == 0x36) key_press(0x23);
      if (s[i] == 0x37) key_press(0x24);
      if (s[i] == 0x38) key_press(0x25);
      if (s[i] == 0x39) key_press(0x26);
      i++;
    }
    key_press(0x28);
  }
  unsigned long en = millis(); // 終了
  // 1分間待つ
  delay(60000 - (en - sn));

}
