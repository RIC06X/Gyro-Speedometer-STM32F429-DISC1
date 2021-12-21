//Author Yanjie Xu
//Dec 21 2021
//Gyro Speedometer Project
//Use Gyro to calculate walking speed

#include "mbed.h"
#include "GYRO_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"
#include "TS_DISCO_F429ZI.h"
#include <queue>
#include <list>

#define BUFFER_SIZE 30

GYRO_DISCO_F429ZI gyro;
LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;

DigitalOut led1(LED4);


void getGyroData(float* GyroBuffer);
void LCD_Setup();
void LCD_printGyro(float* GyroBuffer, uint8_t* text, uint8_t text_length);
void TS_Setup();
void updateStride(TS_StateTypeDef& TS_State);
void StartStopCheck(TS_StateTypeDef& TS_State);
void updateStride(TS_StateTypeDef& TS_State);
void writeData(queue<float *>& data, float* GyroBuffer);
void exportData(queue<float *>& data);

static uint8_t USER_HEIGHT = 80;
bool FLAG_START = false;

int main()
{
    float GyroBuffer[3];
    uint8_t text[BUFFER_SIZE];
    TS_StateTypeDef TS_State;
    queue<float *> saved_data;
    
    printf("Gyroscope started\n");  
    LCD_Setup();
    TS_Setup();

    while(1) {
        // Read Gyroscope values
        getGyroData(GyroBuffer);
        //printf("\033[3A"); // Moves cursor up x lines (x value is between [ and A)
        LCD_printGyro(GyroBuffer, text, 30);
        updateStride(TS_State);
        StartStopCheck(TS_State);

        writeData(saved_data, GyroBuffer);
        exportData(saved_data);

        wait_us(1000 * 500);
    }
}


void getGyroData(float* GyroBuffer){
    gyro.GetXYZ(GyroBuffer);
    printf("%f, %f, %f\n", GyroBuffer[0]/500, GyroBuffer[1]/500, GyroBuffer[2]/500);
}

void LCD_Setup(){
    uint8_t test[20];
    BSP_LCD_SetFont(&Font20);
    lcd.Clear(LCD_COLOR_BLUE);
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_YELLOW);
    lcd.DisplayStringAt(0, LINE(0),  (uint8_t *)"Gyro Speedometer", CENTER_MODE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.DrawRect(21, 202, 38, 38);
    sprintf((char *)test, "+");
    lcd.DisplayStringAt(30, 213, (uint8_t *) test, LEFT_MODE);
    //print stride length
    sprintf((char *)test, "%d cm", USER_HEIGHT);
    lcd.DisplayStringAt(81, 213, (uint8_t *) test, LEFT_MODE);
    
    lcd.DrawRect(180, 202, 38, 38);
    sprintf((char *)test, "-");
    lcd.DisplayStringAt(190, 213, (uint8_t *) test, LEFT_MODE);
    
    lcd.DrawRect(21, 255, 70, 34);
    sprintf((char *)test, "START");
    lcd.DisplayStringAt(23, 260, (uint8_t *) test, LEFT_MODE);

    lcd.DrawRect(148, 255, 70, 34);
    sprintf((char *)test, "STOP");
    lcd.DisplayStringAt(153, 260, (uint8_t *) test, LEFT_MODE);
    // lcd.FillPolygon()
}

void LCD_printGyro(float* GyroBuffer, uint8_t* text, uint8_t text_length){
    sprintf((char *)text, "X = %10.3f", GyroBuffer[0]/500);
    // board foward/backword rotate
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)text, LEFT_MODE);
    sprintf((char *)text, "Y = %10.3f", GyroBuffer[1]/500);
    // board left/right rotate
    lcd.DisplayStringAt(0, LINE(3), (uint8_t *)text, LEFT_MODE);
    sprintf((char *)text, "Z = %10.3f", GyroBuffer[2]/500);
    // board clockwise/counter-clockwise rotate
    lcd.DisplayStringAt(0, LINE(4), (uint8_t *)text, LEFT_MODE);
}

void updateStride(TS_StateTypeDef& TS_State){
    uint8_t char_buffer[20];
    ts.GetState(&TS_State);
    printf("POS = (%d,%d)\n", TS_State.X, TS_State.Y);
    if ((TS_State.TouchDetected) && (TS_State.X > 21) && (TS_State.X < 59) && (TS_State.Y > 202) && (TS_State.Y < 240)){
        //printf("+ btn pressed");
        if(USER_HEIGHT < 255){
            USER_HEIGHT += 5;
        }
    }
    else if ((TS_State.TouchDetected) && (TS_State.X > 180) && (TS_State.X < 218) && (TS_State.Y > 202) && (TS_State.Y < 240)){
        //printf("- btn pressed");
        if (USER_HEIGHT > 0){
            USER_HEIGHT -= 5;
        }
        //lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"- Pressed", LEFT_MODE);
    }
    else{
        lcd.ClearStringLine(5);
    }
    sprintf((char *)char_buffer, "%d cm", USER_HEIGHT);
    lcd.DisplayStringAt(81, 213, (uint8_t *) char_buffer, LEFT_MODE);
}

void StartStopCheck(TS_StateTypeDef& TS_State){
    ts.GetState(&TS_State);
    printf("POS = (%d,%d)\n", TS_State.X, TS_State.Y);
    if ((TS_State.TouchDetected) && (TS_State.X > 21) && (TS_State.X < 91) && (TS_State.Y > 255) && (TS_State.Y < 289)){
        //printf("start btn pressed");
        FLAG_START = true;
        lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"START Pressed", LEFT_MODE);
    }
    else if ((TS_State.TouchDetected) && (TS_State.X > 148 ) && (TS_State.X < 218) && (TS_State.Y > 255) && (TS_State.Y < 289))
    {
        FLAG_START = false;
        lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"STOP Pressed", LEFT_MODE);
    }
}

void TS_Setup(){
    ts.Init(240, 320);
}


void writeData(queue<float *>& data, float* GyroBuffer){
    //mutex ?
    if (FLAG_START){
        float* temp_array = new float[3];
        for (int i = 0; i < 3; i ++){
            temp_array[i] = GyroBuffer[i];
        }
        data.push(temp_array);
        if (data.size() > 40){
            data.pop();
        }
        printf("Queue Size: %d\n", data.size());
    }
}

void exportData(queue<float *>& data){
    //mutex ?
    if (!FLAG_START and data.size() > 0){
        while (data.size()){
            float* temp_array = data.front();
            printf("%f, %f, %f\n", temp_array[0]/500, temp_array[1]/500, temp_array[2]/500);
            data.pop();
        }
    }
}