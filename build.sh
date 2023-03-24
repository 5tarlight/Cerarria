TIMEFORMAT='It took %R seconds.'

time {
  mkdir build
  cd build
  cmake ..
  # make VERBOSE=TRUE
  make
}

cd ..

./build/bin/program
