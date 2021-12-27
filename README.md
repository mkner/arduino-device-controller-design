### Low level controller design for devices and robots using arduino microcontroller 

These projects are based on the course 
Building robots and other devices with Arduino 
(МФТИ - Строим роботов и другие устройства на Arduino)
that is available online from the Moscow Physics and Technical Instutute


The course provides lectures but minimal or missing documentation, diagrams, schematics,
spec sheets. So the major challange was to create the projects from scratch based on 
the general presentation in the lectures. Part lists had to be put together, the parts ordered
and finding the best equivalents to the Troyka modules that were highlighted in the course 
that are not readily available. And schematics and board layouts put had to be put together and then
jetisoned for a more ideal solution with the actual physical layout, wiring, testing for 
the components in the projects.

What a great example of what is not unusual in real world engineering in industry.

The software is basically coded up from scratch to match the ad hoc nature of assembly and 
testing of the projects. The main control loop for the various devices and their interactions is in C++
and utilizes libraries specific to the Arduinio boards.

The eventual goal is to build a custom differential drive autonomous robot.


