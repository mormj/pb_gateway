import foo
import numpy as np
from gateway import sync_block
fb = foo.bar()

fb.run()

# sb = sync_block(  
#             fb,
#             'bar',   
#             [np.complex64],
#             [np.complex64])

# sb.run()