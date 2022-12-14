#include <Arduino.h>

/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with M5StickCPlus sample source code
*                          配套  M5StickCPlus 示例源代码
* Visit for more information: https://docs.m5stack.com/en/hat/hat_8servos_1.1
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/hat/hat_8servos_1.1
*
* Product: 8Servos HAT v1.1.
* Date: 2022/07/12
*******************************************************************************
  Control the running and release of the servo.
  控制伺服机的运行和释放
*/

#include <M5GFX.h>
#include <M5StickCPlus.h>
#include "Hat_8Servos.h"

M5GFX display;
M5Canvas canvas(&display);
Hat_8Servos drive;
bool release = false;

void btn_task(void *arg) {
    while (1) {
        if (M5.BtnA.wasPressed()) {
            release = !release;
        }
        M5.update();
        vTaskDelay(20);
    }
}

void setup() {
    M5.begin();
    display.begin();
    if (display.isEPD()) {
        display.setEpdMode(epd_mode_t::epd_fastest);
        display.invertDisplay(true);
        display.clear(TFT_BLACK);
    }
    display.setRotation(1);
    canvas.setTextColor(BLUE);
    canvas.createSprite(display.width(), display.height());
    canvas.setTextSize((float)canvas.width() / 160);
    while (!drive.begin(&Wire, 0, 26, 0x36)) {
        canvas.drawString("Connect Error", 40, 40);
        canvas.pushSprite(0, 0);
        vTaskDelay(100);
    }
    canvas.drawString("8SERVO HAT", 40, 20);
    canvas.drawString("Click Btn A", 40, 40);
    canvas.drawString("for release Servo", 40, 60);
    canvas.pushSprite(0, 0);
    xTaskCreate(btn_task,   /* Task function. */
                "btn_task", /* String with name of task. */
                8096,       /* Stack size in bytes. */
                NULL,       /* Parameter passed as input of the task */
                1,          /* Priority of the task. */
                NULL);      /* Task handle. */
}

void loop() {
    if (release) {
        drive.enableServoPower(0);
        canvas.fillRect(0, 80, 240, 95, BLACK);
        canvas.drawString("SERVO RELEASE", 40, 80);
        canvas.pushSprite(0, 0);
        vTaskDelay(100);
    } else {
        canvas.fillRect(0, 80, 240, 95, BLACK);
        canvas.drawString("SERVO RUNNING", 40, 80);
        canvas.pushSprite(0, 0);
        // drive.setServoAngle(0, 0);
        // drive.setServoAngle(0, 180);
        // drive.setServoPulse(0, 500); 0deg
        // drive.setServoPulse(0, 2500); 180deg
        // drive.setAllServoAngle(0);
        // drive.setAllServoAngle(180);
        // drive.setAllServoPulse(500); 0deg
        // drive.setAllServoPulse(2500); 180deg
        drive.enableServoPower(1);
        vTaskDelay(100);
        drive.setAllServoAngle(180);
        Serial.println(String(drive.getServoAngle(0)));
        vTaskDelay(600);
        drive.setAllServoAngle(0);
        Serial.println(String(drive.getServoAngle(0)));
        vTaskDelay(600);
    }
}
