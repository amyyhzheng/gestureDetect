# DEEPCRAFT Studio 5.2.2135+b54b28f236fe7c6fb520f00b8de0ba1419f4422f
# Copyright © 2023- Imagimob AB, All Rights Reserved.

import numpy as np
import enum



def copy(src, output):
    np.copyto(output, src.reshape(output.shape))

class ReturnStatus(enum.Enum): 
    RET_SUCCESS = 0
    RET_NODATA = -1
    RET_NOMEM = -2


class Model:
    def __init__(self):
        self.data_in_count = 1
        self.data_in_shape = (1)
        self.data_out_count = 1
        self.data_out_shape = (1)
        self.api = 'function'

    def compute(self, data_in : np.array, data_out : np.array):
        """
        Compute a forward pass
        
        Parameters:
         data_in(float[1]): DESCRIPTION. [1]
         data_out(float[1]): DESCRIPTION. [1]
        """
        
        copy(data_in, data_out.reshape([1]))

