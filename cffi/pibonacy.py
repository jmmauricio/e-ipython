#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 12 10:55:00 2017

@author: jmmauricio
"""


from cffi import FFI
ffi = FFI()

ffi.cdef(
    """
double hyp2f1x ( double a, double b, double c, double x );
"""
)
ffi.set_source(
    "_hyper",  # Nombre del módulo
    """
double hyp2f1x ( a, b, c, x )
double a, b, c, x;
{
    return 1.0;  // De hipergeométrico, poco
}
"""
)


if __name__ == '__main__':
    ffi.compile()