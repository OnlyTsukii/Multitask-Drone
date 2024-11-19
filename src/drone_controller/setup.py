from setuptools import setup
import os
from glob import glob

package_name = 'drone_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=[
        package_name, 
        'drone_controller.task',
        'drone_controller.waypoint'
        ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.[pxy][yma]*'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='xs',
    maintainer_email='1431297183@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'drone_controller = drone_controller.drone_controller:main',
            'task_executor = drone_controller.task.task_executor:main',
            'waypoint_handler = drone_controller.waypoint.waypoint_handler:main'
        ],
    },
)