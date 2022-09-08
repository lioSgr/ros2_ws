from setuptools import setup

package_name = 'learn_topic'

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
            'topic_pub = learn_topic.topic_publisher:main',
            'topic_sub = learn_topic.topic_subscriber:main',
            'topic_webcam_pub      = learn_topic.topic_webcam_pub:main',
            'topic_webcam_sub      = learn_topic.topic_webcam_sub:main',
        ],
    },
)
