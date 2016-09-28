mkdir build
cd build

# Configure step
cmake -DCMAKE_INSTALL_PREFIX=$PREFIX \
 -DCMAKE_BUILD_TYPE=Release \
 -DCMAKE_PREFIX_PATH=$PREFIX \
 -DCMAKE_SYSTEM_PREFIX_PATH=$PREFIX \
 -DCMAKE_SHARED_LINKER_FLAGS=-lm \
 -DTIXI_BUILD_TESTS=ON \
 -DPYTHON_EXECUTABLE:FILEPATH=$PYTHON \
 ..

# Build step
make -j $CPU_COUNT
make doc

# remove linkage to static libs
cmake .

# Install step
make install

# Tests
make test

# create the binary package
make package
cp *.tar.gz $RECIPE_DIR/

# install python packages
mkdir $SP_DIR/tixi
touch $SP_DIR/tixi/__init__.py
cp lib/tixiwrapper.py $SP_DIR/tixi/
python $RECIPE_DIR/fixosxload.py $SP_DIR/tixi/tixiwrapper.py libTIXI
