# The IEEE UMN Coding a Cloud Project

## What is this?
Similar to last semester with the Laser Maze, I wanted to get kids interested in embedded development, and giving away free things (microcontrollers), is one of the best ways to do that. 

So for this project, I designed and wrote a program that runs on an RP2040 to have a lamp that can turn off, auto-cycle through colors, and display any color of the rainbow on the board's built-in NeoPixel LED.

> The hardest part of reproducing this project is mass-producing the parts. Laser cutting, soldering, assembling boxes and the "clouds" took many hours and a number of volunteers. In total, we made around 60 lamps.  

<p align="middle">
<img src="https://github.com/vaibhavshirole/Mini-Lamp/blob/main/resources/images/IMG_8616_Original.jpg?raw=true" alt= “” width="35%" height="100%">
<img src="https://github.com/vaibhavshirole/Mini-Lamp/blob/main/resources/images/IMG_8627_Original.JPG?raw=true" alt= “” width="35%" height="100%">
</p>

<br>

## Outreach Events
**CSE's Rooted in STEM**

> (insert imgs when I get them)

**Shakopee High School**

We also did this project with Shakopee High School, but got too side-tracked to take pictures. 

<br>

## Fabrication
**Laser cutting**

Each lamp needed a custom base to hold up the "cloud" part, and to do this, I re-learned Adobe Illustrator and cut out 50-60ish finger joint boxes out of 1/8-in MDF. 

<p align="middle">
<img src="https://github.com/vaibhavshirole/Mini-Lamp/blob/main/resources/images/the-process/sketch.png?raw=true" alt= “” width="45%" height="100%">
<img src="https://github.com/vaibhavshirole/Mini-Lamp/blob/main/resources/images/the-process/laser-cutting-1.JPG?raw=true" alt= “” width="50%" height="100%">
</p>

**Soldering**

Every microcontroller needed it's headers soldered on, and every potentiometer had three wires on it that needed soldering as well. In total, that's probably >1,300 points soldered.

**Assembly**

Because there were so many lamps that had to be made for these events, I had a group of volunteers help me put everything together. I couldn't have done all of this by myself.

<p align="middle">
<img src="https://github.com/vaibhavshirole/Mini-Lamp/blob/main/resources/images/the-process/assembly.JPG?raw=true" alt= “” width="65%" height="100%">
</p>

<br>

## Coding
**main branch**

The main branch contains the .ino files that are fully filled out and can be directly flashed onto the microcontroller.

**template branch**

The template branch is the branch that the students following the tutorial should look at. Template gives the code that the slides will step through and will result in code that will look just like the completed code by the end.

**Why is there a simple and hard?**

The simple template is good for learning the basics of coding in C. The hard template was overwhelming after running this demo a few times due to how many helper functions there were and all of the comments. The hard template is a good way to learn about using functions within main(), but the simple template is a better starting point. 

<p align="middle">
<img src="https://github.com/vaibhavshirole/Mini-Lamp/blob/main/resources/images/the-process/slideshow.png?raw=true" alt= “” width="85%" height="100%">
</p>