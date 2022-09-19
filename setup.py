import sys

from pybind11 import get_cmake_dir
from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

__version__ = "0.0.1"


ext_modules = [
    Pybind11Extension("rsequence",
        ["src/wrap.cpp", "src/rsequence.cpp"],
        define_macros = [('VERSION_INFO', __version__)],
        ),
]


long_description = '''
Stateful generator of R sequence, 
as described in http://extremelearning.com.au/unreasonable-effectiveness-of-quasirandom-sequences/
'''

setup(
    name="rsequence",
    version=__version__,
    author="Edoardo Pona",
    author_email="edoardo.pona@gmail.com",
    description="Sample numbers from the low discrepancy R sequence",
    long_description=long_description,
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.6",
)