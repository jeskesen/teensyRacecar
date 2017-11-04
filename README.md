# teensyRacecar
Teensy firmware for autonomous competition racecar.

This library contains the firmware for a competition robot based on an RC car.  As the name implies, I'm running this on a Teensy v3.X microcontroller, but the exact value of X is still undecided.  The current implementation uses a Traxxas Stampede 2wd brushless, however this could easily be run on something else. I hope to make this modular so that it can be used in multiple competitions such as [DIY Robocars](https://diyrobocars.com/), [Sparkfun AVC](https://avc.sparkfun.com/), & [the Robomagellan competition at Robogames](http://robogames.net/rules/magellan.php).

This repsoitory is orgainized as a library, so that various subsystems can be tested individually, or that muliple sketches can be accessed, so I can switch between functionalities.

## Dependencies
* [PulsePosition](https://github.com/PaulStoffregen/PulsePosition) for reading from my CPPM RC Reciever.
 
