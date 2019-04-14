# MUL_my_world_2018
A tiny 3D engine written from scratch

# Description
  At the begining this project was a school assignement which aimed to be a terraformer C program.
  I wanted to go further so I managed to improve it at the point it is now a (tiny) 3D engine.
  It is able to read OBJ files (and modify them with mouse and keyboard controls).
  It is almost completely writen from scratch except the window display, keyboard/mouse input and image loading groups of functions from the CSFML library.

# Use

```
USAGE 
./my_world	[map] 
map		object file to load in game 

USER INTERACTION 
buttons to zoom		'q'/'e' 
buttons to size up	'z'/'x' 
move			'arrow'/'up key'/'down key' 

rotate the object: 
ROLL	'j'/'u' 
YAW	'k'/'i' 
PITCH	'l'/'o' 
 
load file, save current object, change texture/color 
filename must be composed of letters and numbers 
```
<p align="center">
  <img src="https://i.imgur.com/suSCf5p.png" width="350" title="hover text">
</p>

# Requirements
  * CSFML (latest version)
  * tested on linux
  * compiled with gcc (8.3.1)
