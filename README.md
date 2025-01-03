# 6502-Driven-Robotic-Arm
Two-linkage robotic arm run by servos and a joystick input on a 6502-driven computer


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


The kinematics were solved by the intersection of circles
