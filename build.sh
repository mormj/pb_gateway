# c++ -g -O0 -Wall -std=c++11 `python3-config --cflags` -fPIC `python3 -m pybind11 --includes` main.cpp -o a.out `python3-config --ldflags`
c++ -g -O0 -Wall -std=c++11 -shared  `python3-config --cflags` -fPIC `python3 -m pybind11 --includes` sync_block.cpp -o gateway`python3-config --extension-suffix` `python3-config --ldflags`
