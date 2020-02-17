import numpy as np
from gateway import sync_block
import ctypes


########################################################################
# Magic to turn pointers into numpy arrays
# http://docs.scipy.org/doc/numpy/reference/arrays.interface.html
########################################################################
def pointer_to_ndarray(addr, dtype, nitems):
    class array_like(object):
        __array_interface__ = {
            'data': (int(addr), False),
            'typestr': dtype.base.str,
            'descr': dtype.base.descr,
            'shape': (nitems,) + dtype.shape,
            'strides': None,
            'version': 3
        }
    return np.asarray(array_like()).view(dtype.base)


class bar(sync_block):
    def __init__(self):  # only default arguments here
        """arguments to this function show up as parameters in GRC"""
        sync_block.__init__(
            self,
            self,
            'bar',   # will show up in GRC
            [np.complex64],
            [np.complex64]
        )

    def test(self):
        print("tested")

    def test_buffer(self, buf):
        print(type(buf))
        print(buf)
        
        ctypes.pythonapi.PyCapsule_GetPointer.restype = ctypes.c_void_p
        ctypes.pythonapi.PyCapsule_GetPointer.argtypes = [ctypes.py_object, ctypes.c_char_p]
        addr = ctypes.pythonapi.PyCapsule_GetPointer(buf, None)

        tmp = pointer_to_ndarray(addr, np.dtype(np.complex64),10)

        tmp[1] = 77+99j

        return 10

    def work(self, input_items, output_items):
        """example: multiply with constant"""
        output_items[0][:] = input_items[0]
        return len(output_items[0])


