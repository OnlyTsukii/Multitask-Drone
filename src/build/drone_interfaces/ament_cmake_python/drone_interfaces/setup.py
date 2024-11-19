from setuptools import find_packages
from setuptools import setup

setup(
    name='drone_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('drone_interfaces', 'drone_interfaces.*')),
)
