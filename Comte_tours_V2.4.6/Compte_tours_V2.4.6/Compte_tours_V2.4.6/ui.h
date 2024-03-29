#ifndef _COMPTE_TOURS_V235_UI_H
#define _COMPTE_TOURS_V235_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif

#include "ui_events.h"
void UP_Animation( lv_obj_t *TargetObject, int delay);
void ui_event_Screen1( lv_event_t * e);
extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_logot;
extern lv_obj_t *ui_comptetours;
extern lv_obj_t *ui_fond;
extern lv_obj_t *ui_needle;
extern lv_obj_t *ui_tmot;
extern lv_obj_t *ui____initial_actions0;


LV_IMG_DECLARE( ui_img_82345605);   // assets\Peugeot_Logo_1980-4.png
LV_IMG_DECLARE( ui_img_ctp_tour_205_ph1v2_png);   // assets\CTP_TOUR_205_PH1V2.png
LV_IMG_DECLARE( ui_img_needle_trans_png);   // assets\needle_trans.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
