#ifndef BATTERY_H
#define BATTERY_H
#include "Component.hpp"
#include <string>

class Battery : public Component {
private:
  double voltage;

public:
  // Constructor
  Battery(const std::string &&name, double voltage, Connection *positive,
          Connection *negative);
  double getCurrent() const;
  void simulate(double time_step);
  void setCharge() const;
};

#endif
