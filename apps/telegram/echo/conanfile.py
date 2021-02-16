import os

from conans import ConanFile, CMake, tools


class RandomChat(ConanFile):
    settings = "os", "compiler", "build_type", "arch", "cppstd"
    generators = "cmake", "cmake_find_package"

    default_options = {"tgbot_cpp:shared": False}

    def requirements(self):
        self.requires("tgbot/1.2.1")
        self.requires("fmt/7.1.3")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

