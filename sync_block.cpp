#include <pybind11/pybind11.h> // must be first
#include <pybind11/complex.h>
#include <pybind11/stl.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

#include <iostream>
#include "sync_block.hpp"
namespace py = pybind11;

using namespace py::literals; // to bring in the `_s` literal

// We need this hack because import_array() returns NULL
// for newer Python versions.
// This function is also necessary because it ensures access to the C API
// and removes a warning.
void* init_numpy()
{
    import_array();
    return NULL;
}


PYBIND11_MODULE(gateway, m) {

    init_numpy();

    py::class_<sync_block, std::shared_ptr<sync_block>>(m, "sync_block")
        .def(py::init<py::object const &, std::string const &, py::list const &, py::list const &>())
        .def("run",&sync_block::run)
        ;
  
} /* end PYBIND11_PLUGIN(_pyho) */