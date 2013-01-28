flagOnSpawn
===========

BZFlag plugin that gives players a flag on spawn depending on a variable

Requirements (pay attention!)
-----------------------------

This plugin requires your BZFlag version to be newer than 2.4.2 (2.4.3 or higher).
If you have another version, check the 'Tags' tab for the appropriate one.
New features will be only added to the latest BZFlag version.

Usage
-----

The flagOnSpawn plugin is easy to use. After you load it (it doesn't require any parameters), set the variable _flagonspawn according to your preferences.

Possible values:
* `none`: Give no flag on spawn, does the same as if the plugin wasn't loaded
* `random`: Gives a random flag on spawn, making a choice amongst the available ones
* Any flag name (e.g. `WG`): Gives the specified flag on spawn

Note that if you want to set this variable on your config file, do so this way:

    -setforced _flagonspawn value

Installation by compilation on Linux
------------------------------------

1. Go to the plugins directory and run `git clone git://github.com/kongr45gpen/flagOnSpawn.git`
2. Edit the Makefile.am and add a line for the flagOnSpawn folder, and do the same to ../configure.ac
3. On the base bzflag source folder, run:
<pre>
./autogen.sh
./configure.sh --disable-client
make
sudo make install
</pre>
4. Add `-loadplugin flagOnSpawn` to your server configuration file.
