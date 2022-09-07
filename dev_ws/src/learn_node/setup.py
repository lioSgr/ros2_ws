from setuptools import setup

package_name = 'learn_node'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lio',
    maintainer_email='lioSgr@126.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'node_talker = learn_node.node_talker:main',
        'node_talker_class = learn_node.node_talker_class:main',
        'node_object = learn_node.node_object:main',
        'node_object_webCam = learn_node.node_webCam:main',
        ],
    },
)
