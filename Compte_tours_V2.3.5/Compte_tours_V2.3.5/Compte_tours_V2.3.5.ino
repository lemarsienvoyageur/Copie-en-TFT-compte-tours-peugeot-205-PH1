// Compte tour TFT peugeot 205 PH1
// Creation Le marsien voyageur
// inclue le compte tours et la température d'eau dans un ecran TFT 3.2 avec le décodeur ILI9341
// https://fr.aliexpress.com/item/1005003152078101.html?spm=a2g0o.order_list.order_list_main.5.21ef5e5bb1eg0c&gatewayAdapt=glo2fra model 3.2 Inch TFT 14P (NO Touch)
// peux fonctionné avec d'autre écran et décodeurs mais pas testé
// Je décline toute responsabilité sur touts dommage causé par la création de ce compte tours

#include <lvgl.h>
#include "ui.h"

#include <Arduino_GFX_Library.h>

#define GFX_BL 27 


Arduino_DataBus *bus = new Arduino_ESP32SPI(21 /* DC */, 22 /* CS */, 18 /* SCK */, 23 /* MOSI */, 19 /* MISO */);
Arduino_GFX *gfx = new Arduino_ILI9341(bus, 17 /* RST */, 3 /* rotation */, false /* IPS */);

const int PIN_SIGNAL_1 = 26;
const int PIN_VEIL = 26;
static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp);
}


const int analogInPin2 = 35;
const int alim = 2;
unsigned long tr = 0;
volatile long comptageImpuls = 0;
long timeRef = 0;
long delai = 250;
long timeRef1 = 0;
long delai1 = 1000;
signed angle = -256;
long signed temp = 0.00;
long signed temp2 = 0.00;

void IRAM_ATTR fonction_ISR() {
  comptageImpuls = comptageImpuls + 1;
}

void setup()
{

  pinMode(PIN_SIGNAL_1, INPUT_PULLUP);
  attachInterrupt(PIN_SIGNAL_1, fonction_ISR, FALLING);

  pinMode(PIN_VEIL, INPUT_PULLUP);
  pinMode(analogInPin2, INPUT_PULLUP);
  pinMode(alim, OUTPUT);
  digitalWrite(alim,HIGH);

#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

  gfx->begin();
  gfx->fillScreen(BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif

  lv_init();

  screenWidth = gfx->width();
  screenHeight = gfx->height();
#ifdef ESP32
  disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth * 32, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 32);
#endif
  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * 32);

    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);

    ui_init();

  }

  ledcSetup(0, 5000, 8);
  ledcAttachPin(GFX_BL, 0);

}

void loop()
{
  lv_timer_handler();
  delay(5);

  if(digitalRead(PIN_VEIL) == 1){
    ledcWrite(0, 255);
  }else{
    ledcWrite(0, 125);
  }

  if (millis() >= timeRef + delai) {
    tr = (comptageImpuls / 2) * 240;
    angle = map(tr, 0, 8000, -256, 2000);
    if(angle < -256){ angle = -256;}
    if(angle > 2000){ angle = 2000;}
    lv_img_set_angle(ui_needle, angle);
    comptageImpuls = 0;
    timeRef = millis();
  }

  if (millis() >= timeRef1 + delai1) {
    temp2 = map(analogRead(analogInPin2),4095, 0, -10, 110);
    char buff2[7];
    sprintf(buff2, "%d °C", temp2);
    lv_label_set_text(ui_tmot, buff2);
    if (temp2 < 55){lv_label_set_recolor(ui_tmot, 0x615DF6);}
    if (56 < temp2 < 95){lv_label_set_recolor(ui_tmot, 0xFFFFFF);}
    if (temp2 > 95){lv_label_set_recolor(ui_tmot, 0xFB0D2C);}
    timeRef1 = millis();
  }

}
