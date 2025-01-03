# 6502-Driven-Robotic-Arm
Two-linkage robotic arm run by servos and a joystick input on a 6502-driven computer

** Please note this is my first time using GitHub, so be kind :) **

First a quick story...
So this project is sort of a funny story. It began on a flight from Kelowna (YLW) to Toronto (YYZ). The airplane I was on did not have a movie-viewing device in 
front of me to sedate my brain for the 4+ hour flight! So I inevitably got bored before the wheels had left the ground and I started doodling on a napkin. I 
decided to take on the challenge of building a robotic arm from scratch without the use of the internet as I would not have access to it on the flight. I settled 
on a two-linkage design actuated by servos and driven using an Arduino. I spent plenty of time trying to figure out how to tell the servos what angle to turn to 
for any given point I tell the arm to actuate to. After trying multiple approaches I settled on the one I will discuss later. I used graphing software pre-downloaded 
on my laptop (as I couldn't access the internet) to test the systems of equations I created. I managed to solve the system of equations to work for the arm using high 
school math (as this took place in the summer between high school and university for me) and write out basic Arduino code on a napkin provided by the flight attendants 
before we landed. Now that you understand the conditions under which this idea was formulated, you can understand why I didn't choose what could be considered 
"conventional" options... It's simply because I came up with it all myself! Anyways, into the rest of the project...


**SYSTEM OF EQUATIONS**
The kinematics were solved by the intersection of circles on a graphing software already downloaded on my Macbook (as online graphers like Desmos were inaccessible 
during the flight) The file for this can be found under "systems of equations".


**ARDUINO**
Before I took on the challenge of programming the arm to run off a 6502 computer, I made it work on Arduino. You can download the code for Arduino under 
"Arduino code IDE 2.3.2".

*PINOUT for Arduino:*
A0 --> VRY,
A1 --> VRX,
D5 --> SERVO 1 signal,
D6 --> SERVO 2 signal,
D7 --> SWITCH (Currently not used)


**6502 COMPUTER**
*Circuit:*
I started with Ben Eater's design with some very small modifications (to free up more ports on the IO bus). You can find his incredible work here https://eater.net/6502 
and full credit to him for the design of the computer (you can find the schematic on his website). I built the computer a few years before this project (in grade 9) and 
decided to repurpose it for this project. I hooked up a PCA9685 to the WD65C22 bus to run the PWM signal for the servos to the computer as it made more sense to me than 
bit bashing directly from the computer and was more accurate than generating PWM from something like a 555 timer (which I did explore). The PCA9685 communicates over 
I2C Which I felt a little more comfortable bit bashing with the computer (plus it looks cool to have more hardware. Next, I hooked up some LM393 op-amps to screen the 
analog input into a digital input for the computer. Now I know what you are thinking. Yes, I could have used a button input instead of the joystick to have essentially 
the same result, and much less hassle, so why did I do it? Because it's cool of course! Sure, buttons are way more practical, but the joystick is way more fun and far 
cooler than the standard push button.

*Circuit of analog to digital converter for joystick:*
<img width="1055" alt="Screenshot 2025-01-03 at 3 02 36 PM" src="https://github.com/user-attachments/assets/d83d7c5a-f97c-4d06-9357-834897418aff" />
(LED's in place of output)
 
 
*Current state of computer (done, but missing one potentiometer which is in the mail):*
![IMG_8047](https://github.com/user-attachments/assets/d64020fe-bd1f-4cda-ad2c-b2703acbbe1f)
 
 
*Another angle :)*
![![IMG_8048](https://github.com/user-attachments/assets/9808ecf0-ec1e-4d73-a533-89d24a3a4d41)
 
 
*Minus PCA9685*
![IMG_8049](https://github.com/user-attachments/assets/b2bb4734-af11-45cd-a3ad-81e87b539d9e)
 
 
*Minus potentiometers*
![IMG_8050](https://github.com/user-attachments/assets/696fb0ed-3183-493f-879c-08ee59bfd5eb)

 
 
*Computer before modification:*
![IMG_7675](https://github.com/user-attachments/assets/49d44b68-5b99-4ae7-b0c1-277537fd347e)
 
 
*Software:*
Unfortunately, as of writing this, the software is not yet complete (neither is the circuit as I am still waiting for parts from Amazon). Once I finish off the software, 
I will update this project and add it to this section. Until then enjoy the Arduino code and system of equations and I will get back to you. Until then, thank you for reading.
Jan 3, 2025
