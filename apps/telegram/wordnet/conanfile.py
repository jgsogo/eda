import os

from conans import ConanFile, CMake, tools


class TelegramWordnet(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"

    def requirements(self):
        self.requires("tgbot/1.2.1")
        self.requires("wnb/0.6")
        self.requires("fmt/7.1.3")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

        self.copy("*", dst="bin/wordnet", src='data', keep_path=True)
