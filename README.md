# MTerm
MTerm is a terminal I decided to work on based around a VTE terminal tutorial. This terminal requires the DEC Terminal Modern font to be pre-installed to your computer. This font can be gotten here https://www.dafont.com/dec-terminal-modern.font and installed to any computer that utilizes .ttf files.

I originally started this terminal out of boredom but I don't feel like quitting working on it :p

# How do I install mterm?

On Debian/Ubuntu
1. Go into your terminal and if you don't already have it installed, install `libvte-2.91-dev` and `cmake`
2. Install the font. You can do this by installing it through a font manager or doing `sudo cp pixifont2.ttf /usr/share/font`
3. Create a build directory by doing `mkdir build`
4. then do the following. `cd build && cmake .. && make`
5. if you want to fully install it follow step 4 up with `sudo make install`

On Fedora
1. Go into your terminal and if it's not already installed install `vte291-devel` and `cmake`
2. Install the font. Same process as Ubuntu/Debian from here to step 5

# Thanks to
Thanks to @foxgirl_IRL on twitter (https://kokoscript.com) for letting me use and package Pixifont 2 Monospace with the terminal and allowing me to rename the internal font name so it would work properly after mterm is compiled. 

Vincent Bernat for writing the original VTE tutorial that led to this.
