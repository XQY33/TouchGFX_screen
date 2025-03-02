#include <gui/start_screen/startView.hpp>
#include<touchgfx/containers/clock/AnalogClock.hpp>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include "main.h"


extern DataPacket packet;



startView::startView()
{
    tickCounter = 0;
    lastTemperature = 36.5f; // 初始体温设置为36.5度

}

void startView::setupScreen()
{
    startViewBase::setupScreen();

}

void startView::tearDownScreen()
{
    startViewBase::tearDownScreen();
}




static uint16_t randomish(int32_t seed)
{
    static uint16_t last = 0;
    const uint16_t num = (seed * (1337 + last)) % 0xFFFF;
    last = num;
    return num;
}


static float ecgPhaseOffset = 0.0f;

/*循环调用处理ecg图像*/
void startView::handleTickEvent()
{
    tickCounter++;

    // Insert each second tick
    if (tickCounter % 2 == 0)
    {
        float yMax = dynamicGraph_ecg.getGraphRangeYMaxAsFloat();

        // ECG-like signal generation with random phase offset
        float ecgValue = 0;
        float phase = fmod(tickCounter * 0.02f + ecgPhaseOffset, 1.2f); // Normalize phase to 0-1.2 range

        if (phase < 0.1f) // P wave
        {
            ecgValue = 0.2f * sinf(phase / 0.1f * M_PI); // Small sine wave for P wave
        }
        else if (phase < 0.2f) // PR segment
        {
            ecgValue = 0.0f;
        }
        else if (phase < 0.3f) // Q wave
        {
            ecgValue = -0.5f * sinf((phase - 0.2f) / 0.1f * M_PI); // Sharp downward slope
        }
        else if (phase < 0.4f) // R wave
        {
            ecgValue = 1.0f * sinf((phase - 0.3f) / 0.1f * M_PI); // Sharp upward slope then downward
        }
        else if (phase < 0.5f) // S wave
        {
            ecgValue = -0.7f * sinf((phase - 0.4f) / 0.1f * M_PI); // Sharp downward slope then recover
        }
        else if (phase < 0.6f) // ST segment
        {
            ecgValue = 0.0f;
        }
        else if (phase < 0.8f) // T wave
        {
            ecgValue = 0.4f * sinf((phase - 0.6f) / 0.2f * M_PI); // Medium sine wave for T wave
        }
        else // Baseline (flat segment)
        {
            ecgValue = 0.0f;
        }

        ecgValue = (ecgValue + 1) * (yMax / 2.0f); // Normalize ECG value to fit graph range
        dynamicGraph_ecg.addDataPoint(static_cast<int>(ecgValue + randomish(tickCounter) % static_cast<int>(yMax / 20.f)));

        // Randomize phase offset every few cycles to change peak position
        if (tickCounter % 100 == 0)
        {
            ecgPhaseOffset = static_cast<float>(randomish(tickCounter) % 1000) / 1000.0f;
        }
    }




    if (tickCounter % 120 == 0)
    {	int SO = packet.blood_oxygen/100;
        Unicode::snprintf(textArea_sao2Buffer, TEXTAREA_SAO2_SIZE, "%d", SO );
        textArea_sao2.invalidate();
    }

    if (tickCounter % 180 == 0)
    {
    	float body_temperature = packet.body_temperature / 10.0f;
        Unicode::snprintfFloat(textArea_temBuffer, TEXTAREA_TEM_SIZE, "%.2f", body_temperature);
        textArea_tem.invalidate();
    }

    if (tickCounter % 180 == 0)
    {

    	int heart_rate=packet.heart_rate/10;
        Unicode::snprintf(textArea_heartBuffer, TEXTAREA_HEART_SIZE, "%d",heart_rate);
        textArea_heart.invalidate();
    }












}





//typedef struct {
//    uint32_t ecg_data[ECG_DATA_SIZE];
//    uint32_t heart_rate;
//    uint32_t body_temperature;
//    uint32_t blood_oxygen;
//} DataPacket;

