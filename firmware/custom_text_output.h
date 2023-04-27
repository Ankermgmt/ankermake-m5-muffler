#include "esphome.h"

class CustomTextOutput : public Component, public TextSensor {
 public:
  void setup() override {
    // You can place any setup code you need here.
  }

  TextSensor *to_text_sensor() {
    return this;
  }

  void write_float_state(float state) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.2f", state);
    publish_state(std::string(buffer));
  }
};
