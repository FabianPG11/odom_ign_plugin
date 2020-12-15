# odom_ign_plugin
Plugin for odometry on ignition gazebo

## Generate the Plugin 
It is neccesary to have the repo 
ign-plugin

The current repository contains 3 files:
* Header: OdomOmnidirectional.hh
* Implement source OdomOmnidirectional.cc
* CMakeList.txt

``` bash 
 cd odom_ign_plugin
mkdir build/
cd build/
cmake ..
make
```

It should generate a .so file 
we can import it to ignition gazebo:
``` bash 
cd odom_ign_plugin
export IGN_GAZEBO_SYSTEM_PLUGIN_PATH=`pwd`/build
```
