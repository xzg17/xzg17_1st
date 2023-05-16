from distutils.core import setup, Extension
import os

os.environ['CC'] = 'gcc'

src_dir = 'src'

ext_modules = [Extension('xzg17', [src_dir + '/pow.c',src_dir + '/wrapper.c'])]

setup(
  name='xzg17_1st',
  ext_modules = ext_modules,
  url="https://github.com/xzg17/xzg17_1st")
