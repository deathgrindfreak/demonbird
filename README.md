DemonBird
=======
DemonBird is a metal-inspired flappy bird clone.  Right now, it uses some stock flappy bird images, but as soon
as my artist collaborator gets off his ass I'll include the new images.

In an attempt to be at least a little original, I've made the colors of the
tetrominoes and the board correspond to the [Solarized](http://ethanschoonover.com/solarized) dark color scheme

Also, this project is still a work in progress and is buggy as hell, so feel free to add to it if you'd like.

![DemonBird](demo.png?raw=true "DemonBird")


Installation
------------

####Linux
If you wish to install the game, first clone the repo:

    git clone http://github.com/deathgrindfreak/demonbird.git

You'll also need the following libraries:

[SDL 1.2](http://libsdl.org/download-1.2.php), [SDL_ttf 2.0](http://libsdl.org/projects/SDL_ttf) and [SDL_mixer 1.2](http://libsdl.org/projects/SDL_mixer)

In Debian or Ubuntu this should install them:

    sudo aptitude install libsdl1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev

Then simply build and run:
    
    make
    ./demonbird


####Windows
I've tested DemonBird a bit on Windows using MinGW, but it requires changing the makefile and including the SDL .dll's.  Take a look at this [tutorial](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php) on installing SDL in Windows if you're interested in trying it out.


Gameplay
--------
####Movement

    left/down/up/right - hjkl or arrow keys

    pause - esc or p


License
-------
Copyright (c) 2014, Cooper Bell

DemonBird is provided **as-is** under the **BSD** license. 
For more information see LICENSE.
