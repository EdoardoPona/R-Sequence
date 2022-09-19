#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "rsequence.h"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

using namespace pybind11::literals;

PYBIND11_MODULE(rsequence, m) {
    py::class_<RSequence>(m, "RSequence")
        .def(py::init<int, float>())
        .def("sample", &RSequence::sample, "sample quasirandom numbers according to R sequence");

    #ifdef VERSION_INFO
		m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
    #else
        m.attr("__version__") = "0.0";
    #endif
}
