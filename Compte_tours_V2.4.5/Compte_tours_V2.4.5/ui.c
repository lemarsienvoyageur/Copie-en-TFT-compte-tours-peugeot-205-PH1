#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void UP_Animation( lv_obj_t *TargetObject, int delay);
void ui_event_Screen1( lv_event_t * e);
lv_obj_t *ui_Screen1;
lv_obj_t *ui_logot;
lv_obj_t *ui_comptetours;
lv_obj_t *ui_fond;
lv_obj_t *ui_needle;
lv_obj_t *ui_tmot;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_ctp_tour_05_ph1v[1] = {&ui_img_ctp_tour_205_ph1v2_png};
const lv_img_dsc_t *ui_imgset_294128139[1] = {&ui_img_82345605};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void UP_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 5000);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity );
lv_anim_set_values(&PropertyAnimation_0, 0, 255 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_linear);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, true );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity );
lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Screen1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      UP_Animation(ui_logot, 2000);
}
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      _ui_screen_change( ui_comptetours, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_logot = lv_img_create(ui_Screen1);
lv_img_set_src(ui_logot, &ui_img_82345605);
lv_obj_set_width( ui_logot, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_logot, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_logot, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_logot, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_logot, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_logot, lv_color_hex(0x020000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_logot, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_logot, lv_color_hex(0x020000), LV_PART_MAIN | LV_STATE_DEFAULT );

lv_obj_add_event_cb(ui_Screen1, ui_event_Screen1, LV_EVENT_ALL, NULL);

}
void ui_comptetours_screen_init(void)
{
ui_comptetours = lv_obj_create(NULL);
lv_obj_clear_flag( ui_comptetours, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_comptetours, lv_color_hex(0x070101), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_comptetours, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fond = lv_img_create(ui_comptetours);
lv_img_set_src(ui_fond, &ui_img_ctp_tour_205_ph1v2_png);
lv_obj_set_width( ui_fond, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_fond, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_fond, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_fond, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_fond, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_pivot(ui_fond,160,135);

ui_needle = lv_img_create(ui_comptetours);
lv_img_set_src(ui_needle, &ui_img_needle_trans_png);
lv_obj_set_width( ui_needle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_needle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_needle, -49 );
lv_obj_set_y( ui_needle, 35 );
lv_obj_set_align( ui_needle, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_needle, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_img_set_pivot(ui_needle,110,45);
lv_img_set_angle(ui_needle,-256);
lv_obj_set_style_blend_mode(ui_needle, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor(ui_needle, lv_color_hex(0x000000), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_needle, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tmot = lv_label_create(ui_comptetours);
lv_obj_set_width( ui_tmot, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tmot, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_tmot, -131 );
lv_obj_set_y( ui_tmot, -98 );
lv_obj_set_align( ui_tmot, LV_ALIGN_CENTER );
lv_label_set_text(ui_tmot,"°C");
lv_obj_set_style_text_font(ui_tmot, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
ui_comptetours_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Screen1);
}
