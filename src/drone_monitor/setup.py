from setuptools import find_packages, setup
import os
from glob import glob

package_name = "drone_monitor"

setup(
    name=package_name,
    version="0.0.0",
    packages=["drone_data_hub"],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="xs",
    maintainer_email="1431297183@qq.com",
    description="TODO: Package description",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "data_hub = drone_data_hub.drone_data_hub:main",
        ],
    },
)
