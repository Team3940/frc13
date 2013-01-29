CyberTooth (Team 3940) 2013 Robot Code
======================================

Introduction
------------
This is the software used by the CyberTooth Robotics Team in the 2013 *FIRST*
Robotics Competition.  We are working on implementing the following features:

* Vision processing all on cRIO
* Camera-assisted shooter aiming
* Automated pyramid climbing
* Lightweight web server to assist in debugging and auto mode development


Directory structure
-------------------

The `auto/` directory contains various modular "commands".  These commands
are primarily for use in autonomous mode, but can also be used to automate
processes during teleoperated control.  Simple commands can be combined
sequentially and concurrently to construct more complex commands.

The `controllers/` directory contains classes to clearly map USB game
controllers as well as more abstract classes which drive subsystems.
For example, the HumanDriver encapsulates the driver game controllers
and maps them to the drivebase.

The `systems/` directory holds classes which encapsulate various physical
subsystems, such as the drivetrain, shooter, and climbing system.

The `util/` directory contains classes which don't seem to fit anywhere else.

`vision/` classes process images taken by the camera to augment aiming while
shooting.

The `web/` directory contains classes to support the web server.
