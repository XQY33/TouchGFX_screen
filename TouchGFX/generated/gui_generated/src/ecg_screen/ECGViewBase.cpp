/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/ecg_screen/ECGViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

ECGViewBase::ECGViewBase() :
    buttonCallback(this, &ECGViewBase::buttonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    boxWithBorder1.setPosition(0, 0, 800, 480);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(181, 165, 165));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(184, 184, 184));
    boxWithBorder1.setBorderSize(5);
    add(boxWithBorder1);

    button_go_back.setXY(10, 410);
    button_go_back.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_PRESSED_ID));
    button_go_back.setAlpha(0);
    button_go_back.setAction(buttonCallback);
    add(button_go_back);

    dynamicGraph1.setPosition(0, 0, 800, 392);
    dynamicGraph1.setScale(1);
    dynamicGraph1.setGraphAreaMargin(0, 0, 0, 0);
    dynamicGraph1.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph1.setGraphRangeY(110, 160);
    dynamicGraph1MinorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    dynamicGraph1MinorXAxisGrid.setInterval(2);
    dynamicGraph1MinorXAxisGrid.setLineWidth(1);
    dynamicGraph1MinorXAxisGrid.setAlpha(100);
    dynamicGraph1MinorXAxisGrid.setScale(1);
    dynamicGraph1MinorXAxisGrid.setMajorGrid(dynamicGraph1MajorXAxisGrid);
    dynamicGraph1.addGraphElement(dynamicGraph1MinorXAxisGrid);

    dynamicGraph1MinorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    dynamicGraph1MinorYAxisGrid.setInterval(2);
    dynamicGraph1MinorYAxisGrid.setLineWidth(1);
    dynamicGraph1MinorYAxisGrid.setAlpha(100);
    dynamicGraph1MinorYAxisGrid.setScale(1);
    dynamicGraph1MinorYAxisGrid.setMajorGrid(dynamicGraph1MajorYAxisGrid);
    dynamicGraph1.addGraphElement(dynamicGraph1MinorYAxisGrid);

    dynamicGraph1MajorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    dynamicGraph1MajorXAxisGrid.setInterval(10);
    dynamicGraph1MajorXAxisGrid.setLineWidth(2);
    dynamicGraph1MajorXAxisGrid.setScale(1);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorXAxisGrid);

    dynamicGraph1MajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    dynamicGraph1MajorYAxisGrid.setInterval(10);
    dynamicGraph1MajorYAxisGrid.setLineWidth(2);
    dynamicGraph1MajorYAxisGrid.setScale(1);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorYAxisGrid);

    dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFromRGB(250, 0, 0));
    dynamicGraph1Line1.setPainter(dynamicGraph1Line1Painter);
    dynamicGraph1Line1.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1Line1);


    dynamicGraph1.addDataPoint(121.308f);
    dynamicGraph1.addDataPoint(116.81091f);
    dynamicGraph1.addDataPoint(114.62595f);
    dynamicGraph1.addDataPoint(115.61028f);
    dynamicGraph1.addDataPoint(119.91762f);
    dynamicGraph1.addDataPoint(126.9449f);
    dynamicGraph1.addDataPoint(135.46188f);
    dynamicGraph1.addDataPoint(143.89282f);
    dynamicGraph1.addDataPoint(150.68198f);
    dynamicGraph1.addDataPoint(154.65424f);
    dynamicGraph1.addDataPoint(155.28337f);
    dynamicGraph1.addDataPoint(152.8031f);
    dynamicGraph1.addDataPoint(148.13445f);
    dynamicGraph1.addDataPoint(142.64766f);
    dynamicGraph1.addDataPoint(137.81775f);
    dynamicGraph1.addDataPoint(134.85802f);
    dynamicGraph1.addDataPoint(134.42187f);
    dynamicGraph1.addDataPoint(136.44558f);
    dynamicGraph1.addDataPoint(140.17079f);
    dynamicGraph1.addDataPoint(144.34056f);
    dynamicGraph1.addDataPoint(147.52096f);
    dynamicGraph1.addDataPoint(148.46852f);
    dynamicGraph1.addDataPoint(146.45328f);
    dynamicGraph1.addDataPoint(141.45733f);
    dynamicGraph1.addDataPoint(134.19956f);
    dynamicGraph1.addDataPoint(125.97978f);
    dynamicGraph1.addDataPoint(118.37953f);
    dynamicGraph1.addDataPoint(112.89196f);
    dynamicGraph1.addDataPoint(110.57101f);
    dynamicGraph1.addDataPoint(111.78486f);
    dynamicGraph1.addDataPoint(116.13375f);
    dynamicGraph1.addDataPoint(122.55199f);
    dynamicGraph1.addDataPoint(129.56889f);
    dynamicGraph1.addDataPoint(135.66482f);
    dynamicGraph1.addDataPoint(139.63535f);
    dynamicGraph1.addDataPoint(140.87469f);
    dynamicGraph1.addDataPoint(139.50936f);
    dynamicGraph1.addDataPoint(136.35011f);
    dynamicGraph1.addDataPoint(132.67439f);
    dynamicGraph1.addDataPoint(129.89352f);
    dynamicGraph1.addDataPoint(129.18675f);
    dynamicGraph1.addDataPoint(131.19269f);
    dynamicGraph1.addDataPoint(135.83435f);
    dynamicGraph1.addDataPoint(142.32154f);
    dynamicGraph1.addDataPoint(149.33047f);
    dynamicGraph1.addDataPoint(155.31737f);
    dynamicGraph1.addDataPoint(158.88955f);
    dynamicGraph1.addDataPoint(159.1435f);
    dynamicGraph1.addDataPoint(155.88721f);
    dynamicGraph1.addDataPoint(149.69241f);
    dynamicGraph1.addDataPoint(141.76352f);
    dynamicGraph1.addDataPoint(133.65528f);
    dynamicGraph1.addDataPoint(126.90746f);
    dynamicGraph1.addDataPoint(122.68564f);
    dynamicGraph1.addDataPoint(121.51523f);
    dynamicGraph1.addDataPoint(123.17312f);
    dynamicGraph1.addDataPoint(126.76256f);
    dynamicGraph1.addDataPoint(130.95236f);
    dynamicGraph1.addDataPoint(134.32079f);
    dynamicGraph1.addDataPoint(135.71949f);
    dynamicGraph1.addDataPoint(134.56749f);
    dynamicGraph1.addDataPoint(131.00302f);
    dynamicGraph1.addDataPoint(125.85533f);
    dynamicGraph1.addDataPoint(120.44346f);
    dynamicGraph1.addDataPoint(116.2509f);
    dynamicGraph1.addDataPoint(114.55609f);
    dynamicGraph1.addDataPoint(116.10937f);
    dynamicGraph1.addDataPoint(120.93589f);
    dynamicGraph1.addDataPoint(128.31328f);
    dynamicGraph1.addDataPoint(136.93022f);
    dynamicGraph1.addDataPoint(145.18775f);
    dynamicGraph1.addDataPoint(151.57039f);
    dynamicGraph1.addDataPoint(154.99703f);
    dynamicGraph1.addDataPoint(155.06636f);
    dynamicGraph1.addDataPoint(152.13774f);
    dynamicGraph1.addDataPoint(147.22818f);
    dynamicGraph1.addDataPoint(141.7514f);
    dynamicGraph1.addDataPoint(137.16323f);
    dynamicGraph1.addDataPoint(134.60063f);
    dynamicGraph1.addDataPoint(134.60275f);
    dynamicGraph1.addDataPoint(136.98248f);
    dynamicGraph1.addDataPoint(140.87965f);
    dynamicGraph1.addDataPoint(144.98273f);
    dynamicGraph1.addDataPoint(147.86419f);
    dynamicGraph1.addDataPoint(148.34685f);
    dynamicGraph1.addDataPoint(145.8109f);
    dynamicGraph1.addDataPoint(140.36567f);
    dynamicGraph1.addDataPoint(132.84323f);
    dynamicGraph1.addDataPoint(124.61468f);
    dynamicGraph1.addDataPoint(117.27319f);
    dynamicGraph1.addDataPoint(112.26075f);
    dynamicGraph1.addDataPoint(110.5293f);
    dynamicGraph1.addDataPoint(112.31863f);
    dynamicGraph1.addDataPoint(117.10501f);
    dynamicGraph1.addDataPoint(123.73282f);
    dynamicGraph1.addDataPoint(130.69688f);
    dynamicGraph1.addDataPoint(136.50622f);
    dynamicGraph1.addDataPoint(140.04065f);
    dynamicGraph1.addDataPoint(140.81294f);
    dynamicGraph1.addDataPoint(139.07305f);
    add(dynamicGraph1);

    back.setBitmap(touchgfx::Bitmap(BITMAP_GO_BACK_ID));
    back.setPosition(0, 400, 80, 80);
    back.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    add(back);
}

ECGViewBase::~ECGViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void ECGViewBase::setupScreen()
{

}

void ECGViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button_go_back)
    {
        //Interaction1
        //When button_go_back clicked change screen to start
        //Go to start with screen transition towards West
        application().gotostartScreenWipeTransitionWest();
    }
}
