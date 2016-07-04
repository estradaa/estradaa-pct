#include <string.h>
#include "enamel.h"
#include <pebble-events/pebble-events.h>

Window *window;

static void main_clay_listener(){
  APP_LOG(APP_LOG_LEVEL_DEBUG, enamel_get_TEXT_TASK());
}

static void main_init(void) {
  // window
  window = window_create();
  window_stack_push(window, true /* Animated */);
  window_set_background_color(window, GColorBlack);

  // enamel
  enamel_init();
  enamel_register_settings_received(main_clay_listener);
  events_app_message_open();
}

static void main_deinit(void) {
  window_destroy(window);
}

int main(void) {
  main_init();
  app_event_loop();
  main_deinit();
}
