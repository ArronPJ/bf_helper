import os

from conans import ConanFile, CMake, tools


class BfHelperTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    #org
    generators = "cmake"
    #generators = "xcode"
    # fail to add catch2
    #build_requires = "catch2/2.13.6"
    #exports_sources = "CMakeLists.txt", "include*", "src*", "test/src*", "test/resources*"
    
    def configure_cmake(self):
        cmake = CMake(self)
        # Options
        cmake.definitions["SOME_DEFINITION_NAME"] = "On"
        cmake.configure()
        return cmake
    
    #def requirements(self):
    #    self.requires("catch2/2.13.6")

    def build(self):
        #org
        #cmake = CMake(self)
        #new
        cmake = self.configure_cmake()
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is
        # in "test_package"
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

    def test(self):
        if not tools.cross_building(self):
            os.chdir("bin")
            self.run(".%sexample" % os.sep)
