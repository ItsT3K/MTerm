# MTerm
MTerm is a terminal I decided to work on based around a VTE terminal tutorial. The original idea of this terminal was to have it look like a DEC terminal by using the DEC Terminal Font. However this got annoying for me to use after a bit. So I decided to change it. Originally the change was to Perfect DOS VGA which looked alright. Then I settled on Pixifont 2 by https://kokoscript.com. 

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
