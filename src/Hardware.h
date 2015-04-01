#pragma once

#include "WPILib.h"
#include "XMLInput.h"

#define drivebase   Hardware::drivebase
#define lift        Hardware::lift
#define fork        Hardware::fork
#define intake      Hardware::intake
#define intakeArms  Hardware::intakeArms

namespace dreadbot {
  struct Hardware {
    static MecanumDrive* drivebase;
	  static MotorGrouping* intake;
		static PneumaticGrouping* lift;
		static PneumaticGrouping* fork;
		static PneumaticGrouping* intakeArms;
  };
}
