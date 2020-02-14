import numpy as np
from gateway import sync_block

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

    def work(self, input_items, output_items):
        """example: multiply with constant"""
        output_items[0][:] = input_items[0]
        return len(output_items[0])


