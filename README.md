flagOnSpawn
===========

BZFlag plugin that gives players a flag on spawn depending on a variable

Usage
-----

The flagOnSpawn plugin is easy to use. After you load it (it doesn't require any parameters), set the variable _flagonspawn according to your preferences.

Possible values:
* `AA`: Give no flag on spawn, does the same as if the plugin wasn't loaded
* Any flag name (e.g. `WG`): Gives the specified flag on spawn

Note that if you want to set this variable on your config file, do so this way:

    -setforced _flagonspawn value

Installation by compilation on Linux
------------------------------------

1. Go to the plugins directory and run `git clone git://github.com/kongr45gpen/flagOnSpawn.git`, then `git checkout 2.0.x`
2. Edit the Makefile.am and add a line for the flagOnSpawn folder, and do the same to ../configure.ac
3. On the base bzflag source folder, run:
<pre>
./autogen.sh
./configure.sh --enable-shared --disable-client
make
sudo make install
</pre>
4. Add `-loadplugin /path/to/plugin` to your server configuration file, where /path/to/plugin is the path to the generated flagOnSpawn.so file
