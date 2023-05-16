from distutils.core import setup, Extension

src_dir = 'src'

ext_modules = [Extension('xzg17', [src_dir + '/pow.c',src_dir + '/wrapper.c'])]

setup(name='xzg17_1st', ext_modules = ext_modules)
