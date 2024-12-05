#include <gui/ecg_screen/ECGView.hpp>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include "main.h"
#include <queue>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/Types.hpp>
extern DataPacket packet;

extern int ECG_flag;

ECGView::ECGView()
{
	tickCounter = 0;

}

void ECGView::setupScreen()
{
    ECGViewBase::setupScreen();
    ECG_flag==1;

}

void ECGView::tearDownScreen()
{
    ECGViewBase::tearDownScreen();
    ECG_flag==0;
}





void ECGView::handleTickEvent()
{
    tickCounter++;


    if (tickCounter % 2 == 0)
    {



        	// 遍历 ecg_data 数组并添加每个数据点到图表中
        for (int i = 0; i < ECG_DATA_SIZE; i++) {
            // 将 uint32_t 数据转换为 float 类型并进行适当的缩放
            float dataPoint = static_cast<float>(packet.ecg_data[i]) / 1000.0f;

            // 添加数据点到图表
            dynamicGraph1.addDataPoint(dataPoint);

        }




    }
}





