#include <pybind11/pybind11.h> // must be first
#include <string>
#include <iostream>

namespace py = pybind11;


class io_buffers
{
  const void *input_buf;
  void *output_buf;
};



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
        std::vector<std::complex<float>> vector_of_complex(10);
      vector_of_complex[0] = std::complex<float>(3.5,4.6);


          py::buffer_info b(
                (void *)&vector_of_complex[0],                            /* Pointer to buffer */
                sizeof(std::complex<float>),                       /* Size of one scalar */
                std::string("gr_complex"), //py::format_descriptor<gr_complex>::format(), /* Python struct-style format descriptor */
                1,                                   /* Number of dimensions */
                { 10, },              /* Buffer dimensions */
                { sizeof(std::complex<float>), }
          );

          std::cout << (void *)&vector_of_complex[0] << std::endl;
          std::cout << vector_of_complex[1] << std::endl;
          d_h.attr("test_buffer")((void *)&vector_of_complex[0]);

          std::cout << vector_of_complex[1] << std::endl;

          // d_h.attr("test")();
      }

};