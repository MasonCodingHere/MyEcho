##########################################################################
# File Name: build.sh
# Author: GeekPanda
# mail: xgx127@126.com
# Created Time: 2020年11月12日 星期四 10时40分13秒
#########################################################################

#!/bin/sh

set -x
pwd
mkdir build bin
cd build
cmake ..
make
cmake .. -DCLIENT=OFF
make
