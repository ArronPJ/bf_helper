from conans import ConanFile, CMake, tools, __version__ as conan_version
from conans.tools import Version


class BfHelperConan(ConanFile):
    name = "bf_helper"
    version = "1.2.3"
    license = "MIT"
    author = "ArronPJ <princejar@gmail.com>"
    url = "https://github.com/ArronPJ/bf_helper"
    description = "Library package by Conan"
    topics = ("helper utility", "crossplatform")
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False], 
        "fPIC": [True, False]
    }
    default_options = {
        "shared": False, 
        "fPIC": True,
        "boost:without_wave": True, 
        "boost:without_test": True,
        "boost:without_stacktrace": True,
        "boost:without_iostreams": True, #need random , regex as well
        #"boost:without_serialization": True, -> date_time need this
        "boost:without_regex": True,
        "boost:without_random": True,
        "boost:without_math": True,
        "boost:without_log": True,
        "boost:without_locale": True,
        "boost:without_graph": True,
        "boost:without_coroutine": True,
        "boost:without_contract": True,
        "boost:without_context": True,  #--- new here(13)
        #"boost:without_container": True,# thread need this
    }
    # add "conanbuildinfo.json", 
    generators = "cmake", "json"
    #exports_sources = "src/*"
    exports_sources = "CMakeLists.txt", "src/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC
    def requirements(self):
        # If we need to dynamic require according to OS?
        self.requires("jansson/2.12")   # new = "jansson/2.13.1"
        self.requires("boost/1.69.0")


    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        

        # for android
        #cmake.definitions["ANDROID_NDK"] = "/aaa/bbb/"
        
        #if conan_version >= Version("1.36.0"):
        #    ...
        #else:
        cmake.configure()
        #cmake.configure(source_folder="src")
        
        ## for Xcode IDE Generate fail , unable to replace "Unix Makefiles"
        #cmake.configure(args=["-G", "Xcode"])
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
