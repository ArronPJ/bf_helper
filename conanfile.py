from conans import ConanFile, CMake


class BfHelperConan(ConanFile):
    name = "bf_helper"
    version = "1.2.3"
    license = "MIT"
    author = "ArronPJ <princejar@gmail.com>"
    url = "https://github.com/ArronPJ/bf_helper"
    description = "Library package by Conan"
    topics = ("helper utility", "crossplatform")
    #requires = "boost/1.71.0" # comma-separated list of requirements
    #requires = "jansson/2.13.1"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False], 
        "fPIC": [True, False]
    }
    default_options = {
        "shared": False, 
        "fPIC": True
    }
    # add "conanbuildinfo.json", 
    generators = "cmake", "json"
    exports_sources = "src/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC
    def requirements(self):
        # If we need to dynamic require according to OS?
        self.requires("jansson/2.12")
        self.requires("boost/1.69.0")


    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure(source_folder="src")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["bf_helper"]
