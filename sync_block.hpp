#include <pybind11/pybind11.h> // must be first
#include <string>
namespace py = pybind11;

class sync_block
{
    private:
      // handle to the python object
      py::handle d_h;
      std::string d_name;
      py::list d_in_sig;
      py::list d_out_sig;
      

    public:


      sync_block(const py::object& obj, const std::string& name, const py::list& in_sig, const py::list& out_sig) : 
        d_h(obj),
        d_name(name),
        d_in_sig(in_sig),
        d_out_sig(out_sig)
      {
        // store the handle, name, io signature
      }

      ~sync_block() {}
      void run()
      {
          d_h.attr("test")();
      }

};