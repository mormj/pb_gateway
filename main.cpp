#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h> 
namespace py = pybind11;

#include <iostream>

int main()
{
    py::scoped_interpreter guard{};
    py::object sys = py::module::import("sys");
    py::print(sys.attr("path"));

    std::cout << "blah" << std::endl;
    py::object bar = py::module::import("foo").attr("bar");
    bar.attr("test")(bar);
    std::cout << "blah" << std::endl;
    return 0;
}