#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 12 10:55:00 2017

@author: jmmauricio
"""



from setuptools import setup, find_packages

setup(
    name="hyper",
    version="0.1.dev0",
    packages=find_packages("src"),
    package_dir={"": "src"},
    setup_requires=["cffi>=1.0.0"],
    install_requires=["cffi>=1.0.0"],
    cffi_modules=["src/_cffi_src/build_hyper.py:ffi"],
)